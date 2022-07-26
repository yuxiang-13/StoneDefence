// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/GameCore/TowerDefenceGameState.h"
#include "Core/GameCore/TowerDefencePlayerController.h"
#include "GameFramework/Character.h"
#include "Interface/Character/IRuleCharacter.h"
#include "RuleOfTheCharacter.generated.h"

UCLASS()
class STONEDEFENCE_API ARuleOfTheCharacter : public ACharacter, public IRuleCharacter
{
	GENERATED_BODY()
private:
	// 让射线 捕捉 对象
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttrubute", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent *TraceShowCharacterInformation;
	// 开火点
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttrubute", meta = (AllowPrivateAccess = "true"))
	class UArrowComponent *OpenFirePoint;
	// UMG
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttrubute", meta = (AllowPrivateAccess = "true"))
	class UWidgetComponent *Widget;
	// 跟踪点
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttrubute", meta = (AllowPrivateAccess = "true"))
	class USceneComponent *HomingPoint;
	
public:
	// Sets default values for this character's properties
	ARuleOfTheCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// 承伤
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	
public:	
	virtual bool IsDeath();
	virtual float GetHealth();
	virtual float GetMaxHealth();
	virtual bool IsTream();

	// 获取游戏控制器 的接口
	FORCEINLINE ATowerDefencePlayerController* GetGameController() { return GetWorld() ? GetWorld()->GetFirstPlayerController<ATowerDefencePlayerController>() : nullptr; };

	// 获取 GameState 的接口
	FORCEINLINE ATowerDefenceGameState* GetGameState() { return GetWorld() ? GetWorld()->GetGameState<ATowerDefenceGameState>() : nullptr; };

	// 获取跟踪点，为子弹做准备
	FORCEINLINE USceneComponent* GetHomingPoint() const {return HomingPoint; };
	FORCEINLINE UArrowComponent* GetFirePoint() const {return OpenFirePoint; };
};
