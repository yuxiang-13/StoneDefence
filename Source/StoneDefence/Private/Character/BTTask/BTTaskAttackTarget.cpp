// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BTTask/BTTaskAttackTarget.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "Character/AIController/MonsterAIController.h"
#include "Character/Core/RuleOfTheCharacter.h"


void UBTTaskAttackTarget::InitializeFromAsset(UBehaviorTree& Asset)
{
	Super::InitializeFromAsset(Asset);
	if (UBlackboardData* BBAsset = GetBlackboardAsset())
	{
		// 查找所选密钥的 ID 和类
		Blackboard_Actor.ResolveSelectedKey(*BBAsset);
	} else
	{
		UE_LOG(LogBehaviorTree, Warning, TEXT("Can'Initialize task: %s"), *GetName());
	}

	
}

EBTNodeResult::Type UBTTaskAttackTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (AMonsterAIController* MyAIController = Cast<AMonsterAIController>(OwnerComp.GetOwner()))
	{
		if (UBlackboardComponent* MyBlackeBoard = OwnerComp.GetBlackboardComponent())
		{
			// 看看是不是正确类型
			if (Blackboard_Actor.SelectedKeyType == UBlackboardKeyType_Object::StaticClass())
			{
				// 获取自己这个Pawn（敌人）
				if (ARuleOfTheCharacter* MyPawn = Cast<ARuleOfTheCharacter>(MyAIController->GetPawn()))
				{
					// 获取黑板上的值  塔
					if (ARuleOfTheCharacter* TargetTower =Cast<ARuleOfTheCharacter>(MyBlackeBoard->GetValueAsObject(Blackboard_Actor.SelectedKeyName)))
					{
						MyPawn->bAttack = true;
						MyAIController->AttackTarget(TargetTower);
						
						return EBTNodeResult::Succeeded;
					} else
					{
						MyPawn->bAttack = false;
						return EBTNodeResult::Succeeded;
					}
				}
			}
		}
	}
	return EBTNodeResult::Failed;
}

void UBTTaskAttackTarget::OnGameplayTaskInitialized(UGameplayTask& Task)
{
	Super::OnGameplayTaskInitialized(Task);
}

void UBTTaskAttackTarget::OnGameplayTaskActivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskActivated(Task);
}

void UBTTaskAttackTarget::OnGameplayTaskDeactivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskDeactivated(Task);
}
