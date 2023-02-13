// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GameSaveSlotList.generated.h" 

USTRUCT()
struct FSaveSlot
{
	GENERATED_BODY()
	FSaveSlot();
	
	// 我们存了多少个存档，存档的内容和日期
	UPROPERTY(SaveGame)
	FText DataText;

	// 是否存档
	UPROPERTY(SaveGame)
	bool bSave;
};


USTRUCT()
struct FSaveSlotList
{
	GENERATED_BODY()
public:
	FSaveSlotList();

	UPROPERTY(SaveGame)
	TMap<int32, FSaveSlot> Slots;

	// 以存档哪些
	UPROPERTY(SaveGame)
	TMap<int32, float> DegreeOfCompletion;

	int32 GetSerialNumber();

	bool RemoveAtGameData(int32 SlotNumber);
	bool AddGameDataByNumber(int32 SlotNumber);
};

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UGameSaveSlotList : public USaveGame
{
	GENERATED_BODY()
public:
	UPROPERTY(SaveGame)
	FSaveSlotList SlotList;
};