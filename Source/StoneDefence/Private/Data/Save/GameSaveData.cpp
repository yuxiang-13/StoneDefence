// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/Save/GameSaveData.h"

FBuildingTower::FBuildingTower()
{
	Init();
}

void FBuildingTower::Init()
{
	TowerID = INDEX_NONE;
	NeedGold = INDEX_NONE;
	TowersPerpareBuildingNumber = 0.0f;
	TowersConstructionNumber = 0.0f;
	MaxConstructionTowersCD = 0.0f;;
	CurrentConstrictionTowersCD = 0.0f;;
	ICO = NULL;
	bDragICO = false;
	bLockCD = false;
	bCallUpdateTowersInfo = false;
}

float FBuildingTower::GetTowerConstructionTimePercentage()
{
	return MaxConstructionTowersCD ? CurrentConstrictionTowersCD / MaxConstructionTowersCD : 0.f;
}

bool FBuildingTower::IsValid()
{
return TowerID != INDEX_NONE;
}

void FBuildingTower::ResetCD()
{
}
