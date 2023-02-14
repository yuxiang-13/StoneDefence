// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/GameUI/Core/UI_Slot.h"
#include "UI_InventorySlot.generated.h" 

class UImage;
class UTextBlock;
class UButton;
struct FBuildingTower;
/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_InventorySlot : public UUI_Slot
{
	GENERATED_BODY()

	
	UPROPERTY(meta = (BindWidget))
	UImage *TowersIcon;

	UPROPERTY(meta = (BindWidget))
	UImage *TowersCD;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock *TPBNumber;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock *TCOfCNumber;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock *TowersCDValue;
	
	UPROPERTY(meta = (BindWidget))
	UButton *TISButton;
public:
	virtual void NativeConstruct() override;
	
	UFUNCTION()
	void OnClickedWidget();

	void UpdateUI();
	
	FBuildingTower &GetBuildingTower();
	
};
