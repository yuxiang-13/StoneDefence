// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI_InventorySlot.h"
#include "UI/GameUI/Core/UI_Slot.h"
#include "UI_Inventory.generated.h" 

class UUniformGridPanel;
/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_Inventory : public UUI_Slot
{
	GENERATED_BODY()
	
	UPROPERTY(meta = (BindWidget))
	UUniformGridPanel *SlotArrayInventory;

	UPROPERTY(EditDefaultsOnly, Category=UI)
	TSubclassOf<UUI_InventorySlot> InventorySlotClass;
	
public:
	virtual void NativeConstruct() override;
	
	void LayoutInventroySlot(int32 ColumNumber, int32 RowNumber);
private: // 技能Item
	TArray<UUI_InventorySlot*> InventorySlotArray;
	
};
