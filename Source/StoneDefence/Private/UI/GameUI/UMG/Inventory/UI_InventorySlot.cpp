// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GameUI/UMG/Inventory/UI_InventorySlot.h"

#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Core/GameCore/TowerDefenceGameState.h"
#include "Data/Save/GameSaveData.h"
#include "DragDrop/StoneDefenceDragDropOperation.h"
#include "Kismet/KismetSystemLibrary.h"
#include "UI/GameUI/UMG/Inventory/UI_Data1.h"
#include "UI/GameUI/UMG/Inventory/DragDrop/UI_ICODragDrog.h"
#include "UI/GameUI/UMG/Tip/UI_TowerTip.h"

void UUI_InventorySlot::NativeConstruct()
{
	Super::NativeConstruct();
	TISButton->OnClicked.AddDynamic(this, &UUI_InventorySlot::OnClickedWidget);

	if (TowersCD)
	{
		CDMaterialDynamic = TowersCD->GetDynamicMaterial();
	}
}

void UUI_InventorySlot::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	// CD
	if (GetBuildingTower().IsValid())
	{
		if (!GetBuildingTower().bLockCD)
		{
			if (!GetBuildingTower().bDragICO)
			{
				UpdateTowersCD(InDeltaTime);
			
			}
		}
	}
}


void UUI_InventorySlot::OnClickedWidget()
{
	if (GetBuildingTower().IsValid())
	{
		if (/*GetBuildingTower().NeedGold*/ 1)
		{
			// 建造的塔++
			GetBuildingTower().TowersPerpareBuildingNumber++;
			if (GetBuildingTower().CurrentConstrictionTowersCD <= 0)
			{
				GetBuildingTower().ResetCD();
			}
		}
	}
}

UWidget* UUI_InventorySlot::GetTowerTip()
{
	if (TowerTipClass)
	{
		if (UUI_TowerTip *TowerTip = CreateWidget<UUI_TowerTip>(GetWorld(), TowerTipClass))
		{
			const FCharacterData &TowerDataInfo = GetGameState()->GetCharacterDataByID(GetBuildingTower().TowerID);
			if (TowerDataInfo.ID != INDEX_NONE)
			{
				TowerTip->InitTip(TowerDataInfo);
				return TowerTip;
			}
		}
	}
	return nullptr;
}

void UUI_InventorySlot::UpdateUI()
{
	GUID;
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

	
	if (GetBuildingTower().TowersConstructionNumber > 0)
	{
		TCOfCNumber->SetVisibility(ESlateVisibility::HitTestInvisible);
	}
	if (GetBuildingTower().TowersPerpareBuildingNumber > 0)
	{
		TPBNumber->SetVisibility(ESlateVisibility::HitTestInvisible);
	}
}

FBuildingTower& UUI_InventorySlot::GetBuildingTower()
{
	return GetGameState()->GetBuildingTower(GUID);
}

void UUI_InventorySlot::ClearSlot()
{
	TowersIcon->SetVisibility(ESlateVisibility::Hidden);
	TowersCD->SetVisibility(ESlateVisibility::Hidden);
	TPBNumber->SetVisibility(ESlateVisibility::Hidden);
	TCOfCNumber->SetVisibility(ESlateVisibility::Hidden);
	TowersCDValue->SetVisibility(ESlateVisibility::Hidden);
}

void UUI_InventorySlot::UpdateTowersCD(float InDeltatime)
{
	if (GetBuildingTower().CurrentConstrictionTowersCD > 0.f)
	{
		// 绘制CD
		DrawTowersCD(GetBuildingTower().GetTowerConstructionTimePercentage());
		
		GetBuildingTower().CurrentConstrictionTowersCD -= InDeltatime;
		GetBuildingTower().bCallUpdateTowersInfo = true;
		
		UpdateTowersBuildingInfo();
	} else if (GetBuildingTower().bCallUpdateTowersInfo)
	{
		GetBuildingTower().bCallUpdateTowersInfo = false;
		// 构建成功一个塔
		GetBuildingTower().TowersPerpareBuildingNumber--;
		GetBuildingTower().TowersConstructionNumber++;

		DrawTowersCD(0.f);

		if (GetBuildingTower().TowersPerpareBuildingNumber > 0)
		{
			GetBuildingTower().ResetCD();
		}
		
		UpdateTowersBuildingInfo();
	}
}

void UUI_InventorySlot::DrawTowersCD(float InTowersCD)
{
	if (CDMaterialDynamic)
	{
		if (InTowersCD > 0.f && InTowersCD < 1.0f)
		{
			CDMaterialDynamic->SetScalarParameterValue(TowersClearValueName, true);
			TowersCD->SetVisibility(ESlateVisibility::HitTestInvisible);
		} else
		{
			CDMaterialDynamic->SetScalarParameterValue(TowersClearValueName, false);
			TowersCD->SetVisibility(ESlateVisibility::Hidden);
		}
		CDMaterialDynamic->SetScalarParameterValue(TowersMatCDName, InTowersCD);
	}
}

