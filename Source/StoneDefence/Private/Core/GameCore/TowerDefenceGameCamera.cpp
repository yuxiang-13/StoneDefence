// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/GameCore/TowerDefenceGameCamera.h"

#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ATowerDefenceGameCamera::ATowerDefenceGameCamera()
{
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	MianCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MianCamera"));
	MarkBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Sign"));

	//绑定我们组件
	CameraBoom->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	MianCamera->AttachToComponent(CameraBoom, FAttachmentTransformRules::KeepRelativeTransform);
	MarkBox->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform); 


	//控制我们摄像机的角距离地面的长度
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));

	MarkBox->SetCollisionProfileName(TEXT("ControllerPawnProfile"));
}

// Called when the game starts or when spawned
void ATowerDefenceGameCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATowerDefenceGameCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATowerDefenceGameCamera::Zoom(bool bDirection, float ZoomSpeed)
{
	if (bDirection)
	{
		if (CameraBoom->TargetArmLength > 400)
		{
			CameraBoom->TargetArmLength -= ZoomSpeed * 2;
		}
	}
	else
	{
		if (CameraBoom->TargetArmLength < 800)
		{
			CameraBoom->TargetArmLength += ZoomSpeed * 2;
		}
	}
}

