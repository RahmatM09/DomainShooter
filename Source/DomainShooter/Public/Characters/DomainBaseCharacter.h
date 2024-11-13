// Domain Shooter By Genifinity

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DomainBaseCharacter.generated.h"

// Forward Declaration
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;


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

	/// Input ********************************************************
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> BaseCharacterIMC;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> IA_BaseCharacterMovement;

	/// Input Functions ***********************************************
	void BaseCharacterMovement(const FInputActionValue& InputActionValue);

public:	
	//Setters And Getters


};
