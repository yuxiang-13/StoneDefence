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

	// 塔CD名字
	UPROPERTY(EditDefaultsOnly, Category=UI)
		FName TowersMatCDName;
	// 塔CD清楚名字
	UPROPERTY(EditDefaultsOnly, Category=UI)
		FName TowersClearValueName;
	
	// CD动态材质
	UPROPERTY()
	class UMaterialInstanceDynamic* CDMaterialDynamic;
public:
	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	UFUNCTION()
	void OnClickedWidget();

	void UpdateUI();
	
	FBuildingTower &GetBuildingTower();
private:
	// 更新CD
	void UpdateTowersCD(float InDeltatime);
	// 绘制CD
	void DrawTowersCD(float InTowersCD);
	// 显示CD
	void DisplayNumber(UTextBlock* TextNumberBlock, int32 TextNumber);
	// 塔的 信息
	void UpdateTowersBuildingInfo();
};
