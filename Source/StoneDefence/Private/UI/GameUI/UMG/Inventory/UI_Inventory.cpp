// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GameUI/UMG/Inventory/UI_Inventory.h"

#include <Expat/expat-2.2.10/lib/expat.h>

#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "Core/GameCore/TowerDefenceGameState.h"

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
	}
}
