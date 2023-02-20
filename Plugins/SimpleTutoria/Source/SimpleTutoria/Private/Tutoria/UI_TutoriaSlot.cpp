#include "Tutoria/UI_TutoriaSlot.h"

#include "./GlobalTutoriaProxy.h"
#include "Components/Button.h"

UUI_TutoriaSlot::UUI_TutoriaSlot(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer)
{
	
}

bool UUI_TutoriaSlot::IsIndexValid()
{
	return TutoriaPath != "";
}

void UUI_TutoriaSlot::Play()
{
	// if (SimpleTutoriaMulticastDelegate.IsBound())
	// {
	// 	SimpleTutoriaMulticastDelegate.Execute(TutoriaPath);
	// }
}

void UUI_TutoriaSlot::NativeConstruct()
{
	Super::NativeConstruct();
	
	PlayButton->OnClicked.AddDynamic(this, &UUI_TutoriaSlot::Play);
}
