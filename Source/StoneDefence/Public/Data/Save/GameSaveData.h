// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GameSaveData.generated.h"

struct FCharacterData;
/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UGameSaveData : public USaveGame
{
	GENERATED_BODY()
public:
	UGameSaveData();
	
	UPROPERTY(SaveGame)
	TMap<uint32, FCharacterData> CharacterDatas;
};
