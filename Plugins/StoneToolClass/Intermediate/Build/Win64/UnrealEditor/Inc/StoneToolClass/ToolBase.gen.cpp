// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "StoneToolClass/Public/Core/ToolBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeToolBase() {}
// Cross Module References
	STONETOOLCLASS_API UClass* Z_Construct_UClass_AToolBase_NoRegister();
	STONETOOLCLASS_API UClass* Z_Construct_UClass_AToolBase();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_StoneToolClass();
// End Cross Module References
	void AToolBase::StaticRegisterNativesAToolBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AToolBase);
	UClass* Z_Construct_UClass_AToolBase_NoRegister()
	{
		return AToolBase::StaticClass();
	}
	struct Z_Construct_UClass_AToolBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AToolBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_StoneToolClass,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AToolBase_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Core/ToolBase.h" },
		{ "ModuleRelativePath", "Public/Core/ToolBase.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AToolBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AToolBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AToolBase_Statics::ClassParams = {
		&AToolBase::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AToolBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AToolBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AToolBase()
	{
		if (!Z_Registration_Info_UClass_AToolBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AToolBase.OuterSingleton, Z_Construct_UClass_AToolBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AToolBase.OuterSingleton;
	}
	template<> STONETOOLCLASS_API UClass* StaticClass<AToolBase>()
	{
		return AToolBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AToolBase);
	struct Z_CompiledInDeferFile_FID_StoneDefence_Plugins_StoneToolClass_Source_StoneToolClass_Public_Core_ToolBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_StoneDefence_Plugins_StoneToolClass_Source_StoneToolClass_Public_Core_ToolBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AToolBase, AToolBase::StaticClass, TEXT("AToolBase"), &Z_Registration_Info_UClass_AToolBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AToolBase), 2013078712U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_StoneDefence_Plugins_StoneToolClass_Source_StoneToolClass_Public_Core_ToolBase_h_1410827914(TEXT("/Script/StoneToolClass"),
		Z_CompiledInDeferFile_FID_StoneDefence_Plugins_StoneToolClass_Source_StoneToolClass_Public_Core_ToolBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_StoneDefence_Plugins_StoneToolClass_Source_StoneToolClass_Public_Core_ToolBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
