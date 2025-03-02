// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MulitFPSPlayerController.h"
#include "WeaponBaseClient.h"
#include "WeaponBaseServer.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
//#include "Net/UnrealNetwork.h"
#include "FPSTeachBaseCharacter.generated.h"

UCLASS()
class MULTIFPSTEACH_API AFPSTeachBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSTeachBaseCharacter();

	UFUNCTION()
	void DelayBeginCreateUI();

#pragma region Weapon
public:

	//装备武器
	void EquipPrimary(AWeaponBaseServer* WeaponBaseServer);
	void EquipSecondary(AWeaponBaseServer* WeaponBaseServer);

	//用于更新角色动画
	UFUNCTION(BlueprintImplementableEvent)
	void UpdataFPArmsBlendPose(int NewIndex);
	//用于更新角色动画
	UFUNCTION(BlueprintImplementableEvent)
	void UpdataBodyBlendPose(int NewIndex);

	//购买武器调用
	UFUNCTION(BlueprintCallable)
	void BuyWeaponFun(EWeaponType WeaponType);

	//切换武器调用
	UFUNCTION(BlueprintCallable)
	void SwitchWeaponFun(EWeapon SwitchType);

	//获取当前武器类型
	UFUNCTION(BlueprintCallable)
	EWeaponType GetCurrentClientWeaponType();

	//获取武器的引用
	AWeaponBaseClient* GetCurrenClientWeapon();
	AWeaponBaseServer* GetCurrenServerWeapon();
	//卸载武器
	void UnEquip();

