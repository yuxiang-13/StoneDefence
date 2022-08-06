// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTService_MonsterFIndTarget.generated.h"

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API UBTService_MonsterFIndTarget : public UBTService
{
	GENERATED_BODY()
public:
	virtual void OnGameplayTaskInitialized(UGameplayTask& Task) override;

	virtual void OnGameplayTaskActivated(UGameplayTask& Task) override;

	virtual void OnGameplayTaskDeactivated(UGameplayTask& Task) override;
};
