// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/Core/RuleOfTheCharacter.h"
#include "Monsters.generated.h"

/**
 * 怪物
 */
UCLASS()
class STONEDEFENCE_API AMonsters : public ARuleOfTheCharacter
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual bool IsTeam(); 
	
	virtual EGameCharacterType::Type GetType();
};
