// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class ARuleOfTheCharacter;

namespace StoneDefenceUtils
{
	ARuleOfTheCharacter* FindTargetRecently(const TArray<ARuleOfTheCharacter*> &InCharacters, const FVector &Loc);
}
