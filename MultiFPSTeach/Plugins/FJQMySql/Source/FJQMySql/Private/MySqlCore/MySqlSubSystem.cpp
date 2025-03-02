// Copyright (c) FJQ.2023.All Rights Reserved
#include "MySqlCore/MySqlSubSystem.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Log/LogFJQMySql.h"
#include "MySqlCore/DLLManager.h"
#include "MySqlCore/MySqlTask.h"

UMySqlSubSystem::UMySqlSubSystem()
{
	
}

bool UMySqlSubSystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return Super::ShouldCreateSubsystem(Outer);
}

void UMySqlSubSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UMySqlSubSystem::Deinitialize()
{
	Super::Deinitialize();
}

UMySqlObject* UMySqlSubSystem::LuaCreateNewMySqlConnection(FString Server, FString DBName, FString UserID, FString Password,
														TMap<FString, FString> ExtraParams)
{
	UMySqlObject* NewMySqlObj = NewObject<UMySqlObject>();
	if (!MySQLConnectors.Contains(CurrentConnectionID))
	{
		MySQLConnectors.Add(CurrentConnectionID);
		MySQLConnectors[CurrentConnectionID] = NewMySqlObj;
	}
	//创建连接数据库任务
	FAsyncTask<NewConnectionTask>* ConnectionTask = new  FAsyncTask<NewConnectionTask>(Server,DBName,UserID,Password,ExtraParams,NewMySqlObj);
	ConnectionTask->StartBackgroundTask();

	return NewMySqlObj;
}

void UMySqlSubSystem::CreateNewMySqlConnection(FString Server, FString DBName, FString UserID, FString Password,
                                                        TMap<FString, FString> ExtraParams)
{
	UMySqlObject* NewMySqlObj = NewObject<UMySqlObject>();
	if (!MySQLConnectors.Contains(CurrentConnectionID))
	{
		MySQLConnectors.Add(CurrentConnectionID);
		MySQLConnectors[CurrentConnectionID] = NewMySqlObj;
	}
	//创建连接数据库任务
	FAsyncTask<NewConnectionTask>* ConnectionTask = new  FAsyncTask<NewConnectionTask>(Server,DBName,UserID,Password,ExtraParams,NewMySqlObj);
	ConnectionTask->StartBackgroundTask();
}


void UMySqlSubSystem::CloseAllConnections()
{
	CurrentConnectionID = 0;
	for (auto& param : MySQLConnectors)
	{
		if (param.Value)
		{
			param.Value->CloseConnection();
			param.Value = nullptr;
		}
	}
	MySQLConnectors.Empty();
}

void UMySqlSubSystem::CloseConnection(UMySqlObject* MySqlObject)
{
	if (MySqlObject)
	{
		MySqlObject->CloseConnection();
	}
}

void UMySqlSubSystem::MakeQuery(UMySqlObject* MySqlObject, FString Query)
{
	if (MySqlObject)
	{
		TArray<FString> QueryArray;
		QueryArray.Add(Query);
		//创建查询任务
		FAsyncTask<MakeQueryAsyncTask>* MakeQueryTask = new FAsyncTask<MakeQueryAsyncTask>(QueryArray,MySqlObject);
		MakeQueryTask->StartBackgroundTask();
	}
}

void UMySqlSubSystem::MakeMultipleQueries(UMySqlObject* MySqlObject, TArray<FString> Queries)
{

	if (MySqlObject)
	{
		FAsyncTask<MakeQueryAsyncTask>* MakeQueryTask = new FAsyncTask<MakeQueryAsyncTask>(Queries,MySqlObject);
		MakeQueryTask->StartBackgroundTask();
	}
}

void UMySqlSubSystem::SelectFromQuery(UMySqlObject* MySqlObject, FString Query)
{
	if (MySqlObject)
	{
		//创建查询任务
		FAsyncTask<SeleteQueryAsyncTask>* SeleteQueryTask = new FAsyncTask<SeleteQueryAsyncTask>(Query,MySqlObject);
		SeleteQueryTask->StartBackgroundTask();
	}
}
/*
void UMySqlSubSystem::InsertImageFromPathQuery(UMySqlObject* MySqlObject, FString DialogueTitle, FString FileTypes,FString TableName,FString ImageName,bool multiselect)
{
	if (MySqlObject)
	{
		if (DLLManager::LoadDLL("FileBrowser.dll"))
		{
			FString Query = TEXT("INSERT INTO ImageData(image)VALUES (@image)"); 
			TArray<FString> FileNames;
			FileNames = DLLManager::GetOpenFileDialogue(DialogueTitle,FileTypes,multiselect);
			if(FileNames.Num() > 0 )
			{
				DLLManager::UnLoadDLL();
				FAsyncTask<InsertImageQueryAsyncTask>* InsertImageTask = new FAsyncTask<InsertImageQueryAsyncTask>(MySqlObject,TableName,ImageName,FileNames);
				InsertImageTask->StartBackgroundTask();
			}
		}
		DLLManager::UnLoadDLL();
	}
}

void UMySqlSubSystem::SelectImageQuery(UMySqlObject* MySqlObject, FString Query,FString ColumnName)
{
	if (MySqlObject)
	{
		FAsyncTask<SeleteImageQueryAsyncTask>* SeleteImageTask = new FAsyncTask<SeleteImageQueryAsyncTask>(MySqlObject,Query,ColumnName);
		SeleteImageTask->StartBackgroundTask();
	}
}
*/



