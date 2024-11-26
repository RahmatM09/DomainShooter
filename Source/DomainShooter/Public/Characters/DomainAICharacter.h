// Domain Shooter By Genifinity

#pragma once

#include "CoreMinimal.h"
#include "Characters/DomainBaseCharacter.h"
#include "DomainAICharacter.generated.h"

/**
 *  Forward Declare
 */

class AWeapon;


UCLASS()
class DOMAINSHOOTER_API ADomainAICharacter : public ADomainBaseCharacter
{
	GENERATED_BODY()
	
public:
	void ShootTask();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Weapon")
	TSubclassOf<AWeapon> WeaponClass;

};
