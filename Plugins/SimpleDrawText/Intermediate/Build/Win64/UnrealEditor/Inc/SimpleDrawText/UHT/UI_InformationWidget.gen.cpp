// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleDrawText/Public/UI/UI_InformationWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUI_InformationWidget() {}
// Cross Module References
	SIMPLEDRAWTEXT_API UClass* Z_Construct_UClass_UUI_InformationWidget();
	SIMPLEDRAWTEXT_API UClass* Z_Construct_UClass_UUI_InformationWidget_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_SimpleDrawText();
// End Cross Module References
	void UUI_InformationWidget::StaticRegisterNativesUUI_InformationWidget()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UUI_InformationWidget);
	UClass* Z_Construct_UClass_UUI_InformationWidget_NoRegister()
	{
		return UUI_InformationWidget::StaticClass();
	}
	struct Z_Construct_UClass_UUI_InformationWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TextWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TextWidget;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUI_InformationWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleDrawText,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_InformationWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "UI/UI_InformationWidget.h" },
		{ "ModuleRelativePath", "Public/UI/UI_InformationWidget.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUI_InformationWidget_Statics::NewProp_TextWidget_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/UI_InformationWidget.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UUI_InformationWidget_Statics::NewProp_TextWidget = { "TextWidget", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UUI_InformationWidget, TextWidget), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UUI_InformationWidget_Statics::NewProp_TextWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_InformationWidget_Statics::NewProp_TextWidget_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UUI_InformationWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UUI_InformationWidget_Statics::NewProp_TextWidget,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUI_InformationWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUI_InformationWidget>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UUI_InformationWidget_Statics::ClassParams = {
		&UUI_InformationWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UUI_InformationWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UUI_InformationWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UUI_InformationWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUI_InformationWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUI_InformationWidget()
	{
		if (!Z_Registration_Info_UClass_UUI_InformationWidget.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UUI_InformationWidget.OuterSingleton, Z_Construct_UClass_UUI_InformationWidget_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UUI_InformationWidget.OuterSingleton;
	}
	template<> SIMPLEDRAWTEXT_API UClass* StaticClass<UUI_InformationWidget>()
	{
		return UUI_InformationWidget::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUI_InformationWidget);
	UUI_InformationWidget::~UUI_InformationWidget() {}
	struct Z_CompiledInDeferFile_FID_yuxiang_Documents_UnrealProjects_Plugins_SimpleDrawText_Source_SimpleDrawText_Public_UI_UI_InformationWidget_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_yuxiang_Documents_UnrealProjects_Plugins_SimpleDrawText_Source_SimpleDrawText_Public_UI_UI_InformationWidget_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UUI_InformationWidget, UUI_InformationWidget::StaticClass, TEXT("UUI_InformationWidget"), &Z_Registration_Info_UClass_UUI_InformationWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UUI_InformationWidget), 28293932U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_yuxiang_Documents_UnrealProjects_Plugins_SimpleDrawText_Source_SimpleDrawText_Public_UI_UI_InformationWidget_h_949254327(TEXT("/Script/SimpleDrawText"),
		Z_CompiledInDeferFile_FID_yuxiang_Documents_UnrealProjects_Plugins_SimpleDrawText_Source_SimpleDrawText_Public_UI_UI_InformationWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_yuxiang_Documents_UnrealProjects_Plugins_SimpleDrawText_Source_SimpleDrawText_Public_UI_UI_InformationWidget_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
