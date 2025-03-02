// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBaseClient.generated.h"

UCLASS()
class MULTIFPSTEACH_API AWeaponBaseClient : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBaseClient();

	UPROPERTY(BlueprintReadWrite,EditAnywhere) //枪械骨骼网格体
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(BlueprintReadWrite,EditAnywhere) //客户端手臂开火动画蒙太奇
	UAnimMontage* ClientArmsFIreAnimMontage;

	UPROPERTY(BlueprintReadWrite,EditAnywhere) //客户端手臂换弹动画蒙太奇
	UAnimMontage* ClientArmsReloadAnimMontage;

	UPROPERTY(BlueprintReadWrite,EditAnywhere) //开火声音
	USoundBase* FireSound;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)  //开火粒子特效
	UParticleSystem* FireParticle;

	UPROPERTY(BlueprintReadWrite,EditAnywhere) //枪械射击抖动class引用
	TSubclassOf<UCameraShakeBase> CameraShake;

	UPROPERTY(BlueprintReadWrite,EditAnywhere) //枪体动画ID
	int FPArmsBlendPose;

	UPROPERTY(BlueprintReadWrite,EditAnywhere) //摄像机视野
	float CameraFieldOfView;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent,Category="Fire")
	void PlayShootAnimation();
	UFUNCTION(BlueprintImplementableEvent,Category="Fire")
	void PlayReloadAnimation();

	void DisplayWeaponEffect();
};