private:
	//记录当前武器
	UPROPERTY(Replicated,meta = (AllowPrivateAccess = "true"))
	EWeaponType ActiveWeapon;
	//记录当前武器类型
	UPROPERTY(Replicated,meta = (AllowPrivateAccess = "true"))
	EWeapon CurrentWeaponType;

	//服务器主武器
	UPROPERTY(meta = (AllowPrivateAccess = "true"))
	AWeaponBaseServer* ServerPrimaryWeapon;
	UPROPERTY(meta=(AllowPrivateAccess = "true"))
	AWeaponBaseClient* ClientPrimaryWeapon;
	//服务器副武器
	UPROPERTY(meta = (AllowPrivateAccess = "true"))
	AWeaponBaseServer* ServerSecondaryWeapon;
	UPROPERTY(meta=(AllowPrivateAccess = "true"))
	AWeaponBaseClient* ClientSecondaryWeapon;
	//服务器匕首武器
	UPROPERTY(meta = (AllowPrivateAccess = "true"))
	AWeaponBaseServer* ServerKnifeWeapon;
	UPROPERTY(meta=(AllowPrivateAccess = "true"))
	AWeaponBaseClient* ClientKnifeWeapon;
	
	UPROPERTY(meta=(AllowPrivateAccess = "true"))
	AWeaponBaseClient* ClientWeapon;

	UPROPERTY(Category = Character, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UAnimInstance* ClientArmsAnimBP;

	UPROPERTY(Category = Character, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UAnimInstance* ServerBodyAnimBP;

	void StartKindOfWeapon();

	void PurchaseWeapon(EWeaponType WeaponType);

	void EquipKnife();

	void ServerDischargeWeapon(EWeapon CurrentWeaponType1,EWeaponType BuyWeaponType);
	
#pragma endregion

private:
	UPROPERTY(Category = Character,VisibleAnywhere,BlueprintReadOnly,meta=(AllowPrivateAccess = "true"))
	UCameraComponent* PlayerCamera;

	UPROPERTY(Category = Character, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* FPArmsMesh;

	UPROPERTY(BlueprintReadOnly,meta = (AllowPrivateAccess = "true"))
	AMulitFPSPlayerController* FPSPlayerController;

	//服务器生成武器
	void ServerSpawnPrimaryWeapon(AWeaponBaseServer* WeaponBaseServer);
	void ServerSpawnSecondaryWeapon(AWeaponBaseServer* WeaponBaseServer);
	void ServerSpawnKnifeWeapon(AWeaponBaseServer* WeaponBaseServer);

	//客户端生成武器
	void ClientSpawnPrimaryWeapon(int CurrentAmmo,int CurrentGunAmmo);
	void ClientSpawnSecondaryWeapon(int CurrentAmmo,int CurrentGunAmmo);
	void ClientSpawnKnifeWeapon(AWeaponBaseServer* WeaponBaseServer);

protected:
	virtual void BeginPlay() override;

#pragma region InputEvent
	
	void MoveForward(float AsixValue);
	void MoveRight(float AsixValue);
	void JumpAction();
	void StopJumpAction();
	void LowSpeedWalkAction();
	void NormalSpeedWalkAction();
	void InputFirePressed();
	void InputFireRelease();
	void InputReLoad();
	void InputAimingPressed();
	void InputAimingRelease();

#pragma endregion 

#pragma region NewWorking
	//����ͬ��
public:
	//换弹
	UPROPERTY(Replicated)
	bool IsReloading;
	UPROPERTY(Replicated)
	bool IsFiring;
	UPROPERTY(Replicated)
	bool IsBuying;

	//换弹结束
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerDelayPlayReloadCallBack();
	void ServerDelayPlayReloadCallBack_Implementation();
	bool ServerDelayPlayReloadCallBack_Validate();
	
	//运动状态
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerLowSpeedWalkAction();
	void ServerLowSpeedWalkAction_Implementation();
	bool ServerLowSpeedWalkAction_Validate();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerNormalSpeedWalkAction();
	void ServerNormalSpeedWalkAction_Implementation();
	bool ServerNormalSpeedWalkAction_Validate();

	//写下当前装备，购买使用
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerBuyWeapon(EWeaponType WeaponType);
	void ServerBuyWeapon_Implementation(EWeaponType WeaponType);
	bool ServerBuyWeapon_Validate(EWeaponType WeaponType);

	//写下当前装备，切枪使用
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSwitchWeaponWeapon(EWeapon SwitchType);
	void ServerSwitchWeaponWeapon_Implementation(EWeapon SwitchType);
	bool ServerSwitchWeaponWeapon_Validate(EWeapon SwitchType);

	//步枪
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerReloadPrimary();
	void ServerReloadPrimary_Implementation();
	bool ServerReloadPrimary_Validate();
	UFUNCTION(Server,Reliable,WithValidation)
	void ServerPrimaryFireRifleWeapon(FVector CameraLocation,FRotator CameraRotator,bool IsMoving);
	void ServerPrimaryFireRifleWeapon_Implementation(FVector CameraLocation,FRotator CameraRotator,bool IsMoving);
	bool ServerPrimaryFireRifleWeapon_Validate(FVector CameraLocation,FRotator CameraRotator,bool IsMoving);

	//手枪
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerReloadSecondary();
	void ServerReloadSecondary_Implementation();
	bool ServerReloadSecondary_Validate();
	UFUNCTION(Server,Reliable,WithValidation)
	void ServerSecondaryFireRifleWeapon(FVector CameraLocation,FRotator CameraRotator,bool IsMoving);
	void ServerSecondaryFireRifleWeapon_Implementation(FVector CameraLocation,FRotator CameraRotator,bool IsMoving);
	bool ServerSecondaryFireRifleWeapon_Validate(FVector CameraLocation,FRotator CameraRotator,bool IsMoving);

	//狙击枪
	UFUNCTION(Server,Reliable,WithValidation)
	void ServerSniperFireRifleWeapon(FVector CameraLocation,FRotator CameraRotator,bool IsMoving);
	void ServerSniperFireRifleWeapon_Implementation(FVector CameraLocation,FRotator CameraRotator,bool IsMoving);
	bool ServerSniperFireRifleWeapon_Validate(FVector CameraLocation,FRotator CameraRotator,bool IsMoving);
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSetAimingBool(bool AimingBool);
	void ServerSetAimingBool_Implementation(bool AimingBool);
	bool ServerSetAimingBool_Validate(bool AimingBool);
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerDelaySniperShootCallBack();
	void ServerDelaySniperShootCallBack_Implementation();
	bool ServerDelaySniperShootCallBack_Validate();
	
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerStopFiring();
	void ServerStopFiring_Implementation();
	bool ServerStopFiring_Validate();

	//其他
	
	//客户端主武器
	UFUNCTION(Client,Reliable)
	void ClientEquipPrimary(int CurrentAmmo,int CurrentGunAmmo);
	//客户端副武器
	UFUNCTION(Client,Reliable)
	void ClientEquipSecondary(int CurrentAmmo,int CurrentGunAmmo);
	//客户端匕首武器
	UFUNCTION(Client,Reliable)
	void ClientEquipKnife(AWeaponBaseServer* KnifeWeapon);
	
	UFUNCTION(Client,Reliable)
	void ClientFire();

	UFUNCTION(Client,Reliable)
	void ClientUpdataAmmoUI(int32 ClipAmmo,int32 GunCurrentAmmo);

	UFUNCTION(Client,Reliable)
	void ClientUpdataHealthUI(float NewHealth,float NewHeadArmor,float NewBodyArmor);

	UFUNCTION(Client,Reliable)
	void ClientPrimaryRecoil();

	UFUNCTION(Client,Reliable)
	void ClientReload();

	UFUNCTION(Client,Reliable)
	void ClientStartAiming();

	UFUNCTION(Client,Reliable)
	void ClientEndAiming();

	UFUNCTION(Client,Reliable)
	void ClientDeathMatchDeath();

	UFUNCTION(Client,Reliable)
	void ClientDelaySniperShootCallBack();

	//多播
	//播放身体射击蒙太奇动画
	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void MultiShooting();
	void MultiShooting_Implementation();
	bool MultiShooting_Validate();

	//播放换弹动画
	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void MultiBodyReload();
	void MultiBodyReload_Implementation();
	bool MultiBodyReload_Validate();

	//生成弹孔
	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void MultiSpawnBulletDecal(FVector Location,FRotator Rotator);
	void MultiSpawnBulletDecal_Implementation(FVector Location,FRotator Rotator);
	bool MultiSpawnBulletDecal_Validate(FVector Location,FRotator Rotator);

	//网络同步所需函数
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

#pragma endregion 
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

#pragma region Fire
public:

	//计时器
	FTimerHandle AutoFire;

	//后坐力
	float NewVerticalCurveAmount;
	float OldVerticalCurveAmount;
	float CurveXCoordValue;
	float VerticalDifferenceValue;
	float NewHorizontalCurveAmount;
	float OldHorizontalCurveAmount;
	float HorizontalDifferenceValue;
	void ReSetRecoil();

	float PistolSpreadMin = 0;
	float PistolSpreadMax = 0;
	
	//开火相关逻辑
	//步枪
	void FireWeaponPrimary();
	void StopFirePrimary();
	void WeaponPrimaryRifleLineTrace(FVector CameraLocation,FRotator CameraRotator,bool IsMoving);
	
	//手枪
	void FireWeaponSecondary();
	void StopFireSecondary();
	void WeaponSecondaryRifleLineTrace(FVector CameraLocation,FRotator CameraRotator,bool IsMoving);
	UFUNCTION()
	void DelaySpreadWeaponShootCallBack();

	//匕首
	//void FireWeaponKnife();
	//void StopFireKnife();
	//void WeaponKnifeRifleLineTrace(FVector CameraLocation,FRotator CameraRotator,bool IsMoving);
	//UFUNCTION()
	//void DelayKnifeWeaponShootCallBack();

	//狙击枪
	void FireWeaponSniper();
	void StopFireSniper();
	void WeaponSniperRifleLineTrace(FVector CameraLocation,FRotator CameraRotator,bool IsMoving);
	UPROPERTY(Replicated)
	bool IsAiming;
	UPROPERTY(VisibleAnywhere,Category = "AimingUI")
	UUserWidget* AimingWidget;
	UPROPERTY(EditAnywhere,Category = "AimingUI")
	TSubclassOf<UUserWidget> UserAimingUI;
	
	void DamagePlayer(UPhysicalMaterial* PhysicalMaterial,AActor* DamagedActor,FVector HitFromDirection,FHitResult& HitInfo);
	UFUNCTION(BlueprintCallable)
	void BuyArmor(bool bHead);

	UFUNCTION(BlueprintCallable)
	void ReSetPlayerState(float NewHealth,float NewHeadArmor,float NewBodyArmor);

	float Health;
	float BodyArmor;
	float HeadArmor;
	
	float DamageHeadResult(float InDamageBase);
	float DamageBodyResult(float InDamageBase);
	
	void WeaponPrimaryAutomaticFire();

	UFUNCTION()
	void OnPointDamage(AActor* DamagedActor, float Damage, class AController* InstigatedBy, FVector HitLocation, class UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection, const class UDamageType* DamageType, AActor* DamageCauser);

	void DeathMatchDeath(AActor* DamageActor);
#pragma endregion 

};




