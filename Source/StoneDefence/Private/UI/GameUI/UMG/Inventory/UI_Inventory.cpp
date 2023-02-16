// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GameUI/UMG/Inventory/UI_Inventory.h"

#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "Core/GameCore/TowerDefenceGameState.h"
#include "Data/Save/GameSaveData.h"

void UUI_Inventory::NativeConstruct()
{
	Super::NativeConstruct();

	LayoutInventroySlot(3, 7);
}

void UUI_Inventory::LayoutInventroySlot(int32 ColumnNumber, int32 RowNumber)
{
	if (InventorySlotClass)
	{
		for (int32 MyRow= 0; MyRow < RowNumber; MyRow++)
		{
			// 排序物品栏
			for (int32 MyColumn = 0; MyColumn < ColumnNumber; MyColumn++)
			{
				UUI_InventorySlot* SlotWidget = CreateWidget<UUI_InventorySlot>(GetWorld(), InventorySlotClass);
				if (SlotWidget)
				{
					if (UUniformGridSlot *GridSlot = SlotArrayInventory->AddChildToUniformGrid(SlotWidget))
					{
						GridSlot->SetColumn(MyColumn);
						GridSlot->SetRow(MyRow);
						GridSlot->SetHorizontalAlignment(EHorizontalAlignment::HAlign_Fill);
						GridSlot->SetVerticalAlignment(EVerticalAlignment::VAlign_Fill);
					}
					InventorySlotArray.Add(SlotWidget);
				}
			}
		}

		// 给 UI item绑定 Guid
		const TArray<const FGuid*> IDs = GetGameState()->GetBuildingTowersID();
		for (int32 i = 0; i < ColumnNumber * RowNumber; i++)
		{
			InventorySlotArray[i]->GUID = *IDs[i];
		}

		TArray<const FCharacterData*> Datas;
		if (GetGameState()->GetTowersDataFormTable(Datas))
		{
			for (int32 i = 0; i < Datas.Num(); i++)
			{
				InventorySlotArray[i]->GetBuildingTower().TowerID = Datas[i]->ID;
				InventorySlotArray[i]->GetBuildingTower().NeedGold = Datas[i]->Glod;
				InventorySlotArray[i]->GetBuildingTower().MaxConstructionTowersCD = Datas[i]->ConstructionTime;
				InventorySlotArray[i]->GetBuildingTower().ICO = Cast<UTexture2D>(Datas[i]->Icon.LoadSynchronous());
				
				InventorySlotArray[i]->UpdateUI();
			}
		}
	}
}
