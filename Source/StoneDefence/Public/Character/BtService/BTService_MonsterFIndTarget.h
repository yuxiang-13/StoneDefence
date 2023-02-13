// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_MonsterFIndTarget.generated.h" 

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UBTService_MonsterFIndTarget : public UBTService
{
	GENERATED_BODY()
public:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	// 目标
	UPROPERTY(EditAnywhere, Category="BlackBoard")
		struct FBlackboardKeySelector BlackBoardKey_Target;
	
	// 距离
	UPROPERTY(EditAnywhere, Category="BlackBoard")
	struct FBlackboardKeySelector BlackBoardKey_Distance;
	
	// 要移动的 终点位置
	UPROPERTY(EditAnywhere, Category="BlackBoard")
	struct FBlackboardKeySelector BlackBoardKey_TargetLocation;
	
	virtual void OnGameplayTaskInitialized(UGameplayTask& Task) override;

	virtual void OnGameplayTaskActivated(UGameplayTask& Task) override;

	virtual void OnGameplayTaskDeactivated(UGameplayTask& Task) override;
};
