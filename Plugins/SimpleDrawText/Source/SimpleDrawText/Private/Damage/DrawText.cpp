// Fill out your copyright notice in the Description page of Project Settings.


#include "Damage/DrawText.h"

#include "Components/TimelineComponent.h"
#include "Components/WidgetComponent.h"
#include "UI/UI_InformationWidget.h"

// Sets default values
ADrawText::ADrawText()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Widget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	Widget->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ADrawText::BeginPlay()
{
	Super::BeginPlay();

	// 初始化timeline
	if (CurveFloatClass.ExternalCurve)
	{
		FOnTimelineFloat TimeLineDelegate;
		FOnTimelineEvent FinishedEvent;
		TimeLineDelegate.BindUFunction(this, FName("TimeLineRangeTime"));
		FinishedEvent.BindUFunction(this, FName("TimeLineFinished"));
		
		Timeline.AddInterpFloat(CurveFloatClass.ExternalCurve, TimeLineDelegate);
		Timeline.SetLooping(false);
		Timeline.PlayFromStart();
		Timeline.SetTimelineFinishedFunc(FinishedEvent);
	}
}

// Called every frame
void ADrawText::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurveFloatClass.ExternalCurve)
	{
		Timeline.TickTimeline(DeltaTime);
	}
}

// 字体向上飘
void ADrawText::TimeLineRangeTime(float Value)
{
	if (Height > 0)
	{
		FVector NewHeight = FMath::Lerp(FVector::ZeroVector, FVector(0,0,Height), Value);
		Widget->AddRelativeLocation(NewHeight);
	}
}

void ADrawText::TimeLineFinished()
{
	Destroy(true);
}

void ADrawText::SetTextBlock(const FString& InText,const FLinearColor & Color, float Percentage)
{
	if (UUI_InformationWidget *InfoWidget = Cast<UUI_InformationWidget>(Widget->GetUserWidgetObject()))
	{
		InfoWidget->SetTextBlockStyle(InText, Color, Percentage);
	}
}

