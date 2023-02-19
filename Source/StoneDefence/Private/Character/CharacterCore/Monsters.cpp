// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CharacterCore/Monsters.h"

#include "UI/GameUI/UMG/Inventory/UI_Data1.h"

void AMonsters::BeginPlay()
{
	Super::BeginPlay();
}

void AMonsters::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

bool AMonsters::IsTeam()
{
	return false;
}

EGameCharacterType::Type AMonsters::GetType()
{
	return EGameCharacterType::Type::MONSTER;
}

void AMonsters::OnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
	Super::OnClicked(TouchedComponent, ButtonPressed);
	
	if (ClickedTargetMonster == nullptr)
	{
		ClickedTargetMonster = this;
	} else
	{
		ClickedTargetMonster = nullptr;
	}
}
