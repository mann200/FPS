// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FJQMySql/Public/MySqlCore/MySqlObject.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMySqlObject() {}
// Cross Module References
	FJQMYSQL_API UClass* Z_Construct_UClass_UMySqlObject_NoRegister();
	FJQMYSQL_API UClass* Z_Construct_UClass_UMySqlObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_FJQMySql();
	FJQMYSQL_API UFunction* Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature();
	FJQMYSQL_API UFunction* Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature();
// End Cross Module References
	void UMySqlObject::StaticRegisterNativesUMySqlObject()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMySqlObject);
	UClass* Z_Construct_UClass_UMySqlObject_NoRegister()
	{
		return UMySqlObject::StaticClass();
	}
	struct Z_Construct_UClass_UMySqlObject_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SelectFromQueryDelegate_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_SelectFromQueryDelegate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MakeFromQueryDelegate_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_MakeFromQueryDelegate;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMySqlObject_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_FJQMySql,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMySqlObject_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "MySqlCore/MySqlObject.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/MySqlCore/MySqlObject.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMySqlObject_Statics::NewProp_SelectFromQueryDelegate_MetaData[] = {
		{ "ModuleRelativePath", "Public/MySqlCore/MySqlObject.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UMySqlObject_Statics::NewProp_SelectFromQueryDelegate = { "SelectFromQueryDelegate", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMySqlObject, SelectFromQueryDelegate), Z_Construct_UDelegateFunction_FJQMySql_SelectFromQueryDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UMySqlObject_Statics::NewProp_SelectFromQueryDelegate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMySqlObject_Statics::NewProp_SelectFromQueryDelegate_MetaData)) }; // 1852560610
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMySqlObject_Statics::NewProp_MakeFromQueryDelegate_MetaData[] = {
		{ "ModuleRelativePath", "Public/MySqlCore/MySqlObject.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UMySqlObject_Statics::NewProp_MakeFromQueryDelegate = { "MakeFromQueryDelegate", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMySqlObject, MakeFromQueryDelegate), Z_Construct_UDelegateFunction_FJQMySql_MakeFromQueryDelegate__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UMySqlObject_Statics::NewProp_MakeFromQueryDelegate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UMySqlObject_Statics::NewProp_MakeFromQueryDelegate_MetaData)) }; // 1615037993
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMySqlObject_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMySqlObject_Statics::NewProp_SelectFromQueryDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMySqlObject_Statics::NewProp_MakeFromQueryDelegate,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMySqlObject_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMySqlObject>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMySqlObject_Statics::ClassParams = {
		&UMySqlObject::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UMySqlObject_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UMySqlObject_Statics::PropPointers),
		0,
		0x008000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMySqlObject_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UMySqlObject_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMySqlObject()
	{
		if (!Z_Registration_Info_UClass_UMySqlObject.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMySqlObject.OuterSingleton, Z_Construct_UClass_UMySqlObject_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMySqlObject.OuterSingleton;
	}
	template<> FJQMYSQL_API UClass* StaticClass<UMySqlObject>()
	{
		return UMySqlObject::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMySqlObject);
	struct Z_CompiledInDeferFile_FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlObject_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlObject_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMySqlObject, UMySqlObject::StaticClass, TEXT("UMySqlObject"), &Z_Registration_Info_UClass_UMySqlObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMySqlObject), 172384261U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlObject_h_3651657403(TEXT("/Script/FJQMySql"),
		Z_CompiledInDeferFile_FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlObject_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MySqlTest_Plugins_FJQMySql_Source_FJQMySql_Public_MySqlCore_MySqlObject_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
