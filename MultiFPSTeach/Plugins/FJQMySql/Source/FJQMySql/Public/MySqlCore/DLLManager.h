// Copyright (c) FJQ.2023.All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "FJQMySqlBPLibrary.h"
//#include "Misc/Paths.h"
//#include "PlatformFeatures.h"
//#include "Misc/FileHelper.h"
//#include "HAL/PlatformFilemanager.h"

#if PLATFORM_WINDOWS
	#include "Windows/WindowsPlatformProcess.h"
	#include <map>
	#include <string>
	#include <vector>
using namespace std;

static class DLLManager
{
private:

	static TArray<FString> GetSplitStringArray(FString Input, const TCHAR* Pattern);

public:
	
	static bool LoadDLL(FString DLLName);
	
	static void UnLoadDLL();

	static TArray<FString> GetOpenFileDialogue(FString DialogueTitle, FString FileTypes, bool multiselect);
	
	static bool CreateConnection(int ConnectionID, FString Server, FString DBName, FString UserID, FString Password, TMap<FString, FString> ExtraParams,
		FString& ErrorMessage);

	static bool UpdateFromQuery(int ConnectionID, FString Query, FString& ErrorMessage);
	static bool SelectFromQuery(int ConnectionID, FString Query, FString& ErrorMessage, TArray<FMySQLDataTable>& ResultByColumn, TArray<FMySQLDataRow>& ResultByRow);

	static bool GetSqlData(int ConnectionID, FString Query, FString& ErrorMessage, TArray<FMySQLDataTable>& ResultByColumn, TArray<FMySQLDataRow>& ResultByRow);

	static void CloseConnection(int ConnectionID);

	//static bool UpdateImageFromPath(int ConnectionID, FString Query, char* ImageChar, FString& ErrorMessage);
	//static TArray<UTexture2D*> SelectImageFromQuery(int ConnectionID, FString Query,FString ColumnName,FString& ErrorMessage);
};

#endif

