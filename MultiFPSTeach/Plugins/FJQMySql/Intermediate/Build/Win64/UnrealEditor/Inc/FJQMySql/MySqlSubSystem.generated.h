// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
 
class UMySqlObject;
#ifdef FJQMYSQL_MySqlSubSystem_generated_h
#error "MySqlSubSystem.generated.h already included, missing '#pragma once' in MySqlSubSystem.h"
#endif
#define FJQMYSQL_MySqlSubSystem_generated_h

#define FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_10_SPARSE_DATA
#define FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_10_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execLuaCreateNewMySqlConnection); \
	DECLARE_FUNCTION(execSelectFromQuery); \
	DECLARE_FUNCTION(execMakeMultipleQueries); \
	DECLARE_FUNCTION(execMakeQuery); \
	DECLARE_FUNCTION(execCloseConnection); \
	DECLARE_FUNCTION(execCloseAllConnections); \
	DECLARE_FUNCTION(execCreateNewMySqlConnection);


#define FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execLuaCreateNewMySqlConnection); \
	DECLARE_FUNCTION(execSelectFromQuery); \
	DECLARE_FUNCTION(execMakeMultipleQueries); \
	DECLARE_FUNCTION(execMakeQuery); \
	DECLARE_FUNCTION(execCloseConnection); \
	DECLARE_FUNCTION(execCloseAllConnections); \
	DECLARE_FUNCTION(execCreateNewMySqlConnection);


#define FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMySqlSubSystem(); \
	friend struct Z_Construct_UClass_UMySqlSubSystem_Statics; \
public: \
	DECLARE_CLASS(UMySqlSubSystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FJQMySql"), NO_API) \
	DECLARE_SERIALIZER(UMySqlSubSystem)


#define FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_10_INCLASS \
private: \
	static void StaticRegisterNativesUMySqlSubSystem(); \
	friend struct Z_Construct_UClass_UMySqlSubSystem_Statics; \
public: \
	DECLARE_CLASS(UMySqlSubSystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/FJQMySql"), NO_API) \
	DECLARE_SERIALIZER(UMySqlSubSystem)


#define FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_10_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UMySqlSubSystem(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UMySqlSubSystem) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMySqlSubSystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMySqlSubSystem); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMySqlSubSystem(UMySqlSubSystem&&); \
	NO_API UMySqlSubSystem(const UMySqlSubSystem&); \
public:


#define FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_10_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UMySqlSubSystem(UMySqlSubSystem&&); \
	NO_API UMySqlSubSystem(const UMySqlSubSystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMySqlSubSystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMySqlSubSystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMySqlSubSystem)


#define FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_7_PROLOG
#define FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_10_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_10_SPARSE_DATA \
	FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_10_RPC_WRAPPERS \
	FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_10_INCLASS \
	FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_10_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_10_SPARSE_DATA \
	FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_10_INCLASS_NO_PURE_DECLS \
	FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FJQMYSQL_API UClass* StaticClass<class UMySqlSubSystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_MultiFPSTeach_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlSubSystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
