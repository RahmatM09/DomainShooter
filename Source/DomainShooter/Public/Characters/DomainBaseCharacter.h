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


private:
	/// Components ***************************************************
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	TObjectPtr<USpringArmComponent> BaseSpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	TObjectPtr<UCameraComponent> Camera;

	/// Input ********************************************************
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> BaseCharacterIMC;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> IA_BaseCharacterMovement;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> IA_BaseCharacterLookAround;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> IA_BaseCharacterJump;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> IA_PickupWeapon;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> IA_Shoot;

	/// Input Functions ***********************************************
	void BaseCharacterMovement(const FInputActionValue& InputActionValue);
	void BaseCharacterLookAround(const FInputActionValue& InputActionValue);
	void BaseCharacterJump(const FInputActionValue& InputActionValue);
	void PickupWeapon(const FInputActionValue& InputActionValue);
	void CharacterShoot(const FInputActionValue& InputActionValue);

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

	// UI *************************************************************
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> CharacterUI;

	TObjectPtr<UUserWidget> UIWidget;

	// Health ********************************************************
	UPROPERTY(VisibleAnywhere, Category = "Health")
	float MaxHealth = 100.f;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	float CurrentHealth = 100.f;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool bIsDead = false;

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
