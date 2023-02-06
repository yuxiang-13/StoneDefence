// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interface/Character/RuleCharacterInterface.h"

class ARuleOfTheCharacter;
class IRuleCharacterInterface;

namespace StoneDefenceUtils
{
	ARuleOfTheCharacter* FindTargetRecently(const TArray<ARuleOfTheCharacter*> &InCharacters, const FVector &Loc);
}


// 公式
namespace Expression
{
	float GetDamage(IRuleCharacterInterface *Enemy, IRuleCharacterInterface *Owner);

	inline float GetDamage(IRuleCharacterInterface* Enemy, IRuleCharacterInterface* Owner)
	{
		if (Enemy && Owner)
		{
			return Enemy->GetCharacterData().PhysicalAttack / ((Owner->GetCharacterData().Armor / 100.f) + 1);
		}
		return 0.0f;
	}
}
