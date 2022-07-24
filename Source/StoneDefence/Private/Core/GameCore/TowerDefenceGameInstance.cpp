// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/GameCore/TowerDefenceGameInstance.h"

#include "SimpleScreenLoading.h"

void UTowerDefenceGameInstance::Init()
{
	Super::Init();

	// 加载模块
	FSimpleScreenLoadingModule  &SimpleScreenLoadingModule = FModuleManager::LoadModuleChecked<FSimpleScreenLoadingModule>("SimpleScreenLoading");
	SimpleScreenLoadingModule.SetupScreenLoading();
}
