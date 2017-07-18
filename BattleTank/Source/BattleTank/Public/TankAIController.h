// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	// How close can AI tank get to its target
	UPROPERTY(EditAnywhere, Category = "Setup")
	float AcceptanceRadius = 8000; // 80 meters
	
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
