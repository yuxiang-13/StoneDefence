// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GameUI/UMG/Inventory/UI_InventorySlot.h"

#include "Components/Button.h"
#include "Components/Image.h"
#include "Core/GameCore/TowerDefenceGameState.h"
#include "Data/Save/GameSaveData.h"

void UUI_InventorySlot::NativeConstruct()
{
	Super::NativeConstruct();
	TISButton->OnClicked.AddDynamic(this, &UUI_InventorySlot::OnClickedWidget);
}

void UUI_InventorySlot::OnClickedWidget()
{
}

void UUI_InventorySlot::UpdateUI()
{
	// 应用上 图片
	if (GetBuildingTower().ICO)
	{
		TowersIcon->SetBrushFromSoftTexture(GetBuildingTower().ICO);

		// 直接这种 ESlateVisibility::Visible 显示，会把下面的按钮点击遮挡
		// TowersIcon->SetVisibility(ESlateVisibility::Visible);
		// 为了能看到也不影响按钮点击 Hit命中 Test测试 Invisible不可见
		TowersIcon->SetVisibility(ESlateVisibility::HitTestInvisible);
	} else
	{
		TowersIcon->SetVisibility(ESlateVisibility::Hidden);
	}
}

FBuildingTower& UUI_InventorySlot::GetBuildingTower()
{
	return GetGameState()->GetBuildingTower(GUID);
}
