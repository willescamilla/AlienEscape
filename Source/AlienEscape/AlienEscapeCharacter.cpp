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

	/* Setup platform spawner spring components */
	SpringPlatformBottom = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringPlatformBottom"));
	SpringPlatformBottom->SetupAttachment(RootComponent);
	SpringPlatformBottom->TargetArmLength = -1700;
	SpringPlatformBottom->SocketOffset = FVector(0.0f, 0.0f, 0.0f);
	SpringPlatformBottom->SetUsingAbsoluteRotation(true);
	SpringPlatformBottom->bDoCollisionTest = false;
	SpringPlatformMiddle = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringPlatformMiddle"));
	SpringPlatformMiddle->SetupAttachment(RootComponent);
	SpringPlatformMiddle->TargetArmLength = -1700;
	SpringPlatformMiddle->SocketOffset = FVector(0.0f, 0.0f, 0.0f);
	SpringPlatformMiddle->SetUsingAbsoluteRotation(true);
	SpringPlatformMiddle->bDoCollisionTest = false;
	SpringPlatformTop = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringPlatformTop"));
	SpringPlatformTop->SetupAttachment(RootComponent);
	SpringPlatformTop->TargetArmLength = -1700;
	SpringPlatformTop->SocketOffset = FVector(0.0f, 0.0f, 0.0f);
	SpringPlatformTop->SetUsingAbsoluteRotation(true);
	SpringPlatformTop->bDoCollisionTest = false;
	
	/* Setup platform spawner components*/
	PlatformSpawnerBottom = CreateDefaultSubobject<USceneComponent>(TEXT("PlatformSpawnerBottom"));
	PlatformSpawnerBottom->SetupAttachment(SpringPlatformBottom, USpringArmComponent::SocketName);
	PlatformSpawnerMiddle = CreateDefaultSubobject<USceneComponent>(TEXT("PlatformSpawnerMiddle"));
	PlatformSpawnerMiddle->SetupAttachment(SpringPlatformMiddle, USpringArmComponent::SocketName);
	PlatformSpawnerTop = CreateDefaultSubobject<USceneComponent>(TEXT("PlatformSpawnerTop"));
	PlatformSpawnerTop->SetupAttachment(SpringPlatformTop, USpringArmComponent::SocketName);

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
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	GetCharacterMovement()->MaxFlySpeed = 600.0f;
	// Lock character motion onto the XZ plane, so the character can't move in or out of the screen
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->SetPlaneConstraintNormal(FVector(0.0f, -1.0f, 0.0f));

	// Behave like a traditional 2D platformer character, with a flat bottom instead of a curved capsule bottom
	// Note: This can cause a little floating when going up inclines; you can choose the tradeoff between better
	// behavior on the edge of a ledge versus inclines by setting this to true or false
	GetCharacterMovement()->bUseFlatBaseForFloorChecks = true;

    // 	TextComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("IncarGear"));
    // 	TextComponent->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));
    // 	TextComponent->SetRelativeLocation(FVector(35.0f, 5.0f, 20.0f));
    // 	TextComponent->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
    // 	TextComponent->SetupAttachment(RootComponent);

	// Enable replication on the Sprite component so animations show up when networked
	GetSprite()->SetIsReplicated(true);
	bReplicates = true;
}

void AAlienEscapeCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AddMovementInput(FVector(1.0f, 0.0f, 0.0f), 1.0);
	UpdateCharacter();
	UpdateSpringArms();
}

//////////////////////////////////////////////////////////////////////////
// Animation
void AAlienEscapeCharacter::UpdateSpringArms()
{
	float characterZPosition = GetActorLocation().Z;
	SpringPlatformBottom->SocketOffset = FVector(0.0f, 0.0f, bottomPlatformSpawnerZ-characterZPosition);
	SpringPlatformMiddle->SocketOffset = FVector(0.0f, 0.0f, middlePlatformSpawnerZ-characterZPosition);
	SpringPlatformTop->SocketOffset = FVector(0.0f, 0.0f, topPlatformSpawnerZ-characterZPosition);
}


void AAlienEscapeCharacter::UpdateCharacter()
{
	// Update animation to match the motion
	UpdateAnimation();

	// Now setup the rotation of the controller based on the direction we are travelling
	const FVector PlayerVelocity = GetVelocity();
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
	if( GetSprite()->GetFlipbook() != DesiredAnimation 	)
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
	//UE_LOG(LogTemp, Warning, TEXT("GravityFlipped"));
	//UE_LOG(LogTemp, Warning, TEXT("%f"), GetCharacterMovement()->GravityScale);
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
