// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_TutoriaSystem.h"

#include "MediaPlaylist.h"
#include "MediaSource.h"
#include "GlobalTutoriaProxy.h"
#include "Components/Button.h"
#include "Components/CheckBox.h"
#include "Components/Image.h"
#include "Components/ScrollBox.h"
#include "Components/Slider.h"
#include "Components/TextBlock.h"
#include "MediaAssets/Public/MediaPlayer.h"
#include "Tutoria/UI_TutoriaSlot.h"
#include "MediaSoundComponent.h"
#include "HAL/FileManager.h"


void UUI_TutoriaSystem::NativeConstruct()
{
	Super::NativeConstruct();

	//绑定代理
	// SimpleTutoriaMulticastDelegate.BindUObject(this, &UUI_TutoriaSystem::Play);

	InitMadia();
	MediaPlayer->OnEndReached.AddDynamic(this, &UUI_TutoriaSystem::FinishPlayMovie);

	ReplayButton->OnClicked.AddDynamic(this, &UUI_TutoriaSystem::Replay);
	PauseButton->OnClicked.AddDynamic(this, &UUI_TutoriaSystem::Pause);
	
	MovieProgress->OnMouseCaptureBegin.AddDynamic(this, &UUI_TutoriaSystem::MouseCaptureBegin);
	MovieProgress->OnMouseCaptureEnd.AddDynamic(this, &UUI_TutoriaSystem::MouseCaptureEnd);

	SuspendButton->OnCheckStateChanged.AddDynamic(this, &UUI_TutoriaSystem::ClickedCheckBox);
}

void UUI_TutoriaSystem::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (MovieProgress)
	{
		// 计算进度 = 当前播放的时间  /  阶段总时间
		float NewValue = MediaPlayer->GetTime().GetTotalSeconds() / MediaPlayer->GetDuration().GetTotalSeconds();
		MovieProgress->SetValue(NewValue);

		PlayTimeText->SetText(FText::FromString(MediaPlayer->GetTime().ToString()+ "/" + MediaPlayer->GetDuration().ToString()));
	}
}

void UUI_TutoriaSystem::InitMadia()
{
	if (MediaPlayer)
	{
		// 遍历文件 找出所有视频文件
		TArray<FString> MadiaFilenames;
		// 获取相对路径
		FString MadiaPath = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir() / TEXT("Media/"));
		// 找出视频
		IFileManager::Get().FindFiles(MadiaFilenames, *(MadiaPath + TEXT("*")), true, false);
		for (int32 i = 0; i < MadiaFilenames.Num(); i++)
		{
	
			if (UUI_TutoriaSlot *TutoriaSlot = CreateWidget<UUI_TutoriaSlot>(GetWorld(), TutoriaSloClass))
			{
				TutoriaSlot->TutoriaPath = MadiaFilenames[i];
				ScrollMediaList->AddChild(TutoriaSlot);
			}
		}
		if (MadiaFilenames.Num() > 0)
		{
			Play(MadiaFilenames[0]);
		}
	}
}

bool UUI_TutoriaSystem::Play(const FString &InPath)
{
	MediaPlayer->OpenFile(InPath);
	return false;
}

void UUI_TutoriaSystem::ClickedCheckBox(bool ClickedWidget)
{
	ActivationMovie();
}

void UUI_TutoriaSystem::ActivationMovie()
{
	if (MediaPlayer->IsPlaying())
	{
		MediaPlayer->Pause();
		PauseImage->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		
		SuspendButton->SetCheckedState( ECheckBoxState::Unchecked);
	} else
	{
		MediaPlayer->Play();
		PauseImage->SetVisibility(ESlateVisibility::Hidden);
		
		SuspendButton->SetCheckedState( ECheckBoxState::Checked);
	}
	
}

void UUI_TutoriaSystem::Replay()
{
	if (MediaPlayer->IsReady())
	{
		MediaPlayer->Rewind();
	}
}

void UUI_TutoriaSystem::Close()
{
	if (MediaPlayer->IsPlaying())
	{
		MediaPlayer->Pause();
		PauseImage->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		
		SuspendButton->SetCheckedState( ECheckBoxState::Unchecked);
	}
	MediaPlayer->Close();
}

void UUI_TutoriaSystem::Pause()
{
	ActivationMovie();
}

void UUI_TutoriaSystem::FinishPlayMovie()
{
	if (MediaPlayer->IsReady())
	{
		MediaPlayer->Close();
	}
}

void UUI_TutoriaSystem::MouseCaptureBegin()
{
	
}

void UUI_TutoriaSystem::MouseCaptureEnd()
{
}
