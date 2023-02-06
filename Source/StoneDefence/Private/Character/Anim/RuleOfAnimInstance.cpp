// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Anim/RuleOfAnimInstance.h"
#include "Character/Core/RuleOfTheCharacter.h"

#if PLATFORM_WINDOWS
#pragma optimize("",off)
#endif



URuleOfAnimInstance::URuleOfAnimInstance()
	:bDeath(false),
	bAttack(false),
	Speed(0.0f)
{
}

void URuleOfAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	ARuleOfTheCharacter* RuleOfTheCharacter = Cast<ARuleOfTheCharacter>(TryGetPawnOwner());
	if (RuleOfTheCharacter)
	{
		
	}
}

void URuleOfAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	// 用于 监测
	if (ARuleOfTheCharacter* RuleOfTheCharacter = Cast<ARuleOfTheCharacter>(TryGetPawnOwner()))
	{
		bAttack = RuleOfTheCharacter->bAttack;
		Speed = RuleOfTheCharacter->GetVelocity().Size();
		if (!RuleOfTheCharacter->IsActive())
		{
			SetDeath(true);
		} else
		{
			SetDeath(false);
		}
	}
}

void URuleOfAnimInstance::SetDeath(bool InDeath)
{
	bDeath = InDeath;
}

#if PLATFORM_WINDOWS
#pragma optimize("",on)
#endif
