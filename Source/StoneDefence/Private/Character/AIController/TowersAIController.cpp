// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AIController/TowersAIController.h"

#include "EngineUtils.h"
#include "Character/CharacterCore/Monsters.h"
#include "Character/CharacterCore/Towers.h"
#include "StoneDefence/StoneDefenceUtils.h"

ATowersAIController::ATowersAIController()
	: HeartbeatDiagnosis(0.0f)
{
}

void ATowersAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	HeartbeatDiagnosis += DeltaSeconds;
	if (HeartbeatDiagnosis >= 0.5f)
	{
		BTService_FindTarget();
		HeartbeatDiagnosis = 0.0f;
	}

	
	if (TArrayMonsters.Num())
	{
		if (ATowers* Towers = GetPawn<ATowers>())
		{
			if (IsValid(Towers))
			{
				Target = Cast<ARuleOfTheCharacter>(FindTarget());
			}
			if (Target.IsValid())
			{
				// FRotationMatrix::MakeFromX  表示 我看像目标（参数是一个方向向量）
				// MakeFrom XX 这个系列的函数是根据你指定的方向 计算出在世界坐标下的相对旋转
				// 例如MakeRotFromX 就是给定一个方向的Vector, 得出这个方向 的 世界坐标的旋转 rotator
				
				Towers->TowersRotator = FRotationMatrix::MakeFromX(Target->GetActorLocation() - GetPawn()->GetActorLocation()).Rotator();
			}
		}
	}
}

AActor* ATowersAIController::FindTarget()
{
	if (TArrayMonsters.Num())
	{
		return StoneDefenceUtils::FindTargetRecently(TArrayMonsters, GetPawn()->GetActorLocation());
	}
	return nullptr;
}

void ATowersAIController::BTService_FindTarget()
{
	TArrayMonsters.Empty();

	if (ATowers* Towers =  GetPawn<ATowers>())
	{
		if (Towers->IsActive())
		{
			for (TActorIterator<AMonsters>It(GetWorld(), AMonsters::StaticClass()); It; ++It)
			{
				if (AMonsters* TheCharacter = *It)
				{
					if (TheCharacter->IsActive())
					{
						FVector TDistance = TheCharacter->GetActorLocation() - GetPawn()->GetActorLocation();
						if (TDistance.Size() <= 1600)
						{
							TArrayMonsters.Add(TheCharacter);
						}
					}
				}
			}
			// TWeakObjectPtr<class ARuleOfTheCharacter> Target 变罗指针
			AttackTarget(Target.Get());
		}
	}
}


void ATowersAIController::AttackTarget(ARuleOfTheCharacter* AttackTargeter)
{
	if (ATowers* Towers = GetPawn<ATowers>())
	{
		if (TArrayMonsters.Num() > 0)
		{
			Towers->bAttack = true;
		} else
		{
			Towers->bAttack = false;
		}
	}
}