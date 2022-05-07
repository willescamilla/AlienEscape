// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "PoolableActor.h"
#include "AlienEscapePlatform.h"
#include "ObjectPool.h"
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ObjectSpawner.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ALIENESCAPE_API UObjectSpawner : public USceneComponent
{
	GENERATED_BODY()

		// Sets default values for this component's properties
		UObjectSpawner();

	UFUNCTION()
		void SpawnActor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	//Every Spawner has its own ObjectPool
	UPROPERTY(Category = "Spawner", EditAnywhere)
		UObjectPool* ObjectPooler;

	UPROPERTY(Category = "Spawner", EditAnywhere)
		float SpawnCooldown = 2.0f;

	UPROPERTY(Category = "Spawner", EditAnywhere)
		float InitialSpawnDelay = 4.0f;

	// Number that RandRange must be higher than in order to spawn an object
	UPROPERTY(Category = "Spawner", EditAnywhere)
		int32 ChanceToSpawn = 2.0f;

	FTimerHandle SpawnTimerHandle;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
