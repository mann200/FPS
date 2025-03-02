// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FJQMySql/Public/FJQMySqlBPLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFJQMySqlBPLibrary() {}
// Cross Module References
	FJQMYSQL_API UScriptStruct* Z_Construct_UScriptStruct_FMySQLDataTable();
	UPackage* Z_Construct_UPackage__Script_FJQMySql();
	FJQMYSQL_API UScriptStruct* Z_Construct_UScriptStruct_FMySQLDataRow();
	FJQMYSQL_API UFunction* Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature();
	FJQMYSQL_API UClass* Z_Construct_UClass_UMySqlObject_NoRegister();
	FJQMYSQL_API UFunction* Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature();
	FJQMYSQL_API UFunction* Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	FJQMYSQL_API UFunction* Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature();
	FJQMYSQL_API UClass* Z_Construct_UClass_UFJQMySqlBPLibrary_NoRegister();
	FJQMYSQL_API UClass* Z_Construct_UClass_UFJQMySqlBPLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MySQLDataTable;
class UScriptStruct* FMySQLDataTable::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MySQLDataTable.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MySQLDataTable.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMySQLDataTable, Z_Construct_UPackage__Script_FJQMySql(), TEXT("MySQLDataTable"));
	}
	return Z_Registration_Info_UScriptStruct_MySQLDataTable.OuterSingleton;
}
template<> FJQMYSQL_API UScriptStruct* StaticStruct<FMySQLDataTable>()
{
	return FMySQLDataTable::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FMySQLDataTable_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ColumnName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ColumnName;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ColumnData_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ColumnData_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ColumnData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMySQLDataTable_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "MySql|Tables" },
		{ "ModuleRelativePath", "Public/FJQMySqlBPLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FMySQLDataTable_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMySQLDataTable>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMySQLDataTable_Statics::NewProp_ColumnName_MetaData[] = {
		{ "Category", "SQLDataTable" },
		{ "ModuleRelativePath", "Public/FJQMySqlBPLibrary.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMySQLDataTable_Statics::NewProp_ColumnName = { "ColumnName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMySQLDataTable, ColumnName), METADATA_PARAMS(Z_Construct_UScriptStruct_FMySQLDataTable_Statics::NewProp_ColumnName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMySQLDataTable_Statics::NewProp_ColumnName_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMySQLDataTable_Statics::NewProp_ColumnData_Inner = { "ColumnData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMySQLDataTable_Statics::NewProp_ColumnData_MetaData[] = {
		{ "Category", "SQLDataTable" },
		{ "ModuleRelativePath", "Public/FJQMySqlBPLibrary.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMySQLDataTable_Statics::NewProp_ColumnData = { "ColumnData", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMySQLDataTable, ColumnData), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FMySQLDataTable_Statics::NewProp_ColumnData_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMySQLDataTable_Statics::NewProp_ColumnData_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMySQLDataTable_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMySQLDataTable_Statics::NewProp_ColumnName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMySQLDataTable_Statics::NewProp_ColumnData_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMySQLDataTable_Statics::NewProp_ColumnData,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMySQLDataTable_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FJQMySql,
		nullptr,
		&NewStructOps,
		"MySQLDataTable",
		sizeof(FMySQLDataTable),
		alignof(FMySQLDataTable),
		Z_Construct_UScriptStruct_FMySQLDataTable_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMySQLDataTable_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FMySQLDataTable_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMySQLDataTable_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMySQLDataTable()
	{
		if (!Z_Registration_Info_UScriptStruct_MySQLDataTable.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MySQLDataTable.InnerSingleton, Z_Construct_UScriptStruct_FMySQLDataTable_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_MySQLDataTable.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MySQLDataRow;
class UScriptStruct* FMySQLDataRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MySQLDataRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MySQLDataRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMySQLDataRow, Z_Construct_UPackage__Script_FJQMySql(), TEXT("MySQLDataRow"));
	}
	return Z_Registration_Info_UScriptStruct_MySQLDataRow.OuterSingleton;
}
template<> FJQMYSQL_API UScriptStruct* StaticStruct<FMySQLDataRow>()
{
	return FMySQLDataRow::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FMySQLDataRow_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStrPropertyParams NewProp_RowData_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RowData_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_RowData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMySQLDataRow_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "MySql|Tables" },
		{ "ModuleRelativePath", "Public/FJQMySqlBPLibrary.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FMySQLDataRow_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMySQLDataRow>();
	}
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FMySQLDataRow_Statics::NewProp_RowData_Inner = { "RowData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMySQLDataRow_Statics::NewProp_RowData_MetaData[] = {
		{ "Category", "SQLDataRow" },
		{ "ModuleRelativePath", "Public/FJQMySqlBPLibrary.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FMySQLDataRow_Statics::NewProp_RowData = { "RowData", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMySQLDataRow, RowData), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FMySQLDataRow_Statics::NewProp_RowData_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMySQLDataRow_Statics::NewProp_RowData_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMySQLDataRow_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMySQLDataRow_Statics::NewProp_RowData_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMySQLDataRow_Statics::NewProp_RowData,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMySQLDataRow_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FJQMySql,
		nullptr,
		&NewStructOps,
		"MySQLDataRow",
		sizeof(FMySQLDataRow),
		alignof(FMySQLDataRow),
		Z_Construct_UScriptStruct_FMySQLDataRow_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMySQLDataRow_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FMySQLDataRow_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMySQLDataRow_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMySQLDataRow()
	{
		if (!Z_Registration_Info_UScriptStruct_MySQLDataRow.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MySQLDataRow.InnerSingleton, Z_Construct_UScriptStruct_FMySQLDataRow_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_MySQLDataRow.InnerSingleton;
	}
	struct Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics
	{
		struct _Script_FJQMySql_eventNewConnectionDelegate_Parms
		{
			bool IsSussess;
			FString Message;
			UMySqlObject* MySqlObject;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsSussess_MetaData[];
#endif
		static void NewProp_IsSussess_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsSussess;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MySqlObject;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::NewProp_IsSussess_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::NewProp_IsSussess_SetBit(void* Obj)
	{
		((_Script_FJQMySql_eventNewConnectionDelegate_Parms*)Obj)->IsSussess = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::NewProp_IsSussess = { "IsSussess", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(_Script_FJQMySql_eventNewConnectionDelegate_Parms), &Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::NewProp_IsSussess_SetBit, METADATA_PARAMS(Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::NewProp_IsSussess_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::NewProp_IsSussess_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_FJQMySql_eventNewConnectionDelegate_Parms, Message), METADATA_PARAMS(Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::NewProp_Message_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::NewProp_Message_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::NewProp_MySqlObject = { "MySqlObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_FJQMySql_eventNewConnectionDelegate_Parms, MySqlObject), Z_Construct_UClass_UMySqlObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::NewProp_IsSussess,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::NewProp_Message,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::NewProp_MySqlObject,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/FJQMySqlBPLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_FJQMySql, nullptr, "NewConnectionDelegate__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::_Script_FJQMySql_eventNewConnectionDelegate_Parms), Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics
	{
		struct _Script_FJQMySql_eventMakeFromQueryDelegate_Parms
		{
			bool IsSussess;
			FString Message;
			UMySqlObject* MySqlObject;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsSussess_MetaData[];
#endif
		static void NewProp_IsSussess_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsSussess;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MySqlObject;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::NewProp_IsSussess_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::NewProp_IsSussess_SetBit(void* Obj)
	{
		((_Script_FJQMySql_eventMakeFromQueryDelegate_Parms*)Obj)->IsSussess = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::NewProp_IsSussess = { "IsSussess", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(_Script_FJQMySql_eventMakeFromQueryDelegate_Parms), &Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::NewProp_IsSussess_SetBit, METADATA_PARAMS(Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::NewProp_IsSussess_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::NewProp_IsSussess_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_FJQMySql_eventMakeFromQueryDelegate_Parms, Message), METADATA_PARAMS(Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::NewProp_Message_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::NewProp_Message_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::NewProp_MySqlObject = { "MySqlObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_FJQMySql_eventMakeFromQueryDelegate_Parms, MySqlObject), Z_Construct_UClass_UMySqlObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::NewProp_IsSussess,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::NewProp_Message,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::NewProp_MySqlObject,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/FJQMySqlBPLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_FJQMySql, nullptr, "MakeFromQueryDelegate__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::_Script_FJQMySql_eventMakeFromQueryDelegate_Parms), Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics
	{
		struct _Script_FJQMySql_eventSeleteImageFromQueryDelegate_Parms
		{
			FString Message;
			UMySqlObject* MySqlObject;
			TArray<UTexture2D*> Texture;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MySqlObject;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Texture_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Texture;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_FJQMySql_eventSeleteImageFromQueryDelegate_Parms, Message), METADATA_PARAMS(Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::NewProp_Message_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::NewProp_Message_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::NewProp_MySqlObject = { "MySqlObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_FJQMySql_eventSeleteImageFromQueryDelegate_Parms, MySqlObject), Z_Construct_UClass_UMySqlObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::NewProp_Texture_Inner = { "Texture", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::NewProp_Texture_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_FJQMySql_eventSeleteImageFromQueryDelegate_Parms, Texture), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::NewProp_Texture_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::NewProp_Texture_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::NewProp_Message,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::NewProp_MySqlObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::NewProp_Texture_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::NewProp_Texture,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/FJQMySqlBPLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_FJQMySql, nullptr, "SeleteImageFromQueryDelegate__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::_Script_FJQMySql_eventSeleteImageFromQueryDelegate_Parms), Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_FJQMySql_SeleteImageFromQueryDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics
	{
		struct _Script_FJQMySql_eventSelectFromQueryDelegate_Parms
		{
			bool IsSussess;
			FString Message;
			TArray<FMySQLDataTable> ResultByColumn;
			TArray<FMySQLDataRow> ResultByRow;
			UMySqlObject* MySqlObject;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsSussess_MetaData[];
#endif
		static void NewProp_IsSussess_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsSussess;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Message;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ResultByColumn_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ResultByColumn_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ResultByColumn;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ResultByRow_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ResultByRow_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ResultByRow;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MySqlObject;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_IsSussess_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_IsSussess_SetBit(void* Obj)
	{
		((_Script_FJQMySql_eventSelectFromQueryDelegate_Parms*)Obj)->IsSussess = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_IsSussess = { "IsSussess", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(_Script_FJQMySql_eventSelectFromQueryDelegate_Parms), &Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_IsSussess_SetBit, METADATA_PARAMS(Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_IsSussess_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_IsSussess_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_FJQMySql_eventSelectFromQueryDelegate_Parms, Message), METADATA_PARAMS(Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_Message_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_Message_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_ResultByColumn_Inner = { "ResultByColumn", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FMySQLDataTable, METADATA_PARAMS(nullptr, 0) }; // 3678573362
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_ResultByColumn_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_ResultByColumn = { "ResultByColumn", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_FJQMySql_eventSelectFromQueryDelegate_Parms, ResultByColumn), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_ResultByColumn_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_ResultByColumn_MetaData)) }; // 3678573362
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_ResultByRow_Inner = { "ResultByRow", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FMySQLDataRow, METADATA_PARAMS(nullptr, 0) }; // 764463573
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_ResultByRow_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_ResultByRow = { "ResultByRow", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_FJQMySql_eventSelectFromQueryDelegate_Parms, ResultByRow), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_ResultByRow_MetaData, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_ResultByRow_MetaData)) }; // 764463573
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_MySqlObject = { "MySqlObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_FJQMySql_eventSelectFromQueryDelegate_Parms, MySqlObject), Z_Construct_UClass_UMySqlObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_IsSussess,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_Message,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_ResultByColumn_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_ResultByColumn,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_ResultByRow_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_ResultByRow,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::NewProp_MySqlObject,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/FJQMySqlBPLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_FJQMySql, nullptr, "SelectFromQueryDelegate__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::_Script_FJQMySql_eventSelectFromQueryDelegate_Parms), Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(UFJQMySqlBPLibrary::execFJQMySqlSampleFunction)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Param);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=UFJQMySqlBPLibrary::FJQMySqlSampleFunction(Z_Param_Param);
		P_NATIVE_END;
	}
	void UFJQMySqlBPLibrary::StaticRegisterNativesUFJQMySqlBPLibrary()
	{
		UClass* Class = UFJQMySqlBPLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FJQMySqlSampleFunction", &UFJQMySqlBPLibrary::execFJQMySqlSampleFunction },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UFJQMySqlBPLibrary_FJQMySqlSampleFunction_Statics
	{
		struct FJQMySqlBPLibrary_eventFJQMySqlSampleFunction_Parms
		{
			float Param;
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Param;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFJQMySqlBPLibrary_FJQMySqlSampleFunction_Statics::NewProp_Param = { "Param", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FJQMySqlBPLibrary_eventFJQMySqlSampleFunction_Parms, Param), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFJQMySqlBPLibrary_FJQMySqlSampleFunction_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FJQMySqlBPLibrary_eventFJQMySqlSampleFunction_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFJQMySqlBPLibrary_FJQMySqlSampleFunction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFJQMySqlBPLibrary_FJQMySqlSampleFunction_Statics::NewProp_Param,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFJQMySqlBPLibrary_FJQMySqlSampleFunction_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFJQMySqlBPLibrary_FJQMySqlSampleFunction_Statics::Function_MetaDataParams[] = {
		{ "Category", "FJQMySqlTesting" },
		{ "DisplayName", "Execute Sample function" },
		{ "Keywords", "FJQMySql sample test testing" },
		{ "ModuleRelativePath", "Public/FJQMySqlBPLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFJQMySqlBPLibrary_FJQMySqlSampleFunction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFJQMySqlBPLibrary, nullptr, "FJQMySqlSampleFunction", nullptr, nullptr, sizeof(Z_Construct_UFunction_UFJQMySqlBPLibrary_FJQMySqlSampleFunction_Statics::FJQMySqlBPLibrary_eventFJQMySqlSampleFunction_Parms), Z_Construct_UFunction_UFJQMySqlBPLibrary_FJQMySqlSampleFunction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFJQMySqlBPLibrary_FJQMySqlSampleFunction_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFJQMySqlBPLibrary_FJQMySqlSampleFunction_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFJQMySqlBPLibrary_FJQMySqlSampleFunction_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFJQMySqlBPLibrary_FJQMySqlSampleFunction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFJQMySqlBPLibrary_FJQMySqlSampleFunction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UFJQMySqlBPLibrary);
	UClass* Z_Construct_UClass_UFJQMySqlBPLibrary_NoRegister()
	{
		return UFJQMySqlBPLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UFJQMySqlBPLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFJQMySqlBPLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_FJQMySql,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UFJQMySqlBPLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UFJQMySqlBPLibrary_FJQMySqlSampleFunction, "FJQMySqlSampleFunction" }, // 180972492
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFJQMySqlBPLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "FJQMySqlBPLibrary.h" },
		{ "ModuleRelativePath", "Public/FJQMySqlBPLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFJQMySqlBPLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFJQMySqlBPLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UFJQMySqlBPLibrary_Statics::ClassParams = {
		&UFJQMySqlBPLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UFJQMySqlBPLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFJQMySqlBPLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFJQMySqlBPLibrary()
	{
		if (!Z_Registration_Info_UClass_UFJQMySqlBPLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UFJQMySqlBPLibrary.OuterSingleton, Z_Construct_UClass_UFJQMySqlBPLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UFJQMySqlBPLibrary.OuterSingleton;
	}
	template<> FJQMYSQL_API UClass* StaticClass<UFJQMySqlBPLibrary>()
	{
		return UFJQMySqlBPLibrary::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFJQMySqlBPLibrary);
	struct Z_CompiledInDeferFile_FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_Statics::ScriptStructInfo[] = {
		{ FMySQLDataTable::StaticStruct, Z_Construct_UScriptStruct_FMySQLDataTable_Statics::NewStructOps, TEXT("MySQLDataTable"), &Z_Registration_Info_UScriptStruct_MySQLDataTable, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMySQLDataTable), 3678573362U) },
		{ FMySQLDataRow::StaticStruct, Z_Construct_UScriptStruct_FMySQLDataRow_Statics::NewStructOps, TEXT("MySQLDataRow"), &Z_Registration_Info_UScriptStruct_MySQLDataRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMySQLDataRow), 764463573U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UFJQMySqlBPLibrary, UFJQMySqlBPLibrary::StaticClass, TEXT("UFJQMySqlBPLibrary"), &Z_Registration_Info_UClass_UFJQMySqlBPLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UFJQMySqlBPLibrary), 558358914U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_1776031863(TEXT("/Script/FJQMySql"),
		Z_CompiledInDeferFile_FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
