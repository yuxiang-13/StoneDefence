// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CharacterCore/Monsters.h"

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
