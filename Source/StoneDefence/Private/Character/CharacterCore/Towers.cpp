// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CharacterCore/Towers.h"

#include "ChaosBlueprint.h"
#include "DestructibleComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "UI/GameUI/UMG/Inventory/UI_Data1.h"

ATowers::ATowers()
{
	ParticleMesh = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleMesh"));
	StaticMeshBuilding = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RangeBuilding"));
	DestructibleMeshBuilding = CreateDefaultSubobject<UDestructibleComponent>(TEXT("Subsitute"));

	StaticMeshBuilding->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	DestructibleMeshBuilding->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	ParticleMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

float ATowers::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator,
                          AActor* DamageCauser)
{
	Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);

	return 0;
}

void ATowers::OnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
	Super::OnClicked(TouchedComponent, ButtonPressed);

	if (ClickedTargetTower == nullptr)
	{
		ClickedTargetTower = this;
	} else
	{
		ClickedTargetTower = nullptr;
	}
}

EGameCharacterType::Type ATowers::GetType()
{
	return EGameCharacterType::Type::TOWER;
}

bool ATowers::IsTeam()
{
	return true;
};
