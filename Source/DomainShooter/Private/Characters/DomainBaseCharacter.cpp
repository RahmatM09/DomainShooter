// Domain Shooter By Genifinity

#include "Characters/DomainBaseCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "DomainShooter/Public/Weapons/Weapon.h"
#include "Components/CapsuleComponent.h"
#include "DomainShooter/Public/Weapons/Weapon.h"	
#include "Components/SphereComponent.h"

ADomainBaseCharacter::ADomainBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

void ADomainBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADomainBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADomainBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ADomainBaseCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	
	CurrentHealth -= DamageAmount;

	CurrentHealth = FMath::Clamp(CurrentHealth, 0.f, MaxHealth);

	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance && HitMontage)
	{
		AnimInstance->Montage_Play(HitMontage);
	}

	if (CurrentHealth <= 0.f)
	{
		bIsDead = true;

		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		
		if (Controller)
		{
			Controller->SetIgnoreMoveInput(true);
			Controller->SetIgnoreLookInput(true);
		}

		GetMesh()->SetSimulatePhysics(true);
		GetMesh()->SetCollisionProfileName(TEXT("Ragdoll"));

		if (UWorld* World = GetWorld())
		{
			World->GetTimerManager().SetTimer(DeathTimerHandle, this, &ADomainBaseCharacter::DestroyActor, DestroyTime, false);
		}
	}

	return DamageAmount;
}

void ADomainBaseCharacter::PickWeapon(AWeapon* WeaponToPick)
{
	WeaponToPick->CollisionSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WeaponToPick->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	WeaponToPick->SetActorRelativeLocation(FVector(0.f, 0.f, 0.f));
	WeaponToPick->SetActorRelativeRotation(FRotator(0.0, 0.0, 0.0));
	WeaponToPick->SetOwner(this);
}

void ADomainBaseCharacter::Shoot(AWeapon* WeaponToShoot)
{
	if (WeaponToShoot)
	{
		UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
		if (AnimInstance && FireMontage)
		{
			AnimInstance->Montage_Play(FireMontage);
		}
		Weapon->WeaponShoot();
	}
	
}

void ADomainBaseCharacter::DestroyActor()
{
	Destroy();
}
