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
	MaxStagesAreMonsters = 0;
	CurrentSpawnMosnterTime = 0.0f;
	GameCount = 0;
	MaxGameCount = 0;
	GoldGrowthTime = 1.f;
	GoldGrowthMaxTime = 1.5f;
	KillMonstersNumber = 0;
	KillMonsterBossNumber = 0;
	TowersDeathNumber = 0;
	MainTowersDeathNumber = 0;
}

// bool FGameInstanceDatas::IsVaild()
// {
// }
//
// int32 FGameInstanceDatas::GetSurplusMonsters()
// {
// }
//
// float FGameInstanceDatas::GetPerOfRemMonsters()
// {
// }
//
// void FGameInstanceDatas::ResetSpawnMosnterTime()
// {
// }
//
// void FGameInstanceDatas::StageDecision()
// {
// }
//
// void FGameInstanceDatas::AssignedMonsterAmount()
// {
// }
