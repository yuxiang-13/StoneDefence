// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/UI_TutoriaBase.h"
#include "UI_TutoriaSystem.generated.h"

class UCheckBox;
class UButton;
class USlider;
class UImage;
class UTextBlock;
class UMediaPlayer;
class UUI_TutoriaSlot;

UCLASS()
class SIMPLETUTORIA_API UUI_TutoriaSystem : public UUI_TutoriaBase
{
	GENERATED_BODY()

	// 重新播放
	UPROPERTY(meta=(BindWidget))
	UButton *ReplayButton;
	
	// 点击
	UPROPERTY(meta=(BindWidget))
	UCheckBox *SuspendButton;

	// 关闭
	UPROPERTY(meta=(BindWidget))
	UButton *CloseButton;

	// 暂停
	UPROPERTY(meta=(BindWidget))
	UButton *PauseButton;

	// 可拖拽进度条
	UPROPERTY(meta=(BindWidget))
	USlider *MovieProgress;

	// 暂停图片
	UPROPERTY(meta=(BindWidget))
	UImage *PauseImage;
	
	// 播放时间
	UPROPERTY(meta=(BindWidget))
	UTextBlock *PlayTimeText;
public:
	// 载入播放器
	UPROPERTY(EditAnywhere, Category=UI)
	UMediaPlayer* MediaPlayer;

	// 视频源UI列表中 Item
	UPROPERTY(EditAnywhere, Category=UI)
	TSubclassOf<UUI_TutoriaSlot> TutoriaSloClass;
private:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	// 初始化视频
	UFUNCTION()
	void InitMadia(bool bPlayMovie);

	UFUNCTION()
	virtual  void ClickedCheckBox(bool ClickedWidget);
	
	// 播放电影
	UFUNCTION()
	void ActivationMovie();

	UFUNCTION()
	bool Play(int32 Index);

	// 重新 播放电影
	UFUNCTION()
	void Replay();
	
	// 关闭 播放电影
	UFUNCTION()
	void Close();

	
	// 暂停 播放电影
	UFUNCTION()
	void Pause();
	
	
	// 电影播放完毕
	UFUNCTION()
	void FinishPlayMovie();

	// 滑条开始
	UFUNCTION()
	void MouseCaptureBegin();
	
	// 滑条结束
	UFUNCTION()
	void MouseCaptureEnd();
};
