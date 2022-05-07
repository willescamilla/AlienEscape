// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectPool.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/Actor.h"
#include "Engine.h"

// Sets default values for this component's properties
UObjectPool::UObjectPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


APoolableActor* UObjectPool::GetPooledActor()
{
	for (APoolableActor* PoolableActor : Pool) {
		if (!PoolableActor->IsActive()) {
			return PoolableActor;
		}
	}
	return nullptr;
}

// Called when the game starts
void UObjectPool::BeginPlay()
{
	Super::BeginPlay();
	if (PooledActorSubclass != NULL) {
		UWorld* const World = GetWorld();
		if (World) {

			// For some reason this for loop is adding PoolSize*2!
			for (int i = 0; i < PoolSize; i++) {
				APoolableActor* PoolableActor = World->SpawnActor<APoolableActor>(PooledActorSubclass, FVector().ZeroVector, FRotator().ZeroRotator);
				PoolableActor->SetActive(false);
				Pool.Add(PoolableActor);
				UE_LOG(LogTemp, Warning, TEXT("Added object to the pool"));
			}
		}
	}
}


// Called every frame
void UObjectPool::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}