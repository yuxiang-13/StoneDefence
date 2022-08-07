// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/Core/RuleOfTheAIController.h"
#include "TowersAIController.generated.h"

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API ATowersAIController : public ARuleOfTheAIController
{
	GENERATED_BODY()
public:
	ATowersAIController();
	
	virtual void Tick(float DeltaSeconds) override;
	
	virtual AActor* FindTarget() override;

protected:
	void BTService_FindTarget();

	// 这里存放怪物
	UPROPERTY()
	TArray<class ARuleOfTheCharacter*> TArrayMonsters;
	
	// 心跳
	float HeartbeatDiagnosis;
	
	// 目标对象
	TWeakObjectPtr<class ARuleOfTheCharacter> Target;
};
