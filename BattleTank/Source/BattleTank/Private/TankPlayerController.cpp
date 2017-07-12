// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto AimingComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();
	if (ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
	
	return;
}

void ATankPlayerController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	//UE_LOG(LogTemp, Warning, TEXT("PlayerController ticking..."));

	AimTowardsCrosshair();

	return;
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!ensure(GetControlledTank())) { return; }

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(OUT HitLocation)) // is going to line trace
	{
		///UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
		GetControlledTank()->AimAt(HitLocation);
	}
	
	return;
}

bool ATankPlayerController::GetSightRayHitLocation( FVector &HitLocation ) const
{
	/// Find crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(OUT ViewportSizeX, OUT ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(
		CrossHairXLocation * ViewportSizeX, 
		CrossHairYLocation * ViewportSizeY
	);

	/// de-project the screen position of the crosshair to the world
	FVector LookDirection;
	if (GetLookLocation(ScreenLocation, OUT LookDirection))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Looking Direction: %s"), *LookDirection.ToString());
		/// line trace along that look direction and find what we hit (up to max range)
		GetLookVectorHitLocation(LookDirection, OUT HitLocation);
	}

	
	return true;
}

bool ATankPlayerController::GetLookLocation(FVector2D ScreenLocation, FVector &LookDirection) const
{
	FVector CameraWorldLocation; // Not needed
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		OUT CameraWorldLocation,
		OUT LookDirection
	);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		OUT HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
	)
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false; // Line trace didn't succeed
}
