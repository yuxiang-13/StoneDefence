

#include "SScrrenLoading.h"
#include "Widgets/Notifications/SProgressBar.h"

void SScreenLoading::Construct(const FArguments &InArgs, const FString &InMapname)
{
	Mapname = InMapname;
	ChildSlot
		[
			SNew(SProgressBar)
			.Percent(this, &SScreenLoading::GetProgress)
		];
}

TOptional<float> SScreenLoading::GetProgress() const
{
	// 获取百分比，开始和结束  是-1
	float LoadPrecnetage = GetAsyncLoadPercentage(*Mapname);
	return LoadPrecnetage * 0.01;
}
