// Domain Shooter By Genifinity


#include "Characters/DomainBaseCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"

ADomainBaseCharacter::ADomainBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ADomainBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	check(BaseCharacterIMC);

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		check(Subsystem);
		Subsystem->AddMappingContext(BaseCharacterIMC, 0);
	}

}

void ADomainBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADomainBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	EnhancedInputComponent->BindAction(IA_MoveForward, ETriggerEvent::Triggered, this, &ADomainBaseCharacter::MoveForward);
}

void ADomainBaseCharacter::MoveForward(const FInputActionValue& InputActionValue)
{

}
