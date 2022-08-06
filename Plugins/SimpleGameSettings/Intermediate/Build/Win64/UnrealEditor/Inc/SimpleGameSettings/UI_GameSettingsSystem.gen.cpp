// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleGameSettings/Public/UI_GameSettingsSystem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_GameSettingsSystem() {}
// Cross Module References
	SIMPLEGAMESETTINGS_API UClass* Z_Construct_UClass_UUI_GameSettingsSystem_NoRegister();
	SIMPLEGAMESETTINGS_API UClass* Z_Construct_UClass_UUI_GameSettingsSystem();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_SimpleGameSettings();
// End Cross Module References
	void UUI_GameSettingsSystem::StaticRegisterNativesUUI_GameSettingsSystem()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUI_GameSettingsSystem);
	UClass* Z_Construct_UClass_UUI_GameSettingsSystem_NoRegister()
	{
		return UUI_GameSettingsSystem::StaticClass();
	}
	struct Z_Construct_UClass_UUI_GameSettingsSystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_GameSettingsSystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleGameSettings,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_GameSettingsSystem_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "UI_GameSettingsSystem.h" },
		{ "ModuleRelativePath", "Public/UI_GameSettingsSystem.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_GameSettingsSystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_GameSettingsSystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UUI_GameSettingsSystem_Statics::ClassParams = {
		&UUI_GameSettingsSystem::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UUI_GameSettingsSystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_GameSettingsSystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUI_GameSettingsSystem()
	{
		if (!Z_Registration_Info_UClass_UUI_GameSettingsSystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUI_GameSettingsSystem.OuterSingleton, Z_Construct_UClass_UUI_GameSettingsSystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UUI_GameSettingsSystem.OuterSingleton;
	}
	template<> SIMPLEGAMESETTINGS_API UClass* StaticClass<UUI_GameSettingsSystem>()
	{
		return UUI_GameSettingsSystem::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_GameSettingsSystem);
	struct Z_CompiledInDeferFile_FID_UnrealProjects_Plugins_SimpleGameSettings_Source_SimpleGameSettings_Public_UI_GameSettingsSystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_Plugins_SimpleGameSettings_Source_SimpleGameSettings_Public_UI_GameSettingsSystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UUI_GameSettingsSystem, UUI_GameSettingsSystem::StaticClass, TEXT("UUI_GameSettingsSystem"), &Z_Registration_Info_UClass_UUI_GameSettingsSystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUI_GameSettingsSystem), 2266707158U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_Plugins_SimpleGameSettings_Source_SimpleGameSettings_Public_UI_GameSettingsSystem_h_1887509433(TEXT("/Script/SimpleGameSettings"),
		Z_CompiledInDeferFile_FID_UnrealProjects_Plugins_SimpleGameSettings_Source_SimpleGameSettings_Public_UI_GameSettingsSystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_Plugins_SimpleGameSettings_Source_SimpleGameSettings_Public_UI_GameSettingsSystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
