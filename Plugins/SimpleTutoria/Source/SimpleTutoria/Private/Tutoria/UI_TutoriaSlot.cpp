#include "Tutoria/UI_TutoriaSlot.h"

UUI_TutoriaSlot::UUI_TutoriaSlot()
{
	Index = INDEX_NONE;
}

bool UUI_TutoriaSlot::IsIndexValid()
{
	return Index != INDEX_NONE;
}
