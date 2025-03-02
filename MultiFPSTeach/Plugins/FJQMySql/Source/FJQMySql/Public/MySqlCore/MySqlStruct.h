// Copyright (c) FJQ.2023.All Rights Reserved
#pragma once
#include "CoreMinimal.h"
#include "MySqlStruct.generated.h"

USTRUCT(BlueprintType)
struct FJQMYSQL_API FCreate
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, Category = Options)
	double area;

	UPROPERTY(BlueprintReadWrite, Category = Options)
	double farmland;

	UPROPERTY(BlueprintReadWrite, Category = Options)
	double gdp;

	UPROPERTY(BlueprintReadWrite, Category = Options)
	double population;

};