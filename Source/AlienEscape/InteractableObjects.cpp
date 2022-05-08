// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableObjects.h"

AInteractableObjects::AInteractableObjects()
{
    //Register Events
    OnActorBeginOverlap.AddDynamic(this, &AInteractableObjects::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &AInteractableObjects::OnOverlapEnd);
}

void AInteractableObjects::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
    //if (OtherActor && (OtherActor != this)) {
    //    // Cast this actor into an object that can be added back to the pool
    //    APoolableActor* ObjectInPool = dynamic_cast<APoolableActor*>(OverlappedActor);
    //    ObjectInPool->Deactivate();
    //}
}

void AInteractableObjects::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
}
