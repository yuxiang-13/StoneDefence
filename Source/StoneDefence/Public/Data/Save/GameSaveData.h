// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GameSaveData.generated.h"

struct FCharacterData;

// 建造塔
USTRUCT()
struct FBuildingTower
{
	GENERATED_BODY()

	UPROPERTY(SaveGame)
	int32 TowerID;

	//需要的消费金币
	UPROPERTY(SaveGame)
	int32 NeedGold;

	//准备阶段塔建造数量
	UPROPERTY(SaveGame)
	int32 TowersPerpareBuildingNumber;

	//塔已经建造数量
	UPROPERTY(SaveGame)
	int32 TowersConstructionNumber;

	//当前塔最大建造CD
	UPROPERTY(SaveGame)
	float MaxConstructionTowersCD;

	//当前建造中塔的CD
	UPROPERTY(SaveGame)
	float CurrentConstrictionTowersCD;

	//作为ICO指针
	UPROPERTY(SaveGame)
	UTexture2D* ICO;

	//是否拖拽图标
	UPROPERTY(SaveGame)
	bool bDragICO;

	//锁
	UPROPERTY(SaveGame)
	bool bLockCD;

	UPROPERTY(SaveGame)
	bool bCallUpdateTowersInfo;

public:
	FBuildingTower();

	void Init();

	float GetTowerConstructionTimePercentage();

	bool IsValid();

	void ResetCD();
};

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UGameSaveData : public USaveGame
{
	GENERATED_BODY()
public:
	
	UPROPERTY(SaveGame)
	TMap<FGuid, FCharacterData> CharacterDatas;

	//FGuid格子ID
	TMap<FGuid, FBuildingTower> BuildingTowers;
};
