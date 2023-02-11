// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleArchives/Public/SaveLoad/UI_ArchivesBar.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_ArchivesBar() {}
// Cross Module References
	SIMPLEARCHIVES_API UClass* Z_Construct_UClass_UUI_ArchivesBar();
	SIMPLEARCHIVES_API UClass* Z_Construct_UClass_UUI_ArchivesBar_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_SimpleArchives();
// End Cross Module References
	void UUI_ArchivesBar::StaticRegisterNativesUUI_ArchivesBar()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUI_ArchivesBar);
	UClass* Z_Construct_UClass_UUI_ArchivesBar_NoRegister()
	{
		return UUI_ArchivesBar::StaticClass();
	}
	struct Z_Construct_UClass_UUI_ArchivesBar_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_ArchivesBar_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleArchives,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_ArchivesBar_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "SaveLoad/UI_ArchivesBar.h" },
		{ "ModuleRelativePath", "Public/SaveLoad/UI_ArchivesBar.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_ArchivesBar_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_ArchivesBar>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UUI_ArchivesBar_Statics::ClassParams = {
		&UUI_ArchivesBar::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UUI_ArchivesBar_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_ArchivesBar_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUI_ArchivesBar()
	{
		if (!Z_Registration_Info_UClass_UUI_ArchivesBar.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUI_ArchivesBar.OuterSingleton, Z_Construct_UClass_UUI_ArchivesBar_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UUI_ArchivesBar.OuterSingleton;
	}
	template<> SIMPLEARCHIVES_API UClass* StaticClass<UUI_ArchivesBar>()
	{
		return UUI_ArchivesBar::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_ArchivesBar);
	UUI_ArchivesBar::~UUI_ArchivesBar() {}
	struct Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleArchives_Source_SimpleArchives_Public_SaveLoad_UI_ArchivesBar_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleArchives_Source_SimpleArchives_Public_SaveLoad_UI_ArchivesBar_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UUI_ArchivesBar, UUI_ArchivesBar::StaticClass, TEXT("UUI_ArchivesBar"), &Z_Registration_Info_UClass_UUI_ArchivesBar, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUI_ArchivesBar), 403492141U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleArchives_Source_SimpleArchives_Public_SaveLoad_UI_ArchivesBar_h_943064708(TEXT("/Script/SimpleArchives"),
		Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleArchives_Source_SimpleArchives_Public_SaveLoad_UI_ArchivesBar_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleArchives_Source_SimpleArchives_Public_SaveLoad_UI_ArchivesBar_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
