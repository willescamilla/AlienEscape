// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PoolableActor.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ObjectPool.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ALIENESCAPE_API UObjectPool : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UObjectPool();
	APoolableActor* GetPooledActor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	void AddToPool(TSubclassOf<class APoolableActor> subclass);

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Could in the future create an EditAnywhere TSet of TSubclassOf<class APoolableActor>
	UPROPERTY(EditAnywhere, Category = "Pool Info")
		TSubclassOf<class APoolableActor> PooledActorSubclass;

	UPROPERTY(EditAnywhere, Category = "Pool Info")
		int PoolSize = 50;

	UPROPERTY(EditAnywhere, Category = "Pool Info")
		float GunChance = 5;
	UPROPERTY(EditAnywhere, Category = "Pool Info")
		float HeartChance = 10;
	UPROPERTY(EditAnywhere, Category = "Pool Info")
		float IntelChance = 45;
	UPROPERTY(EditAnywhere, Category = "Pool Info")
		float LaserChance = 20;
	UPROPERTY(EditAnywhere, Category = "Pool Info")
		float MissileChance = 20;

	TSubclassOf<class APoolableActor> Gun_BPclass;
	TSubclassOf<class APoolableActor> Heart_BPclass;
	TSubclassOf<class APoolableActor> Intel_BPclass;
	TSubclassOf<class APoolableActor> Laser_BPclass;
	TSubclassOf<class APoolableActor> Missile_BPclass;

	TArray<APoolableActor*> Pool;
};