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
	
	UPROPERTY(meta=(BindWidget))
	UButton *PlayButton;
public:
	UUI_TutoriaSlot(const FObjectInitializer& ObjectInitializer);

	UPROPERTY()
	FString TutoriaPath;

	bool IsIndexValid();

	UFUNCTION()
	void Play();
protected:
	virtual void NativeConstruct() override;
};
