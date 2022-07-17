// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HallUI/Core/TowerDefenceHallHUD.h"

ATowerDefenceHallHUD::ATowerDefenceHallHUD()
{
	// HUD这个类中，实例化userwidget
	static ConstructorHelpers::FClassFinder<UUI_MainHall> HallMain_BPClass(TEXT("/Game/UI/Hall/HallMain_BP"));
	MainHallClass = HallMain_BPClass.Class;
}

void ATowerDefenceHallHUD::BeginPlay()
{
	Super::BeginPlay();

	MainHall = CreateWidget<UUI_MainHall>(GetWorld(), MainHallClass);
	MainHall->AddToViewport();
}
