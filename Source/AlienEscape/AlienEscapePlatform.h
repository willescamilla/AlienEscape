// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PoolableActor.h"
#include "GameFramework/Actor.h"
#include "PaperSpriteComponent.h"
#include "GameFramework/MovementComponent.h"
#include "CoreMinimal.h"
#include "AlienEscapePlatform.generated.h"

UCLASS()
class ALIENESCAPE_API AAlienEscapePlatform : public APoolableActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAlienEscapePlatform();

protected:

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USphereComponent* SphereComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UParticleSystemComponent* ParticleComp;*/

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
