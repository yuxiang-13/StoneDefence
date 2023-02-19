// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"

class ARuleOfTheCharacter;

extern FGuid TowerICOGUID;

extern AActor *TowerDoll;

extern bool bLocalGUID;

// 被敲击的塔
extern ARuleOfTheCharacter *ClickedTargetTower;
// 被敲击的怪
extern  ARuleOfTheCharacter *ClickedTargetMonster;