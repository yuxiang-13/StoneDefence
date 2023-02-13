// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/Core/RuleOfTheCharacter.h"
#include "Towers.generated.h" 

/**
 *  塔
 */
UCLASS()
class STONEDEFENCE_API ATowers : public ARuleOfTheCharacter
{
	GENERATED_BODY()

	// 特效
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttrubute", meta = (AllowPrivateAccess = "true"))
	class UParticleSystemComponent* ParticleMesh;
	// 静态模型（可建筑 范围）
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttrubute", meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent *StaticMeshBuilding;
	// 破碎组件
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttrubute", meta = (AllowPrivateAccess = "true"))
	class UDestructibleComponent *DestructibleMeshBuilding;
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttrubute")
	FRotator TowersRotator;
public:
	ATowers();

	
	virtual EGameCharacterType::Type GetType();
	virtual bool IsTeam(); 
protected:

	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	
};
