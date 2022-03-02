// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformSpawner.h"
#include "Components/BoxComponent.h"
#include "TimerManager.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
APlatformSpawner::APlatformSpawner()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolume"));
	SpawnVolume->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ObjectPooler = CreateDefaultSubobject<UObjectPool>(TEXT("ObjectPooler"));
}

// Called when the game starts or when spawned
void APlatformSpawner::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &APlatformSpawner::SpawnActor, SpawnCooldown, true, InitialSpawnDelay);
}

void APlatformSpawner::SpawnActor()
{
	if (FMath::RandRange(0, 10) > ChanceToSpawn) {
		APoolableActor* PoolableActor = ObjectPooler->GetPooledActor();
		if (PoolableActor == nullptr) {
			UE_LOG(LogTemp, Warning, TEXT("Cannot Spawn Platform"));
		}

		PoolableActor->SetActorLocation(GetActorLocation());
		PoolableActor->SetActorRotation(GetActorRotation());
		PoolableActor->SetActive(true);
		UE_LOG(LogTemp, Warning, TEXT("Spawning Platform"));
	}
}

