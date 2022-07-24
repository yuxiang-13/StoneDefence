// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FSimpleScreenLoadingModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	// 模块导出 宏，就能让其他地方调用这个函数
	SIMPLESCREENLOADING_API void SetupScreenLoading();
private:
	void BeginLoadingScreen(const FString& MapName);
	void EndLoadingScreen(UWorld * World);
};
