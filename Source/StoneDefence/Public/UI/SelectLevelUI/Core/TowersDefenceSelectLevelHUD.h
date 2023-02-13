// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/SelectLevelUI/UMG/UI_SelectLevelMain.h"
#include "TowersDefenceSelectLevelHUD.generated.h" 

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API ATowersDefenceSelectLevelHUD : public AHUD
{
	GENERATED_BODY()
public:
	ATowersDefenceSelectLevelHUD();

	virtual void BeginPlay() override;
private:
	TSubclassOf<UUI_SelectLevelMain> SelectLevelMainClass;
	class UUI_SelectLevelMain* SelectLevelMain;
};
