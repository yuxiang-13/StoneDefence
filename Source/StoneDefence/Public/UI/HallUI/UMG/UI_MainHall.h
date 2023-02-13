// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RuleOfTheWidget.h"
#include "UI_MainHall.generated.h" 

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_MainHall : public UUI_RuleOfTheWidget
{
	GENERATED_BODY()
	
	UPROPERTY(meta = (BindWidget))
	class UBorder *MainBoard;
	
	UPROPERTY(meta = (BindWidget))
	class USizeBox *BoxList;

	UPROPERTY(meta = (BindWidget))
	class UUI_HallMenuSystem *HallMenuSystem;

	// 存档
	UPROPERTY(EditDefaultsOnly, Category = UI)
	TSubclassOf<class UUI_ArchivesSystem> ArchivesSystemClass;

	// 游戏设置
	UPROPERTY(EditDefaultsOnly, Category = UI)
	TSubclassOf<class UUI_GameSettingsSystem> GameSettingsSystemlass;

	// 视频
	UPROPERTY(EditDefaultsOnly, Category = UI)
	TSubclassOf<class UUI_TutoriaSystem> TutoriaSystemClass;
public:
	// 初始化 类似 beginplay
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
	
	UFUNCTION()
	void BindSpecialContent();
	UFUNCTION()
	void BindSecretTerritory();
};
