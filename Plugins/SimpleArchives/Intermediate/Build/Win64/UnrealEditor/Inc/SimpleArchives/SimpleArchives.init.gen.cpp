// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSimpleArchives_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_SimpleArchives;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_SimpleArchives()
	{
		if (!Z_Registration_Info_UPackage__Script_SimpleArchives.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/SimpleArchives",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x5F0BE9E2,
				0xDCA3F321,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_SimpleArchives.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_SimpleArchives.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_SimpleArchives(Z_Construct_UPackage__Script_SimpleArchives, TEXT("/Script/SimpleArchives"), Z_Registration_Info_UPackage__Script_SimpleArchives, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x5F0BE9E2, 0xDCA3F321));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
