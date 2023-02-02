// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/GameCore/TowerDefenceGameState.h"

#include "Data/Core/CharacterData.h"
#include "StoneDefence/StoneDefenceMacro.h"

static FCharacterData CharacterDataNULL;

const FCharacterData &ATowerDefenceGameState::AddCharacterData(const FString &Hash, const FCharacterData& Data)
{
	return CharacterDatas.Add(Hash, Data);
}

bool ATowerDefenceGameState::RemoveCharacterData(const FString& Hash)
{
	CharacterDatas.Remove(Hash);
	return true;
}

FCharacterData& ATowerDefenceGameState::GetCharacterData(const FString& Hash)
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
