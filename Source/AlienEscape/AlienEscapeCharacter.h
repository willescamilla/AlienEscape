// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Components/SceneComponent.h"
#include "AlienEscapeCharacter.generated.h"

class UTextRenderComponent;

/**
 * This class is the default character for AlienEscape, and it is responsible for all
 * physical interaction between the player and the world.
 *
 * The capsule component (inherited from ACharacter) handles collision with the world
 * The CharacterMovementComponent (inherited from ACharacter) handles movement of the collision capsule
 * The Sprite component (inherited from APaperCharacter) handles the visuals
 */
UCLASS(config = Game)
class AAlienEscapeCharacter : public APaperCharacter
{
	GENERATED_BODY()

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent *SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent *CameraBoom;

	/** Spring Arm for Spawners */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Spawner, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* SpringPlatformBottom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Spawner, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* SpringPlatformMiddle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Spawner, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* SpringPlatformTop;


	UTextRenderComponent *TextComponent;
	virtual void Tick(float DeltaSeconds) override;

protected:
	// The animation to play while running around
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		class UPaperFlipbook *RunningAnimation;

	// The animation to play while idle (standing still)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		class UPaperFlipbook *IdleAnimation;

	/** Spawner components */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawner, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* PlatformSpawnerBottom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawner, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* PlatformSpawnerMiddle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawner, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* PlatformSpawnerTop;

	/* Ensures the Z location of the Spawners stays constant*/
	void UpdateSpringArms();

	/* Updates the animation and rotation of character*/
	void UpdateCharacter();

	/** Called to choose the correct animation to play based on the character's movement state (running or standing still) */
	void UpdateAnimation();

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawner)
		float bottomPlatformSpawnerZ = -384;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawner)
		float middlePlatformSpawnerZ = -84;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Spawner)
		float topPlatformSpawnerZ = 216;

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent *InputComponent) override;
	// End of APawn interface


	// Functions I made
	/** Handles player input */
	void MoveRight(float Value);
	void FlipGravity();
	void SlideStart();
	void SlideStop();
	void UsePowerup();
	void UseSpecialAbility();

public:
	AAlienEscapeCharacter();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent *GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent *GetCameraBoom() const { return CameraBoom; }
};
