// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFJQMySql_init() {}
	FJQMYSQL_API UFunction* Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature();
	FJQMYSQL_API UFunction* Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature();
	FJQMYSQL_API UFunction* Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature();
	FJQMYSQL_API UFunction* Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_FJQMySql;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_FJQMySql()
	{
		if (!Z_Registration_Info_UPackage__Script_FJQMySql.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/FJQMySql",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x36D5A1F9,
				0xF759EAA9,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_FJQMySql.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_FJQMySql.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_FJQMySql(Z_Construct_UPackage__Script_FJQMySql, TEXT("/Script/FJQMySql"), Z_Registration_Info_UPackage__Script_FJQMySql, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x36D5A1F9, 0xF759EAA9));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
