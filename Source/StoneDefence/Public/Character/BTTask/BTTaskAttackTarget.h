// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskAttackTarget.generated.h" 

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UBTTaskAttackTarget : public UBTTaskNode
{
	GENERATED_BODY()

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	// 初始化资源
	virtual void InitializeFromAsset(UBehaviorTree& Asset) override;
	
	// 攻击目标
	UPROPERTY(EditAnywhere, Category=Blackboard)
	struct FBlackboardKeySelector Blackboard_Actor;
	
	virtual void OnGameplayTaskInitialized(UGameplayTask& Task) override;

	virtual void OnGameplayTaskActivated(UGameplayTask& Task) override;

	virtual void OnGameplayTaskDeactivated(UGameplayTask& Task) override;
};
