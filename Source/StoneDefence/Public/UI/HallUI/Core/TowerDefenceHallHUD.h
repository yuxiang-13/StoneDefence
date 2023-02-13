// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/HallUI/UMG/UI_MainHall.h"
#include "TowerDefenceHallHUD.generated.h" 

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API ATowerDefenceHallHUD : public AHUD
{
	GENERATED_BODY()
public:
	ATowerDefenceHallHUD();

	virtual void BeginPlay() override;
private:
	// 捕获 蓝图资源
	TSubclassOf<UUI_MainHall> MainHallClass;
	// 根据资源创建的类
	class UUI_MainHall* MainHall;
};
