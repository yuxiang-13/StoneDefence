// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GameUI/UMG/UI_MainScreen.h"

#include "Blueprint/WidgetLayoutLibrary.h"
#include "Character/Core/RuleOfTheCharacter.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/Image.h"
#include "Core/GameCore/TowerDefencePlayerController.h"
#include "Data/Save/GameSaveData.h"
#include "DragDrop/StoneDefenceDragDropOperation.h"
#include "Kismet/KismetSystemLibrary.h"
#include "UI/GameUI/UMG/Inventory/UI_Data1.h"
#include "UI/GameUI/UMG/Inventory/UI_InventorySlot.h"
#include "UI/GameUI/UMG/Tip/UI_TowerTip.h"

void UUI_MainScreen::NativeConstruct()
{
	Super::NativeConstruct();
	
}

void UUI_MainScreen::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	//  显示角色信息
	
	// 获取选中Actor
	if (ARuleOfTheCharacter * InCharacter = Cast<ARuleOfTheCharacter>(GetPlayerController()->GetHitResult().GetActor()))
	{
		FCharacterData& CharacterData = GetGameState()->GetCharacterData(InCharacter->GUID);
		if (CharacterData.IsValid())
		{
			// 刷新UI
			CharacterTip->SetVisibility(ESlateVisibility::HitTestInvisible);
			CharacterTip->InitTip(CharacterData);

			
			if (UCanvasPanelSlot* NewPanelSlot = Cast<UCanvasPanelSlot>(CharacterTip->Slot))
			{
				FVector2D ScreenLocation = FVector2D::ZeroVector;
			    // 把世界空间转化成Widget空间
			    UWidgetLayoutLibrary::ProjectWorldLocationToWidgetPosition(GetPlayerController(), GetPlayerController()->GetHitResult().Location, ScreenLocation, true);
				NewPanelSlot->SetPosition(ScreenLocation);
			}
		} else
		{
			CharacterTip->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else
	{
			CharacterTip->SetVisibility(ESlateVisibility::Hidden);
	}

	//  显示集火对象
	if (IsValid(ClickedTargetMonster) && ClickedTargetMonster->IsActive())
	{
		// 获取集火UI
		if (UCanvasPanelSlot* NewPanelSlot = Cast<UCanvasPanelSlot>(FireConcentrationPoint->Slot))
		{
			FVector2D ScreenLocation = FVector2D::ZeroVector;
			// 把敌人  的世界空间   转化成   Widget空间
			UWidgetLayoutLibrary::ProjectWorldLocationToWidgetPosition(GetPlayerController(), ClickedTargetMonster->GetActorLocation(), ScreenLocation, true);
			NewPanelSlot->SetPosition(ScreenLocation);
			FireConcentrationPoint->SetVisibility(ESlateVisibility::HitTestInvisible);
		}
	} else
	{
		ClickedTargetMonster = nullptr;
		FireConcentrationPoint->SetVisibility(ESlateVisibility::Hidden);
	}
}

bool UUI_MainScreen::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
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
			MyInventorySlot->UpdateUI();
			bDrop = true;
		}
	}
	
	return bDrop;
}
