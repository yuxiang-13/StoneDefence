// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_SpawnBullet.generated.h" 

/**
 * 
 */
UCLASS(const, hidecategories=Object, collapsecategories, Config = Game, meta=(DisplayName="Spawn Buttle"))
class STONEDEFENCE_API UAnimNotify_SpawnBullet : public UAnimNotify
{
	GENERATED_BODY()
public:
	UAnimNotify_SpawnBullet();
	
	virtual FString GetNotifyName_Implementation() const override;
	
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AnimNotify", meta=(ExposeOnSpawn = true))
	TSubclassOf<class ARuleOfTheBullet> BulletClass;
};
