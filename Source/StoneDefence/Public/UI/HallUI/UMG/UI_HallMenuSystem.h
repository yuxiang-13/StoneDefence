// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RuleOfTheWidget.h"
#include "UI_HallMenuSystem.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_HallMenuSystem : public UUI_RuleOfTheWidget
{
	GENERATED_BODY()
	
	UPROPERTY(meta = (BindWidget))
	UButton *GameStartButton;

	UPROPERTY(meta = (BindWidget))
	UButton *HistoryButton;

	UPROPERTY(meta = (BindWidget))
	UButton *GameSettingsButton; // 设置

	UPROPERTY(meta = (BindWidget))
	UButton *TutorialWebsiteButton; // 视频

	UPROPERTY(meta = (BindWidget))
	UButton *BrowserButton; // 打开浏览器

	UPROPERTY(meta = (BindWidget))
	UButton *QuitGameButton; // 退出
public:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void GameStart();
	UFUNCTION()
	void History();
	UFUNCTION()
	void GameSettings();
	UFUNCTION()
	void TutorialWebsite();
	UFUNCTION()
	void Browser();
	UFUNCTION()
	void QuitGame();
};
