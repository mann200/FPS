// Copyright (c) FJQ.2023.All Rights Reserved
#include "MySqlCore/MySqlTask.h"
#include "MySqlCore/DLLManager.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>


NewConnectionTask::NewConnectionTask(FString Server, FString DB, FString User, FString UserPassword,
                                     TMap<FString, FString> Params,UMySqlObject* MySql)
{
	ServerIPAndPort = Server;
	DBName = DB;
	UserID = User;
	Password = UserPassword;
	ExtraParams = Params;
	MySqlObject = MySql;
}

NewConnectionTask::~NewConnectionTask()
{
}

void NewConnectionTask::DoWork()
{
	if (MySqlObject)
	{
		MySqlObject->CreateNewConnection(ServerIPAndPort,DBName,UserID,Password,ExtraParams);
	}
}

MakeQueryAsyncTask::MakeQueryAsyncTask(TArray<FString> Queries, UMySqlObject* MySql)
{
	QueryArray = Queries;
	MySqlObject = MySql;
}

MakeQueryAsyncTask::~MakeQueryAsyncTask()
{
	
}

void MakeQueryAsyncTask::DoWork()
{
	if (MySqlObject)
	{
		FString ErrorMessage;
		for (auto Query : QueryArray)
		{
			MySqlObject->MakeFromQuery(Query);
		}
	}
}

SeleteQueryAsyncTask::SeleteQueryAsyncTask(FString Query1, UMySqlObject* MySql)
{
	Query = Query1;
	MySqlObject = MySql;
}

SeleteQueryAsyncTask::~SeleteQueryAsyncTask()
{
}

void SeleteQueryAsyncTask::DoWork()
{
	if (MySqlObject)
	{
		MySqlObject->SelectFromQuery(Query);
	}
}

/*
InsertImageQueryAsyncTask::InsertImageQueryAsyncTask(UMySqlObject* MySql, FString TName, FString IName,
	TArray<FString> FileNameArray)
{
	MySqlObject = MySql;
	TableName = TName;
	ImageName = IName;
	FileNames = FileNameArray;
}

InsertImageQueryAsyncTask::~InsertImageQueryAsyncTask()
{
}

void InsertImageQueryAsyncTask::DoWork()
{
	if (MySqlObject)
	{
		FString Query = TEXT("INSERT INTO ") + TableName + TEXT("(")  +ImageName +TEXT(") VALUES ");
		char* QueryValue;
		for (FString Param : FileNames)
		{
			QueryValue = UFJQMySqlBPLibrary::GetImageDataFromPath(Param);
			int32 Length = MultiByteToWideChar(CP_UTF8, 0, QueryValue, -1, nullptr, 0);
			wchar_t* WideStr = new wchar_t[Length];
			MultiByteToWideChar(CP_UTF8, 0, QueryValue, -1, WideStr, Length);
			FString fs(WideStr);
			delete[] WideStr;
			if (QueryValue != nullptr)
			{
				Query = Query + TEXT("('") + fs + TEXT("')");
				MySqlObject->MakeFromQuery(Query);
				//MySqlObject->UpdataImageFromQuery(Query,QueryValue);
			}
		}
	}
	
}

SeleteImageQueryAsyncTask::SeleteImageQueryAsyncTask(UMySqlObject* MySql, FString Q,FString CName)
{
	MySqlObject = MySql;
	Query = Q;
	ColumnName = CName;
}

SeleteImageQueryAsyncTask::~SeleteImageQueryAsyncTask()
{
}

void SeleteImageQueryAsyncTask::DoWork()
{
	if (MySqlObject)
	{
		MySqlObject->SeleteImageFromQuery(Query,ColumnName);
	}
}
*/
