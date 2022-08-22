// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "StoneToolClass/Public/Tool/DisplacementTrgger.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDisplacementTrgger() {}
// Cross Module References
	STONETOOLCLASS_API UClass* Z_Construct_UClass_ADisplacementTrgger_NoRegister();
	STONETOOLCLASS_API UClass* Z_Construct_UClass_ADisplacementTrgger();
	STONETOOLCLASS_API UClass* Z_Construct_UClass_AToolBase();
	UPackage* Z_Construct_UPackage__Script_StoneToolClass();
// End Cross Module References
	void ADisplacementTrgger::StaticRegisterNativesADisplacementTrgger()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADisplacementTrgger);
	UClass* Z_Construct_UClass_ADisplacementTrgger_NoRegister()
	{
		return ADisplacementTrgger::StaticClass();
	}
	struct Z_Construct_UClass_ADisplacementTrgger_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADisplacementTrgger_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AToolBase,
		(UObject* (*)())Z_Construct_UPackage__Script_StoneToolClass,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADisplacementTrgger_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Tool/DisplacementTrgger.h" },
		{ "ModuleRelativePath", "Public/Tool/DisplacementTrgger.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADisplacementTrgger_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADisplacementTrgger>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ADisplacementTrgger_Statics::ClassParams = {
		&ADisplacementTrgger::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ADisplacementTrgger_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADisplacementTrgger_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADisplacementTrgger()
	{
		if (!Z_Registration_Info_UClass_ADisplacementTrgger.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADisplacementTrgger.OuterSingleton, Z_Construct_UClass_ADisplacementTrgger_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ADisplacementTrgger.OuterSingleton;
	}
	template<> STONETOOLCLASS_API UClass* StaticClass<ADisplacementTrgger>()
	{
		return ADisplacementTrgger::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADisplacementTrgger);
	struct Z_CompiledInDeferFile_FID_StoneDefence_Plugins_StoneToolClass_Source_StoneToolClass_Public_Tool_DisplacementTrgger_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_StoneDefence_Plugins_StoneToolClass_Source_StoneToolClass_Public_Tool_DisplacementTrgger_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ADisplacementTrgger, ADisplacementTrgger::StaticClass, TEXT("ADisplacementTrgger"), &Z_Registration_Info_UClass_ADisplacementTrgger, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADisplacementTrgger), 1825647059U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_StoneDefence_Plugins_StoneToolClass_Source_StoneToolClass_Public_Tool_DisplacementTrgger_h_991083719(TEXT("/Script/StoneToolClass"),
		Z_CompiledInDeferFile_FID_StoneDefence_Plugins_StoneToolClass_Source_StoneToolClass_Public_Tool_DisplacementTrgger_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_StoneDefence_Plugins_StoneToolClass_Source_StoneToolClass_Public_Tool_DisplacementTrgger_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
