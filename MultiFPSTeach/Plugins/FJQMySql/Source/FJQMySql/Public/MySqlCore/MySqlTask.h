// Copyright (c) FJQ.2023.All Rights Reserved
#pragma once
#include "CoreMinimal.h"
#include "MySqlObject.h"

class FJQMYSQL_API NewConnectionTask : public FNonAbandonableTask
{
private:
	FString ServerIPAndPort;
	FString DBName;
	FString UserID;
	FString Password;
	TMap<FString, FString> ExtraParams;
	UMySqlObject* MySqlObject;

public:
	NewConnectionTask(FString ServerIPAndPort, FString DB, FString User, FString UserPassword,
		TMap<FString, FString> Params,UMySqlObject* MySql);
	
	virtual ~NewConnectionTask();
	virtual void DoWork();
	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(NewConnectionTask, STATGROUP_ThreadPoolAsyncTasks);
	}
};

class FJQMYSQL_API MakeQueryAsyncTask : public FNonAbandonableTask
{
private:
	TArray<FString> QueryArray;
	UMySqlObject* MySqlObject;

public:
	MakeQueryAsyncTask(TArray<FString> Queries,UMySqlObject* MySql);

	virtual ~MakeQueryAsyncTask();
	virtual void DoWork();
	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(MakeQueryAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
	}
};

class FJQMYSQL_API SeleteQueryAsyncTask : public FNonAbandonableTask
{
private:
	FString Query;
	UMySqlObject* MySqlObject;

public:
	SeleteQueryAsyncTask(FString Query1,UMySqlObject* MySql);

	virtual ~SeleteQueryAsyncTask();
	virtual void DoWork();
	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(SeleteQueryAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
	}
};
/*
class FJQMYSQL_API InsertImageQueryAsyncTask : public FNonAbandonableTask
{
private:
	UMySqlObject* MySqlObject;
	FString TableName;
	FString ImageName;
	TArray<FString> FileNames;
	
public:
	InsertImageQueryAsyncTask(UMySqlObject* MySql,FString TName,FString IName,TArray<FString> FileNameArray);

	virtual ~InsertImageQueryAsyncTask();
	virtual void DoWork();
	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(InsertImageQueryAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
	}
};

class FJQMYSQL_API SeleteImageQueryAsyncTask : public FNonAbandonableTask
{
private:
	UMySqlObject* MySqlObject;
	FString Query;
	FString ColumnName;
	
public:
	SeleteImageQueryAsyncTask(UMySqlObject* MySql,FString Q,FString CName);

	virtual ~SeleteImageQueryAsyncTask();
	virtual void DoWork();
	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(SeleteImageQueryAsyncTask, STATGROUP_ThreadPoolAsyncTasks);
	}
};

*/
