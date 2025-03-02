// Fill out your copyright notice in the Description page of Project Settings.


#include "KismetMultiFPSLibrary.h"

void UKismetMultiFPSLibrary::SortValues(TArray<FDeathMacthPlayerData>& Values)
{
	//Values.Sort([](FDeathMacthPlayerData A,FDeathMacthPlayerData B){return A.Score > B.Score;});
	QuickSort(Values,0,Values.Num()-1);
}
//手写快速排序
//原理：在数组中拿一个数当基准值，首下标往右移，尾下标往左移（遍历一遍后，比基准值大或小的在左边，其他在右边）
//之后左边单独排序，右边单独排序。直到排序小标相同退出
//此算法复杂度非常非常低
TArray<FDeathMacthPlayerData>& UKismetMultiFPSLibrary::QuickSort(TArray<FDeathMacthPlayerData>& Values, int Start,
	int End)
{
	if (Start >= End)
	{
		return Values;
	}
	int i = Start;
	int j = End;
	FDeathMacthPlayerData Temp = Values[i];
	while (i != j)
	{
		while (j > i && Values[j].Score <= Temp.Score)
		{
			j--;
		}
		Values[i] = Values[j];
		while (j > i && Values[i].Score >= Temp.Score)
		{
			i++;
		}
		Values[j] = Values[i];
	}
	Values[i] = Temp;
	//左边排序
	QuickSort(Values,Start,i-1);
	//右边排序
	QuickSort(Values,i+1,End);

	return  Values;
}

