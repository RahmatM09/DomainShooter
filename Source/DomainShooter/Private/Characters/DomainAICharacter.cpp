// Domain Shooter By Genifinity


#include "Characters/DomainAICharacter.h"
#include "DomainShooter/Public/Weapons/Weapon.h"

void ADomainAICharacter::BeginPlay()
{
	Super::BeginPlay();

	if (Weapon)
	{
		if (UWorld* World = GetWorld())
		{
			Weapon = World->SpawnActor<AWeapon>(WeaponClass);
			PickWeapon(Weapon);
			Weapon->SetActorRelativeRotation(FRotator(0.f, 90.f, 0.f));
		}
	}
}
