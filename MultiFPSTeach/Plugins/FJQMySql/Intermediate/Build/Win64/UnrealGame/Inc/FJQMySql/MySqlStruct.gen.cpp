// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FJQMySql/Public/MySqlCore/MySqlStruct.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMySqlStruct() {}
// Cross Module References
	FJQMYSQL_API UScriptStruct* Z_Construct_UScriptStruct_FCreate();
	UPackage* Z_Construct_UPackage__Script_FJQMySql();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_Create;
class UScriptStruct* FCreate::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_Create.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_Create.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCreate, Z_Construct_UPackage__Script_FJQMySql(), TEXT("Create"));
	}
	return Z_Registration_Info_UScriptStruct_Create.OuterSingleton;
}
template<> FJQMYSQL_API UScriptStruct* StaticStruct<FCreate>()
{
	return FCreate::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FCreate_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_area_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_area;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_farmland_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_farmland;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_gdp_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_gdp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_population_MetaData[];
#endif
		static const UECodeGen_Private::FDoublePropertyParams NewProp_population;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCreate_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/MySqlCore/MySqlStruct.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FCreate_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCreate>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCreate_Statics::NewProp_area_MetaData[] = {
		{ "Category", "Options" },
		{ "ModuleRelativePath", "Public/MySqlCore/MySqlStruct.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FCreate_Statics::NewProp_area = { "area", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCreate, area), METADATA_PARAMS(Z_Construct_UScriptStruct_FCreate_Statics::NewProp_area_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCreate_Statics::NewProp_area_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCreate_Statics::NewProp_farmland_MetaData[] = {
		{ "Category", "Options" },
		{ "ModuleRelativePath", "Public/MySqlCore/MySqlStruct.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FCreate_Statics::NewProp_farmland = { "farmland", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCreate, farmland), METADATA_PARAMS(Z_Construct_UScriptStruct_FCreate_Statics::NewProp_farmland_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCreate_Statics::NewProp_farmland_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCreate_Statics::NewProp_gdp_MetaData[] = {
		{ "Category", "Options" },
		{ "ModuleRelativePath", "Public/MySqlCore/MySqlStruct.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FCreate_Statics::NewProp_gdp = { "gdp", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCreate, gdp), METADATA_PARAMS(Z_Construct_UScriptStruct_FCreate_Statics::NewProp_gdp_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCreate_Statics::NewProp_gdp_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCreate_Statics::NewProp_population_MetaData[] = {
		{ "Category", "Options" },
		{ "ModuleRelativePath", "Public/MySqlCore/MySqlStruct.h" },
	};
#endif
	const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FCreate_Statics::NewProp_population = { "population", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCreate, population), METADATA_PARAMS(Z_Construct_UScriptStruct_FCreate_Statics::NewProp_population_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCreate_Statics::NewProp_population_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCreate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCreate_Statics::NewProp_area,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCreate_Statics::NewProp_farmland,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCreate_Statics::NewProp_gdp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCreate_Statics::NewProp_population,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCreate_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FJQMySql,
		nullptr,
		&NewStructOps,
		"Create",
		sizeof(FCreate),
		alignof(FCreate),
		Z_Construct_UScriptStruct_FCreate_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCreate_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FCreate_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCreate_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FCreate()
	{
		if (!Z_Registration_Info_UScriptStruct_Create.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_Create.InnerSingleton, Z_Construct_UScriptStruct_FCreate_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_Create.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlStruct_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlStruct_h_Statics::ScriptStructInfo[] = {
		{ FCreate::StaticStruct, Z_Construct_UScriptStruct_FCreate_Statics::NewStructOps, TEXT("Create"), &Z_Registration_Info_UScriptStruct_Create, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCreate), 98858686U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlStruct_h_3700104837(TEXT("/Script/FJQMySql"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlStruct_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlStruct_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
