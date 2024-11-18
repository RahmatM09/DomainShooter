// Domain Shooter By Genifinity

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

// Forward Declare
class USphereComponent;
class UProjectileMovementComponent;


UCLASS()
class DOMAINSHOOTER_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectile();

protected:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	virtual void BeginPlay() override;

private:	
	// Components *******************************
	UPROPERTY(VisibleAnywhere, Category = "Components")
	TObjectPtr<USphereComponent> SphereCollision;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	TObjectPtr<UStaticMeshComponent> ProjectileMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;

	// Variables **********************************
	UPROPERTY(EditAnywhere, Category = "Effects")
	TObjectPtr<UParticleSystem> ImpactParticle;

	UPROPERTY(EditAnywhere, Category = "Effects")
	TObjectPtr<USoundBase> ImpactSound;

	UPROPERTY(EditAnywhere, Category = "Damage")
	float BaseDamage = 20.f;

};
