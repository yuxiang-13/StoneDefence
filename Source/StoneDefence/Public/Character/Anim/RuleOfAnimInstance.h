// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "RuleOfAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API URuleOfAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	URuleOfAnimInstance();
	
	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable)
	void SetDeath(bool InDeath);

	// UPROPERTY(BlueprintCallable, Category="Anim")
	// void SetAttack(bool InAttack);
	//
	// UPROPERTY(BlueprintCallable, Category="Anim")
	// void SetSpeed(float InSpeed);
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="AnimAttrubute")
		bool bDeath;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="AnimAttrubute")
		bool bAttack;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="AnimAttrubute")
		float Speed;
};
