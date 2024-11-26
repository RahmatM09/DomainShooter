// Domain Shooter By Genifinity

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskNode_Shoot.generated.h"

/**
 * 
 */
UCLASS()
class DOMAINSHOOTER_API UBTTaskNode_Shoot : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTTaskNode_Shoot();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);
};
