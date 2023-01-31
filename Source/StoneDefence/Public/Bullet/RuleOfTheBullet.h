// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/Core/RuleOfTheCharacter.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "StoneDefence/StoneDefenceType.h"
#include "RuleOfTheBullet.generated.h"

UCLASS()
class STONEDEFENCE_API ARuleOfTheBullet : public AActor
{
	GENERATED_BODY()
	
	//子弹碰撞盒子
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttrubute", meta = (AllowPrivateAccess = "true"))
	class USphereComponent* BoxDamage;
 
	//作为根组件
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttrubute", meta = (AllowPrivateAccess = "true"))
	class USceneComponent* RootBullet;
	
public:
	UPROPERTY(EditDefaultsOnly, Category="Bullet")
	TEnumAsByte<EBulletType> BulletType;

	// 子弹的伤害特效(碰撞特效)
	UPROPERTY(EditDefaultsOnly, Category="Bullet")
	class UParticleSystem* DamgageParticle;
	// 开火 特效
	UPROPERTY(EditDefaultsOnly, Category="Bullet")
	class UParticleSystem* OpenFireParticle;

	
	UPROPERTY(EditDefaultsOnly, Category="BULLET TRACK LINE SP")
	float SplineOffset;
	
	// Sets default values for this actor's properties
	ARuleOfTheBullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	void RadialDamage(const FVector& Origin, ARuleOfTheCharacter* InstigatorCharacter);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UProjectileMovementComponent* ProjectileMovement;
private:
	UPROPERTY()
	class USplineComponent *Spline;
	float CurrentSplineTime;
};