void UUI_InventorySlot::DisplayNumber(UTextBlock* TextNumberBlock, int32 TextNumber)
{
	if (TextNumber < 1 || !GetBuildingTower().IsValid())
	{
		TextNumberBlock->SetVisibility(ESlateVisibility::Hidden);
	} else
	{
		TextNumberBlock->SetText(FText::FromString(FString::Printf(TEXT("%02d"), TextNumber)));
		TextNumberBlock->SetVisibility(ESlateVisibility::HitTestInvisible);
	}
}

void UUI_InventorySlot::UpdateTowersBuildingInfo()
{
	DisplayNumber(TowersCDValue, GetBuildingTower().CurrentConstrictionTowersCD);
	DisplayNumber(TCOfCNumber, GetBuildingTower().TowersConstructionNumber);
	DisplayNumber(TPBNumber, GetBuildingTower().TowersPerpareBuildingNumber);
}


// 开始拖拽
FReply UUI_InventorySlot::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
	// UKismetSystemLibrary::PrintString(this, TEXT("RightMouseButton 111"), true, true, FLinearColor::Red, 10.f);
	
	// 判断是不是鼠标右键  或者是屏幕触摸事件
	if (InMouseEvent.GetEffectingButton() == EKeys::RightMouseButton || InMouseEvent.IsTouchEvent()) 
	{
		// 查看当前拖拽的Widget是不是有效
		TSharedPtr<SWidget> SlateWidgetDrag = GetCachedWidget();
		if (SlateWidgetDrag.IsValid())
		{
			FReply Reply = FReply::Handled();
			// [dɪˈtekt] 发现;查明;侦察出
			// 表示鼠标右键会创建出Widget
			Reply.DetectDrag(SlateWidgetDrag.ToSharedRef(), EKeys::RightMouseButton);
			return Reply;
		}
	}
	
	return FReply::Unhandled();
}

// 产生拖拽
void UUI_InventorySlot::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent,
	UDragDropOperation*& OutOperation)
{
	if (GetBuildingTower().IsValid() && IsValid(IcoDragDropClass))
	{
		// 创建拖拽Widget
		UUI_ICODragDrog* IconDragDrop = CreateWidget<UUI_ICODragDrog>(GetWorld(), IcoDragDropClass);
		if (IconDragDrop)
		{
			// 生成拖拽类
			if (UStoneDefenceDragDropOperation* StoneDefenceDrag =
				NewObject<UStoneDefenceDragDropOperation>(GetTransientPackage(), UStoneDefenceDragDropOperation::StaticClass())
			)
			{
				// 标签设置成强引用  目的告诉GC 不要回收
				StoneDefenceDrag->SetFlags(RF_StrongRefOnFrame);
				// Payload为代理绑定时传递的额外参数
				StoneDefenceDrag->Payload = this;
				// 返回给接口
				OutOperation = StoneDefenceDrag;
				// 让拖拽类 长得像 谁
				StoneDefenceDrag->DefaultDragVisual = IconDragDrop;

				
				GetBuildingTower().bDragICO = true;
				// 隐藏自己Slot图标啥的
				ClearSlot();
			}
		}
	}
	Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);
}

// 拖拽松手 释放
bool UUI_InventorySlot::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
	UDragDropOperation* InOperation)
{
	Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);

	bool bDrop = false;

	// 把此拖拽生成的类，转化成自己刚刚 继承自UDragDropOperation的 UStoneDefenceDragDropOperation类
	if (UStoneDefenceDragDropOperation* StoneDefenceDragDropOperation = Cast<UStoneDefenceDragDropOperation>(InOperation))
	{
		// Payload为代理绑定时传递的额外参数 取出来   注意：：：此时发生拖拽，松手时候看看是交换物品还是保持原样
		if (UUI_InventorySlot* MyInventorySlot = Cast<UUI_InventorySlot>(StoneDefenceDragDropOperation->Payload))
		{
			MyInventorySlot->GetBuildingTower().bDragICO = false;

			// 看看这个槽是不是存在 塔   开始交换
			GetGameState()->RequestInventorySlotSwap(GUID, MyInventorySlot->GUID);
			// 更新UI
			UpdateUI();
			MyInventorySlot->UpdateUI();
			bDrop = true;
		}
	}
	
	return bDrop;
}

void UUI_InventorySlot::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);
	// 鼠标移动到塔上，做标记
	TowerICOGUID = GUID;
}

void UUI_InventorySlot::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);
}
