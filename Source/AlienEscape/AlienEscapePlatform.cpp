// Fill out your copyright notice in the Description page of Project Settings.


#include "AlienEscapePlatform.h"
#include "UObject/ConstructorHelpers.h"
//#include "Components/SphereComponent.h"
//#include "Particles/ParticleSystemComponent.h"

// Sets default values
AAlienEscapePlatform::AAlienEscapePlatform()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    ////Creating our Default Components
    //SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
    //StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
    //ParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComp"));

    ////Attaching the Components and setting physics
    //SphereComp->SetupAttachment(RootComponent);
    //SphereComp->SetSimulatePhysics(true);
    //SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

    //StaticMeshComp->AttachToComponent(SphereComp, FAttachmentTransformRules::KeepRelativeTransform);
    //ParticleComp->AttachToComponent(StaticMeshComp, FAttachmentTransformRules::KeepRelativeTransform);

    ////Setting the Sphere radius to be of a smaller size in line with the Static Mesh.
    //SphereComp->SetSphereRadius(16.0f);

    ////Setting the Static Mesh Scale and Location to fit the radius of the Sphere.
    //StaticMeshComp->SetRelativeLocation(FVector(0.0, 0.0, -12.0f));
    //StaticMeshComp->SetRelativeScale3D(FVector(0.25, 0.25, 0.25));

    ////Using Constructor Helpers to set our Static Mesh Comp with a Sphere Shape.
    //static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereMeshAsset(TEXT("StaticMesh'/Game/MobileStarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
    //StaticMeshComp->SetStaticMesh(SphereMeshAsset.Object);

    ////Using Constructor Helpers to set our Particle Comp with our Fire Particle Comp.
    //static ConstructorHelpers::FObjectFinder<UParticleSystem>ParticleCompAsset(TEXT("ParticleSystem'/Game/MobileStarterContent/Particles/P_Fire.P_Fire'"));
    //ParticleComp->SetTemplate(ParticleCompAsset.Object);
}

// Called when the game starts or when spawned
void AAlienEscapePlatform::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void AAlienEscapePlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    //SetActorLocation(GetActorLocation() + FVector(-2.0, 0.0, 0.0));
}


