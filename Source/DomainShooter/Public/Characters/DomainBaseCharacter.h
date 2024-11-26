// Domain Shooter By Genifinity

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DomainBaseCharacter.generated.h"

// Forward Declaration
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class USpringArmComponent;
class UCameraComponent;
class AWeapon;
class UUserWidget;

UCLASS()
class DOMAINSHOOTER_API ADomainBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ADomainBaseCharacter();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

protected:
	virtual void BeginPlay() override;

	// Weapon Variable ************************************************
	bool bCanPickup = false;
	UPROPERTY()
	TObjectPtr<AWeapon> Weapon;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool bHasRifle = false;

	// Animations *****************************************************
	UPROPERTY(EditAnywhere, Category = "Animations")
	TObjectPtr<UAnimMontage> FireMontage;

	UPROPERTY(EditAnywhere, Category = "Animations")
	TObjectPtr<UAnimMontage> HitMontage;

	// Health ********************************************************
	UPROPERTY(VisibleAnywhere, Category = "Health")
	float MaxHealth = 100.f;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	float CurrentHealth = 100.f;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool bIsDead = false;

	// Weapon Functions **********************************************
	void PickWeapon(AWeapon* WeaponToPick);

private:
	// Death Timer *********************************************************
	FTimerHandle DeathTimerHandle;

	UFUNCTION()
	void DestroyActor();

	UPROPERTY(EditAnywhere, Category = "DeathTimer")
	float DestroyTime = 10.f;

public:	
	//Setters And Getters
	FORCEINLINE void SetCanPickup(bool NewPickup) { bCanPickup = NewPickup; }
	FORCEINLINE void SetWeapon(AWeapon* NewWeapon) { Weapon = NewWeapon; }

};
