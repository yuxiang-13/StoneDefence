// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GameUI/UMG/Inventory/UI_InventorySlot.h"

#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Core/GameCore/TowerDefenceGameState.h"
#include "Data/Save/GameSaveData.h"

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
	if (!GetBuildingTower().bLockCD)
	{
		if (GetBuildingTower().bDragICO)
		{
			UpdateTowersCD(InDeltaTime);
			
		}
	}
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
		} else
		{
			CDMaterialDynamic->SetScalarParameterValue(TowersClearValueName, false);
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
