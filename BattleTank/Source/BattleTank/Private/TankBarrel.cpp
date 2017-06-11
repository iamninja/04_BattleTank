// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the barrel to the right amount this frame
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevetionChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevetionChange;
	auto Elevation = FMath::Clamp<float>(
		RawNewElevation,
		MinElevationDegrees,
		MaxElevationDegrees
	);

	SetRelativeRotation(FRotator(Elevation, 0, 0));

}


