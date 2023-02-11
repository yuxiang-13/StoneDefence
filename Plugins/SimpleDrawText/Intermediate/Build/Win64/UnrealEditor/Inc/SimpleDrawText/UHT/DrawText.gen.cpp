// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleDrawText/Public/Damage/DrawText.h"
#include "Engine/Classes/Curves/CurveFloat.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDrawText() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FRuntimeFloatCurve();
	SIMPLEDRAWTEXT_API UClass* Z_Construct_UClass_ADrawText();
	SIMPLEDRAWTEXT_API UClass* Z_Construct_UClass_ADrawText_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UWidgetComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SimpleDrawText();
// End Cross Module References
	DEFINE_FUNCTION(ADrawText::execTimeLineFinished)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TimeLineFinished();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ADrawText::execTimeLineRangeTime)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TimeLineRangeTime(Z_Param_Value);
		P_NATIVE_END;
	}
	void ADrawText::StaticRegisterNativesADrawText()
	{
		UClass* Class = ADrawText::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "TimeLineFinished", &ADrawText::execTimeLineFinished },
			{ "TimeLineRangeTime", &ADrawText::execTimeLineRangeTime },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ADrawText_TimeLineFinished_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADrawText_TimeLineFinished_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Damage/DrawText.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADrawText_TimeLineFinished_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADrawText, nullptr, "TimeLineFinished", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ADrawText_TimeLineFinished_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ADrawText_TimeLineFinished_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ADrawText_TimeLineFinished()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADrawText_TimeLineFinished_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ADrawText_TimeLineRangeTime_Statics
	{
		struct DrawText_eventTimeLineRangeTime_Parms
		{
			float Value;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ADrawText_TimeLineRangeTime_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(DrawText_eventTimeLineRangeTime_Parms, Value), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADrawText_TimeLineRangeTime_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADrawText_TimeLineRangeTime_Statics::NewProp_Value,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ADrawText_TimeLineRangeTime_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Damage/DrawText.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADrawText_TimeLineRangeTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADrawText, nullptr, "TimeLineRangeTime", nullptr, nullptr, sizeof(Z_Construct_UFunction_ADrawText_TimeLineRangeTime_Statics::DrawText_eventTimeLineRangeTime_Parms), Z_Construct_UFunction_ADrawText_TimeLineRangeTime_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADrawText_TimeLineRangeTime_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ADrawText_TimeLineRangeTime_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ADrawText_TimeLineRangeTime_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ADrawText_TimeLineRangeTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADrawText_TimeLineRangeTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADrawText);
	UClass* Z_Construct_UClass_ADrawText_NoRegister()
	{
		return ADrawText::StaticClass();
	}
	struct Z_Construct_UClass_ADrawText_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurveFloatClass_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_CurveFloatClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Widget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Widget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Height_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Height;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADrawText_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleDrawText,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ADrawText_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ADrawText_TimeLineFinished, "TimeLineFinished" }, // 4256282538
		{ &Z_Construct_UFunction_ADrawText_TimeLineRangeTime, "TimeLineRangeTime" }, // 1761534923
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADrawText_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Damage/DrawText.h" },
		{ "ModuleRelativePath", "Public/Damage/DrawText.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADrawText_Statics::NewProp_CurveFloatClass_MetaData[] = {
		{ "Category", "TimeLine" },
		{ "Comment", "// \xe6\x9b\xb2\xe7\xba\xbf\n" },
		{ "ModuleRelativePath", "Public/Damage/DrawText.h" },
		{ "ToolTip", "\xe6\x9b\xb2\xe7\xba\xbf" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ADrawText_Statics::NewProp_CurveFloatClass = { "CurveFloatClass", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADrawText, CurveFloatClass), Z_Construct_UScriptStruct_FRuntimeFloatCurve, METADATA_PARAMS(Z_Construct_UClass_ADrawText_Statics::NewProp_CurveFloatClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADrawText_Statics::NewProp_CurveFloatClass_MetaData)) }; // 1477693291
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADrawText_Statics::NewProp_Widget_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "" },
		{ "Comment", "// \xe9\xa3\x98\xe5\xad\x97widget\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Damage/DrawText.h" },
		{ "ToolTip", "\xe9\xa3\x98\xe5\xad\x97widget" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADrawText_Statics::NewProp_Widget = { "Widget", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADrawText, Widget), Z_Construct_UClass_UWidgetComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ADrawText_Statics::NewProp_Widget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADrawText_Statics::NewProp_Widget_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADrawText_Statics::NewProp_Height_MetaData[] = {
		{ "Category", "DrawText" },
		{ "Comment", "// \xe9\xab\x98\xe5\xba\xa6\n" },
		{ "ModuleRelativePath", "Public/Damage/DrawText.h" },
		{ "ToolTip", "\xe9\xab\x98\xe5\xba\xa6" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADrawText_Statics::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ADrawText, Height), METADATA_PARAMS(Z_Construct_UClass_ADrawText_Statics::NewProp_Height_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ADrawText_Statics::NewProp_Height_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADrawText_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADrawText_Statics::NewProp_CurveFloatClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADrawText_Statics::NewProp_Widget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADrawText_Statics::NewProp_Height,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADrawText_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADrawText>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ADrawText_Statics::ClassParams = {
		&ADrawText::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ADrawText_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ADrawText_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ADrawText_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADrawText_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADrawText()
	{
		if (!Z_Registration_Info_UClass_ADrawText.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADrawText.OuterSingleton, Z_Construct_UClass_ADrawText_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ADrawText.OuterSingleton;
	}
	template<> SIMPLEDRAWTEXT_API UClass* StaticClass<ADrawText>()
	{
		return ADrawText::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADrawText);
	ADrawText::~ADrawText() {}
	struct Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleDrawText_Source_SimpleDrawText_Public_Damage_DrawText_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleDrawText_Source_SimpleDrawText_Public_Damage_DrawText_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ADrawText, ADrawText::StaticClass, TEXT("ADrawText"), &Z_Registration_Info_UClass_ADrawText, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADrawText), 314456693U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleDrawText_Source_SimpleDrawText_Public_Damage_DrawText_h_2878469946(TEXT("/Script/SimpleDrawText"),
		Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleDrawText_Source_SimpleDrawText_Public_Damage_DrawText_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_project_StoneDefence_Plugins_SimpleDrawText_Source_SimpleDrawText_Public_Damage_DrawText_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
