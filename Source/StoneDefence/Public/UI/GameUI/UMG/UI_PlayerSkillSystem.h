// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Core/UI_RuleOfTheWidget.h"
#include "UI_PlayerSkillSystem.generated.h" 

class UUI_SkillSlot;
/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UUI_PlayerSkillSystem : public UUI_RuleOfTheWidget
{
	GENERATED_BODY()

	UPROPERTY(meta=(BindWidget))
	UUI_SkillSlot *FreezeSkill;

	UPROPERTY(meta = (BindWidget))
	UUI_SkillSlot *ExplosionSkill;

	// 回复所有塔 血
	UPROPERTY(meta = (BindWidget))
	UUI_SkillSlot *RecoverySkill;

	// 回复水晶血
	UPROPERTY(meta = (BindWidget))
	UUI_SkillSlot *RecoveryMainTowersSkill;
	
public:
	virtual void NativeConstruct() override;
	
private:
	FKey FreezeSkillKey;
	FKey ExplosionSkillKey;
	FKey RecoverySkillKey;
	FKey RecoveryMainTowersSkillKey;
};
