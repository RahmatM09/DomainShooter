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

UCLASS()
class DOMAINSHOOTER_API ADomainBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ADomainBaseCharacter();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

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

public:	
	//Setters And Getters
	FORCEINLINE void SetCanPickup(bool NewPickup) { bCanPickup = NewPickup; }
	FORCEINLINE void SetWeapon(AWeapon* NewWeapon) { Weapon = NewWeapon; }

};
