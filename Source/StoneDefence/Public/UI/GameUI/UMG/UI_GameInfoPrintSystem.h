// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RuleOfTheWidget.h"
#include "UI_GameInfoPrintSystem.generated.h" 

class UTextBlock;
/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_GameInfoPrintSystem : public UUI_RuleOfTheWidget
{
	GENERATED_BODY()
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TDGameLog;

public:

	virtual void NativeConstruct()override;
};
