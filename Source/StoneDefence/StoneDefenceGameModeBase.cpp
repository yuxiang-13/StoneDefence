// Copyright Epic Games, Inc. All Rights Reserved.


#include "StoneDefenceGameModeBase.h"

#include "Core/GameCore/TowerDefenceGameState.h"
#include "Core/GameCore/TowerDefencePlayerController.h"
#include "Core/GameCore/TowerDefencePlayerState.h"
#include "Core/GameCore/TowerDefenceGameCamera.h"
#include "UI/GameUI/Core/RuleOfTheHUD.h"

AStoneDefenceGameModeBase::AStoneDefenceGameModeBase()
{
	//加载我们的GameState
	GameStateClass = ATowerDefenceGameState::StaticClass();
	//加载我们的Controller
	PlayerControllerClass = ATowerDefencePlayerController::StaticClass();
	//加载我们ControllerPawn
	DefaultPawnClass = ATowerDefenceGameCamera::StaticClass();
	//加载我们的PlayerState
	PlayerStateClass = ATowerDefencePlayerState::StaticClass();
	//加载我们的HUD
	HUDClass = ARuleOfTheHUD::StaticClass();
}
