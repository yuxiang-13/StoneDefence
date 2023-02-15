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

	//  拖拽显示的UI
	UPROPERTY(EditDefaultsOnly, Category=UI)
	TSubclassOf<class UUI_ICODragDrog> IcoDragDropClass;
	
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

	// 隐藏Slot
	void ClearSlot();
private:
	// 更新CD
	void UpdateTowersCD(float InDeltatime);
	// 绘制CD
	void DrawTowersCD(float InTowersCD);
	// 显示CD
	void DisplayNumber(UTextBlock* TextNumberBlock, int32 TextNumber);
	// 塔的 信息
	void UpdateTowersBuildingInfo();

protected:
	// 鼠标按下
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	// 拖拽动作
	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;
	// 拖拽后松手
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	// 鼠标进入
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	// 鼠标出来
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;
};
