// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleGameSettings/Public/GameSettings/UI_GameSettingAudio.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_GameSettingAudio() {}
// Cross Module References
	SIMPLEGAMESETTINGS_API UClass* Z_Construct_UClass_UUI_GameSettingAudio();
	SIMPLEGAMESETTINGS_API UClass* Z_Construct_UClass_UUI_GameSettingAudio_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_SimpleGameSettings();
// End Cross Module References
	void UUI_GameSettingAudio::StaticRegisterNativesUUI_GameSettingAudio()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUI_GameSettingAudio);
	UClass* Z_Construct_UClass_UUI_GameSettingAudio_NoRegister()
	{
		return UUI_GameSettingAudio::StaticClass();
	}
	struct Z_Construct_UClass_UUI_GameSettingAudio_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_GameSettingAudio_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleGameSettings,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_GameSettingAudio_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "GameSettings/UI_GameSettingAudio.h" },
		{ "ModuleRelativePath", "Public/GameSettings/UI_GameSettingAudio.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_GameSettingAudio_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_GameSettingAudio>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UUI_GameSettingAudio_Statics::ClassParams = {
		&UUI_GameSettingAudio::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UUI_GameSettingAudio_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_GameSettingAudio_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUI_GameSettingAudio()
	{
		if (!Z_Registration_Info_UClass_UUI_GameSettingAudio.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUI_GameSettingAudio.OuterSingleton, Z_Construct_UClass_UUI_GameSettingAudio_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UUI_GameSettingAudio.OuterSingleton;
	}
	template<> SIMPLEGAMESETTINGS_API UClass* StaticClass<UUI_GameSettingAudio>()
	{
		return UUI_GameSettingAudio::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_GameSettingAudio);
	UUI_GameSettingAudio::~UUI_GameSettingAudio() {}
	struct Z_CompiledInDeferFile_FID_yuxiang_Documents_UnrealProjects_Plugins_SimpleGameSettings_Source_SimpleGameSettings_Public_GameSettings_UI_GameSettingAudio_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_yuxiang_Documents_UnrealProjects_Plugins_SimpleGameSettings_Source_SimpleGameSettings_Public_GameSettings_UI_GameSettingAudio_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UUI_GameSettingAudio, UUI_GameSettingAudio::StaticClass, TEXT("UUI_GameSettingAudio"), &Z_Registration_Info_UClass_UUI_GameSettingAudio, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUI_GameSettingAudio), 2325668700U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_yuxiang_Documents_UnrealProjects_Plugins_SimpleGameSettings_Source_SimpleGameSettings_Public_GameSettings_UI_GameSettingAudio_h_3021665900(TEXT("/Script/SimpleGameSettings"),
		Z_CompiledInDeferFile_FID_yuxiang_Documents_UnrealProjects_Plugins_SimpleGameSettings_Source_SimpleGameSettings_Public_GameSettings_UI_GameSettingAudio_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_yuxiang_Documents_UnrealProjects_Plugins_SimpleGameSettings_Source_SimpleGameSettings_Public_GameSettings_UI_GameSettingAudio_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
