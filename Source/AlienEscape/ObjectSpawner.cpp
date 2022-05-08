// Fill out your copyright notice in the Description page of Project Settings.

#include "ObjectSpawner.h"
#include "Components/BoxComponent.h"
#include "TimerManager.h"
#include "Engine.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UObjectSpawner::UObjectSpawner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	ObjectPooler = CreateDefaultSubobject<UObjectPool>(TEXT("ObjectPooler"));
}


// Called when the game starts
void UObjectSpawner::BeginPlay()
{
	Super::BeginPlay();
	UWorld* const World = GetWorld();
	World->GetTimerManager().SetTimer(SpawnTimerHandle, this, &UObjectSpawner::SpawnActor, SpawnCooldown, true, InitialSpawnDelay);
}


// Called every frame
void UObjectSpawner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UObjectSpawner::SpawnActor()
{
	if (FMath::RandRange(0, 10) >= ChanceToSpawn) {
		APoolableActor* PoolableActor = ObjectPooler->GetPooledActor();
		if (PoolableActor == nullptr) {
			UE_LOG(LogTemp, Warning, TEXT("Cannot Spawn Object"));
		}
		else
		{
			PoolableActor->SetActorLocation(GetComponentLocation());
			PoolableActor->SetActorRotation(GetComponentRotation());
			PoolableActor->SetActive(true);
			//UE_LOG(LogTemp, Warning, TEXT("Spawning Object"));
		}
	}
}
