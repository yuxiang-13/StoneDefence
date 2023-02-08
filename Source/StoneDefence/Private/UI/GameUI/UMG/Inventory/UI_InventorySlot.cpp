// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GameUI/UMG/Inventory/UI_InventorySlot.h"

#include "Components/Button.h"
#include "Core/GameCore/TowerDefenceGameState.h"

void UUI_InventorySlot::NativeConstruct()
{
	Super::NativeConstruct();
	TISButton->OnClicked.AddDynamic(this, &UUI_InventorySlot::OnClickedWidget);
}

void UUI_InventorySlot::OnClickedWidget()
{
}

FBuildingTower& UUI_InventorySlot::GetBuildingTower()
{
	return GetGameState()->GetBuildingTower(GUID);
}
