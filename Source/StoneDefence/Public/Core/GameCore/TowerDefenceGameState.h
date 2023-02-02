// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "TowerDefenceGameState.generated.h"

struct FCharacterData;
/**
 * 
 */
UCLASS()
class STONEDEFENCE_API ATowerDefenceGameState : public AGameState
{
	GENERATED_BODY()

public:
	const FCharacterData &AddCharacterData(const FString &Hash, const FCharacterData &Data);
	bool RemoveCharacterData(const FString &Hash);
	FCharacterData &GetCharacterData(const FString &Hash);
private:
	// 所有角色数据（包括所有建筑 和 所有的塔）
	UPROPERTY()
	TMap<FString,FCharacterData> CharacterDatas;
};
