// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Engine.h"

void UTankTrack::SetThrottle(float Throttle) const
{
	//auto Time = GetWorld()->GetTimeSeconds();
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *Name, Throttle);

	// TODO Clamp actual throttle value so player cant over-drive
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}


