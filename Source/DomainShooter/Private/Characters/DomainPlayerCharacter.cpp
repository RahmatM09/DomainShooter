// Domain Shooter By Genifinity


#include "Characters/DomainPlayerCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "DomainShooter/Public/Weapons/Weapon.h"
#include "Components/SphereComponent.h"
#include "Blueprint/UserWidget.h"
#include "Components/CapsuleComponent.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISense_Sight.h"


ADomainPlayerCharacter::ADomainPlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	BaseSpringArm->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(BaseSpringArm);

	StimulusSource = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("AIPerceptionStimuliSource"));
	StimulusSource->RegisterForSense(UAISense_Sight::StaticClass());
	StimulusSource->RegisterWithPerceptionSystem();

}

void ADomainPlayerCharacter::BeginPlay()
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

void ADomainPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADomainPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	EnhancedInputComponent->BindAction(IA_BaseCharacterMovement, ETriggerEvent::Triggered, this, &ADomainPlayerCharacter::BaseCharacterMovement);
	EnhancedInputComponent->BindAction(IA_BaseCharacterLookAround, ETriggerEvent::Triggered, this, &ADomainPlayerCharacter::BaseCharacterLookAround);
	EnhancedInputComponent->BindAction(IA_BaseCharacterJump, ETriggerEvent::Started, this, &ADomainPlayerCharacter::BaseCharacterJump);
	EnhancedInputComponent->BindAction(IA_PickupWeapon, ETriggerEvent::Started, this, &ADomainPlayerCharacter::PickupWeapon);
	EnhancedInputComponent->BindAction(IA_Shoot, ETriggerEvent::Started, this, &ADomainPlayerCharacter::CharacterShoot);
}

void ADomainPlayerCharacter::BaseCharacterMovement(const FInputActionValue& InputActionValue)
{
	FVector2D MovementVector = InputActionValue.Get<FVector2D>();

	if (Controller)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector ForwardDirection = UKismetMathLibrary::GetForwardVector(Rotation);
		const FVector RightDirection = UKismetMathLibrary::GetRightVector(Rotation);

		AddMovementInput(ForwardDirection, MovementVector.X);
		AddMovementInput(RightDirection, MovementVector.Y);
	}
}

void ADomainPlayerCharacter::BaseCharacterLookAround(const FInputActionValue& InputActionValue)
{
	FVector2D LookAroundValue = InputActionValue.Get<FVector2D>();

	if (Controller)
	{
		AddControllerYawInput(LookAroundValue.X);
		AddControllerPitchInput(LookAroundValue.Y * -1.f);
	}
}

void ADomainPlayerCharacter::BaseCharacterJump(const FInputActionValue& InputActionValue)
{
	Jump();
}

void ADomainPlayerCharacter::PickupWeapon(const FInputActionValue& InputActionValue)
{
	if (bCanPickup && Weapon)
	{
		PickWeapon(Weapon);

		bHasRifle = true;

		if (CharacterUI)
		{
			UIWidget = CreateWidget<UUserWidget>(GetWorld(), CharacterUI);
			if (UIWidget)
			{
				UIWidget->AddToViewport();
			}
		}
	}
}

void ADomainPlayerCharacter::CharacterShoot(const FInputActionValue& InputActionValue)
{
	if (Weapon && bHasRifle)
	{
		UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
		if (AnimInstance && FireMontage)
		{
			AnimInstance->Montage_Play(FireMontage);
		}
		Weapon->WeaponShoot();
	}
}
