// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RuleOfTheWidget.h"
#include "UI_ICODragDrog.generated.h"

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_ICODragDrog : public UUI_RuleOfTheWidget
{
	GENERATED_BODY()

	// 拖拽时塔的图标
	UPROPERTY(meta=(BindWidget))
	class UImage *Icon;

public:
	// 设置图片
	void DrawIcon(UTexture2D *InIcon);
	
};
