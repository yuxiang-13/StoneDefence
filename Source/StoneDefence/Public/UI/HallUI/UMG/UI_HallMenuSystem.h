// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
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
	
	UPROPERTY(meta = (BindWidget))
	UButton *SecretTerritoryButton;

	UPROPERTY(meta = (BindWidget))
	UButton *SpecialContentButton;
public:
	virtual void NativeConstruct() override;

	void BindGameStart(FOnButtonClickedEvent ClickedEvent);
	void BindSecretTerritory(FOnButtonClickedEvent ClickedEvent);
	void BindHistory(FOnButtonClickedEvent ClickedEvent);
	void BindGameSettings(FOnButtonClickedEvent ClickedEvent);
	void BindTutorialWebsite(FOnButtonClickedEvent ClickedEvent);
	void BindBrowser(FOnButtonClickedEvent ClickedEvent);
	void BindSpecialContent(FOnButtonClickedEvent ClickedEvent);
	void BindQuitGame(FOnButtonClickedEvent ClickedEvent);
};
