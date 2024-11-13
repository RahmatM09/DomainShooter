// Domain Shooter By Genifinity

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DomainBaseCharacter.generated.h"

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


public:	
	//Setters And Getters


};
