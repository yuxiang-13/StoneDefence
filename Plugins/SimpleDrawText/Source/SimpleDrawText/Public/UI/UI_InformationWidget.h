// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_InformationWidget.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEDRAWTEXT_API UUI_InformationWidget : public UUserWidget
{
	GENERATED_BODY()
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* TextWidget;

public:
	// 设置字体样式，颜色 大小
	void SetTextBlockStyle(const FString &InText,const FLinearColor& Color, float Percentage);
};
