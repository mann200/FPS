// Copyright (c) FJQ.2023.All Rights Reserved
#pragma once
#include "CoreMinimal.h"
#include "MySqlObject.h"
#include "MySqlSubSystem.generated.h"

UCLASS()
class UMySqlSubSystem : public UGameInstanceSubsystem 
{
	GENERATED_BODY()

public:
	UMySqlSubSystem();
	
#pragma region SubsystemOverride
	virtual bool ShouldCreateSubsystem(UObject* Outer) const  override;
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override ;
#pragma endregion
	
public:
	//用于存储已连接的数据库
	UPROPERTY()
	TMap<int32,UMySqlObject*> MySQLConnectors;
	UPROPERTY()
	int32 CurrentConnectionID;

public:
	
	UPROPERTY(BlueprintAssignable)
	FNewConnectionDelegate NewConnectionDelegate;
	
	//调用MySql方法
public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create MySql New Connection"), Category = "MySql|Subsystem")
	void CreateNewMySqlConnection(FString Server, FString DBName, FString UserID, FString Password,
		TMap<FString, FString> ExtraParams);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Close All Connections"), Category = "MySql|Subsystem")
	void CloseAllConnections();

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Close Connection"), Category = "MySql|Subsystem")
	void CloseConnection(UMySqlObject* MySqlObject);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Make Query"), Category = "MySql|Subsystem")
	void MakeQuery(UMySqlObject* MySqlObject, FString Query);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Make Multiple Queries"), Category = "MySql|Subsystem")
	void MakeMultipleQueries(UMySqlObject* MySqlObject, TArray<FString> Queries);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Select From Query"), Category = "MySql|Subsystem")
	void SelectFromQuery(UMySqlObject* MySqlObject, FString Query);
	
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Create MySql New Connection"), Category = "MySql|Subsystem")
	UMySqlObject* LuaCreateNewMySqlConnection(FString Server, FString DBName, FString UserID, FString Password,
	
	TMap<FString, FString> ExtraParams);
};




