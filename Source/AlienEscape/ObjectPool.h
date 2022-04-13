// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PoolableActor.h"
#include "AlienEscapePlatform.h"
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ObjectPool.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ALIENESCAPE_API UObjectPool : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UObjectPool();
	APoolableActor* GetPooledActor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, Category = "ObjectPooler")
		TSubclassOf<class APoolableActor> PooledActorSubclass;

	UPROPERTY(EditAnywhere, Category = "ObjectPooler")
		int PoolSize = 100;

	TArray<APoolableActor*> Pool;
};
