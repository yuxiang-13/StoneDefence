// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleTutoria/Public/UI_TutoriaSystem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_TutoriaSystem() {}
// Cross Module References
	SIMPLETUTORIA_API UClass* Z_Construct_UClass_UUI_TutoriaSystem_NoRegister();
	SIMPLETUTORIA_API UClass* Z_Construct_UClass_UUI_TutoriaSystem();
	SIMPLETUTORIA_API UClass* Z_Construct_UClass_UUI_TutoriaBase();
	UPackage* Z_Construct_UPackage__Script_SimpleTutoria();
// End Cross Module References
	void UUI_TutoriaSystem::StaticRegisterNativesUUI_TutoriaSystem()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUI_TutoriaSystem);
	UClass* Z_Construct_UClass_UUI_TutoriaSystem_NoRegister()
	{
		return UUI_TutoriaSystem::StaticClass();
	}
	struct Z_Construct_UClass_UUI_TutoriaSystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_TutoriaSystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUI_TutoriaBase,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleTutoria,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_TutoriaSystem_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "UI_TutoriaSystem.h" },
		{ "ModuleRelativePath", "Public/UI_TutoriaSystem.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_TutoriaSystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_TutoriaSystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UUI_TutoriaSystem_Statics::ClassParams = {
		&UUI_TutoriaSystem::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UUI_TutoriaSystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_TutoriaSystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUI_TutoriaSystem()
	{
		if (!Z_Registration_Info_UClass_UUI_TutoriaSystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUI_TutoriaSystem.OuterSingleton, Z_Construct_UClass_UUI_TutoriaSystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UUI_TutoriaSystem.OuterSingleton;
	}
	template<> SIMPLETUTORIA_API UClass* StaticClass<UUI_TutoriaSystem>()
	{
		return UUI_TutoriaSystem::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_TutoriaSystem);
	struct Z_CompiledInDeferFile_FID_UnrealProjects_Plugins_SimpleTutoria_Source_SimpleTutoria_Public_UI_TutoriaSystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_Plugins_SimpleTutoria_Source_SimpleTutoria_Public_UI_TutoriaSystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UUI_TutoriaSystem, UUI_TutoriaSystem::StaticClass, TEXT("UUI_TutoriaSystem"), &Z_Registration_Info_UClass_UUI_TutoriaSystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUI_TutoriaSystem), 4088241935U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_Plugins_SimpleTutoria_Source_SimpleTutoria_Public_UI_TutoriaSystem_h_2750814752(TEXT("/Script/SimpleTutoria"),
		Z_CompiledInDeferFile_FID_UnrealProjects_Plugins_SimpleTutoria_Source_SimpleTutoria_Public_UI_TutoriaSystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_Plugins_SimpleTutoria_Source_SimpleTutoria_Public_UI_TutoriaSystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
