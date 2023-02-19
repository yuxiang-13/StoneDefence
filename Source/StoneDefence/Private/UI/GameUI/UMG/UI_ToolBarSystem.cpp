// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GameUI/UMG/UI_ToolBarSystem.h"

#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Core/GameCore/TowerDefenceGameState.h"
#include "Data/Core/GameData.h"
#include "Data/Core/PlayerData.h"
#include "Kismet/KismetSystemLibrary.h"

void UUI_ToolBarSystem::NativeConstruct()
{
	Super::NativeConstruct();
}

void UUI_ToolBarSystem::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	
	//显示游戏的倒计时
	if (GameCount)
	{
		FString Time = GetCurrentCountTime(GetGameState()->GetGameDatas().GameCount);
	
		GameCount->SetText(FText::FromString(Time));
	}
	
	//显示金币
	if (GameGlob)
		GameGlob->SetText(FText::AsNumber(GetGameState()->GetPlayerData().GameGold));

	// 塔死亡数
	if (TowersDeathNumber)
		TowersDeathNumber->SetText(FText::AsNumber(GetGameState()->GetGameDatas().TowersDeathNumber));

	// 杀死敌人数量
	if (KillSoldier)
		KillSoldier->SetText(FText::AsNumber(GetGameState()->GetGameDatas().KillMonstersNumber));

	// 当前怪物剩余百分比
	if (GSQProgressBar)
		GSQProgressBar->SetPercent(GetGameState()->GetGameDatas().GetPerOfRemMonsters());

	// 当前阶段 04/40
	if (GameLevelSurplusQuantity)
	{
		GameLevelSurplusQuantity->SetText(
			FText(FText::FromString(
				FString::Printf(TEXT("%2d / %2d"), GetGameState()->GetGameDatas().PerNumberOfMonsters.Num(), GetGameState()->GetGameDatas().CurrentStagesAreMonsters)
			))
		);
	}
		
}

//获取时间格式
FString UUI_ToolBarSystem::GetCurrentCountTime(float NewTimeCount)
{
	const int32 NewOurTime = FMath::Max(0, FMath::TruncToInt(NewTimeCount));
	const int32 NewMinrutes = NewOurTime / 60;
	const int32 NewSeconds = NewOurTime % 60; // s
	return FString::Printf(TEXT("%02d:%02d"), NewMinrutes, NewSeconds); // 00 : 00
}
