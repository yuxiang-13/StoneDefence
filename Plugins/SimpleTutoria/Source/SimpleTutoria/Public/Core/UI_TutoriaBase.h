// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_TutoriaBase.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLETUTORIA_API UUI_TutoriaBase : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UWidgetAnimation* GetNameWidgetAnimation(const FString& WidgetAnimationName) const;
};
