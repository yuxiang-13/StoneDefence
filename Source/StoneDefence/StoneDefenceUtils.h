// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interface/Character/RuleCharacterInterface.h"

class ARuleOfTheCharacter;
class IRuleCharacterInterface;

namespace StoneDefenceUtils
{
	ARuleOfTheCharacter* FindTargetRecently(const TArray<ARuleOfTheCharacter*> &InCharacters, const FVector &Loc);

	template<class Type>
	void GetAllActor(UWorld* World, TArray<Type*> &Array)
	{
		for (TActorIterator<Type>It(World, Type::StaticClass()); It; ++It)
		{
			if (Type* A = Cast<Type>(*It))
			{
				Array.Add(A);
			}
		}
	}

	// 获取 较少数组（返回指针数组，进行拷贝一次。指针占用4字节，较少的浪费）
	template<class Type>
	TArray<Type*> GetAllActor(UWorld* World)
	{
		TArray<Type*> Array;
		for (TActorIterator<Type>It(World, Type::StaticClass()); It; ++It)
		{
			if (Type* A = Cast<Type>(*It))
			{
				Array.Add(A);
			}
		}
		return Array;
	}
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
