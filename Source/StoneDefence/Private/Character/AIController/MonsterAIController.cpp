// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AIController/MonsterAIController.h"

#include "Character/CharacterCore/Towers.h"
#include "EngineUtils.h"
#include "StoneDefence/StoneDefenceUtils.h"

AActor* AMonsterAIController::FindTarget()
{
	if (!Target.IsValid() || !Target->IsActive())
	{
		
		TArray<ARuleOfTheCharacter*> TargetMainTowersArray;
		TArray<ARuleOfTheCharacter*> TargetTowersArray;

		for (TActorIterator<ATowers> It(GetWorld(), ATowers::StaticClass()); It; ++It)
		{
			ATowers* TheCharacter = *It;
			if (TheCharacter && TheCharacter->IsActive())
			{
				if (TheCharacter->GetType() == EGameCharacterType::Type::TOWER)
				{
					TargetTowersArray.Add(TheCharacter);
				} else if (TheCharacter->GetType() == EGameCharacterType::Type::MAIN_TOWER)
				{
					TargetMainTowersArray.Add(TheCharacter);
				}
			}
		}

		ATowers* MainTowers = Cast<ATowers>(StoneDefenceUtils::FindTargetRecently(TargetMainTowersArray, GetPawn()->GetActorLocation()));
		ATowers* NorTowers =Cast<ATowers>(StoneDefenceUtils::FindTargetRecently(TargetTowersArray, GetPawn()->GetActorLocation()));

		if (MainTowers)
		{
			return MainTowers;
		}

		return NorTowers;
	}
	return Target.Get();
}

void AMonsterAIController::AttackTarget(ARuleOfTheCharacter* AttackTargeter)
{
}
