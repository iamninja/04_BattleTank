// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	// Move the barrel to the right amount this frame
	UE_LOG(LogTemp, Warning, TEXT("Barrel-elevate() called at speed: %f"), DegreesPerSecond);

}


