// Copyright (c) FJQ.2023.All Rights Reserved

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "FJQMySqlBPLibrary.generated.h"


class UMySqlSubSystem;
class UMySqlObject;

USTRUCT(BlueprintType, Category = "MySql|Tables")
struct FMySQLDataTable
{
	GENERATED_BODY()
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SQLDataTable")
	FString ColumnName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SQLDataTable")
	TArray<FString> ColumnData;
};

USTRUCT(BlueprintType, Category = "MySql|Tables")
struct FMySQLDataRow
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SQLDataRow")
	TArray<FString> RowData;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FNewConnectionDelegate,const bool,IsSussess,const FString&,Message,UMySqlObject*,MySqlObject);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FMakeFromQueryDelegate,const bool,IsSussess,const FString&,Message,UMySqlObject*,MySqlObject);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FSeleteImageFromQueryDelegate,const FString&,Message,UMySqlObject*,MySqlObject,const TArray<UTexture2D*>&,Texture);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FSelectFromQueryDelegate,const bool,IsSussess,const FString&,Message,
	const TArray<FMySQLDataTable>&, ResultByColumn,const TArray<FMySQLDataRow>&, ResultByRow,UMySqlObject*,MySqlObject);



UCLASS()
class UFJQMySqlBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords = "FJQMySql sample test testing"), Category = "FJQMySqlTesting")
	static float FJQMySqlSampleFunction(float Param);
	
	static char* GetImageDataFromPath(FString Path);

	static UTexture2D* GetTextureFromChar(char* ImageChar);
	
};
