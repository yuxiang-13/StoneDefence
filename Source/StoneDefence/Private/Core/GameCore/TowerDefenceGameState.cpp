// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/GameCore/TowerDefenceGameState.h"

#include "Character/Core/RuleOfTheCharacter.h"
#include "Data/Core/CharacterData.h"
#include "StoneDefence/StoneDefenceMacro.h"

//static 与 extern 联系：
//加了static修饰的全局变量或函数，无法在使用extern在其他源文件中使用。

// 定义静态类
// extern ：extern（外部引用）可以置于变量或者函数前，以标示变量或函数的定义在别的文件中，在一个文件中用到的extern这些变量或函数是外来的，
// 不是本文件定义的，提示编译器遇到此变量和函数时在其他模块中寻找其定义。注意，只有其他文件中的全局变量才能被其他文件所extern。
FCharacterData CharacterDataNULL;

ATowerDefenceGameState::ATowerDefenceGameState()
{
	
}

ARuleOfTheCharacter* ATowerDefenceGameState::SpawnCharacter(const FVector& Location, const FRotator& Rotator)
{
	if (GetWorld())
	{
		if (ARuleOfTheCharacter * RuleOfTheCharacter = GetWorld()->SpawnActor<ARuleOfTheCharacter>(ARuleOfTheCharacter::StaticClass(), Location, Rotator))
		{
			RuleOfTheCharacter->GUID = FGuid::NewGuid();

			FCharacterData CharacterData;
			AddCharacterData(RuleOfTheCharacter->GUID, CharacterData);
		}
	}
	return nullptr;
}

const FCharacterData &ATowerDefenceGameState::AddCharacterData(const FGuid &Hash, const FCharacterData& Data)
{
	return CharacterDatas.Add(Hash, Data);
}

bool ATowerDefenceGameState::RemoveCharacterData(const FGuid& Hash)
{
	CharacterDatas.Remove(Hash);
	return true;
}

FCharacterData& ATowerDefenceGameState::GetCharacterData(const FGuid& Hash)
{
	if (CharacterDatas.Contains(Hash))
	{
		return CharacterDatas[Hash];
	} else
	{
		// SD_print_r(Error, "The current [%s] is invalid", *Hash);
		return CharacterDataNULL;
	}
}
