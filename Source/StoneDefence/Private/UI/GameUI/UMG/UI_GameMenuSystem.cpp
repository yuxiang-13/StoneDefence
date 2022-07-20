// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GameUI/UMG/UI_GameMenuSystem.h"

#include "Components/Button.h"

void UUI_GameMenuSystem::NativeConstruct()
{
	Super::NativeConstruct();
	
	ReturnGameButton		->OnClicked.AddDynamic(this, &UUI_GameMenuSystem::BindReturnGame);
	SaveGameButton			->OnClicked.AddDynamic(this, &UUI_GameMenuSystem::BindSaveGame);
	SaveSettingsButton		->OnClicked.AddDynamic(this, &UUI_GameMenuSystem::BindSaveSettings);
	GameQuitButton			->OnClicked.AddDynamic(this, &UUI_GameMenuSystem::GameQuit);
}

void UUI_GameMenuSystem::BindSaveGame()
{
}

void UUI_GameMenuSystem::BindSaveSettings()
{
}

void UUI_GameMenuSystem::BindReturnGame()
{
}

void UUI_GameMenuSystem::GameQuit()
{
}
