// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RuleOfTheWidget.h"
#include "UI_SelectLevelMain.generated.h" 

class UButton;
class UCanvasPanel;
class UUI_LevelButton;
/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_SelectLevelMain : public UUI_RuleOfTheWidget
{
	GENERATED_BODY()

	UPROPERTY(meta=(BindWidget))
		UButton* ReturnMenuButton;
	UPROPERTY(meta = (BindWidget))
		UCanvasPanel* SelectMap;
public:
	virtual void NativeConstruct() override;

protected:
	void InitSelectLevelButton();

	// 返回主菜单
	UFUNCTION()
	void ReturnMenu();
private:
	TArray<UUI_LevelButton*> AllLevelButton;
};
