// Domain Shooter By Genifinity


#include "Weapons/Weapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SphereComponent.h"
#include "DomainShooter/Public/Characters/DomainBaseCharacter.h"

AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	RootComponent = CollisionSphere;
	CollisionSphere->SetSphereRadius(100.f);
	
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(CollisionSphere);
	WeaponMesh->SetRelativeRotation(FRotator(0.0, -90.0, 0.0));
	
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AWeapon::OnComponentOverlap);
	CollisionSphere->OnComponentEndOverlap.AddDynamic(this, &AWeapon::OnComponentEndOverlap);
}

void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon::OnComponentOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ADomainBaseCharacter* BaseCharacter = Cast<ADomainBaseCharacter>(OtherActor);
	if (BaseCharacter)
	{
		BaseCharacter->SetCanPickup(true);
		BaseCharacter->SetWeapon(this);
		UE_LOG(LogTemp, Error, TEXT("You can Pickup"));
	}
}

void AWeapon::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ADomainBaseCharacter* BaseCharacter = Cast<ADomainBaseCharacter>(OtherActor);
	if (BaseCharacter)
	{
		BaseCharacter->SetCanPickup(false);
		UE_LOG(LogTemp, Error, TEXT("You can't Pickup"));
	}
	
}
