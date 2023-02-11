// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleTutoria/Public/Tutoria/UI_TutoriaSlot.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_TutoriaSlot() {}
// Cross Module References
	SIMPLETUTORIA_API UClass* Z_Construct_UClass_UUI_TutoriaBase();
	SIMPLETUTORIA_API UClass* Z_Construct_UClass_UUI_TutoriaSlot();
	SIMPLETUTORIA_API UClass* Z_Construct_UClass_UUI_TutoriaSlot_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SimpleTutoria();
// End Cross Module References
	void UUI_TutoriaSlot::StaticRegisterNativesUUI_TutoriaSlot()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUI_TutoriaSlot);
	UClass* Z_Construct_UClass_UUI_TutoriaSlot_NoRegister()
	{
		return UUI_TutoriaSlot::StaticClass();
	}
	struct Z_Construct_UClass_UUI_TutoriaSlot_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_TutoriaSlot_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUI_TutoriaBase,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleTutoria,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_TutoriaSlot_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Tutoria/UI_TutoriaSlot.h" },
		{ "ModuleRelativePath", "Public/Tutoria/UI_TutoriaSlot.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_TutoriaSlot_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_TutoriaSlot>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UUI_TutoriaSlot_Statics::ClassParams = {
		&UUI_TutoriaSlot::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UUI_TutoriaSlot_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_TutoriaSlot_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUI_TutoriaSlot()
	{
		if (!Z_Registration_Info_UClass_UUI_TutoriaSlot.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUI_TutoriaSlot.OuterSingleton, Z_Construct_UClass_UUI_TutoriaSlot_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UUI_TutoriaSlot.OuterSingleton;
	}
	template<> SIMPLETUTORIA_API UClass* StaticClass<UUI_TutoriaSlot>()
	{
		return UUI_TutoriaSlot::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_TutoriaSlot);
	UUI_TutoriaSlot::~UUI_TutoriaSlot() {}
	struct Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleTutoria_Source_SimpleTutoria_Public_Tutoria_UI_TutoriaSlot_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleTutoria_Source_SimpleTutoria_Public_Tutoria_UI_TutoriaSlot_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UUI_TutoriaSlot, UUI_TutoriaSlot::StaticClass, TEXT("UUI_TutoriaSlot"), &Z_Registration_Info_UClass_UUI_TutoriaSlot, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUI_TutoriaSlot), 1000227016U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleTutoria_Source_SimpleTutoria_Public_Tutoria_UI_TutoriaSlot_h_3153829031(TEXT("/Script/SimpleTutoria"),
		Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleTutoria_Source_SimpleTutoria_Public_Tutoria_UI_TutoriaSlot_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleTutoria_Source_SimpleTutoria_Public_Tutoria_UI_TutoriaSlot_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
