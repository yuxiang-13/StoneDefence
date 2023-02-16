// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Core/RuleOfTheCharacter.h"

#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "Core/GameCore/TowerDefenceGameState.h"
#include "Damage/DrawText.h"
#include "Data/Core/CharacterData.h"
#include "Particles/ParticleEmitter.h"
#include "Particles/ParticleLODLevel.h"
#include "StoneDefence/StoneDefenceUtils.h"
#include "UI/Character/UI_Health.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/TypeData/ParticleModuleTypeDataMesh.h"

#if PLATFORM_WINDOWS
#pragma optimize("",off)
#endif

// Sets default values
ARuleOfTheCharacter::ARuleOfTheCharacter(): bAttack(false)
{
	GUID = FGuid::NewGuid();
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
	
	float DamageValue = Expression::GetDamage(Cast<ARuleOfTheCharacter>(DamageCauser), this);
	
	GetCharacterData().Health -= DamageValue;
	if (!IsActive())
	{
		GetCharacterData().Health = 0.0f;
	}
	
	// 产生伤害字体
	if (DrawTextClass)
	{
		if (ADrawText *MyValueText = GetWorld()->SpawnActor<ADrawText>(DrawTextClass, GetActorLocation(), FRotator::ZeroRotator))
		{
			FString DamageText = FString::Printf(TEXT("-%0.f"), DamageValue);
			MyValueText->SetTextBlock(DamageText, FLinearColor::Red, DamageValue / GetCharacterData().MaxHealth);
		}
	}
	
	UpdateUI();
	return DamageValue;
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


bool ARuleOfTheCharacter::IsActive()
{
	if (!IsDeath())
	{
		return true;
	} else
	{
		return false;
	}
}




bool ARuleOfTheCharacter::IsDeath()
{
	if (GetHealth() <= 0.f)
	{
		return true;
	} else
	{
		return false;
	}
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
		return GetGameState()->GetCharacterData(GUID);
	}
	// ATowerDefenceGameState 中 定义了这个变量
	return CharacterDataNULL;
}

UStaticMesh* ARuleOfTheCharacter::GetDollMesh()
{
	TArray<USceneComponent*> SceneComponent;
	RootComponent->GetChildrenComponents(true, SceneComponent);
	for (auto &Tmp: SceneComponent)
	{
		if (Tmp->IsA(UStaticMeshComponent::StaticClass()))
		{
			if (UStaticMeshComponent *NewStaticMeshComponent = Cast<UStaticMeshComponent>(Tmp))
			{
				if (NewStaticMeshComponent->GetStaticMesh())
				{
					return NewStaticMeshComponent->GetStaticMesh();
				}
			}
		}
		else if (Tmp->IsA(UParticleSystemComponent::StaticClass()))
		{
			UParticleSystemComponent * NewParticleSystemComponent = Cast<UParticleSystemComponent>(Tmp);
			// 粒子中获取mesh
			if (NewParticleSystemComponent->Template && NewParticleSystemComponent->Template->Emitters.Num() > 0)
			{
				for (const UParticleEmitter *Tmp111 : NewParticleSystemComponent->Template->Emitters)
				{
					if (Tmp111->LODLevels[0]->bEnabled)
					{
						if (UParticleModuleTypeDataMesh* MyUParticleModuleTypeDataMesh = Cast<UParticleModuleTypeDataMesh>(Tmp111->LODLevels[0]->TypeDataModule))
						{
							return MyUParticleModuleTypeDataMesh->Mesh;
						}
					}
				}
			}
		}
		else if (Tmp->IsA(USkeletalMeshComponent::StaticClass()))
		{
			
		}

	}
	return NULL;
}

ATowerDefenceGameState* ARuleOfTheCharacter::GetGameState()
{
	return GetWorld() ? GetWorld()->GetGameState<ATowerDefenceGameState>() : nullptr; 
}

#if PLATFORM_WINDOWS
#pragma optimize("",on)
#endif