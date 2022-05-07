// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnersContainer.h"
#include "Components/SceneComponent.h"

// Sets default values
ASpawnersContainer::ASpawnersContainer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	Spawner_0 = CreateDefaultSubobject<UObjectSpawner>(TEXT("Spawner_0"));
	Spawner_1 = CreateDefaultSubobject<UObjectSpawner>(TEXT("Spawner_1"));
	Spawner_2 = CreateDefaultSubobject<UObjectSpawner>(TEXT("Spawner_2"));
	Spawner_3 = CreateDefaultSubobject<UObjectSpawner>(TEXT("Spawner_3"));
	Spawner_4 = CreateDefaultSubobject<UObjectSpawner>(TEXT("Spawner_4"));
	Spawner_5 = CreateDefaultSubobject<UObjectSpawner>(TEXT("Spawner_5"));
	Spawner_6 = CreateDefaultSubobject<UObjectSpawner>(TEXT("Spawner_6"));
	Spawner_7 = CreateDefaultSubobject<UObjectSpawner>(TEXT("Spawner_7"));
	Spawner_8 = CreateDefaultSubobject<UObjectSpawner>(TEXT("Spawner_8"));
}

// Called when the game starts or when spawned
void ASpawnersContainer::BeginPlay()
{
	Super::BeginPlay();
	setupPlatforms();
	setupOtherSpawners();
}

void ASpawnersContainer::setupPlatforms()
{
	float verticalDistance = (characterHeight * 3) + platformHeight;
	Spawner_7->SetRelativeLocation(FVector(0.0, 0.0, verticalDistance));
	Spawner_4->SetRelativeLocation(FVector().ZeroVector);
	Spawner_1->SetRelativeLocation(FVector(0.0, 0.0, -verticalDistance));
}

void ASpawnersContainer::setupOtherSpawners()
{
	float verticalDistance = (characterHeight * 3) + (platformHeight);
	float smallGap = (characterHeight / 2) + (platformHeight / 2);

	Spawner_8->SetRelativeLocation(FVector(0.0, 0.0, (verticalDistance + smallGap)));
	Spawner_6->SetRelativeLocation(FVector(0.0, 0.0, (verticalDistance - smallGap)));
	Spawner_5->SetRelativeLocation(FVector(0.0, 0.0, smallGap));
	Spawner_3->SetRelativeLocation(FVector(0.0, 0.0, -smallGap));
	Spawner_2->SetRelativeLocation(FVector(0.0, 0.0, -(verticalDistance - smallGap)));
	Spawner_0->SetRelativeLocation(FVector(0.0, 0.0, -(verticalDistance + smallGap)));
}

// Called every frame
void ASpawnersContainer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}