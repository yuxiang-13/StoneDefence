// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/SelectLevelUI/UMG/UI_SelectLevelMain.h"

#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Kismet/GameplayStatics.h"
#include "UI/SelectLevelUI/UMG/Button/UI_LevelButton.h"

void UUI_SelectLevelMain::NativeConstruct()
{
	Super::NativeConstruct();

	InitSelectLevelButton();

	ReturnMenuButton->OnClicked.AddDynamic(this, &UUI_SelectLevelMain::ReturnMenu);
}

void UUI_SelectLevelMain::InitSelectLevelButton()
{

	if (SelectMap)
	{
		TArray<UPanelSlot*> PanelSlotArray = SelectMap->GetSlots(); // UPanelSlot 排布(就是子节点)
		for (UPanelSlot* PanelSlotEle : PanelSlotArray)
		{
			// UPanelSlot 排布(就是子节点)
			
			// if (PanelSlotEle->Content.IsA(UUI_LevelButton::StaticClass())){}
			if (UUI_LevelButton* LevelButtonArp = Cast<UUI_LevelButton>(PanelSlotEle->Content))
			{
				AllLevelButton.Add(LevelButtonArp);
			}
		}
	}
}

void UUI_SelectLevelMain::ReturnMenu()
{
	UGameplayStatics::OpenLevel(GetWorld(), "HallMap");
}
