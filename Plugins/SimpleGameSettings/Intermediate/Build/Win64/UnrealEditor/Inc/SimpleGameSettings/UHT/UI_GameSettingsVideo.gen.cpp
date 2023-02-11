// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleGameSettings/Public/GameSettings/UI_GameSettingsVideo.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_GameSettingsVideo() {}
// Cross Module References
	SIMPLEGAMESETTINGS_API UClass* Z_Construct_UClass_UUI_GameSettingsVideo();
	SIMPLEGAMESETTINGS_API UClass* Z_Construct_UClass_UUI_GameSettingsVideo_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_SimpleGameSettings();
// End Cross Module References
	void UUI_GameSettingsVideo::StaticRegisterNativesUUI_GameSettingsVideo()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUI_GameSettingsVideo);
	UClass* Z_Construct_UClass_UUI_GameSettingsVideo_NoRegister()
	{
		return UUI_GameSettingsVideo::StaticClass();
	}
	struct Z_Construct_UClass_UUI_GameSettingsVideo_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_GameSettingsVideo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleGameSettings,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_GameSettingsVideo_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "GameSettings/UI_GameSettingsVideo.h" },
		{ "ModuleRelativePath", "Public/GameSettings/UI_GameSettingsVideo.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_GameSettingsVideo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_GameSettingsVideo>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UUI_GameSettingsVideo_Statics::ClassParams = {
		&UUI_GameSettingsVideo::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UUI_GameSettingsVideo_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_GameSettingsVideo_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUI_GameSettingsVideo()
	{
		if (!Z_Registration_Info_UClass_UUI_GameSettingsVideo.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUI_GameSettingsVideo.OuterSingleton, Z_Construct_UClass_UUI_GameSettingsVideo_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UUI_GameSettingsVideo.OuterSingleton;
	}
	template<> SIMPLEGAMESETTINGS_API UClass* StaticClass<UUI_GameSettingsVideo>()
	{
		return UUI_GameSettingsVideo::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_GameSettingsVideo);
	UUI_GameSettingsVideo::~UUI_GameSettingsVideo() {}
	struct Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleGameSettings_Source_SimpleGameSettings_Public_GameSettings_UI_GameSettingsVideo_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleGameSettings_Source_SimpleGameSettings_Public_GameSettings_UI_GameSettingsVideo_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UUI_GameSettingsVideo, UUI_GameSettingsVideo::StaticClass, TEXT("UUI_GameSettingsVideo"), &Z_Registration_Info_UClass_UUI_GameSettingsVideo, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUI_GameSettingsVideo), 2583888948U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleGameSettings_Source_SimpleGameSettings_Public_GameSettings_UI_GameSettingsVideo_h_2910605712(TEXT("/Script/SimpleGameSettings"),
		Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleGameSettings_Source_SimpleGameSettings_Public_GameSettings_UI_GameSettingsVideo_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleGameSettings_Source_SimpleGameSettings_Public_GameSettings_UI_GameSettingsVideo_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
