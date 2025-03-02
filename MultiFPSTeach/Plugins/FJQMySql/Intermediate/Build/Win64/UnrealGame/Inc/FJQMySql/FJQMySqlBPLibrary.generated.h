// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UMySqlObject;
struct FMySQLDataTable;
struct FMySQLDataRow;
class UObject;
class UMySqlSubSystem;
#ifdef FJQMYSQL_FJQMySqlBPLibrary_generated_h
#error "FJQMySqlBPLibrary.generated.h already included, missing '#pragma once' in FJQMySqlBPLibrary.h"
#endif
#define FJQMYSQL_FJQMySqlBPLibrary_generated_h

#define FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_14_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMySQLDataTable_Statics; \
	FJQMYSQL_API static class UScriptStruct* StaticStruct();


template<> FJQMYSQL_API UScriptStruct* StaticStruct<struct FMySQLDataTable>();

#define FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_26_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMySQLDataRow_Statics; \
	FJQMYSQL_API static class UScriptStruct* StaticStruct();


template<> FJQMYSQL_API UScriptStruct* StaticStruct<struct FMySQLDataRow>();

#define FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_32_DELEGATE \
struct _Script_FJQMySql_eventNewConnectionDelegate_Parms \
{ \
	bool IsSussess; \
	FString Message; \
	UMySqlObject* MySqlObject; \
}; \
static inline void FNewConnectionDelegate_DelegateWrapper(const FMulticastScriptDelegate& NewConnectionDelegate, bool IsSussess, const FString& Message, UMySqlObject* MySqlObject) \
{ \
	_Script_FJQMySql_eventNewConnectionDelegate_Parms Parms; \
	Parms.IsSussess=IsSussess ? true : false; \
	Parms.Message=Message; \
	Parms.MySqlObject=MySqlObject; \
	NewConnectionDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_33_DELEGATE \
struct _Script_FJQMySql_eventMakeFromQueryDelegate_Parms \
{ \
	bool IsSussess; \
	FString Message; \
	UMySqlObject* MySqlObject; \
}; \
static inline void FMakeFromQueryDelegate_DelegateWrapper(const FMulticastScriptDelegate& MakeFromQueryDelegate, bool IsSussess, const FString& Message, UMySqlObject* MySqlObject) \
{ \
	_Script_FJQMySql_eventMakeFromQueryDelegate_Parms Parms; \
	Parms.IsSussess=IsSussess ? true : false; \
	Parms.Message=Message; \
	Parms.MySqlObject=MySqlObject; \
	MakeFromQueryDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_35_DELEGATE \
struct _Script_FJQMySql_eventSelectFromQueryDelegate_Parms \
{ \
	bool IsSussess; \
	FString Message; \
	TArray<FMySQLDataTable> ResultByColumn; \
	TArray<FMySQLDataRow> ResultByRow; \
	UMySqlObject* MySqlObject; \
}; \
static inline void FSelectFromQueryDelegate_DelegateWrapper(const FMulticastScriptDelegate& SelectFromQueryDelegate, bool IsSussess, const FString& Message, TArray<FMySQLDataTable> const& ResultByColumn, TArray<FMySQLDataRow> const& ResultByRow, UMySqlObject* MySqlObject) \
{ \
	_Script_FJQMySql_eventSelectFromQueryDelegate_Parms Parms; \
	Parms.IsSussess=IsSussess ? true : false; \
	Parms.Message=Message; \
	Parms.ResultByColumn=ResultByColumn; \
	Parms.ResultByRow=ResultByRow; \
	Parms.MySqlObject=MySqlObject; \
	SelectFromQueryDelegate.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_40_SPARSE_DATA
#define FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_40_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetMySqlSubsystem); \
	DECLARE_FUNCTION(execFJQMySqlSampleFunction);


#define FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_40_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetMySqlSubsystem); \
	DECLARE_FUNCTION(execFJQMySqlSampleFunction);


#define FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_40_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFJQMySqlBPLibrary(); \
	friend struct Z_Construct_UClass_UFJQMySqlBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UFJQMySqlBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FJQMySql"), NO_API) \
	DECLARE_SERIALIZER(UFJQMySqlBPLibrary)


#define FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_40_INCLASS \
private: \
	static void StaticRegisterNativesUFJQMySqlBPLibrary(); \
	friend struct Z_Construct_UClass_UFJQMySqlBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UFJQMySqlBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FJQMySql"), NO_API) \
	DECLARE_SERIALIZER(UFJQMySqlBPLibrary)


#define FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_40_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFJQMySqlBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFJQMySqlBPLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFJQMySqlBPLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFJQMySqlBPLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFJQMySqlBPLibrary(UFJQMySqlBPLibrary&&); \
	NO_API UFJQMySqlBPLibrary(const UFJQMySqlBPLibrary&); \
public:


#define FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_40_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFJQMySqlBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFJQMySqlBPLibrary(UFJQMySqlBPLibrary&&); \
	NO_API UFJQMySqlBPLibrary(const UFJQMySqlBPLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFJQMySqlBPLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFJQMySqlBPLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFJQMySqlBPLibrary)


#define FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_37_PROLOG
#define FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_40_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_40_SPARSE_DATA \
	FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_40_RPC_WRAPPERS \
	FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_40_INCLASS \
	FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_40_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_40_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_40_SPARSE_DATA \
	FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_40_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_40_INCLASS_NO_PURE_DECLS \
	FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h_40_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class FJQMySqlBPLibrary."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FJQMYSQL_API UClass* StaticClass<class UFJQMySqlBPLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_FJQMySqlBPLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
