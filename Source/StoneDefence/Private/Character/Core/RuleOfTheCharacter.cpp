// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Core/RuleOfTheCharacter.h"

#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "Core/GameCore/TowerDefenceGameState.h"
#include "Data/Core/CharacterData.h"
#include "UI/Character/UI_Health.h"

// Sets default values
ARuleOfTheCharacter::ARuleOfTheCharacter(): bAttack(false)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HomingPoint = CreateDefaultSubobject<USceneComponent>(TEXT("HomePoint"));
	HomingPoint = RootComponent;
	
	Widget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	OpenFirePoint = CreateDefaultSubobject<UArrowComponent>(TEXT("OpenFilePoint"));
	TraceShowCharacterInformation = CreateDefaultSubobject<UBoxComponent>(TEXT("TraceShowCharacterInformation"));

	Widget->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	OpenFirePoint->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	TraceShowCharacterInformation->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	// 设置 碰撞
	TraceShowCharacterInformation->SetCollisionProfileName("Scanning");
	TraceShowCharacterInformation->SetBoxExtent(FVector(38.f, 38.f, 100.f));
}

// Called when the game starts or when spawned
void ARuleOfTheCharacter::BeginPlay()
{
	Super::BeginPlay();

	// 生成默认 controller
	if (!GetController())
	{
		SpawnDefaultController();
	}
	UpdateUI();
}

// Called every frame
void ARuleOfTheCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float ARuleOfTheCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	GetCharacterData().Health -= DamageAmount / 10.f;
	UpdateUI();
	return 0;
}

void ARuleOfTheCharacter::UpdateUI()
{
	if (Widget)
	{
		if (UUI_Health* HealthUI = Cast<UUI_Health>(Widget->GetUserWidgetObject()))
		{
			HealthUI->SetTitle(GetCharacterData().Name.ToString());
			HealthUI->SetHealth(GetHealth() / GetMaxHealth());
		}
	}
}

bool ARuleOfTheCharacter::IsDeath()
{
	return GetHealth() <= 0.0f;
}

float ARuleOfTheCharacter::GetHealth()
{
	return GetCharacterData().Health;
}

float ARuleOfTheCharacter::GetMaxHealth()
{
	return GetCharacterData().MaxHealth;
}

bool ARuleOfTheCharacter::IsTeam()
{
	return false;
}

EGameCharacterType::Type ARuleOfTheCharacter::GetType()
{
	return EGameCharacterType::Type::MAX;
}

FCharacterData& ARuleOfTheCharacter::GetCharacterData()
{
	if (GetGameState())
	{
		return GetGameState()->GetCharacterData(GetUniqueID());
	}
	// ATowerDefenceGameState 中 定义了这个变量
	return CharacterDataNULL;
};
