// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Core/RuleOfTheCharacter.h"

#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "Data/Core/CharacterData.h"

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

	return 0;
}

bool ARuleOfTheCharacter::IsDeath()
{
	return GetHealth() <= 0.0f;
}

float ARuleOfTheCharacter::GetHealth()
{
	return GetCharacterData().MaxHealth;
}

float ARuleOfTheCharacter::GetMaxHealth()
{
	return GetCharacterData().Health;
}

bool ARuleOfTheCharacter::IsTeam()
{
	return false;
}

EGameCharacterType::Type ARuleOfTheCharacter::GetType()
{
	return EGameCharacterType::Type::MAX;
}

const FCharacterData& ARuleOfTheCharacter::GetCharacterData()
{
	if (GetGameState())
	{
		return GetGameState()->GetCharacterData(GUID);
	}
	// ATowerDefenceGameState 中 定义了这个变量
	return CharacterDataNULL;
};
