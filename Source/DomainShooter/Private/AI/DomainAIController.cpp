// Domain Shooter By Genifinity


#include "AI/DomainAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "DomainShooter/Public/Characters/DomainPlayerCharacter.h"

ADomainAIController::ADomainAIController()
{
	DomainAIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("DomainAIPerception"));

	SightSenseConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightSenseConfig"));
	SightSenseConfig->SightRadius = 1500.f;
	SightSenseConfig->LoseSightRadius = 2000.f;
	SightSenseConfig->PeripheralVisionAngleDegrees = 90.f;

	SightSenseConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightSenseConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightSenseConfig->DetectionByAffiliation.bDetectNeutrals = true;

	DomainAIPerception->ConfigureSense(*SightSenseConfig);
	DomainAIPerception->SetDominantSense(SightSenseConfig->GetSenseImplementation());

	DomainAIPerception->OnTargetPerceptionInfoUpdated.AddDynamic(this, &ADomainAIController::OnPerceptionUpdated);
}

void ADomainAIController::BeginPlay()
{
	Super::BeginPlay();

	if (BT_DomianAI)
	{
		RunBehaviorTree(BT_DomianAI);
		BB_Domain = GetBlackboardComponent();
		
		if (UseBlackboard(BT_DomianAI->GetBlackboardAsset(), BB_Domain))
		{
			FVector Location = GetPawn()->GetActorLocation();
			BB_Domain->SetValueAsVector(TEXT("StartLocation"), Location);
		}
	}
}

void ADomainAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void ADomainAIController::OnPerceptionUpdated(const FActorPerceptionUpdateInfo& UpdateInfo)
{
	AActor* Actor = UpdateInfo.Target.Get();
	if(Actor && Actor->IsA(ADomainPlayerCharacter::StaticClass()))
	{
		if (UpdateInfo.Stimulus.WasSuccessfullySensed())
		{
			BB_Domain->SetValueAsVector(TEXT("TargetLocation"), Actor->GetActorLocation());
			SetFocus(Actor);
		}
		else
		{
			BB_Domain->ClearValue(TEXT("TargetLocation"));
			ClearFocus(0);
		}
	}

}
