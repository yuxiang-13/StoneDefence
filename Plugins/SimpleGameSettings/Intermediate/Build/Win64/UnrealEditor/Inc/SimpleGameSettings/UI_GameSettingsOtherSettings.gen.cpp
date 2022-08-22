// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleGameSettings/Public/GameSettings/UI_GameSettingsOtherSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_GameSettingsOtherSettings() {}
// Cross Module References
	SIMPLEGAMESETTINGS_API UClass* Z_Construct_UClass_UUI_GameSettingsOtherSettings_NoRegister();
	SIMPLEGAMESETTINGS_API UClass* Z_Construct_UClass_UUI_GameSettingsOtherSettings();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_SimpleGameSettings();
// End Cross Module References
	void UUI_GameSettingsOtherSettings::StaticRegisterNativesUUI_GameSettingsOtherSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUI_GameSettingsOtherSettings);
	UClass* Z_Construct_UClass_UUI_GameSettingsOtherSettings_NoRegister()
	{
		return UUI_GameSettingsOtherSettings::StaticClass();
	}
	struct Z_Construct_UClass_UUI_GameSettingsOtherSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_GameSettingsOtherSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleGameSettings,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_GameSettingsOtherSettings_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "GameSettings/UI_GameSettingsOtherSettings.h" },
		{ "ModuleRelativePath", "Public/GameSettings/UI_GameSettingsOtherSettings.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_GameSettingsOtherSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_GameSettingsOtherSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UUI_GameSettingsOtherSettings_Statics::ClassParams = {
		&UUI_GameSettingsOtherSettings::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UUI_GameSettingsOtherSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_GameSettingsOtherSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUI_GameSettingsOtherSettings()
	{
		if (!Z_Registration_Info_UClass_UUI_GameSettingsOtherSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUI_GameSettingsOtherSettings.OuterSingleton, Z_Construct_UClass_UUI_GameSettingsOtherSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UUI_GameSettingsOtherSettings.OuterSingleton;
	}
	template<> SIMPLEGAMESETTINGS_API UClass* StaticClass<UUI_GameSettingsOtherSettings>()
	{
		return UUI_GameSettingsOtherSettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_GameSettingsOtherSettings);
	struct Z_CompiledInDeferFile_FID_StoneDefence_Plugins_SimpleGameSettings_Source_SimpleGameSettings_Public_GameSettings_UI_GameSettingsOtherSettings_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_StoneDefence_Plugins_SimpleGameSettings_Source_SimpleGameSettings_Public_GameSettings_UI_GameSettingsOtherSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UUI_GameSettingsOtherSettings, UUI_GameSettingsOtherSettings::StaticClass, TEXT("UUI_GameSettingsOtherSettings"), &Z_Registration_Info_UClass_UUI_GameSettingsOtherSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUI_GameSettingsOtherSettings), 840441107U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_StoneDefence_Plugins_SimpleGameSettings_Source_SimpleGameSettings_Public_GameSettings_UI_GameSettingsOtherSettings_h_2408947866(TEXT("/Script/SimpleGameSettings"),
		Z_CompiledInDeferFile_FID_StoneDefence_Plugins_SimpleGameSettings_Source_SimpleGameSettings_Public_GameSettings_UI_GameSettingsOtherSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_StoneDefence_Plugins_SimpleGameSettings_Source_SimpleGameSettings_Public_GameSettings_UI_GameSettingsOtherSettings_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
