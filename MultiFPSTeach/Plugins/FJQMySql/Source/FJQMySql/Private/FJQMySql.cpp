// Copyright (c) FJQ.2023.All Rights Reserved

#include "FJQMySql.h"

#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FFJQMySqlModule"

void FFJQMySqlModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	CopyDLL(TEXT("mysqlcppconn-9-vs14.dll"));
	CopyDLL(TEXT("libcrypto-1_1-x64.dll"));
	CopyDLL(TEXT("libssl-1_1-x64.dll"));
}

void FFJQMySqlModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

void FFJQMySqlModule::CopyDLL(FString DLLName)
{
	FString Pluginpath = IPluginManager::Get().FindPlugin(TEXT("FJQMySql"))->GetBaseDir();
	FString PluginDLLPath = FPaths::Combine(*Pluginpath, TEXT("Binaries"), TEXT("Win64"), DLLName);

	FString ProjectDirectory = FPaths::ProjectDir();
	FString ProjectDLLDirectory = FPaths::Combine(*ProjectDirectory, TEXT("Binaries"), TEXT("Win64"));

	FString ProjectDLLPath = FPaths::Combine(*ProjectDLLDirectory, DLLName);

	if (!FPaths::DirectoryExists(*ProjectDLLDirectory))
	{
		FPlatformFileManager::Get().GetPlatformFile().CreateDirectoryTree(*ProjectDLLDirectory);
	}

	if (FPaths::FileExists(ProjectDLLPath))
	{
		FPlatformFileManager::Get().GetPlatformFile().CopyFile(*PluginDLLPath, *ProjectDLLPath);
	}
	else if (FPaths::FileExists(PluginDLLPath))
	{
		FPlatformFileManager::Get().GetPlatformFile().CopyFile(*ProjectDLLPath, *PluginDLLPath);
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFJQMySqlModule, FJQMySql)