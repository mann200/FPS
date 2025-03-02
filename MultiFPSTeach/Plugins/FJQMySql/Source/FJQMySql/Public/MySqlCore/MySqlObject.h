// Copyright (c) FJQ.2023.All Rights Reserved
#pragma once
#include "CoreMinimal.h"
#include "FJQMySqlBPLibrary.h"
#include "MySqlObject.generated.h"

UCLASS(Blueprintable)
class UMySqlObject : public UObject
{
	GENERATED_BODY()
private:
	UMySqlObject();

public:
	UWorld* World = nullptr;
	
public:
	UPROPERTY(BlueprintAssignable)
	FSelectFromQueryDelegate SelectFromQueryDelegate;
	UPROPERTY(BlueprintAssignable)
	FMakeFromQueryDelegate MakeFromQueryDelegate;
	UPROPERTY(BlueprintAssignable)
	FSeleteImageFromQueryDelegate SeleteImageDelegate;
	
	bool IsSussess;
	FString ErrorMessage;
	TArray<FMySQLDataTable> ResultByColumn;
	TArray<FMySQLDataRow> ResultByRow;

//SubSystem系统调用数据库函数
	void CreateNewConnection(FString Server, FString DBName, FString UserID, FString Password, TMap<FString, FString> ExtraParams);
	void CloseConnection();
	void MakeFromQuery(FString Query);
	void SelectFromQuery(FString Query);

	//void UpdataImageFromQuery(FString Query,char* ImageChar);
	//void SeleteImageFromQuery(FString Query,FString ColumnName);
	
//Http系统调用数据库函数
	UMySqlObject* CreateConnection(FString Server, FString DBName, FString UserID, FString Password, TMap<FString, FString> ExtraParams);
	bool HttpMakeFromQuery(FString Query);
	bool HttpSelectFromQuery(FString Query,TArray<FMySQLDataTable>& ResultColumn,TArray<FMySQLDataRow>& ResultRow);
	
};

