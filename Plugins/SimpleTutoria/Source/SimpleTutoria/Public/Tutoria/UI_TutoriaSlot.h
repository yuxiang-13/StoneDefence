// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/UI_TutoriaBase.h"
#include "UI_TutoriaSlot.generated.h"

class UButton;
class UMediaSource;
/**
 * 
 */
UCLASS()
class SIMPLETUTORIA_API UUI_TutoriaSlot : public UUI_TutoriaBase
{
	GENERATED_BODY()
public:
	// 载入视频源
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=UI)
	UMediaSource* MediaSource;
};
