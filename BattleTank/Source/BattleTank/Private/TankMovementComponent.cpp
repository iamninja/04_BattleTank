// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialize(UTankTrack *LeftTrackToSet, UTankTrack *RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;

	return;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"), Throw);

	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	// TODO prevent double speed due to dual control use

	return;
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("Intend turn right at throw: %f"), Throw);

	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	// TODO prevent double speed due to dual control use

	return;
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	// No need to call super. We are replacing the functionality here.
	auto TankName = GetOwner()->GetName();
	auto MoveVelocityString = MoveVelocity.ToString();

	UE_LOG(LogTemp, Warning, TEXT("%s vectoring to %s"), *TankName, *MoveVelocityString);
}

