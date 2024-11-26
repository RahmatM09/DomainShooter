// Domain Shooter By Genifinity

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "DomainAIController.generated.h"

/**
 * Forward Declare
 */

class UBehaviorTree;
class UBlackboardComponent;
class UAIPerceptionComponent;
class UAISenseConfig_Sight;

UCLASS()
class DOMAINSHOOTER_API ADomainAIController : public AAIController
{
	GENERATED_BODY()

public:
	ADomainAIController();
	
protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "AI")
	TObjectPtr<UBehaviorTree> BT_DomianAI;

	UPROPERTY(VisibleAnywhere, Category = "AI")
	UBlackboardComponent* BB_Domain;

	UPROPERTY(VisibleAnywhere, Category = "AI|Perception")
	TObjectPtr<UAIPerceptionComponent> DomainAIPerception;

	UPROPERTY(VisibleAnywhere, Category = "AI|Perception")
	TObjectPtr<UAISenseConfig_Sight> SightSenseConfig;

	// Callback functions ************************************************
	UFUNCTION()
	void OnPerceptionUpdated(const FActorPerceptionUpdateInfo& UpdateInfo);

};
