// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformSpawner.h"
#include "Components/BoxComponent.h"
#include "TimerManager.h"
#include "Engine.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
UPlatformSpawner::UPlatformSpawner()
{
	//RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	//SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolume"));
	//SpawnVolume->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ObjectPooler = CreateDefaultSubobject<UObjectPool>(TEXT("ObjectPooler"));
}

// Called when the game starts or when spawned
void UPlatformSpawner::BeginPlay()
{
	Super::BeginPlay();
	UWorld* const World = GetWorld();
	World->GetTimerManager().SetTimer(SpawnTimerHandle, this, &UPlatformSpawner::SpawnActor, SpawnCooldown, true, InitialSpawnDelay);
}

void UPlatformSpawner::SpawnActor()
{
	if (FMath::RandRange(0, 10) >= ChanceToSpawn) {
		APoolableActor* PoolableActor = ObjectPooler->GetPooledActor();
		if (PoolableActor == nullptr) {
			UE_LOG(LogTemp, Warning, TEXT("Cannot Spawn Platform"));
		}

		PoolableActor->SetActorLocation(GetComponentLocation());
		PoolableActor->SetActorRotation(GetComponentRotation());
		PoolableActor->SetActive(true);
		UE_LOG(LogTemp, Warning, TEXT("Spawning Platform"));
	}
}

