// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MultiFPSTeach/EGameType.h"
#include "MulitFPSPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MULTIFPSTEACH_API AMulitFPSPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	//游戏类型
	UPROPERTY(EditAnywhere)
	EGameType KingOfGame;
	
public:
	
	void PlayFPSCameraShake(TSubclassOf<UCameraShakeBase> CameraShake);

	UFUNCTION(BlueprintImplementableEvent,Category="PlayerUI")
	void CreatePlayerUI();

	UFUNCTION(BlueprintImplementableEvent,Category="PlayerUI")
	void DoRecoilAnim();

	UFUNCTION(BlueprintImplementableEvent,Category="PlayerUI")
	void UpdataPlayerAmmoUI(int32 ClipAmmo,int32 GunCurrentAmmo);

	UFUNCTION(BlueprintImplementableEvent,Category="PlayerUI")
	void UpdataPlayerHealthUI(float NewHealth,float NewHeadArmor,float NewBodyArmor);

	/*
	 * DamageActor是伤害来源
	 */
	UFUNCTION(BlueprintImplementableEvent,Category="Health")
	void DeathMatchDeath(AActor* DamageActor);
	
};
