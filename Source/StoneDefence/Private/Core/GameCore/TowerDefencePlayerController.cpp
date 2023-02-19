// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/GameCore/TowerDefencePlayerController.h"

#include "Core/GameCore/TowerDefenceGameCamera.h"
#include "Kismet/KismetSystemLibrary.h"
#include "UI/GameUI/UMG/Inventory/UI_Data1.h"

ATowerDefencePlayerController::ATowerDefencePlayerController()
{
	// 打开鼠标显示
	bShowMouseCursor = true;

	// 打开事件敲击
	bEnableClickEvents = true;
	
}

void ATowerDefencePlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	float ScreenMoveSpeed = 20.f;
	ScreenMoveUnits.ListenScreenMove(this, ScreenMoveSpeed);
	
	// 是否正在拖拽 塔
	if (TowerDoll)
	{
		if (MouseTaceHit.Location != FVector::ZeroVector)
		{
			MouseTaceHit = FHitResult();
		}
		/*
		 *UE C++获取鼠标点击
		* 只要是继承于ACharacter或APawn类的，都可以把Controller转换成APlayerController来用GetHitResultUnderCursor这个函数，
		* 本质上其实是射线检测GetWorld()->LineTraceSingleByChannel，只是做了很多安全判断，比如保证获得玩家屏幕，保证点击的不是UI。
		* 通过Hit传引用进去，传结果出来。Hit.bBlockingHit代表检测到了物体
		*
		* [ˈkɜːrsər] 鼠标;鼠标指针
		 */
		// 检测
		FHitResult TaceOutHit;	
		GetHitResultUnderCursor(ECollisionChannel::ECC_GameTraceChannel4, true, TaceOutHit);
		TowerDoll->SetActorLocation(TaceOutHit.Location);
		
	} else // 是否 点击怪物详情 TODO:
	{
		// 鼠标检测  把检测到的怪物 复制到 MouseTaceHit
		GetHitResultUnderCursor(ECollisionChannel::ECC_GameTraceChannel5, true, MouseTaceHit);
	}
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
	InputComponent->BindAction("MouseMiddleButton", IE_Released, this, &ATowerDefencePlayerController::MouseMiddleButtonRelease);
}

void ATowerDefencePlayerController::MouseMiddleButtonPresed()
{
	EventMouseMiddlePressed.ExecuteIfBound();
}

void ATowerDefencePlayerController::MouseMiddleButtonRelease()
{
	EventMouseMiddleReleased.ExecuteIfBound();
}

const FHitResult& ATowerDefencePlayerController::GetHitResult()
{
	return MouseTaceHit;
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
