// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "KismetMultiFPSLibrary.generated.h"

USTRUCT(BlueprintType)
struct FDeathMacthPlayerData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FName PlayerName;

	UPROPERTY(BlueprintReadWrite)
	int Score;

	FDeathMacthPlayerData()
	{
		PlayerName = TEXT(" ");
		Score = 0;
	}
};

UCLASS()
class MULTIFPSTEACH_API UKismetMultiFPSLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable,Category="Sort")
	static void SortValues(UPARAM(ref) TArray<FDeathMacthPlayerData>& Values);

	static TArray<FDeathMacthPlayerData>& QuickSort(UPARAM(ref) TArray<FDeathMacthPlayerData>& Values,int Start,int End);
};

