// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/SelectLevelCore/TowerDefenceSelectLevelGameMode.h"

#include "UI/SelectLevelUI/Core/TowersDefenceSelectLevelHUD.h"

ATowerDefenceSelectLevelGameMode::ATowerDefenceSelectLevelGameMode()
{
	HUDClass = ATowersDefenceSelectLevelHUD::StaticClass();
	
}

void ATowerDefenceSelectLevelGameMode::BeginPlay()
{
	Super::BeginPlay();
	
}
