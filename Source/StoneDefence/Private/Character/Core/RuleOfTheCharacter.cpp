// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Core/RuleOfTheCharacter.h"

#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "Core/GameCore/TowerDefenceGameState.h"
#include "Damage/DrawText.h"
#include "Data/Core/CharacterData.h"
#include "Kismet/KismetSystemLibrary.h"
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
	
	//DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams( FComponentOnClickedSignature, UPrimitiveComponent, OnClicked, UPrimitiveComponent*, TouchedComponent , FKey, ButtonPressed);
	TraceShowCharacterInformation->OnClicked.AddDynamic(this, &ARuleOfTheCharacter::OnClicked);
}

void ARuleOfTheCharacter::OnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
	// UKismetSystemLibrary::PrintString(this, TEXT("- - ->>>>111"), true, true, FLinearColor::Red, 10.f);
	
}


// Called every frame
void ARuleOfTheCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateUI();
}

float ARuleOfTheCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	
	auto DrawGameTest = [&](ARuleOfTheCharacter *InOwner, FStringFormatNamedArguments NamedArgs, float InDamgageValue, FLinearColor InColor)
	{
		if (DrawTextClass)
		{
			if (ADrawText* MyValueText = GetWorld()->SpawnActor<ADrawText>(DrawTextClass, InOwner->GetActorLocation(), FRotator::ZeroRotator))
			{
				const FString DamageText = FString::Format(TEXT("{Var1}  {Var2}"), NamedArgs);
				
				MyValueText->SetTextBlock(DamageText, InColor, InDamgageValue / InOwner->GetCharacterData().MaxHealth);
			}
		}
	};

	float DamageValue = Expression::GetDamage(Cast<ARuleOfTheCharacter>(DamageCauser), this);
	
	GetCharacterData().Health -= DamageValue;
	
	FCharacterData InCharacterData = GetCharacterData();
	if (InCharacterData.IsValid())
	{
		if (!IsActive())
		{
			GetCharacterData().Health = 0.0f;
			SetLifeSpan(3.0f);

			Widget->SetVisibility(false);

			// 谁杀死我，谁得到我提供的最懂经验
			if (ARuleOfTheCharacter*CauserCharacter = Cast<ARuleOfTheCharacter>(DamageCauser))
			{
				if (CauserCharacter->IsActive())
				{
					if (CauserCharacter->GetCharacterData().UpdateLevel(InCharacterData.AddEmpiricalValue))
					{
					
					}

					FStringFormatNamedArguments NamedArgs1;
					NamedArgs1.Add(TEXT("Var1"), "+EP ");
					NamedArgs1.Add(TEXT("Var2"),   FString::Printf(TEXT("%0.f"), GetCharacterData().AddEmpiricalValue));
				
					// 添加经验值
					DrawGameTest(CauserCharacter, NamedArgs1, InCharacterData.AddEmpiricalValue, FLinearColor::Yellow);
				}
				// 寻找范围内最近敌人 给加0.3倍经验减半
				TArray<ARuleOfTheCharacter*> EnemyCharacters;
				StoneDefenceUtils::FindRangeTargetRecently(this, 1000.f, EnemyCharacters);
				for (ARuleOfTheCharacter* InEnemy : EnemyCharacters)
				{
					if (InEnemy != CauserCharacter)
					{
						if (InEnemy->IsActive())
						{
							if (InEnemy->GetCharacterData().UpdateLevel(InCharacterData.AddEmpiricalValue * 0.3f))
							{
					
							}
							FStringFormatNamedArguments NamedArgs2;
							NamedArgs2.Add(TEXT("Var1"), "+EP ");
							NamedArgs2.Add(TEXT("Var2"),   FString::Printf(TEXT("%0.f"), GetCharacterData().AddEmpiricalValue));
							DrawGameTest(InEnemy, NamedArgs2, InCharacterData.AddEmpiricalValue, FLinearColor::Yellow);
						}
					}
				}
			}

			GetGameState()->RemoveCharacterData(GUID);
		}
		FStringFormatNamedArguments NamedArgs3;
		NamedArgs3.Add(TEXT("Var1"), " ");
		NamedArgs3.Add(TEXT("Var2"),   FString::Printf(TEXT("%0.f"), DamageValue));
		// 产生伤害字体 TEXT("-%0.f")
		DrawGameTest(this, NamedArgs3, DamageValue, FLinearColor::Red);
	}
	
	
	return DamageValue;
}

void ARuleOfTheCharacter::UpdateUI()
{
	if (Widget)
	{
		if (GetCharacterData().IsValid())
		{
			if (UUI_Health* HealthUI = Cast<UUI_Health>(Widget->GetUserWidgetObject()))
			{
				HealthUI->SetTitle(GetCharacterData().Name.ToString());
				HealthUI->SetHealth(GetHealth() / GetMaxHealth());
			}
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