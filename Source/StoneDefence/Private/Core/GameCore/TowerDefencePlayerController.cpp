// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/GameCore/TowerDefencePlayerController.h"

#include "Core/GameCore/TowerDefenceGameCamera.h"

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


void ATowerDefencePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	//鼠标滚轮
	InputComponent->BindAction("MouseWheelUp", IE_Pressed, this, &ATowerDefencePlayerController::MouseWheelUp);
	InputComponent->BindAction("MouseWheelDown", IE_Pressed, this, &ATowerDefencePlayerController::MouseWheelDown);

	InputComponent->BindAction("MouseMiddleButton", IE_Pressed, this, &ATowerDefencePlayerController::MouseMiddleButtonPresed);
	InputComponent->BindAction("MouseMiddleButton", IE_Pressed, this, &ATowerDefencePlayerController::MouseMiddleButtonRelease);
}

void ATowerDefencePlayerController::MouseMiddleButtonPresed()
{
	EventMouseMiddlePressed.ExecuteIfBound();
}

void ATowerDefencePlayerController::MouseMiddleButtonRelease()
{
	EventMouseMiddleReleased.ExecuteIfBound();
}

static float WheelValue = 15.f;
void ATowerDefencePlayerController::MouseWheelUp()
{
	ATowerDefenceGameCamera* ZoomCamera = Cast<ATowerDefenceGameCamera>(GetPawn());
	if (ZoomCamera)
	{
		ZoomCamera->Zoom(true, WheelValue);
	}
}

void ATowerDefencePlayerController::MouseWheelDown()
{
	ATowerDefenceGameCamera* ZoomCamera = Cast<ATowerDefenceGameCamera>(GetPawn());
	if (ZoomCamera)
	{
		ZoomCamera->Zoom(false, WheelValue);
	}
}
