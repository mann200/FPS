// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FJQMySql/Public/MySqlCore/MySqlSubSystem.h"
#include "Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMySqlSubSystem() {}
// Cross Module References
	FJQMYSQL_API UClass* Z_Construct_UClass_UMySqlSubSystem_NoRegister();
	FJQMYSQL_API UClass* Z_Construct_UClass_UMySqlSubSystem();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	UPackage* Z_Construct_UPackage__Script_FJQMySql();
	FJQMYSQL_API UClass* Z_Construct_UClass_UMySqlObject_NoRegister();
	FJQMYSQL_API UFunction* Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature();
// End Cross Module References
	DEFINE_FUNCTION(UMySqlSubSystem::execSelectFromQuery)
	{
		P_GET_OBJECT(UMySqlObject,Z_Param_MySqlObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_Query);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SelectFromQuery(Z_Param_MySqlObject,Z_Param_Query);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMySqlSubSystem::execMakeMultipleQueries)
	{
		P_GET_OBJECT(UMySqlObject,Z_Param_MySqlObject);
		P_GET_TARRAY(FString,Z_Param_Queries);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MakeMultipleQueries(Z_Param_MySqlObject,Z_Param_Queries);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMySqlSubSystem::execMakeQuery)
	{
		P_GET_OBJECT(UMySqlObject,Z_Param_MySqlObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_Query);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MakeQuery(Z_Param_MySqlObject,Z_Param_Query);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMySqlSubSystem::execCloseConnection)
	{
		P_GET_OBJECT(UMySqlObject,Z_Param_MySqlObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CloseConnection(Z_Param_MySqlObject);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMySqlSubSystem::execCloseAllConnections)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CloseAllConnections();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMySqlSubSystem::execCreateNewMySqlConnection)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Server);
		P_GET_PROPERTY(FStrProperty,Z_Param_DBName);
		P_GET_PROPERTY(FStrProperty,Z_Param_UserID);
		P_GET_PROPERTY(FStrProperty,Z_Param_Password);
		P_GET_TMAP(FString,FString,Z_Param_ExtraParams);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CreateNewMySqlConnection(Z_Param_Server,Z_Param_DBName,Z_Param_UserID,Z_Param_Password,Z_Param_ExtraParams);
		P_NATIVE_END;
	}
	void UMySqlSubSystem::StaticRegisterNativesUMySqlSubSystem()
	{
		UClass* Class = UMySqlSubSystem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CloseAllConnections", &UMySqlSubSystem::execCloseAllConnections },
			{ "CloseConnection", &UMySqlSubSystem::execCloseConnection },
			{ "CreateNewMySqlConnection", &UMySqlSubSystem::execCreateNewMySqlConnection },
			{ "MakeMultipleQueries", &UMySqlSubSystem::execMakeMultipleQueries },
			{ "MakeQuery", &UMySqlSubSystem::execMakeQuery },
			{ "SelectFromQuery", &UMySqlSubSystem::execSelectFromQuery },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMySqlSubSystem_CloseAllConnections_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMySqlSubSystem_CloseAllConnections_Statics::Function_MetaDataParams[] = {
		{ "Category", "MySql|Subsystem" },
		{ "DisplayName", "Close All Connections" },
		{ "ModuleRelativePath", "Public/MySqlCore/MySqlSubSystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMySqlSubSystem_CloseAllConnections_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMySqlSubSystem, nullptr, "CloseAllConnections", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMySqlSubSystem_CloseAllConnections_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMySqlSubSystem_CloseAllConnections_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMySqlSubSystem_CloseAllConnections()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMySqlSubSystem_CloseAllConnections_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMySqlSubSystem_CloseConnection_Statics
	{
		struct MySqlSubSystem_eventCloseConnection_Parms
		{
			UMySqlObject* MySqlObject;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MySqlObject;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMySqlSubSystem_CloseConnection_Statics::NewProp_MySqlObject = { "MySqlObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MySqlSubSystem_eventCloseConnection_Parms, MySqlObject), Z_Construct_UClass_UMySqlObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMySqlSubSystem_CloseConnection_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMySqlSubSystem_CloseConnection_Statics::NewProp_MySqlObject,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMySqlSubSystem_CloseConnection_Statics::Function_MetaDataParams[] = {
		{ "Category", "MySql|Subsystem" },
		{ "DisplayName", "Close Connection" },
		{ "ModuleRelativePath", "Public/MySqlCore/MySqlSubSystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMySqlSubSystem_CloseConnection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMySqlSubSystem, nullptr, "CloseConnection", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMySqlSubSystem_CloseConnection_Statics::MySqlSubSystem_eventCloseConnection_Parms), Z_Construct_UFunction_UMySqlSubSystem_CloseConnection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMySqlSubSystem_CloseConnection_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMySqlSubSystem_CloseConnection_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMySqlSubSystem_CloseConnection_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMySqlSubSystem_CloseConnection()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMySqlSubSystem_CloseConnection_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics
	{
		struct MySqlSubSystem_eventCreateNewMySqlConnection_Parms
		{
			FString Server;
			FString DBName;
			FString UserID;
			FString Password;
			TMap<FString,FString> ExtraParams;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_Server;
		static const UECodeGen_Private::FStrPropertyParams NewProp_DBName;
		static const UECodeGen_Private::FStrPropertyParams NewProp_UserID;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Password;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ExtraParams_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ExtraParams_Key_KeyProp;
		static const UECodeGen_Private::FMapPropertyParams NewProp_ExtraParams;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::NewProp_Server = { "Server", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MySqlSubSystem_eventCreateNewMySqlConnection_Parms, Server), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::NewProp_DBName = { "DBName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MySqlSubSystem_eventCreateNewMySqlConnection_Parms, DBName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::NewProp_UserID = { "UserID", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MySqlSubSystem_eventCreateNewMySqlConnection_Parms, UserID), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::NewProp_Password = { "Password", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MySqlSubSystem_eventCreateNewMySqlConnection_Parms, Password), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::NewProp_ExtraParams_ValueProp = { "ExtraParams", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::NewProp_ExtraParams_Key_KeyProp = { "ExtraParams_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::NewProp_ExtraParams = { "ExtraParams", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MySqlSubSystem_eventCreateNewMySqlConnection_Parms, ExtraParams), EMapPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::NewProp_Server,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::NewProp_DBName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::NewProp_UserID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::NewProp_Password,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::NewProp_ExtraParams_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::NewProp_ExtraParams_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::NewProp_ExtraParams,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::Function_MetaDataParams[] = {
		{ "Category", "MySql|Subsystem" },
		{ "DisplayName", "Create MySql New Connection" },
		{ "ModuleRelativePath", "Public/MySqlCore/MySqlSubSystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMySqlSubSystem, nullptr, "CreateNewMySqlConnection", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::MySqlSubSystem_eventCreateNewMySqlConnection_Parms), Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMySqlSubSystem_MakeMultipleQueries_Statics
	{
		struct MySqlSubSystem_eventMakeMultipleQueries_Parms
		{
			UMySqlObject* MySqlObject;
			TArray<FString> Queries;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MySqlObject;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Queries_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Queries;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMySqlSubSystem_MakeMultipleQueries_Statics::NewProp_MySqlObject = { "MySqlObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MySqlSubSystem_eventMakeMultipleQueries_Parms, MySqlObject), Z_Construct_UClass_UMySqlObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMySqlSubSystem_MakeMultipleQueries_Statics::NewProp_Queries_Inner = { "Queries", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UMySqlSubSystem_MakeMultipleQueries_Statics::NewProp_Queries = { "Queries", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MySqlSubSystem_eventMakeMultipleQueries_Parms, Queries), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMySqlSubSystem_MakeMultipleQueries_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMySqlSubSystem_MakeMultipleQueries_Statics::NewProp_MySqlObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMySqlSubSystem_MakeMultipleQueries_Statics::NewProp_Queries_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMySqlSubSystem_MakeMultipleQueries_Statics::NewProp_Queries,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMySqlSubSystem_MakeMultipleQueries_Statics::Function_MetaDataParams[] = {
		{ "Category", "MySql|Subsystem" },
		{ "DisplayName", "Make Multiple Queries" },
		{ "ModuleRelativePath", "Public/MySqlCore/MySqlSubSystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMySqlSubSystem_MakeMultipleQueries_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMySqlSubSystem, nullptr, "MakeMultipleQueries", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMySqlSubSystem_MakeMultipleQueries_Statics::MySqlSubSystem_eventMakeMultipleQueries_Parms), Z_Construct_UFunction_UMySqlSubSystem_MakeMultipleQueries_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMySqlSubSystem_MakeMultipleQueries_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMySqlSubSystem_MakeMultipleQueries_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMySqlSubSystem_MakeMultipleQueries_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMySqlSubSystem_MakeMultipleQueries()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMySqlSubSystem_MakeMultipleQueries_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMySqlSubSystem_MakeQuery_Statics
	{
		struct MySqlSubSystem_eventMakeQuery_Parms
		{
			UMySqlObject* MySqlObject;
			FString Query;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MySqlObject;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Query;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMySqlSubSystem_MakeQuery_Statics::NewProp_MySqlObject = { "MySqlObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MySqlSubSystem_eventMakeQuery_Parms, MySqlObject), Z_Construct_UClass_UMySqlObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMySqlSubSystem_MakeQuery_Statics::NewProp_Query = { "Query", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MySqlSubSystem_eventMakeQuery_Parms, Query), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMySqlSubSystem_MakeQuery_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMySqlSubSystem_MakeQuery_Statics::NewProp_MySqlObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMySqlSubSystem_MakeQuery_Statics::NewProp_Query,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMySqlSubSystem_MakeQuery_Statics::Function_MetaDataParams[] = {
		{ "Category", "MySql|Subsystem" },
		{ "DisplayName", "Make Query" },
		{ "ModuleRelativePath", "Public/MySqlCore/MySqlSubSystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMySqlSubSystem_MakeQuery_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMySqlSubSystem, nullptr, "MakeQuery", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMySqlSubSystem_MakeQuery_Statics::MySqlSubSystem_eventMakeQuery_Parms), Z_Construct_UFunction_UMySqlSubSystem_MakeQuery_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMySqlSubSystem_MakeQuery_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMySqlSubSystem_MakeQuery_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMySqlSubSystem_MakeQuery_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMySqlSubSystem_MakeQuery()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMySqlSubSystem_MakeQuery_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMySqlSubSystem_SelectFromQuery_Statics
	{
		struct MySqlSubSystem_eventSelectFromQuery_Parms
		{
			UMySqlObject* MySqlObject;
			FString Query;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MySqlObject;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Query;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UMySqlSubSystem_SelectFromQuery_Statics::NewProp_MySqlObject = { "MySqlObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MySqlSubSystem_eventSelectFromQuery_Parms, MySqlObject), Z_Construct_UClass_UMySqlObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UMySqlSubSystem_SelectFromQuery_Statics::NewProp_Query = { "Query", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MySqlSubSystem_eventSelectFromQuery_Parms, Query), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMySqlSubSystem_SelectFromQuery_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMySqlSubSystem_SelectFromQuery_Statics::NewProp_MySqlObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMySqlSubSystem_SelectFromQuery_Statics::NewProp_Query,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMySqlSubSystem_SelectFromQuery_Statics::Function_MetaDataParams[] = {
		{ "Category", "MySql|Subsystem" },
		{ "DisplayName", "Select From Query" },
		{ "ModuleRelativePath", "Public/MySqlCore/MySqlSubSystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMySqlSubSystem_SelectFromQuery_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMySqlSubSystem, nullptr, "SelectFromQuery", nullptr, nullptr, sizeof(Z_Construct_UFunction_UMySqlSubSystem_SelectFromQuery_Statics::MySqlSubSystem_eventSelectFromQuery_Parms), Z_Construct_UFunction_UMySqlSubSystem_SelectFromQuery_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMySqlSubSystem_SelectFromQuery_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UMySqlSubSystem_SelectFromQuery_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UMySqlSubSystem_SelectFromQuery_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UMySqlSubSystem_SelectFromQuery()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMySqlSubSystem_SelectFromQuery_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMySqlSubSystem);
	UClass* Z_Construct_UClass_UMySqlSubSystem_NoRegister()
	{
		return UMySqlSubSystem::StaticClass();
	}
	struct Z_Construct_UClass_UMySqlSubSystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MySQLConnectors_ValueProp;
		static const UECodeGen_Private::FIntPropertyParams NewProp_MySQLConnectors_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MySQLConnectors_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_MySQLConnectors;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentConnectionID_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentConnectionID;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NewConnectionDelegate_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_NewConnectionDelegate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMySqlSubSystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_FJQMySql,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UMySqlSubSystem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMySqlSubSystem_CloseAllConnections, "CloseAllConnections" }, // 2104468770
		{ &Z_Construct_UFunction_UMySqlSubSystem_CloseConnection, "CloseConnection" }, // 205942261
		{ &Z_Construct_UFunction_UMySqlSubSystem_CreateNewMySqlConnection, "CreateNewMySqlConnection" }, // 533003938
		{ &Z_Construct_UFunction_UMySqlSubSystem_MakeMultipleQueries, "MakeMultipleQueries" }, // 613389969
		{ &Z_Construct_UFunction_UMySqlSubSystem_MakeQuery, "MakeQuery" }, // 1986715049
		{ &Z_Construct_UFunction_UMySqlSubSystem_SelectFromQuery, "SelectFromQuery" }, // 193321998
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMySqlSubSystem_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MySqlCore/MySqlSubSystem.h" },
		{ "ModuleRelativePath", "Public/MySqlCore/MySqlSubSystem.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMySqlSubSystem_Statics::NewProp_MySQLConnectors_ValueProp = { "MySQLConnectors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UClass_UMySqlObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMySqlSubSystem_Statics::NewProp_MySQLConnectors_Key_KeyProp = { "MySQLConnectors_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMySqlSubSystem_Statics::NewProp_MySQLConnectors_MetaData[] = {
		{ "Comment", "//\xe7\x94\xa8\xe4\xba\x8e\xe5\xad\x98\xe5\x82\xa8\xe5\xb7\xb2\xe8\xbf\x9e\xe6\x8e\xa5\xe7\x9a\x84\xe6\x95\xb0\xe6\x8d\xae\xe5\xba\x93\n" },
		{ "ModuleRelativePath", "Public/MySqlCore/MySqlSubSystem.h" },
		{ "ToolTip", "\xe7\x94\xa8\xe4\xba\x8e\xe5\xad\x98\xe5\x82\xa8\xe5\xb7\xb2\xe8\xbf\x9e\xe6\x8e\xa5\xe7\x9a\x84\xe6\x95\xb0\xe6\x8d\xae\xe5\xba\x93" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UMySqlSubSystem_Statics::NewProp_MySQLConnectors = { "MySQLConnectors", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMySqlSubSystem, MySQLConnectors), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UMySqlSubSystem_Statics::NewProp_MySQLConnectors_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMySqlSubSystem_Statics::NewProp_MySQLConnectors_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMySqlSubSystem_Statics::NewProp_CurrentConnectionID_MetaData[] = {
		{ "ModuleRelativePath", "Public/MySqlCore/MySqlSubSystem.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMySqlSubSystem_Statics::NewProp_CurrentConnectionID = { "CurrentConnectionID", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMySqlSubSystem, CurrentConnectionID), METADATA_PARAMS(Z_Construct_UClass_UMySqlSubSystem_Statics::NewProp_CurrentConnectionID_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMySqlSubSystem_Statics::NewProp_CurrentConnectionID_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMySqlSubSystem_Statics::NewProp_NewConnectionDelegate_MetaData[] = {
		{ "Comment", "/*\n\x09""FAsyncTask<NewConnectionTask>* ConnectionTask = nullptr;\n\x09""FAsyncTask<MakeQueryAsyncTask>* MakeQueryTask = nullptr;\n\x09""FAsyncTask<SeleteQueryAsyncTask>* SeleteQueryTask = nullptr;\n\x09*/" },
		{ "ModuleRelativePath", "Public/MySqlCore/MySqlSubSystem.h" },
		{ "ToolTip", "FAsyncTask<NewConnectionTask>* ConnectionTask = nullptr;\nFAsyncTask<MakeQueryAsyncTask>* MakeQueryTask = nullptr;\nFAsyncTask<SeleteQueryAsyncTask>* SeleteQueryTask = nullptr;" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UMySqlSubSystem_Statics::NewProp_NewConnectionDelegate = { "NewConnectionDelegate", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMySqlSubSystem, NewConnectionDelegate), Z_Construct_UDelegateFunction_FJQMySql_NewConnectionDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UMySqlSubSystem_Statics::NewProp_NewConnectionDelegate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMySqlSubSystem_Statics::NewProp_NewConnectionDelegate_MetaData)) }; // 3833732811
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMySqlSubSystem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMySqlSubSystem_Statics::NewProp_MySQLConnectors_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMySqlSubSystem_Statics::NewProp_MySQLConnectors_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMySqlSubSystem_Statics::NewProp_MySQLConnectors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMySqlSubSystem_Statics::NewProp_CurrentConnectionID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMySqlSubSystem_Statics::NewProp_NewConnectionDelegate,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMySqlSubSystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMySqlSubSystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMySqlSubSystem_Statics::ClassParams = {
		&UMySqlSubSystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UMySqlSubSystem_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UMySqlSubSystem_Statics::PropPointers),
		0,
		0x008000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMySqlSubSystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMySqlSubSystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMySqlSubSystem()
	{
		if (!Z_Registration_Info_UClass_UMySqlSubSystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMySqlSubSystem.OuterSingleton, Z_Construct_UClass_UMySqlSubSystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMySqlSubSystem.OuterSingleton;
	}
	template<> FJQMYSQL_API UClass* StaticClass<UMySqlSubSystem>()
	{
		return UMySqlSubSystem::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMySqlSubSystem);
	struct Z_CompiledInDeferFile_FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMySqlSubSystem, UMySqlSubSystem::StaticClass, TEXT("UMySqlSubSystem"), &Z_Registration_Info_UClass_UMySqlSubSystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMySqlSubSystem), 310779030U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_806845619(TEXT("/Script/FJQMySql"),
		Z_CompiledInDeferFile_FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
