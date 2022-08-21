// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BtService/BTService_MonsterFIndTarget.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Character/AIController/MonsterAIController.h"
#include "Character/Core/RuleOfTheCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UBTService_MonsterFIndTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	if (ARuleOfTheAIController* MonsterAIController = Cast<ARuleOfTheAIController>(OwnerComp.GetOwner()))
	{
		if (UBlackboardComponent* MyBlackBoard = OwnerComp.GetBlackboardComponent())
		{
			if (ARuleOfTheCharacter* NewTarget = Cast<ARuleOfTheCharacter>(MonsterAIController->FindTarget()))
			{
				if (Target != NewTarget)
				{
					if (ARuleOfTheCharacter* MonsterSelf = Cast<ARuleOfTheCharacter>(MonsterAIController->GetPawn()))
					{
						// 立刻停止 移动
						MonsterSelf->GetCharacterMovement()->StopMovementImmediately();
					}
					Target = NewTarget;
				}
				if (Target.IsValid())
				{
					if (Target->IsActive()) // 目标存活
					{
						FVector CurrentLocation = FVector::ZeroVector;
						FVector NewTargetV = MonsterAIController->GetPawn()->GetActorLocation() - Target.Get()->GetActorLocation();
						NewTargetV.Normalize();
						CurrentLocation = NewTargetV * 800.f + Target.Get()->GetActorLocation();
						
						
						MyBlackBoard->SetValueAsObject(BlackBoardKey_Target.SelectedKeyName, Target.Get());
						MyBlackBoard->SetValueAsVector(BlackBoardKey_TargetLocation.SelectedKeyName, CurrentLocation);
					} else
					{
						MyBlackBoard->SetValueAsObject(BlackBoardKey_Target.SelectedKeyName, nullptr);
						MyBlackBoard->SetValueAsVector(BlackBoardKey_TargetLocation.SelectedKeyName, FVector::Zero());
					}
				} else
				{
					MyBlackBoard->SetValueAsObject(BlackBoardKey_Target.SelectedKeyName, nullptr);
					MyBlackBoard->SetValueAsVector(BlackBoardKey_TargetLocation.SelectedKeyName, FVector::Zero());
				}
			}


			// 获取距离
			if (Target.IsValid())
			{
				FVector MyLocation = MonsterAIController->GetPawn()->GetActorLocation();
				FVector TMDistance = MyLocation - Target->GetActorLocation();
				if (TMDistance.Size() > 2000)
				{
					if (ARuleOfTheCharacter* MonsterAI = Cast<ARuleOfTheCharacter>(MonsterAIController->GetPawn()))
					{
						MonsterAI->bAttack = false;
					}
				}
				MyBlackBoard->SetValueAsFloat(BlackBoardKey_Distance.SelectedKeyName, TMDistance.Size());
			} else {
				MyBlackBoard->SetValueAsFloat(BlackBoardKey_Distance.SelectedKeyName, 0.f);
			}
		}
	}
}

void UBTService_MonsterFIndTarget::OnGameplayTaskInitialized(UGameplayTask& Task)
{
	Super::OnGameplayTaskInitialized(Task);
}

void UBTService_MonsterFIndTarget::OnGameplayTaskActivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskActivated(Task);
}

void UBTService_MonsterFIndTarget::OnGameplayTaskDeactivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskDeactivated(Task);
}
