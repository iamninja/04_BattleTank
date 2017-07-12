// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Must be the last include 

// Forward declaration
class UTankBarrel;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

private:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	// TODO remove once firing is moved to aiming component
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	//UClass *ProjectileBlueprint; // Alternative with subclass..
	TSubclassOf<AProjectile> ProjectileBluprint;

	// Local barrel reference for spawning projectile
	UTankBarrel *Barrel = nullptr; // TODO Remove

	double LastFireTime = 0;
};
