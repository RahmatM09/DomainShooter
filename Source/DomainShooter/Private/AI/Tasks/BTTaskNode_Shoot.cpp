// Domain Shooter By Genifinity


#include "AI/Tasks/BTTaskNode_Shoot.h"
#include "AIController.h"
#include "DomainShooter/Public/Characters/DomainAICharacter.h"

UBTTaskNode_Shoot::UBTTaskNode_Shoot()
{
	NodeName = "Shoot";
}

EBTNodeResult::Type UBTTaskNode_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	AAIController* DomainAIController = OwnerComp.GetAIOwner();
	if (!DomainAIController)
		return EBTNodeResult::Failed;

	ADomainAICharacter* DomainAICharacter = Cast<ADomainAICharacter>(DomainAIController->GetPawn());
	if (!DomainAICharacter)
		return EBTNodeResult::Failed;

	DomainAICharacter->ShootTask();

	return EBTNodeResult::Succeeded;
}
