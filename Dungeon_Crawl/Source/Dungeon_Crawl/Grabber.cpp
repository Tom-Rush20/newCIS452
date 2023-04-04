// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	//FRotator MyRotation = GetComponentRotation();
	//FString RotationString = MyRotation.ToCompactString();
	//UE_LOG(LogTemp, Display, TEXT("Grabber Rotation: %s"), *RotationString);

	//Draw a debug line forward from player
	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * MaxGrabDistance;
	DrawDebugLine(GetWorld(), Start, End, FColor::Red);


	//Geometry Sweep using a sphere
	//trace channel for grabber ECC_GameTraceChannel2

	//sphere used for geometry sweep
	FCollisionShape Sphere = FCollisionShape::MakeSphere(GrabRadius);

	//a variable to hold the results of our sweep
	FHitResult HitResult;


	//the geometry sweep
	bool HasHit = GetWorld()->SweepSingleByChannel(
	HitResult,
	Start, End,
	FQuat::Identity,
	ECC_GameTraceChannel2,
	Sphere
	);

	if (HasHit) 
	{
		FString HitActorName = HitResult.GetActor()->GetActorNameOrLabel();
		UE_LOG(LogTemp, Display, TEXT("Hit actor's name: %s"), *HitActorName);
	}
	else 
	{
		UE_LOG(LogTemp, Display, TEXT("No actor hit."));
	}

}

