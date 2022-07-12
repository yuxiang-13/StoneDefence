// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Bullet/RuleIfTheBullet.h"

// Sets default values
ARuleIfTheBullet::ARuleIfTheBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARuleIfTheBullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARuleIfTheBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

