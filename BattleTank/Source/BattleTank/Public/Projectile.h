// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class UProjectileMovementComponent;
class UStaticMeshComponent;
class UParticleSystemComponent;
class URadialForceComponent;

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	void LaunchProjectile(float Speed) const;

private:
	UProjectileMovementComponent *ProjectileMovement = nullptr;

	void OnTimerExpire();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float DestroyDelay = 10.f;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent *CollisionMesh = nullptr; // Alternative with subclass..
	//TSubclassOf<UStaticMeshComponent> CollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UParticleSystemComponent *LaunchBlast = nullptr; // Alternative with subclass..
	//TSubclassOf<UParticleSystemComponent> LaunchBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UParticleSystemComponent *ImpactBlast = nullptr; // Alternative with subclass..
	//TSubclassOf<UParticleSystemComponent> LaunchBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	URadialForceComponent *ExplosionForce = nullptr;

	UFUNCTION()
	void OnHit(UPrimitiveComponent *HitComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
};
