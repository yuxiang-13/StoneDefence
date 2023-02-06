// Copyright Epic Games, Inc. All Rights Reserved.

#include "StoneDefenceUtils.h"

#include "Character/Core/RuleOfTheCharacter.h"


#if PLATFORM_WINDOWS
#pragma optimize("",off)
#endif

ARuleOfTheCharacter* StoneDefenceUtils::FindTargetRecently(const TArray<ARuleOfTheCharacter*>& InCharacters, const FVector &Loc)
{
	if (InCharacters.Num())
	{
		float TargetDistance = 9999999;
		int32 Index = INDEX_NONE;
		for (int32 i = 0; i < InCharacters.Num(); i++)
		{
			if (ARuleOfTheCharacter* GameCharacter = InCharacters[i])
			{
				FVector Location = GameCharacter->GetActorLocation();
				FVector TmpVector = Location - Loc;

				float Distance = TmpVector.Size();
				if (Distance < TargetDistance && GameCharacter->IsActive())
				{
					Index = i;
					TargetDistance = Distance;
				}
			}
		}

		if (Index != INDEX_NONE)
		{
			return InCharacters[Index];
		}
	}

	return nullptr;
}

#if PLATFORM_WINDOWS
#pragma optimize("",on)
#endif