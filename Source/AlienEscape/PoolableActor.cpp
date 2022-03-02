// Fill out your copyright notice in the Description page of Project Settings.


#include "PoolableActor.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
APoolableActor::APoolableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APoolableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APoolableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APoolableActor::SetActive(bool InActive)
{
    bIsActive = InActive;
    SetActorHiddenInGame(!InActive);
}

bool APoolableActor::IsActive()
{
    return bIsActive;
}

void APoolableActor::Deactivate()
{
    SetActive(false);
}

