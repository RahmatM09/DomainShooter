// Domain Shooter By Genifinity

#pragma once

#include "CoreMinimal.h"
#include "Characters/DomainBaseCharacter.h"
#include "DomainPlayerCharacter.generated.h"

// Forward Declaration
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class USpringArmComponent;
class UCameraComponent;
class AWeapon;
class UUserWidget;
class UAIPerceptionStimuliSourceComponent;
class UPawnNoiseEmitterComponent;

/**
 * 
 */
UCLASS()
class DOMAINSHOOTER_API ADomainPlayerCharacter : public ADomainBaseCharacter
{
	GENERATED_BODY()
	

public:
	ADomainPlayerCharacter();

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

	UPROPERTY(VisibleAnywhere, Category = "AI")
	TObjectPtr <UAIPerceptionStimuliSourceComponent> StimulusSource;

	UPROPERTY(VisibleAnywhere, Category = "AI")
	TObjectPtr<UPawnNoiseEmitterComponent> NoiseEmitter;

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



	// UI *************************************************************
	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> CharacterUI;

	TObjectPtr<UUserWidget> UIWidget;


public:

};
