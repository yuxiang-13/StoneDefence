// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Damage/DrawText.h"

#include "Components/TimelineComponent.h"
#include "Components/WidgetComponent.h"

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
		// FOnTimelineEvent TimeLineDelegate;
		// FOnTimelineEvent FinishedEvent;
		// TimeLineDelegate.BindUFunction(this, FName("TimeLineRangeTime"));
		// FinishedEvent.BindUFunction(this, FName("TimeLineFinished"));
		//
		// Timeline.AddInterpFloat(CurveFloatClass.ExternalCurve, TimeLineDelegate);
		// Timeline.SetLooping(false);
		// Timeline.PlayFromStart();
		// Timeline.SetTimelineFinishedFunc(FinishedEvent);
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

void ADrawText::TimeLineRangeTime(float Value)
{
	
}

void ADrawText::TimeLineFinished()
{
	
}

