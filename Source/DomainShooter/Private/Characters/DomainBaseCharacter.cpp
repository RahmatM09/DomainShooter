// Domain Shooter By Genifinity


#include "Characters/DomainBaseCharacter.h"

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

