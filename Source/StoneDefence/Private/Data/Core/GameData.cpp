// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/Core/GameData.h"

FGameInstanceDatas::FGameInstanceDatas()
{
	Init();
}

void FGameInstanceDatas::Init()
{
	NumberOfMonster = 20;
	GameDifficulty = 0;
	bAllMainTowerDie = false;
	bGameOver = false;
	bCurrentLevelMissionSuccess = false;
	SpawnMonsterState = 0;
	CurrentLevel = INDEX_NONE;
	TimeInterval = 0.5f;
	CurrentSpawnMosnterTime = 0.0f;
	GameCount = 6000;
	MaxGameCount = 0;
	GoldGrowthTime = 1.f;
	GoldGrowthMaxTime = 1.5f;
	KillMonstersNumber = 0;
	KillMonsterBossNumber = 0;
	TowersDeathNumber = 0;
	MainTowersDeathNumber = 0;
}

float FGameInstanceDatas::GetPerOfRemMonsters()
{
	int32 MaxMonsterNumber = GetMaxMonstersNumber();
	if (MaxMonsterNumber != 0)
	{
		return (float)(NumberOfMonster / MaxMonsterNumber);
	}
	return 0.f;
}

int32 FGameInstanceDatas::GetMaxMonstersNumber()
{
	int32 MaxMonsterNumber = 0;
	for (auto &Tmp : PerNumberOfMonsters)
	{
		MaxMonsterNumber += Tmp;
	}
	return MaxMonsterNumber;
}

void FGameInstanceDatas::ResetSpawnMosnterTime()
{
	CurrentSpawnMosnterTime = 0.f;
}
//
// void FGameInstanceDatas::StageDecision()
// {
// }
//
// void FGameInstanceDatas::AssignedMonsterAmount()
// {
// }
