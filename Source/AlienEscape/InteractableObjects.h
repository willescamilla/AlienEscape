// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PoolableActor.h"
#include "InteractableObjects.generated.h"

/**
 * 
 */
UCLASS()
class ALIENESCAPE_API AInteractableObjects : public APoolableActor
{
	GENERATED_BODY()
public:

	// constructor sets default values for this actor's properties
	AInteractableObjects();

	// overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	// overlap end function
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
};
