// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleTutoria/Public/Core/UI_TutoriaBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_TutoriaBase() {}
// Cross Module References
	SIMPLETUTORIA_API UClass* Z_Construct_UClass_UUI_TutoriaBase();
	SIMPLETUTORIA_API UClass* Z_Construct_UClass_UUI_TutoriaBase_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_SimpleTutoria();
// End Cross Module References
	void UUI_TutoriaBase::StaticRegisterNativesUUI_TutoriaBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUI_TutoriaBase);
	UClass* Z_Construct_UClass_UUI_TutoriaBase_NoRegister()
	{
		return UUI_TutoriaBase::StaticClass();
	}
	struct Z_Construct_UClass_UUI_TutoriaBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_TutoriaBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleTutoria,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_TutoriaBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Core/UI_TutoriaBase.h" },
		{ "ModuleRelativePath", "Public/Core/UI_TutoriaBase.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_TutoriaBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_TutoriaBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UUI_TutoriaBase_Statics::ClassParams = {
		&UUI_TutoriaBase::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UUI_TutoriaBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_TutoriaBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUI_TutoriaBase()
	{
		if (!Z_Registration_Info_UClass_UUI_TutoriaBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUI_TutoriaBase.OuterSingleton, Z_Construct_UClass_UUI_TutoriaBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UUI_TutoriaBase.OuterSingleton;
	}
	template<> SIMPLETUTORIA_API UClass* StaticClass<UUI_TutoriaBase>()
	{
		return UUI_TutoriaBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_TutoriaBase);
	UUI_TutoriaBase::~UUI_TutoriaBase() {}
	struct Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleTutoria_Source_SimpleTutoria_Public_Core_UI_TutoriaBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleTutoria_Source_SimpleTutoria_Public_Core_UI_TutoriaBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UUI_TutoriaBase, UUI_TutoriaBase::StaticClass, TEXT("UUI_TutoriaBase"), &Z_Registration_Info_UClass_UUI_TutoriaBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUI_TutoriaBase), 1093419385U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleTutoria_Source_SimpleTutoria_Public_Core_UI_TutoriaBase_h_3189212550(TEXT("/Script/SimpleTutoria"),
		Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleTutoria_Source_SimpleTutoria_Public_Core_UI_TutoriaBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleTutoria_Source_SimpleTutoria_Public_Core_UI_TutoriaBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
