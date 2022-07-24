// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleArchives/Public/UI_ArchivesSystem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_ArchivesSystem() {}
// Cross Module References
	SIMPLEARCHIVES_API UClass* Z_Construct_UClass_UUI_ArchivesSystem_NoRegister();
	SIMPLEARCHIVES_API UClass* Z_Construct_UClass_UUI_ArchivesSystem();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_SimpleArchives();
// End Cross Module References
	void UUI_ArchivesSystem::StaticRegisterNativesUUI_ArchivesSystem()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUI_ArchivesSystem);
	UClass* Z_Construct_UClass_UUI_ArchivesSystem_NoRegister()
	{
		return UUI_ArchivesSystem::StaticClass();
	}
	struct Z_Construct_UClass_UUI_ArchivesSystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_ArchivesSystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleArchives,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_ArchivesSystem_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "UI_ArchivesSystem.h" },
		{ "ModuleRelativePath", "Public/UI_ArchivesSystem.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_ArchivesSystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_ArchivesSystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UUI_ArchivesSystem_Statics::ClassParams = {
		&UUI_ArchivesSystem::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UUI_ArchivesSystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_ArchivesSystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUI_ArchivesSystem()
	{
		if (!Z_Registration_Info_UClass_UUI_ArchivesSystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUI_ArchivesSystem.OuterSingleton, Z_Construct_UClass_UUI_ArchivesSystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UUI_ArchivesSystem.OuterSingleton;
	}
	template<> SIMPLEARCHIVES_API UClass* StaticClass<UUI_ArchivesSystem>()
	{
		return UUI_ArchivesSystem::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_ArchivesSystem);
	struct Z_CompiledInDeferFile_FID_StoneDefence_Plugins_SimpleArchives_Source_SimpleArchives_Public_UI_ArchivesSystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_StoneDefence_Plugins_SimpleArchives_Source_SimpleArchives_Public_UI_ArchivesSystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UUI_ArchivesSystem, UUI_ArchivesSystem::StaticClass, TEXT("UUI_ArchivesSystem"), &Z_Registration_Info_UClass_UUI_ArchivesSystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUI_ArchivesSystem), 1369044680U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_StoneDefence_Plugins_SimpleArchives_Source_SimpleArchives_Public_UI_ArchivesSystem_h_3648874375(TEXT("/Script/SimpleArchives"),
		Z_CompiledInDeferFile_FID_StoneDefence_Plugins_SimpleArchives_Source_SimpleArchives_Public_UI_ArchivesSystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_StoneDefence_Plugins_SimpleArchives_Source_SimpleArchives_Public_UI_ArchivesSystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
