// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/GameCore/TowerDefencePlayerController.h"

ATowerDefencePlayerController::ATowerDefencePlayerController()
{
	// 打开鼠标显示
	bShowMouseCursor = true;
	
}

void ATowerDefencePlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	float ScreenMoveSpeed = 20.f;
	ScreenMoveUnits.ListenScreenMove(this, ScreenMoveSpeed);
}

void ATowerDefencePlayerController::BeginPlay()
{
	Super::BeginPlay();
	SetInputModeGameAndUI();
}

void ATowerDefencePlayerController::SetInputModeGameAndUI()
{
	FInputModeGameAndUI InputMode;
	// 鼠标锁定到屏幕
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	// 鼠标一直显示
	InputMode.SetHideCursorDuringCapture(false);
	
	SetInputMode(InputMode);
}
