// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController not possesing a tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController possesing: %s"), *ControlledTank->GetName());
	}

	ATank* PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController couldn't find Player TankController."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found Player TankController: %s"), *PlayerTank->GetName());
	}
	return;
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}