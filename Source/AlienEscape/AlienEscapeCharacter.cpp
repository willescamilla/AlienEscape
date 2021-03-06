// Copyright Epic Games, Inc. All Rights Reserved.

#include "AlienEscapeCharacter.h"
#include "PaperFlipbookComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT(text), fstring))

DEFINE_LOG_CATEGORY_STATIC(SideScrollerCharacter, Log, All);

//////////////////////////////////////////////////////////////////////////
// AAlienEscapeCharacter

AAlienEscapeCharacter::AAlienEscapeCharacter()
{
	// Use only Yaw from the controller and ignore the rest of the rotation.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	// Set the size of our collision capsule.
	GetCapsuleComponent()->SetCapsuleHalfHeight(96.0f);
	GetCapsuleComponent()->SetCapsuleRadius(40.0f);

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 500.0f;
	CameraBoom->SocketOffset = FVector(0.0f, 0.0f, 75.0f);
	CameraBoom->SetUsingAbsoluteRotation(true);
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));


	// Create an orthographic camera (no perspective) and attach it to the boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->ProjectionMode = ECameraProjectionMode::Orthographic;
	SideViewCameraComponent->OrthoWidth = 2048.0f;
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	// Prevent all automatic rotation behavior on the camera, character, and camera component
	CameraBoom->SetUsingAbsoluteRotation(true);
	SideViewCameraComponent->bUsePawnControlRotation = false;
	SideViewCameraComponent->bAutoActivate = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;

	// Configure character movement
	GetCharacterMovement()->GravityScale = 10.0;
	GetCharacterMovement()->AirControl = 0.0f;
	GetCharacterMovement()->JumpZVelocity = 10.f;
	GetCharacterMovement()->GroundFriction = 0.0f;

	//The Speed at which the character is currently moving when using function "AddMovementInput"
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	GetCharacterMovement()->MaxFlySpeed = 600.0f;
	// Lock character motion onto the XZ plane, so the character can't move in or out of the screen
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->SetPlaneConstraintNormal(FVector(0.0f, -1.0f, 0.0f));

	// Behave like a traditional 2D platformer character, with a flat bottom instead of a curved capsule bottom
	// Note: This can cause a little floating when going up inclines; you can choose the tradeoff between better
	// behavior on the edge of a ledge versus inclines by setting this to true or false
	GetCharacterMovement()->bUseFlatBaseForFloorChecks = true;

	// Enable replication on the Sprite component so animations show up when networked
	GetSprite()->SetIsReplicated(true);
	bReplicates = true;
}

void AAlienEscapeCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AddMovementInput(FVector(1.0f, 0.0f, 0.0f), 1.0);
	UpdateCharacter();
}

//////////////////////////////////////////////////////////////////////////
// Animation

void AAlienEscapeCharacter::UpdateCharacter()
{
	// Update animation to match the motion
	UpdateAnimation();

	// Now setup the rotation of the controller based on the direction we are travelling
	const FVector PlayerVelocity = GetVelocity();
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, FString::Printf(TEXT("My Speed: %s"), *PlayerVelocity.ToString()));
	float TravelDirection = PlayerVelocity.X;
	// Set the rotation so that the character faces his direction of travel.
	if (Controller != nullptr)
	{
		if (TravelDirection < 0.0f)
		{
			Controller->SetControlRotation(FRotator(0.0, 180.0f, 0.0f));
		}
		else if (TravelDirection > 0.0f)
		{
			Controller->SetControlRotation(FRotator(0.0f, 0.0f, 0.0f));
		}
	}
}

//  Currently the character is always running
void AAlienEscapeCharacter::UpdateAnimation()
{
	const FVector PlayerVelocity = GetVelocity();
	const float PlayerSpeedSqr = PlayerVelocity.SizeSquared();

	// Are we moving or standing still?
	UPaperFlipbook* DesiredAnimation = (PlayerSpeedSqr > 0.0f) ? RunningAnimation : IdleAnimation;
	if (GetSprite()->GetFlipbook() != DesiredAnimation)
	{
		GetSprite()->SetFlipbook(DesiredAnimation);
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void AAlienEscapeCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Note: the 'Jump' action and the 'MoveRight' axis are bound to actual keys/buttons/sticks in DefaultInput.ini (editable from Project Settings..Input)
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("FlipGravity", IE_Pressed, this, &AAlienEscapeCharacter::FlipGravity);
	PlayerInputComponent->BindAction("Slide", IE_Pressed, this, &AAlienEscapeCharacter::SlideStart);
	PlayerInputComponent->BindAction("Slide", IE_Released, this, &AAlienEscapeCharacter::SlideStop);
	PlayerInputComponent->BindAction("UseSpecialAbility", IE_Pressed, this, &AAlienEscapeCharacter::UseSpecialAbility);
	PlayerInputComponent->BindAction("UsePowerup", IE_Pressed, this, &AAlienEscapeCharacter::UsePowerup);
	PlayerInputComponent->BindAxis("MoveRight", this, &AAlienEscapeCharacter::MoveRight);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &AAlienEscapeCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AAlienEscapeCharacter::TouchStopped);
}

void AAlienEscapeCharacter::MoveRight(float Value)
{
	/*UpdateChar();*/

	// Apply the input to the character motion
	//AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);
}

void AAlienEscapeCharacter::FlipGravity()
{
	GetCharacterMovement()->GravityScale *= -1.0f;
	Jump();
	FRotator NewRotation = GetActorRotation();
	NewRotation.Roll += 180;
	SetActorRotation(NewRotation);
}

void AAlienEscapeCharacter::SlideStart()
{
	Crouch();
	UE_LOG(LogTemp, Warning, TEXT("Slide Start"));
}

void AAlienEscapeCharacter::SlideStop()
{
	UnCrouch();
	UE_LOG(LogTemp, Warning, TEXT("Slide Stop"));
	UE_LOG(LogTemp, Warning, TEXT("%f"), GetCharacterMovement()->GravityScale);
}

void AAlienEscapeCharacter::UsePowerup()
{
	UE_LOG(LogTemp, Warning, TEXT("Powerup"));
	UE_LOG(LogTemp, Warning, TEXT("%f"), GetCharacterMovement()->MovementMode);
}

void AAlienEscapeCharacter::UseSpecialAbility()
{
	UE_LOG(LogTemp, Warning, TEXT("SpecialAbility"));
}

void AAlienEscapeCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// Jump on any touch
	//Jump();
}

void AAlienEscapeCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// Cease jumping once touch stopped
	//StopJumping();
}