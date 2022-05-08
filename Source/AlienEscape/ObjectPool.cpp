// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectPool.h"
#include "InteractableObjects.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/Actor.h"
#include "Engine.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UObjectPool::UObjectPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	//A NULL value here means we want InteractableObjects to spawn
	//Code for finding the InteractableObjects child blueprints
	if (PooledActorSubclass == NULL) {

		//Intel
		ConstructorHelpers::FClassFinder<APoolableActor> IntelBPClassFinder(TEXT("/Game/AlienEscape/Blueprints/BP_Intel"));
		if (IntelBPClassFinder.Class != NULL) {
			Intel_BPclass = IntelBPClassFinder.Class;
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("CANNOT FIND BP CLASS: INTEL"));
		}

		//Gun
		ConstructorHelpers::FClassFinder<APoolableActor> GunBPClassFinder(TEXT("/Game/AlienEscape/Blueprints/BP_Gun"));
		if (GunBPClassFinder.Class != NULL) {
			Gun_BPclass = GunBPClassFinder.Class;
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("CANNOT FIND BP CLASS: GUN"));
		}

		//Heart
		ConstructorHelpers::FClassFinder<APoolableActor> HeartBPClassFinder(TEXT("/Game/AlienEscape/Blueprints/BP_Heart"));
		if (HeartBPClassFinder.Class != NULL) {
			Heart_BPclass = HeartBPClassFinder.Class;
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("CANNOT FIND BP CLASS: HEART"));
		}

		//Laser
		ConstructorHelpers::FClassFinder<APoolableActor> LaserBPClassFinder(TEXT("/Game/AlienEscape/Blueprints/BP_Laser"));
		if (LaserBPClassFinder.Class != NULL) {
			Laser_BPclass = LaserBPClassFinder.Class;
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("CANNOT FIND BP CLASS: LASER"));
		}

		//Missile
		ConstructorHelpers::FClassFinder<APoolableActor> MissileBPClassFinder(TEXT("/Game/AlienEscape/Blueprints/BP_Missile"));
		if (MissileBPClassFinder.Class != NULL) {
			Missile_BPclass = MissileBPClassFinder.Class;
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("CANNOT FIND BP CLASS: MISSILE"));
		}
	}

}

//Returns a random InActive actor from the pool by starting the 
//search at a random index
APoolableActor* UObjectPool::GetPooledActor()
{
	int numPoolItems = Pool.Num();
	int startingLoc = FMath::RandRange(0, numPoolItems - 1);
	APoolableActor* PoolableActor;

	//End loop once (i == startingLoc-1) because then we've checked every item in pool
	for (int i = startingLoc; i != startingLoc - 1; i++) {
		if (Pool.IsValidIndex(i)) {
			PoolableActor = Pool[i];
			if (!PoolableActor->IsActive()) {
				return PoolableActor;
			}
			else if (i == numPoolItems - 1) { //Sends the index back to the start
				i = -1;
			}
		}
	}
	return nullptr;
}

// Called when the game starts
void UObjectPool::BeginPlay()
{
	Super::BeginPlay();
	
	if (PooledActorSubclass != NULL) {
		// For some reason this for loop is adding PoolSize*2!
		for (int i = 0; i < PoolSize; i++) {
			AddToPool(PooledActorSubclass);
		}
	}
	else { //When PooledActorSubclass == NULL that means we want to spawn InteractableObjects
		int numGuns = (GunChance / 100) * PoolSize;
		int numHearts = (HeartChance / 100) * PoolSize;
		int numIntel = (IntelChance / 100) * PoolSize;
		int numLasers = (LaserChance / 100) * PoolSize;
		int numMissiles = (MissileChance / 100) * PoolSize;

		//Increase i after every added object to keep track of how many pool items there are
		//Also check i < PoolSize in every sub-forloop as to not go over pool size
		for (int i = 0; i < PoolSize; i++) {
			if (Gun_BPclass != NULL) {
				for (int j = 0; j < numGuns && i < PoolSize; j++) {
					AddToPool(Gun_BPclass);
					i++;
				}
			}
			if (Heart_BPclass != NULL) {
				for (int j = 0; j < numHearts && i < PoolSize; j++) {
					AddToPool(Heart_BPclass);
					i++;
				}
			}
			if (Intel_BPclass != NULL) {
				for (int j = 0; j < numIntel && i < PoolSize; j++) {
					AddToPool(Intel_BPclass);
					i++;
				}
			}
			if (Laser_BPclass != NULL) {
				for (int j = 0; j < numLasers && i < PoolSize; j++) {
					AddToPool(Laser_BPclass);
					i++;
				}
			}
			if (Missile_BPclass != NULL) {
				for (int j = 0; j < numMissiles && i < PoolSize; j++) {
					AddToPool(Missile_BPclass);
					i++;
				}
			}
		}
	}
}

void UObjectPool::AddToPool(TSubclassOf<class APoolableActor> subclass)
{
	UWorld* const World = GetWorld();
	if (World) {
		APoolableActor* PoolableActor = World->SpawnActor<APoolableActor>(subclass, FVector().ZeroVector, FRotator().ZeroRotator);
		PoolableActor->SetActive(false);
		Pool.Add(PoolableActor);
		//UE_LOG(LogTemp, Warning, TEXT("Added object to the pool"));
	}
}


// Called every frame
void UObjectPool::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}