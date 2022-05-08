// Fill out your copyright notice in the Description page of Project Settings.


#include "DimensionalRift.h"
#include "PoolableActor.h"
// include draw debug helpers header file
#include "DrawDebugHelpers.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))

ADimensionalRift::ADimensionalRift()
{
    //Register Events
    OnActorBeginOverlap.AddDynamic(this, &ADimensionalRift::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &ADimensionalRift::OnOverlapEnd);
}

void ADimensionalRift::BeginPlay()
{
    Super::BeginPlay();

}

void ADimensionalRift::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
    
}

void ADimensionalRift::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
    //DrawDebugBox(GetWorld(), GetActorLocation(), GetActorScale() * 10, FColor::Cyan, true, -1, 0, 5);
    if (OtherActor && (OtherActor != this)) {
 
        if (dynamic_cast<APoolableActor*>(OtherActor) != nullptr) {
            //printFString("%s IS a poolable object", *OtherActor->GetName());
            // Cast OtherActor into an object that can be added back to the pool
            APoolableActor* ObjectInPool = dynamic_cast<APoolableActor*>(OtherActor);
            //printFString("Deactivating: s", *OtherActor->GetName());
            ObjectInPool->Deactivate();
        }
        else {
            // Something went through the rift that isn't part of the pool
            printFString("%s IS NOT a poolable object", *OtherActor->GetName());
        }
        
    }
}