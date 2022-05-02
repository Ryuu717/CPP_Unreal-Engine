// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class USoundBase;

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	class UProjectileMovementComponent* ProjectileMovementComponent;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult & Hit);

	UPROPERTY(EditAnywhere, Category = "combat")
	float Damage = 50.f;

	UPROPERTY(EditAnywhere, Category = "combat")
	UParticleSystem* HitParticles;
	
	UPROPERTY(EditAnywhere, Category = "combat")
	class UParticleSystemComponent* TrailParticles;

	UPROPERTY(EditAnywhere, Category = "combat")
	USoundBase* LaunchSound;

	UPROPERTY(EditAnywhere, Category = "combat")
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category = "combat")
	TSubclassOf<UCameraShakeBase> HitCameraShake;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
