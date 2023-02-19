// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RuleOfTheWidget.h"
#include "UI_MainScreen.generated.h" 

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_MainScreen : public UUI_RuleOfTheWidget
{
	GENERATED_BODY()

	// 菜单
	UPROPERTY(meta = (BindWidget))
	class UUI_GameMenuSystem* GameMenuSystem;

	// 打印
	UPROPERTY(meta = (BindWidget))
	class UUI_GameInfoPrintSystem* GameInfoPrintSystem;
	
	UPROPERTY(meta = (BindWidget))
	class UUI_MiniMapSystem* MiniMapSystem;

	// 任务
	UPROPERTY(meta = (BindWidget))
	class UUI_MissionSystem* MissionSystem;

	// 技能
	UPROPERTY(meta = (BindWidget))
	class UUI_PlayerSkillSystem* PlayerSkillSystem;

	// 背包
	UPROPERTY(meta = (BindWidget))
	class UUI_RucksackSystem* RucksackSystem;

	// 状态栏
	UPROPERTY(meta = (BindWidget))
	class UUI_ToolBarSystem* ToolBarSystem;

	// 怪物信息UI
	UPROPERTY(meta = (BindWidget))
	class UUI_TowerTip* CharacterTip;

	// 火力集中点
	UPROPERTY(meta = (BindWidget))
	class UImage* FireConcentrationPoint;
	
public:
	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	// 拖拽响应
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
};
