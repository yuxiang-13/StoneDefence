// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tool/ScreenMove.h"
#include "TowerDefencePlayerController.generated.h" 

/**
 * 
 */
UCLASS()
class STONEDEFENCE_API ATowerDefencePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	// 按下鼠标中键
	FSimpleDelegate EventMouseMiddlePressed;
	// 松开鼠标中键
	FSimpleDelegate EventMouseMiddleReleased;
public:
	//构建我们的函数
	ATowerDefencePlayerController();

	//Tick 如同类的心脏
	virtual void Tick(float DeltaSeconds)override;

	//初始化我们的操作
	virtual void BeginPlay()override;

	
	//***********************************控制函数***********************************
	/** 允许玩家自己更新自己的绑定响应. */
	virtual void SetupInputComponent()override;

	//鼠标滚轮控制
	void MouseWheelUp();
	void MouseWheelDown();
public:
	// 锁定鼠标
	void SetInputModeGameAndUI();

	// 鼠标中键按下松开
	void MouseMiddleButtonPresed();
	void MouseMiddleButtonRelease();
protected:
	
	FScreenMoveUnits ScreenMoveUnits;
};
