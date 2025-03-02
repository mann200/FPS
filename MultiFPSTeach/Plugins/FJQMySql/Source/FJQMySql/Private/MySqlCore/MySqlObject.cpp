// Copyright (c) FJQ.2023.All Rights Reserved
#include "MySqlCore/MySqlObject.h"
#include "Kismet/GameplayStatics.h"
#include "MySqlCore/DLLManager.h"
#include "MySqlCore/MySqlSubSystem.h"


UMySqlObject::UMySqlObject()
{
	World = GWorld->GetWorld();
}

void UMySqlObject::CreateNewConnection(FString Server, FString DBName, FString UserID, FString Password,
	TMap<FString, FString> ExtraParams)
{
	if (DLLManager::LoadDLL("MySQLLibrary.dll"))
	{
		IsSussess = DLLManager::CreateConnection(0,Server,DBName,UserID,Password,ExtraParams,ErrorMessage);
		UGameInstance* GameInstace = UGameplayStatics::GetGameInstance(World);
		if (GameInstace)
		{
			UMySqlSubSystem* MySqlSubSystem = GameInstace->GetSubsystem<UMySqlSubSystem>();
			if (MySqlSubSystem)
			{
				if (IsSussess)
				{
					MySqlSubSystem->CurrentConnectionID += 1;
				}
				MySqlSubSystem->NewConnectionDelegate.Broadcast(IsSussess, ErrorMessage, this);
			}
		}
	}
	else
	{
		ErrorMessage = "Dll Error!!!!";
	}
}

UMySqlObject* UMySqlObject::CreateConnection(FString Server, FString DBName, FString UserID, FString Password,
	TMap<FString, FString> ExtraParams)
{
	if (DLLManager::LoadDLL("MySQLLibrary.dll"))
	{
		IsSussess = DLLManager::CreateConnection(0,Server,DBName,UserID,Password,ExtraParams,ErrorMessage);
		if(IsSussess)
		{
			return this;
		}
	}
	return nullptr;
}


void UMySqlObject::CloseConnection()
{
	if (DLLManager::LoadDLL("MySQLLibrary.dll"))
	{
		DLLManager::CloseConnection(0);
		DLLManager::UnLoadDLL();
	}
}

void UMySqlObject::MakeFromQuery(FString Query)
{
	if (DLLManager::LoadDLL("MySQLLibrary.dll"))
	{
		IsSussess = DLLManager::UpdateFromQuery(0,Query,ErrorMessage);
		MakeFromQueryDelegate.Broadcast(IsSussess,ErrorMessage,this);
		DLLManager::UnLoadDLL();
	}
}

void UMySqlObject::SelectFromQuery(FString Query)
{
	if (DLLManager::LoadDLL("MySQLLibrary.dll"))
	{
		ResultByColumn.Empty();
		ResultByRow.Empty();
		IsSussess = DLLManager::SelectFromQuery(0,Query,ErrorMessage,ResultByColumn,ResultByRow);
		SelectFromQueryDelegate.Broadcast(IsSussess,ErrorMessage,ResultByColumn,ResultByRow,this);
		DLLManager::UnLoadDLL();
	}
}
/*
void UMySqlObject::UpdataImageFromQuery(FString Query, char* ImageChar)
{
	if (DLLManager::LoadDLL("MySQLLibrary.dll"))
	{
		IsSussess = DLLManager::UpdateImageFromPath(0,Query,ImageChar,ErrorMessage);
		DLLManager::UnLoadDLL();
	}
}

void UMySqlObject::SeleteImageFromQuery(FString Query,FString ColumnName)
{
	if (DLLManager::LoadDLL("MySQLLibrary.dll"))
	{
		TArray<UTexture2D*> Texture = DLLManager::SelectImageFromQuery(0,Query,ColumnName,ErrorMessage);
		SeleteImageDelegate.Broadcast(ErrorMessage,this,Texture);
		DLLManager::UnLoadDLL();
	}
}
*/


bool UMySqlObject::HttpMakeFromQuery(FString Query)
{
	IsSussess = false;
	if (DLLManager::LoadDLL("MySQLLibrary.dll"))
	{
		IsSussess = DLLManager::UpdateFromQuery(0,Query,ErrorMessage);
		DLLManager::UnLoadDLL();
	}
	return IsSussess;
}

bool UMySqlObject::HttpSelectFromQuery(FString Query,TArray<FMySQLDataTable>& ResultColumn,TArray<FMySQLDataRow>& ResultRow)
{
	IsSussess = false;
	if (DLLManager::LoadDLL("MySQLLibrary.dll"))
	{
		IsSussess = DLLManager::SelectFromQuery(0,Query,ErrorMessage,ResultColumn,ResultRow);
		DLLManager::UnLoadDLL();
	}
	return IsSussess;
}

