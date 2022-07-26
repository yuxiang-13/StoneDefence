// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Core/RuleOfTheCharacter.h"

#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"

// Sets default values
ARuleOfTheCharacter::ARuleOfTheCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	HomingPoint = CreateDefaultSubobject<USceneComponent>(TEXT("HomePoint"));
	Widget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	OpenFirePoint = CreateDefaultSubobject<UArrowComponent>(TEXT("OpenFilePoint"));
	TraceShowCharacterInformation = CreateDefaultSubobject<UBoxComponent>(TEXT("TraceShowCharacterInformation"));

	HomingPoint->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
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
	return false;
}

float ARuleOfTheCharacter::GetHealth()
{
	return 0.0f;
}

float ARuleOfTheCharacter::GetMaxHealth()
{
	return 0.0f;
}

bool ARuleOfTheCharacter::IsTream()
{
	return false;
}
