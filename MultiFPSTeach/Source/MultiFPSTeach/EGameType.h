#pragma once
#include "EGameType.generated.h"

UENUM(BlueprintType)
enum class EGameType : uint8
{
	GameDeath UMETA(DisplayName = "GameDeath"),
	Game5v5 UMETA(DisplayName = "Game5v5"),
	EEND,
};

/*
 * 用于切换装备
 */
UENUM()
enum class EWeapon : uint8
{
	PrimaryWeapon UMETA(DisplayName = "PrimaryWeapon"),
	SecondaryWeapans UMETA(DisplayName = "SecondaryWeapans"),
	Knife UMETA(DisplayName = "Knife"),
	//Dagger UMETA(DisplayName = "Dagger"),
};
