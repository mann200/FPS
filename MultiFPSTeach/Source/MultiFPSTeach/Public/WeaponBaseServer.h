// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBaseClient.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "WeaponBaseServer.generated.h"

UENUM()
enum class EWeaponType :uint8
{
	AK47 UMETA(DisplayName = "AK47"),
	M4A1 UMETA(DisplayName = "M4A1"),
	MP7 UMETA(DisplayName = "MP7"),
	DesertEagle UMETA(DisplayName = "DesertEagle"),
	Sniper UMETA(DisplayName = "Sniper"),
	Knife UMETA(DisplayName = "Knife"),
	EEND,
};

UCLASS()
class MULTIFPSTEACH_API AWeaponBaseServer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBaseServer();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int AnimBlendID;

	UPROPERTY(EditAnywhere) //枪械类型自定义枚举
	EWeaponType KindOfWeapon;

	UPROPERTY(EditAnywhere) //枪械骨骼网格体
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(EditAnywhere) //碰撞盒
	USphereComponent* SphereCollision;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite) //AWeaponBaseClient的引用
	TSubclassOf<AWeaponBaseClient>  ClientWeaponBPClass;

	UPROPERTY(BlueprintReadWrite,EditAnywhere) //身体开火动画
	UAnimMontage* ServerBodyFIreAnimMontage;

	UPROPERTY(BlueprintReadWrite,EditAnywhere) //身体开火动画
	UAnimMontage* ServerBodyReloadAnimMontage;

	UPROPERTY(BlueprintReadWrite,EditAnywhere) //射线检测距离
	float BulletDistance;

	UPROPERTY(BlueprintReadWrite,EditAnywhere) //弹孔材质
	UMaterialInterface* BulletDecal;

	UPROPERTY(BlueprintReadWrite,EditAnywhere) //基础伤害
	float DamageBase;

	UPROPERTY(BlueprintReadWrite,EditAnywhere) //自动
	bool IsAutomatic;

	UPROPERTY(BlueprintReadWrite,EditAnywhere) //自动射击间隔
	float AutomaticFireRate;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	UCurveFloat* VerticalRecoilCurve;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	UCurveFloat* HorizontalRecoilCurve;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	float MovingFireFloatRandom;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="SpreadWeaponData")
	float SpreadWeaponCallBackRate;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="SpreadWeaponData")
	float SpreadWeaponMinIndex;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="SpreadWeaponData")
	float SpreadWeaponMaxIndex;

#pragma region basic

	//枪剩余子弹
	UPROPERTY(EditAnywhere)
	int32 GunCurrentAmmo;

	//弹夹剩余子弹
	UPROPERTY(EditAnywhere,replicated)//加replicated，服务器改变了，客户端也会改变
	int32 ClipCurrentAmmo;

	//弹夹容量
	UPROPERTY(EditAnywhere)
	int32 MaxClipAmmo;

	//减伤
	UPROPERTY(BlueprintReadWrite,EditAnywhere) //头盔减免伤害
	float HeadDamageReduction;
	UPROPERTY(BlueprintReadWrite,EditAnywhere) //防弹减免伤害
	float BodyDamageReduction;

#pragma endregion 

	UPROPERTY(BlueprintReadWrite,EditAnywhere) //开火声音
	USoundBase* FireSound;
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere) //开火粒子特效
	UParticleSystem* MuzzleFlash;

	UFUNCTION()  //碰撞盒重叠时触发的函数
	void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void EquipWeapon();

	UFUNCTION(NetMulticast, Reliable, WithValidation) //多播生成开火相关事件
	void MultiShootingEffect();
	void MultiShootingEffect_Implementation();
	bool MultiShootingEffect_Validate();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
