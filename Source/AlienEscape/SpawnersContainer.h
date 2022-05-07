// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ObjectSpawner.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnersContainer.generated.h"

UCLASS()
class ALIENESCAPE_API ASpawnersContainer : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpawnersContainer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/*Functions for setting up heights of spawners within this container*/
	void setupPlatforms();
	void setupOtherSpawners();

	/* Spawner are stacked as follows
	*		8
	*			7 (Platform)
	*		6
	*		5
	*			4 (Platform)
	*		3
	*		2
	*			1 (Platform)
	*		0
	*/

	/*Platform Spawners*/
	UPROPERTY(Category = "Platform Spawners", EditAnywhere)
		UObjectSpawner* Spawner_7;
	UPROPERTY(Category = "Platform Spawners", EditAnywhere)
		UObjectSpawner* Spawner_4;
	UPROPERTY(Category = "Platform Spawners", EditAnywhere)
		UObjectSpawner* Spawner_1;

	/*Other Spawners*/
	UPROPERTY(Category = "Other Spawners", EditAnywhere)
		UObjectSpawner* Spawner_8;
	UPROPERTY(Category = "Other Spawners", EditAnywhere)
		UObjectSpawner* Spawner_6;
	UPROPERTY(Category = "Other Spawners", EditAnywhere)
		UObjectSpawner* Spawner_5;
	UPROPERTY(Category = "Other Spawners", EditAnywhere)
		UObjectSpawner* Spawner_3;
	UPROPERTY(Category = "Other Spawners", EditAnywhere)
		UObjectSpawner* Spawner_2;
	UPROPERTY(Category = "Other Spawners", EditAnywhere)
		UObjectSpawner* Spawner_0;

	/*Distance between spawners is dependant on the height of the character and platform sprites*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner Height Variables")
		float characterHeight = 92;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner Height Variables")
		float platformHeight = 35;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};