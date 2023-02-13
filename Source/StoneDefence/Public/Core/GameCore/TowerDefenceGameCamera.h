// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TowerDefenceGameCamera.generated.h" 

UCLASS()
class STONEDEFENCE_API ATowerDefenceGameCamera : public APawn
{
	GENERATED_BODY()
private:
	//控制我们摄像机离场景的距离
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
	
	//主摄像机
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* MianCamera;

	//摄像机的碰撞标识
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* MarkBox;
public:
	// Sets default values for this character's properties
	ATowerDefenceGameCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	void Zoom(bool bDirection, float ZoomSpeed);
};
