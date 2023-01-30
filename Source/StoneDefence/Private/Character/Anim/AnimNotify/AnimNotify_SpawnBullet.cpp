// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Anim/AnimNotify/AnimNotify_SpawnBullet.h"

#include "Bullet/RuleOfTheBullet.h"
#include "Character/Core/RuleOfTheCharacter.h"
#include "Components/ArrowComponent.h"

UAnimNotify_SpawnBullet::UAnimNotify_SpawnBullet()
{
}

FString UAnimNotify_SpawnBullet::GetNotifyName_Implementation() const
{
	if (BulletClass)
	{
		return BulletClass->GetName();
	} else
	{
		return Super::GetNotifyName_Implementation();
	}
}

void UAnimNotify_SpawnBullet::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	// GetOuter 不是 GetOwner
	if (ARuleOfTheCharacter* Character = Cast<ARuleOfTheCharacter>(MeshComp->GetOuter()))
	{
		USceneComponent* Arrow = Character->GetFirePoint();

		FTransform Transform;
		Transform.SetLocation(Arrow->GetComponentLocation());
		Transform.SetRotation(Arrow->GetComponentRotation().Quaternion());
		
		FActorSpawnParameters ActorSpawnParameters;
		ActorSpawnParameters.Instigator = Character; // 施法者
		
		if (ARuleOfTheBullet* Bullet = Character->GetWorld()->SpawnActor<ARuleOfTheBullet>(BulletClass, Transform, ActorSpawnParameters))
		{
			
		}
	}
}
