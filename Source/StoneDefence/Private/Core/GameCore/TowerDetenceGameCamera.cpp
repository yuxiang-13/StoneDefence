// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/GameCore/TowerDetenceGameCamera.h"

// Sets default values
ATowerDetenceGameCamera::ATowerDetenceGameCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATowerDetenceGameCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATowerDetenceGameCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATowerDetenceGameCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

