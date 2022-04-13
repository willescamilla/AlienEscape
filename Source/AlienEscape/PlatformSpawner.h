// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PoolableActor.h"
#include "AlienEscapePlatform.h"
#include "ObjectPool.h"
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GameFramework/Actor.h"
#include "PlatformSpawner.generated.h"

UCLASS()
class ALIENESCAPE_API UPlatformSpawner : public USceneComponent
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UPlatformSpawner();

	UFUNCTION()
		void SpawnActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBoxComponent* SpawnVolume;
	
	UPROPERTY(EditAnywhere, Category = "Trigger")
		bool trigger;

	UPROPERTY(Category = "Spawner", EditAnywhere)
		UObjectPool* ObjectPooler;

	UPROPERTY(Category = "Spawner", EditAnywhere)
		float SpawnCooldown = 2.0f;

	UPROPERTY(Category = "Spawner", EditAnywhere)
		float InitialSpawnDelay = 4.0f;

	// Number that RandRange must be higher than in order to spawn platforms
	UPROPERTY(Category = "Spawner", EditAnywhere)
		int32 ChanceToSpawn = 2.0f;

	FTimerHandle SpawnTimerHandle;

};
