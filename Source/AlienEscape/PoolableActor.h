// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PoolableActor.generated.h"

UCLASS()
class ALIENESCAPE_API APoolableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APoolableActor();

	void SetActive(bool InActive);
	bool IsActive();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool bIsActive;
	void Deactivate();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
