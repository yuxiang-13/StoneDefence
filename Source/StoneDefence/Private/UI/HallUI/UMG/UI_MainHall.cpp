// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HallUI/UMG/UI_MainHall.h"

#include "UI_ArchivesSystem.h"
#include "UI_GameSettingsSystem.h"
#include "UI_TutoriaSystem.h"
#include "Components/Button.h"
#include "Components/SizeBox.h"
#include "Kismet/GameplayStatics.h"
#include "UI/HallUI/UMG/UI_HallMenuSystem.h"

// 切换UI
template<class T,class UserObject>
UserObject* CreateAssistWidget(T* ThisClass, UClass *AssisClass, USizeBox *WidgetArray)
{
	UserObject *UserObjectElement = nullptr;
	// 播放动画的 判断
	if (0)
	{
			// 播放 Board 淡入
	}

	if (WidgetArray->GetChildAt(0))
	{
		if (WidgetArray->GetChildAt(0)->IsA(AssisClass))
		{
			// 播放 Board 淡出

			return UserObjectElement;
		} else
		{
			WidgetArray->ClearChildren();
		}
	}

	UserObjectElement = CreateWidget<UserObject>(ThisClass->GetWorld(), AssisClass);
	if (UserObjectElement)
	{
		if (WidgetArray->AddChild(UserObjectElement))
		{
			//
		} else
		{
			UserObjectElement->RemoveFromParent();
		}
	}

	return UserObjectElement;
}

void UUI_MainHall::NativeConstruct()
{
	Super::NativeConstruct();

	if (HallMenuSystem)
	{
		//GameStart
		{
			FOnButtonClickedEvent Delegate;
			Delegate.AddDynamic(this, &UUI_MainHall::GameStart);
			HallMenuSystem->BindGameStart(Delegate);
		}

		//SecretTerritory
		{
			FOnButtonClickedEvent Delegate;
			Delegate.AddDynamic(this, &UUI_MainHall::BindSecretTerritory);
			HallMenuSystem->BindSecretTerritory(Delegate);
		}

		//History
		{
			FOnButtonClickedEvent Delegate;
			Delegate.AddDynamic(this, &UUI_MainHall::History);
			HallMenuSystem->BindHistory(Delegate);
		}

		//GameSettings
		{
			FOnButtonClickedEvent Delegate;
			Delegate.AddDynamic(this, &UUI_MainHall::GameSettings);
			HallMenuSystem->BindGameSettings(Delegate);
		}

		//TutorialWebsite
		{
			FOnButtonClickedEvent Delegate;
			Delegate.AddDynamic(this, &UUI_MainHall::TutorialWebsite);
			HallMenuSystem->BindTutorialWebsite(Delegate);
		}

		//Browser
		{
			FOnButtonClickedEvent Delegate;
			Delegate.AddDynamic(this, &UUI_MainHall::Browser);
			HallMenuSystem->BindBrowser(Delegate);
		}

		//SpecialContent
		{
			FOnButtonClickedEvent Delegate;
			Delegate.AddDynamic(this, &UUI_MainHall::BindSpecialContent);
			HallMenuSystem->BindSpecialContent(Delegate);
		}

		//QuitGame
		{
			FOnButtonClickedEvent Delegate;
			Delegate.AddDynamic(this, &UUI_MainHall::QuitGame);
			HallMenuSystem->BindQuitGame(Delegate);
		}
	}
}





void UUI_MainHall::GameStart()
{
	UGameplayStatics::OpenLevel(GetWorld(), "SelectLevel");
}

void UUI_MainHall::History()
{
	CreateAssistWidget<UUI_MainHall, UUI_ArchivesSystem>(this, ArchivesSystemClass, BoxList);
}

void UUI_MainHall::GameSettings()
{
	CreateAssistWidget<UUI_MainHall, UUI_GameSettingsSystem>(this, GameSettingsSystemlass, BoxList);
}

void UUI_MainHall::TutorialWebsite()
{
	CreateAssistWidget<UUI_MainHall, UUI_TutoriaSystem>(this, TutoriaSystemClass, BoxList);
}

void UUI_MainHall::Browser()
{
}

void UUI_MainHall::QuitGame()
{
}

void UUI_MainHall::BindSpecialContent()
{
}

void UUI_MainHall::BindSecretTerritory()
{
	
}
