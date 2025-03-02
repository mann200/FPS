// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSTeachBaseCharacter.h"
#include "MulitFPSPlayerController.h"
#include "WeaponBaseServer.h"
#include "../../../Plugins/Developer/RiderLink/Source/RD/thirdparty/clsocket/src/ActiveSocket.h"
#include "Blueprint/UserWidget.h"
#include "Components/DecalComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Net/UnrealNetwork.h"
#include "PhysicalMaterials/PhysicalMaterial.h"

// Sets default values
AFPSTeachBaseCharacter::AFPSTeachBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//设置父子级关系
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	if (PlayerCamera)
	{
		PlayerCamera->SetupAttachment(RootComponent);
		PlayerCamera->bUsePawnControlRotation = true;
	}
	FPArmsMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FPArmsMesh"));
	if (FPArmsMesh)
	{
		FPArmsMesh->SetupAttachment(PlayerCamera);
		FPArmsMesh->SetOnlyOwnerSee(true);
	}
	//设置自已是否可见
	GetMesh()->SetOwnerNoSee(true);
	//设置碰撞
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	GetMesh()->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	
}

void AFPSTeachBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	IsAiming = false;
	IsFiring = false;
	IsReloading = false;
	IsBuying = false;
	Health = 100;
	BodyArmor = 0;
	HeadArmor = 0;
	OnTakePointDamage.AddDynamic(this,&AFPSTeachBaseCharacter::OnPointDamage);

	//获取FPArms的动画蓝图
	ClientArmsAnimBP = FPArmsMesh->GetAnimInstance();

	//获取Body的动画蓝图
	ServerBodyAnimBP = GetMesh()->GetAnimInstance();

	//延迟生成UI,并且获取FPSPlayerController
	DelayBeginCreateUI();
}

void AFPSTeachBaseCharacter::DelayBeginCreateUI()
{
	//获取playerController
	FPSPlayerController = Cast<AMulitFPSPlayerController>(GetController());
	if (FPSPlayerController)
	{
		//生成准心UI
		FPSPlayerController->CreatePlayerUI();

		//设置初始枪支
		StartKindOfWeapon();

		//ClientUpdataAmmoUI(ServerPrimaryWeapon->ClipCurrentAmmo,ServerPrimaryWeapon->GunCurrentAmmo);
	}
	else
	{
		FLatentActionInfo ActionInfo;
		ActionInfo.CallbackTarget = this;
		ActionInfo.ExecutionFunction = TEXT("DelayBeginCreateUI");
		ActionInfo.UUID = FMath::Rand();
		ActionInfo.Linkage = 0;
		UKismetSystemLibrary::Delay(this,0.2f,ActionInfo);
	}
}

void AFPSTeachBaseCharacter::ServerSpawnPrimaryWeapon(AWeaponBaseServer* WeaponBaseServer)
{
	ServerPrimaryWeapon = WeaponBaseServer;
	ServerPrimaryWeapon->SetOwner(this);
	ActiveWeapon = ServerPrimaryWeapon->KindOfWeapon;
	CurrentWeaponType = EWeapon::PrimaryWeapon;
	FName WeaponSocketName = TEXT("Weapon_Rifle");
	if (ActiveWeapon == EWeaponType::M4A1)
	{
		WeaponSocketName = TEXT("M4A1_Socket");
	}
	ServerPrimaryWeapon->K2_AttachToComponent(this->GetMesh(),WeaponSocketName,EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		true);
	UpdataBodyBlendPose(ServerPrimaryWeapon->AnimBlendID);
	ClientEquipPrimary(ServerPrimaryWeapon->ClipCurrentAmmo,ServerPrimaryWeapon->GunCurrentAmmo); 
}

void AFPSTeachBaseCharacter::ClientSpawnPrimaryWeapon(int CurrentAmmo,int CurrentGunAmmo)
{
	//此判断用于切枪删除武器
	if (ClientSecondaryWeapon)
	{
		ClientSecondaryWeapon->Destroy();
		ClientSecondaryWeapon = nullptr;
	}
	if (ClientPrimaryWeapon)
	{
		ClientPrimaryWeapon->Destroy();
		ClientPrimaryWeapon = nullptr;
	}
	if(ClientKnifeWeapon)
	{
		ClientKnifeWeapon->Destroy();
		ClientKnifeWeapon = nullptr;
	}
	//生成Actor的基础属性
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Owner = this;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	//生成Actor
	ClientPrimaryWeapon = GetWorld()->SpawnActor<AWeaponBaseClient>(ServerPrimaryWeapon->ClientWeaponBPClass,GetActorTransform(),SpawnInfo);
	if (!(ActiveWeapon == ServerPrimaryWeapon->KindOfWeapon))
	{
		ActiveWeapon = ServerPrimaryWeapon->KindOfWeapon;
	}
	FName WeaponSocketName = TEXT("WeaponSocket");
	if (ActiveWeapon == EWeaponType::M4A1)
	{
		WeaponSocketName = TEXT("M4A1_Socket");
	}
	if (ActiveWeapon == EWeaponType::Sniper)
	{
		UKismetSystemLibrary::PrintString(this,FString::Printf(TEXT("Yes")));
		WeaponSocketName = TEXT("AWP_Socket");
	}
	//将生成的武器绑定在对应骨骼上
	ClientPrimaryWeapon->K2_AttachToComponent(FPArmsMesh,WeaponSocketName,
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		true);
	//更新UI
	ClientUpdataAmmoUI(CurrentAmmo,CurrentGunAmmo);
	if (ClientPrimaryWeapon)
	{
		//切换动画蓝图
		UpdataFPArmsBlendPose(ClientPrimaryWeapon->FPArmsBlendPose);
	}
}

void AFPSTeachBaseCharacter::ServerSpawnSecondaryWeapon(AWeaponBaseServer* WeaponBaseServer)
{
	ServerSecondaryWeapon = WeaponBaseServer;
	ServerSecondaryWeapon->SetOwner(this);
	ActiveWeapon = ServerSecondaryWeapon->KindOfWeapon;
	CurrentWeaponType = EWeapon::SecondaryWeapans;
	ServerSecondaryWeapon->K2_AttachToComponent(this->GetMesh(),TEXT("Weapon_Rifle"),EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		true);
	UpdataBodyBlendPose(ServerSecondaryWeapon->AnimBlendID);
	ClientEquipSecondary(ServerSecondaryWeapon->ClipCurrentAmmo,ServerSecondaryWeapon->GunCurrentAmmo);
}

void AFPSTeachBaseCharacter::ServerSpawnKnifeWeapon(AWeaponBaseServer* WeaponBaseServer)
{
	ServerKnifeWeapon = WeaponBaseServer;
	ServerKnifeWeapon->SetOwner(this);
	ActiveWeapon = ServerKnifeWeapon->KindOfWeapon;
	CurrentWeaponType = EWeapon::Knife;
	ServerKnifeWeapon->K2_AttachToComponent(this->GetMesh(),TEXT("Knife_Socket"),EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		true);

	ClientEquipKnife(ServerKnifeWeapon);
	
}

void AFPSTeachBaseCharacter::ClientSpawnKnifeWeapon(AWeaponBaseServer* WeaponBaseServer)
{
	//此判断用于切枪删除武器
	if (ClientSecondaryWeapon)
	{
		ClientSecondaryWeapon->Destroy();
		ClientSecondaryWeapon = nullptr;
	}
	if (ClientPrimaryWeapon)
	{
		ClientPrimaryWeapon->Destroy();
		ClientPrimaryWeapon = nullptr;
	}
	if(ClientKnifeWeapon)
	{
		ClientKnifeWeapon->Destroy();
		ClientKnifeWeapon = nullptr;
	}
	//生成Actor的基础属性
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Owner = this;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	//生成Actor
	ClientKnifeWeapon = GetWorld()->SpawnActor<AWeaponBaseClient>(WeaponBaseServer->ClientWeaponBPClass,GetActorTransform(),SpawnInfo);
	if (!(ActiveWeapon == WeaponBaseServer->KindOfWeapon))
	{
		ActiveWeapon = WeaponBaseServer->KindOfWeapon;
	}
	//将生成的武器绑定在对应骨骼上
	ClientKnifeWeapon->K2_AttachToComponent(FPArmsMesh,TEXT("Knife_Socket"),
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		true);
	//更新UI
	ClientUpdataAmmoUI(WeaponBaseServer->ClipCurrentAmmo,WeaponBaseServer->GunCurrentAmmo);
	if (ClientKnifeWeapon)
	{
		//切换动画蓝图
		UpdataFPArmsBlendPose(ClientKnifeWeapon->FPArmsBlendPose);
	}
}

void AFPSTeachBaseCharacter::ClientSpawnSecondaryWeapon(int CurrentAmmo,int CurrentGunAmmo)
{
	//此判断用于切枪删除武器
	if (ClientSecondaryWeapon)
	{
		ClientSecondaryWeapon->Destroy();
		ClientSecondaryWeapon = nullptr;
	}
	if (ClientPrimaryWeapon)
	{
		ClientPrimaryWeapon->Destroy();
		ClientPrimaryWeapon = nullptr;
	}
	if(ClientKnifeWeapon)
	{
		ClientKnifeWeapon->Destroy();
		ClientKnifeWeapon = nullptr;
	}
	//生成Actor的基础属性
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Owner = this;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	//生成Actor
	ClientSecondaryWeapon = GetWorld()->SpawnActor<AWeaponBaseClient>(ServerSecondaryWeapon->ClientWeaponBPClass,GetActorTransform(),SpawnInfo);
	if (!(ActiveWeapon == ServerSecondaryWeapon->KindOfWeapon))
	{
		ActiveWeapon = ServerSecondaryWeapon->KindOfWeapon;
	}
	//将生成的武器绑定在对应骨骼上
	ClientSecondaryWeapon->K2_AttachToComponent(FPArmsMesh,TEXT("WeaponSocket"),
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		true);
	//更新UI
	ClientUpdataAmmoUI(ServerSecondaryWeapon->ClipCurrentAmmo,ServerSecondaryWeapon->GunCurrentAmmo);
	if (ClientSecondaryWeapon)
	{
		//切换动画蓝图
		UpdataFPArmsBlendPose(ClientSecondaryWeapon->FPArmsBlendPose);
	}
}

void AFPSTeachBaseCharacter::ClientUpdataAmmoUI_Implementation(int32 ClipAmmo,int32 GunCurrentAmmo)
{
	if(FPSPlayerController)
	{
		//调用更新UI信息函数
		FPSPlayerController->UpdataPlayerAmmoUI(ClipAmmo,GunCurrentAmmo);
	}
}

void AFPSTeachBaseCharacter::ClientUpdataHealthUI_Implementation(float NewHealth,float NewHeadArmor,float NewBodyArmor)
{
	if(FPSPlayerController)
	{
		//调用更新UI信息函数
		FPSPlayerController->UpdataPlayerHealthUI(NewHealth,NewHeadArmor,NewBodyArmor);
	}
}

//后坐力
void AFPSTeachBaseCharacter::ClientPrimaryRecoil_Implementation()
{
	//设置水平和垂直方向的后坐力
	AWeaponBaseServer* CurrenServerWeapon = GetCurrenServerWeapon();
	UCurveFloat* VerticalRecoil = nullptr;
	UCurveFloat* HorizontalRecoil = nullptr;
	if (CurrenServerWeapon)
	{
		//设置后坐力曲线图
		VerticalRecoil = CurrenServerWeapon->VerticalRecoilCurve;
		HorizontalRecoil = CurrenServerWeapon->HorizontalRecoilCurve;
	}
	//曲线取值下标
	CurveXCoordValue += 0.1;
	if (VerticalRecoil)
	{
		NewVerticalCurveAmount = VerticalRecoil->GetFloatValue(CurveXCoordValue);
	}
	if (HorizontalRecoil)
	{
		NewHorizontalCurveAmount = HorizontalRecoil->GetFloatValue(CurveXCoordValue);
	}
	//曲线差值
	VerticalDifferenceValue = NewVerticalCurveAmount - OldVerticalCurveAmount;
	HorizontalDifferenceValue = NewHorizontalCurveAmount - OldHorizontalCurveAmount;

	if (FPSPlayerController)
	{
		FRotator PlayerControlRotator = FPSPlayerController->GetControlRotation();
		FPSPlayerController->SetControlRotation(FRotator(PlayerControlRotator.Pitch + VerticalDifferenceValue,
			PlayerControlRotator.Yaw + HorizontalDifferenceValue,
			PlayerControlRotator.Roll));
	}

	OldHorizontalCurveAmount = NewHorizontalCurveAmount;
	OldVerticalCurveAmount = NewVerticalCurveAmount;
	
}

void AFPSTeachBaseCharacter::ClientReload_Implementation()
{
	AWeaponBaseClient* CurrenClientWeapon = GetCurrenClientWeapon();
	if(CurrenClientWeapon)
	{
		//枪体播放动画
		CurrenClientWeapon->PlayReloadAnimation();
		//手臂播放动画
		UAnimMontage* ClientFPArmsAnim = CurrenClientWeapon->ClientArmsReloadAnimMontage;
		ClientArmsAnimBP->Montage_Play(ClientFPArmsAnim);

		float AnimTime = CurrenClientWeapon->ClientArmsReloadAnimMontage->GetPlayLength();
		
		FLatentActionInfo ActionInfo;
		ActionInfo.CallbackTarget = this;
		ActionInfo.ExecutionFunction = TEXT("ServerDelayPlayReloadCallBack");
		ActionInfo.UUID = FMath::Rand();
		ActionInfo.Linkage = 0;
		UKismetSystemLibrary::Delay(this,AnimTime ,ActionInfo);
	}
}

void AFPSTeachBaseCharacter::ClientStartAiming_Implementation()
{
	if (FPArmsMesh)
	{
		FPArmsMesh->SetHiddenInGame(true);
	}
	if (ClientPrimaryWeapon)
	{
		ClientPrimaryWeapon->WeaponMesh->SetHiddenInGame(true);
		if (PlayerCamera)
		{
			PlayerCamera->SetFieldOfView(ClientPrimaryWeapon->CameraFieldOfView);
		}
	}

	AimingWidget = CreateWidget<UUserWidget>(GetWorld(),UserAimingUI);
	AimingWidget->AddToViewport();
}

void AFPSTeachBaseCharacter::ClientEndAiming_Implementation()
{
	if (FPArmsMesh)
	{
		FPArmsMesh->SetHiddenInGame(false);
	}
	if (ClientPrimaryWeapon)
	{
		ClientPrimaryWeapon->WeaponMesh->SetHiddenInGame(false);
		if (PlayerCamera)
		{
			PlayerCamera->SetFieldOfView(90);
		}
	}
	if (AimingWidget)
	{
		AimingWidget->RemoveFromParent();
	}
}

void AFPSTeachBaseCharacter::ClientDeathMatchDeath_Implementation()
{
	AWeaponBaseClient* CurrentClientWeapon = GetCurrenClientWeapon();
	if (CurrentClientWeapon)
	{
		CurrentClientWeapon->Destroy();
	}
}

void AFPSTeachBaseCharacter::ClientDelaySniperShootCallBack_Implementation()
{
	if (ClientPrimaryWeapon)
	{
		FLatentActionInfo ActionInfo;
		ActionInfo.CallbackTarget = this;
		ActionInfo.ExecutionFunction = TEXT("ServerDelaySniperShootCallBack");
		ActionInfo.UUID = FMath::Rand();
		ActionInfo.Linkage = 0;
		UKismetSystemLibrary::Delay(this,
			ClientPrimaryWeapon->ClientArmsFIreAnimMontage->GetPlayLength(),ActionInfo);
	}
}

//多播开火动画
void AFPSTeachBaseCharacter::MultiShooting_Implementation()
{
	if(ServerBodyAnimBP)
	{
		if (ServerPrimaryWeapon)
		{
			//播放motage
			ServerBodyAnimBP->Montage_Play(ServerPrimaryWeapon->ServerBodyFIreAnimMontage);
		}
	}
}

bool AFPSTeachBaseCharacter::MultiShooting_Validate()
{
	return true;
}

void AFPSTeachBaseCharacter::MultiBodyReload_Implementation()
{
	AWeaponBaseServer* CurrenServerWeapon = GetCurrenServerWeapon();
	if(CurrenServerWeapon)
	{
		//身体播放动画
		ServerBodyAnimBP->Montage_Play(CurrenServerWeapon->ServerBodyReloadAnimMontage);
	}
}

bool AFPSTeachBaseCharacter::MultiBodyReload_Validate()
{
	return true;
}

void AFPSTeachBaseCharacter::MultiSpawnBulletDecal_Implementation(FVector Location,FRotator Rotator)
{
	AWeaponBaseServer* CurrenServerWeapon = GetCurrenServerWeapon();
	if (CurrenServerWeapon)
	{
		//生成弹孔并重新设置可视范围
		UDecalComponent* Decal = UGameplayStatics::SpawnDecalAtLocation(GetWorld(),CurrenServerWeapon->BulletDecal,
			FVector(8,8,8),Location,Rotator,10);
		if (Decal)
		{
			Decal->SetFadeScreenSize(0.001);
		}
	}
}

bool AFPSTeachBaseCharacter::MultiSpawnBulletDecal_Validate(FVector Location,FRotator Rotator)
{
	return true;
}

// Called every frame
void AFPSTeachBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

#pragma region Input

// Called to bind functionality to input
void AFPSTeachBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//绑定映射函数
	InputComponent->BindAction(TEXT("LowSpeedWalk"), IE_Pressed, this, &AFPSTeachBaseCharacter::LowSpeedWalkAction);
	InputComponent->BindAction(TEXT("LowSpeedWalk"), IE_Released, this, &AFPSTeachBaseCharacter::NormalSpeedWalkAction);
	
	InputComponent->BindAction(TEXT("Jump"),IE_Pressed,this,&AFPSTeachBaseCharacter::JumpAction);
	InputComponent->BindAction(TEXT("Jump"), IE_Released, this, &AFPSTeachBaseCharacter::StopJumpAction);

	InputComponent->BindAction(TEXT("Fire"),IE_Pressed,this,&AFPSTeachBaseCharacter::InputFirePressed);
	InputComponent->BindAction(TEXT("Fire"),IE_Released,this,&AFPSTeachBaseCharacter::InputFireRelease);

	InputComponent->BindAction(TEXT("Aiming"),IE_Pressed,this,&AFPSTeachBaseCharacter::InputAimingPressed);
	InputComponent->BindAction(TEXT("Aiming"),IE_Released,this,&AFPSTeachBaseCharacter::InputAimingRelease);
	
	InputComponent->BindAxis(TEXT("MoveForward"), this, &AFPSTeachBaseCharacter::MoveForward);
	InputComponent->BindAxis(TEXT("MoveRight"), this, &AFPSTeachBaseCharacter::MoveRight);
	
	InputComponent->BindAxis(TEXT("Turn"), this, &AFPSTeachBaseCharacter::AddControllerYawInput);
	InputComponent->BindAxis(TEXT("LookUp"), this, &AFPSTeachBaseCharacter::AddControllerPitchInput);

	InputComponent->BindAction(TEXT("ReLoad"),IE_Pressed,this,&AFPSTeachBaseCharacter::InputReLoad);

	
}

void AFPSTeachBaseCharacter::MoveForward(float AsixValue)
{
	AddMovementInput(GetActorForwardVector(), AsixValue, false);
}

void AFPSTeachBaseCharacter::MoveRight(float AsixValue)
{
	AddMovementInput(GetActorRightVector(), AsixValue, false);
}

void AFPSTeachBaseCharacter::JumpAction()
{
	Jump();
}

void AFPSTeachBaseCharacter::StopJumpAction()
{
	StopJumping();
}

#pragma endregion 

#pragma region Fire

void AFPSTeachBaseCharacter::InputFirePressed()
{
	//判断武器类型
	switch (ActiveWeapon)
	{
		case EWeaponType::AK47:
			{
				FireWeaponPrimary();
			}
		break;
		case EWeaponType::M4A1:
			{
				FireWeaponPrimary();
			}
		break;
		case EWeaponType::MP7:
			{
				FireWeaponPrimary();
			}
		break;
		case EWeaponType::DesertEagle:
			{
				FireWeaponSecondary();
			}
		break;
		case EWeaponType::Sniper:
			{
				FireWeaponSniper();
			}
		break;
	}
}

void AFPSTeachBaseCharacter::InputFireRelease()
{
	//判断武器类型
	switch (ActiveWeapon)
	{
		case EWeaponType::AK47:
			{
				StopFirePrimary();
			}
		break;
		case EWeaponType::M4A1:
			{
				StopFirePrimary();
			}
		break;
		case EWeaponType::MP7:
			{
				StopFirePrimary();
			}
		break;
		case EWeaponType::DesertEagle:
			{
				StopFireSecondary();
			}
		break;
		case EWeaponType::Sniper:
			{
				StopFireSniper();
			}
		break;
	}
}

void AFPSTeachBaseCharacter::InputReLoad()
{
	if (!IsReloading)
	{
		if (!IsFiring)
		{
			switch (ActiveWeapon)
			{
				case EWeaponType::AK47:
					{
						ServerReloadPrimary();
					}
				break;
				case EWeaponType::M4A1:
					{
						ServerReloadPrimary();
					}
				break;
				case EWeaponType::MP7:
					{
						ServerReloadPrimary();
					}
				break;
				case EWeaponType::DesertEagle:
					{
						ServerReloadSecondary();
					}
				break;
				case EWeaponType::Sniper:
					{
						ServerReloadPrimary();
					}
				break;
			}
		}
	}
}

void AFPSTeachBaseCharacter::InputAimingPressed()
{
	//设置判断瞄准的Bool，调用客户端瞄准函数（瞄准UI，隐藏Mesh）
	if (ActiveWeapon == EWeaponType::Sniper)
	{
		ServerSetAimingBool(true);
		ClientStartAiming();
	}
}

void AFPSTeachBaseCharacter::InputAimingRelease()
{
	if (ActiveWeapon == EWeaponType::Sniper)
	{
		ServerSetAimingBool(false);
		ClientEndAiming();
	}
}

void AFPSTeachBaseCharacter::ServerDelayPlayReloadCallBack_Implementation()
{
	AWeaponBaseServer* CurrenServerWeapon = GetCurrenServerWeapon();
	IsReloading = false;
	if (CurrenServerWeapon)
	{
		int32 GunCurrentAmmo = CurrenServerWeapon->GunCurrentAmmo;
		int32 ClipCurrentAmmo = CurrenServerWeapon->ClipCurrentAmmo;
		int32 const MaxClipAmmo= CurrenServerWeapon->MaxClipAmmo;
		if (GunCurrentAmmo > MaxClipAmmo - ClipCurrentAmmo)
		{
			GunCurrentAmmo -= (MaxClipAmmo - ClipCurrentAmmo);
			ClipCurrentAmmo = MaxClipAmmo;
		}
		else
		{
			ClipCurrentAmmo += GunCurrentAmmo;
			GunCurrentAmmo = 0;
		}
		CurrenServerWeapon->GunCurrentAmmo = GunCurrentAmmo;
		CurrenServerWeapon->ClipCurrentAmmo = ClipCurrentAmmo;
		ClientUpdataAmmoUI(ClipCurrentAmmo,GunCurrentAmmo);
	}
}

bool AFPSTeachBaseCharacter::ServerDelayPlayReloadCallBack_Validate()
{
	return true;
}


void AFPSTeachBaseCharacter::ReSetRecoil()
{
	NewVerticalCurveAmount = 0;
	OldVerticalCurveAmount = 0;
	CurveXCoordValue = 0;
	VerticalDifferenceValue = 0;
	NewHorizontalCurveAmount = 0;
	OldHorizontalCurveAmount = 0;
	HorizontalDifferenceValue = 0;
}

void AFPSTeachBaseCharacter::FireWeaponPrimary()
{
	if (ServerPrimaryWeapon)
	{
		if(ServerPrimaryWeapon->ClipCurrentAmmo > 0 && !IsReloading)
		{
			if (UKismetMathLibrary::VSize(GetVelocity())>0.1)
			{
				//服务端（减少弹药，射线检测（武器），上海计算，弹孔生成,音效，特效）
				ServerPrimaryFireRifleWeapon(PlayerCamera->GetComponentLocation(),PlayerCamera->GetComponentRotation(),true);
			}
			else
			{
				//服务端（减少弹药，射线检测（武器），上海计算，弹孔生成,音效，特效）
				ServerPrimaryFireRifleWeapon(PlayerCamera->GetComponentLocation(),PlayerCamera->GetComponentRotation(),false);
			}
		
			//客户端（模型动画）
			ClientFire();

			//后坐力
			ClientPrimaryRecoil();

			if (ServerPrimaryWeapon->IsAutomatic)
			{
				//GetWorldTimerManager() == GetWorld()->GetTimerManager()
				GetWorld()->GetTimerManager().SetTimer(AutoFire,this,&AFPSTeachBaseCharacter::WeaponPrimaryAutomaticFire,ServerPrimaryWeapon->AutomaticFireRate,true);
			}
		
			//UKismetSystemLibrary::PrintString(this,FString::Printf(TEXT("ServerPrimaryWeapon->ClipCurrentAmmo = %d"),ServerPrimaryWeapon->ClipCurrentAmmo));
		}
	}

}

void AFPSTeachBaseCharacter::FireWeaponSecondary()
{
	if (ServerSecondaryWeapon)
	{
		if(ServerSecondaryWeapon->ClipCurrentAmmo > 0 && !IsReloading)
		{
			if (UKismetMathLibrary::VSize(GetVelocity())>0.1)
			{
				//服务端（减少弹药，射线检测（武器），上海计算，弹孔生成,音效，特效）
				ServerSecondaryFireRifleWeapon(PlayerCamera->GetComponentLocation(),PlayerCamera->GetComponentRotation(),true);
			}
			else
			{
				//服务端（减少弹药，射线检测（武器），上海计算，弹孔生成,音效，特效）
				ServerSecondaryFireRifleWeapon(PlayerCamera->GetComponentLocation(),PlayerCamera->GetComponentRotation(),false);
			}
		
			//客户端（模型动画）
			ClientFire();
			
			//UKismetSystemLibrary::PrintString(this,FString::Printf(TEXT("ServerPrimaryWeapon->ClipCurrentAmmo = %d"),ServerPrimaryWeapon->ClipCurrentAmmo));
		}
	}

}

void AFPSTeachBaseCharacter::FireWeaponSniper()
{
	if (ServerPrimaryWeapon)
	{
		if(ServerPrimaryWeapon->ClipCurrentAmmo > 0 && !IsReloading && !IsFiring)
		{
			if (UKismetMathLibrary::VSize(GetVelocity())>0.1)
			{
				//服务端（减少弹药，射线检测（武器），上海计算，弹孔生成,音效，特效）
				ServerSniperFireRifleWeapon(PlayerCamera->GetComponentLocation(),PlayerCamera->GetComponentRotation(),true);
			}
			else
			{
				//服务端（减少弹药，射线检测（武器），上海计算，弹孔生成,音效，特效）
				ServerSniperFireRifleWeapon(PlayerCamera->GetComponentLocation(),PlayerCamera->GetComponentRotation(),false);
			}
		
			//客户端（模型动画）
			ClientFire();

		}
	}
}

void AFPSTeachBaseCharacter::StopFireSniper()
{
	//ServerStopFiring();
}

void AFPSTeachBaseCharacter::StopFireSecondary()
{
	ServerStopFiring();
}

void AFPSTeachBaseCharacter::StopFirePrimary()
{
	ServerStopFiring();
	//关闭定时器
	GetWorld()->GetTimerManager().ClearTimer(AutoFire);
	ReSetRecoil();
}

//主武器射线检测
void AFPSTeachBaseCharacter::WeaponPrimaryRifleLineTrace(FVector CameraLocation,FRotator CameraRotator,bool IsMoving)
{
	//初始化参数
	FVector EndLocation;
	TArray<AActor*> IngoryArray;
	IngoryArray.Add(this);
	FHitResult HitResult;
	if (ServerPrimaryWeapon)
	{
		if (IsMoving)
		{
			FVector VT = CameraLocation + UKismetMathLibrary::GetForwardVector(CameraRotator)*ServerPrimaryWeapon->BulletDistance;
			float RandomX = UKismetMathLibrary::RandomFloatInRange(-ServerPrimaryWeapon->MovingFireFloatRandom,ServerPrimaryWeapon->MovingFireFloatRandom);
			float RandomY = UKismetMathLibrary::RandomFloatInRange(-ServerPrimaryWeapon->MovingFireFloatRandom,ServerPrimaryWeapon->MovingFireFloatRandom);
			float RandomZ = UKismetMathLibrary::RandomFloatInRange(-ServerPrimaryWeapon->MovingFireFloatRandom,ServerPrimaryWeapon->MovingFireFloatRandom);
			EndLocation = FVector(VT.X + RandomX,VT.Y + RandomY,VT.Z + RandomZ);
		}
		else
		{
			//计算射线检测末位置Location，UKismetMathLibrary::GetForwardVector获得旋转的向前向量（单位向量）
			EndLocation = CameraLocation + UKismetMathLibrary::GetForwardVector(CameraRotator)*ServerPrimaryWeapon->BulletDistance;
		}
	}

	//射线检测函数
	bool HitSuccess = UKismetSystemLibrary::LineTraceSingle(GetWorld(),CameraLocation,EndLocation,ETraceTypeQuery::TraceTypeQuery1,false,
	IngoryArray,EDrawDebugTrace::None,HitResult,true,FLinearColor::Red,FLinearColor::Green,3.f);
	if (HitSuccess)
	{
		UKismetSystemLibrary::PrintString(GetWorld(),FString::Printf(TEXT("Hit Actor Name = %s"),*HitResult.GetActor()->GetName()));
		//判断射线检测打到的物体是否为AFPSTeachBaseCharacter
		AFPSTeachBaseCharacter* FPSCharacter = Cast<AFPSTeachBaseCharacter>(HitResult.GetActor());
		if (FPSCharacter)
		{
			//智能指针
			DamagePlayer(HitResult.PhysMaterial.Get(),HitResult.GetActor(),CameraLocation,HitResult);
		}
		else
		{
			//计算法线到物体X轴的旋转
			FRotator Rotation = UKismetMathLibrary::MakeRotFromX(HitResult.Normal);
			//多播生成弹孔
			MultiSpawnBulletDecal(HitResult.Location,Rotation);
		}
	}
	
}

//副武器射线检测
void AFPSTeachBaseCharacter::WeaponSecondaryRifleLineTrace(FVector CameraLocation, FRotator CameraRotator,
	bool IsMoving)
{
	//初始化参数
	FVector EndLocation;
	TArray<AActor*> IngoryArray;
	IngoryArray.Add(this);
	FHitResult HitResult;
	FVector CameraForwardVector;
	if (ServerSecondaryWeapon)
	{
		if (IsMoving)
		{
			FRotator Rotator;
			Rotator.Roll = CameraRotator.Roll;
			Rotator.Pitch = CameraRotator.Pitch + UKismetMathLibrary::RandomFloatInRange(PistolSpreadMin,PistolSpreadMax);
			Rotator.Yaw = CameraRotator.Yaw + UKismetMathLibrary::RandomFloatInRange(PistolSpreadMin,PistolSpreadMax);
			CameraForwardVector = UKismetMathLibrary::GetForwardVector(Rotator);
			
			FVector VT = CameraLocation + CameraForwardVector *ServerSecondaryWeapon->BulletDistance;
			float RandomX = UKismetMathLibrary::RandomFloatInRange(-ServerSecondaryWeapon->MovingFireFloatRandom,ServerSecondaryWeapon->MovingFireFloatRandom);
			float RandomY = UKismetMathLibrary::RandomFloatInRange(-ServerSecondaryWeapon->MovingFireFloatRandom,ServerSecondaryWeapon->MovingFireFloatRandom);
			float RandomZ = UKismetMathLibrary::RandomFloatInRange(-ServerSecondaryWeapon->MovingFireFloatRandom,ServerSecondaryWeapon->MovingFireFloatRandom);
			EndLocation = FVector(VT.X + RandomX,VT.Y + RandomY,VT.Z + RandomZ);
		}
		else
		{
			FRotator Rotator;
			Rotator.Roll = CameraRotator.Roll;
			Rotator.Pitch = CameraRotator.Pitch + UKismetMathLibrary::RandomFloatInRange(PistolSpreadMin,PistolSpreadMax);
			Rotator.Yaw = CameraRotator.Yaw + UKismetMathLibrary::RandomFloatInRange(PistolSpreadMin,PistolSpreadMax);
			CameraForwardVector = UKismetMathLibrary::GetForwardVector(Rotator);
			//计算射线检测末位置Location，UKismetMathLibrary::GetForwardVector获得旋转的向前向量（单位向量）连续射击越快偏移约大
			EndLocation = CameraLocation + CameraForwardVector*ServerSecondaryWeapon->BulletDistance;
		}
	}

	PistolSpreadMax += ServerSecondaryWeapon->SpreadWeaponMaxIndex;
	PistolSpreadMin -= ServerSecondaryWeapon->SpreadWeaponMinIndex;

	//射线检测函数
	bool HitSuccess = UKismetSystemLibrary::LineTraceSingle(GetWorld(),CameraLocation,EndLocation,ETraceTypeQuery::TraceTypeQuery1,false,
	IngoryArray,EDrawDebugTrace::None,HitResult,true,FLinearColor::Red,FLinearColor::Green,3.f);
	if (HitSuccess)
	{
		UKismetSystemLibrary::PrintString(GetWorld(),FString::Printf(TEXT("Hit Actor Name = %s"),*HitResult.GetActor()->GetName()));
		//判断射线检测打到的物体是否为AFPSTeachBaseCharacter
		AFPSTeachBaseCharacter* FPSCharacter = Cast<AFPSTeachBaseCharacter>(HitResult.GetActor());
		if (FPSCharacter)
		{
			//智能指针
			DamagePlayer(HitResult.PhysMaterial.Get(),HitResult.GetActor(),CameraLocation,HitResult);
		}
		else
		{
			//计算法线到物体X轴的旋转
			FRotator Rotation = UKismetMathLibrary::MakeRotFromX(HitResult.Normal);
			//多播生成弹孔
			MultiSpawnBulletDecal(HitResult.Location,Rotation);
		}
	}
}

void AFPSTeachBaseCharacter::WeaponSniperRifleLineTrace(FVector CameraLocation, FRotator CameraRotator, bool IsMoving)
{
	//初始化参数
	FVector EndLocation;
	FVector CameraForwardVector = UKismetMathLibrary::GetForwardVector(CameraRotator);
	TArray<AActor*> IngoryArray;
	IngoryArray.Add(this);
	FHitResult HitResult;
	if (ServerPrimaryWeapon)
	{
		//是否开镜导致不同的射线检测
		if (IsAiming)
		{
			if (IsMoving)
			{
				FVector VT = CameraLocation + CameraForwardVector*ServerPrimaryWeapon->BulletDistance;
				float RandomX = UKismetMathLibrary::RandomFloatInRange(-ServerPrimaryWeapon->MovingFireFloatRandom,ServerPrimaryWeapon->MovingFireFloatRandom);
				float RandomY = UKismetMathLibrary::RandomFloatInRange(-ServerPrimaryWeapon->MovingFireFloatRandom,ServerPrimaryWeapon->MovingFireFloatRandom);
				float RandomZ = UKismetMathLibrary::RandomFloatInRange(-ServerPrimaryWeapon->MovingFireFloatRandom,ServerPrimaryWeapon->MovingFireFloatRandom);
				EndLocation = FVector(VT.X + RandomX,VT.Y + RandomY,VT.Z + RandomZ);
			}
			else
			{
				//计算射线检测末位置Location，UKismetMathLibrary::GetForwardVector获得旋转的向前向量（单位向量）
				EndLocation = CameraLocation + CameraForwardVector*ServerPrimaryWeapon->BulletDistance;
			}
			ServerSetAimingBool(false);
			ClientEndAiming();
		}
		else
		{
			FVector VT = CameraLocation + CameraForwardVector*ServerPrimaryWeapon->BulletDistance;
			float RandomX = UKismetMathLibrary::RandomFloatInRange(-ServerPrimaryWeapon->MovingFireFloatRandom,ServerPrimaryWeapon->MovingFireFloatRandom);
			float RandomY = UKismetMathLibrary::RandomFloatInRange(-ServerPrimaryWeapon->MovingFireFloatRandom,ServerPrimaryWeapon->MovingFireFloatRandom);
			float RandomZ = UKismetMathLibrary::RandomFloatInRange(-ServerPrimaryWeapon->MovingFireFloatRandom,ServerPrimaryWeapon->MovingFireFloatRandom);
			EndLocation = FVector(VT.X + RandomX,VT.Y + RandomY,VT.Z + RandomZ);
		}
	}

	//射线检测函数
	bool HitSuccess = UKismetSystemLibrary::LineTraceSingle(GetWorld(),CameraLocation,EndLocation,ETraceTypeQuery::TraceTypeQuery1,false,
	IngoryArray,EDrawDebugTrace::None,HitResult,true,FLinearColor::Red,FLinearColor::Green,3.f);

	if (HitSuccess)
	{
		UKismetSystemLibrary::PrintString(GetWorld(),FString::Printf(TEXT("Hit Actor Name = %s"),*HitResult.GetActor()->GetName()));
		//判断射线检测打到的物体是否为AFPSTeachBaseCharacter
		AFPSTeachBaseCharacter* FPSCharacter = Cast<AFPSTeachBaseCharacter>(HitResult.GetActor());
		if (FPSCharacter)
		{
			//智能指针
			DamagePlayer(HitResult.PhysMaterial.Get(),HitResult.GetActor(),CameraLocation,HitResult);
		}
		else
		{
			//计算法线到物体X轴的旋转
			FRotator Rotation = UKismetMathLibrary::MakeRotFromX(HitResult.Normal);
			//多播生成弹孔
			MultiSpawnBulletDecal(HitResult.Location,Rotation);
		}
	}
	
}

void AFPSTeachBaseCharacter::DamagePlayer(UPhysicalMaterial* PhysicalMaterial,AActor* DamagedActor,FVector HitFromDirection,FHitResult& HitInfo)
{
	AWeaponBaseServer* CurrenServerWeapon = GetCurrenServerWeapon();
	if(CurrenServerWeapon)
	{
		switch (PhysicalMaterial->SurfaceType)
		{
			case EPhysicalSurface::SurfaceType1:
				{
					float Damage = CurrenServerWeapon->DamageBase * 4;
					Damage = DamageHeadResult(Damage);
					//Head
					UGameplayStatics::ApplyPointDamage(DamagedActor,Damage,HitFromDirection,HitInfo,
		GetController(),this,UDamageType::StaticClass());
				}
			break;
			case EPhysicalSurface::SurfaceType2:
				{
					float Damage = CurrenServerWeapon->DamageBase * 1;
					Damage = DamageBodyResult(Damage);
					//Body
					UGameplayStatics::ApplyPointDamage(DamagedActor,Damage,HitFromDirection,HitInfo,
		GetController(),this,UDamageType::StaticClass());
				}
				break;
			case EPhysicalSurface::SurfaceType3:
				{
					float Damage = CurrenServerWeapon->DamageBase * 0.8;
					Damage = DamageBodyResult(Damage);
					//Arm
					UGameplayStatics::ApplyPointDamage(DamagedActor,Damage,HitFromDirection,HitInfo,
		GetController(),this,UDamageType::StaticClass());
				}
				break;
			case EPhysicalSurface::SurfaceType4:
				{
					float Damage = CurrenServerWeapon->DamageBase * 0.7;
					Damage = DamageBodyResult(Damage);
					//Leg
					UGameplayStatics::ApplyPointDamage(DamagedActor,Damage,HitFromDirection,HitInfo,
		GetController(),this,UDamageType::StaticClass());
				}
				break;
		}
	}
}

void AFPSTeachBaseCharacter::BuyArmor(bool bHead)
{
	if (bHead)
	{
		HeadArmor = 100;
		UKismetSystemLibrary::PrintString(GetOwner(),FString::Printf(TEXT("%d"),HeadArmor));
	}
	else
	{
		BodyArmor = 100;
		UKismetSystemLibrary::PrintString(GetOwner(),FString::Printf(TEXT("%d"),BodyArmor));
	}
	ClientUpdataHealthUI(Health,HeadArmor,BodyArmor);
}

void AFPSTeachBaseCharacter::ReSetPlayerState(float NewHealth, float NewHeadArmor, float NewBodyArmor)
{
	if(HasAuthority())
	{
		Health = NewHealth;
		HeadArmor = NewHeadArmor;
		BodyArmor = NewBodyArmor;
		ClientUpdataHealthUI(Health,HeadArmor,BodyArmor);
	}
}

void AFPSTeachBaseCharacter::OnPointDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy,
                                           FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection,
                                           const UDamageType* DamageType, AActor* DamageCauser)
{
	Health -= Damage;
	ClientUpdataHealthUI(Health,HeadArmor,BodyArmor);
	if (Health <= 0)
	{
		//角色死亡
		DeathMatchDeath(DamageCauser);
	}
	UKismetSystemLibrary::PrintString(this,FString::Printf(TEXT("Health = %f"),Health));
}

float AFPSTeachBaseCharacter::DamageHeadResult(float InDamageBase)
{
	AWeaponBaseServer* CurrenServerWeapon = GetCurrenServerWeapon();
	float InDamageReduction = CurrenServerWeapon->HeadDamageReduction;
	if (!(HeadArmor == 0))
	{
		if (InDamageReduction <= HeadArmor)
		{
			HeadArmor -= InDamageReduction;
		}
		else
		{
			InDamageReduction = HeadArmor;
			HeadArmor = 0;
		}
		InDamageBase -= InDamageReduction;
	}
	return InDamageBase;
}

float AFPSTeachBaseCharacter::DamageBodyResult(float InDamageBase)
{
	AWeaponBaseServer* CurrenServerWeapon = GetCurrenServerWeapon();
	float InDamageReduction = CurrenServerWeapon->BodyDamageReduction;
	if (!(BodyArmor == 0))
	{
		if (InDamageReduction <= BodyArmor)
		{
			BodyArmor -= InDamageReduction;
		}
		else
		{
			InDamageReduction = BodyArmor;
			BodyArmor = 0;
		}
		InDamageBase -= InDamageReduction;
	}
	return InDamageBase;
}

void AFPSTeachBaseCharacter::DelaySpreadWeaponShootCallBack()
{
	PistolSpreadMax = 0 ;
	PistolSpreadMin = 0 ;
}


void AFPSTeachBaseCharacter::WeaponPrimaryAutomaticFire()
{
	if(ServerPrimaryWeapon->ClipCurrentAmmo > 0)
	{
		if (UKismetMathLibrary::VSize(GetVelocity()) > 0.1)
		{
			//服务端（减少弹药，射线检测（武器），伤害计算，弹孔生成,音效，特效）
			ServerPrimaryFireRifleWeapon(PlayerCamera->GetComponentLocation(),PlayerCamera->GetComponentRotation(),true);
		}
		else
		{
			//服务端（减少弹药，射线检测（武器），伤害计算，弹孔生成,音效，特效）
			ServerPrimaryFireRifleWeapon(PlayerCamera->GetComponentLocation(),PlayerCamera->GetComponentRotation(),false);
		}
		
		//客户端（模型动画）
		ClientFire();

		//后坐力
		ClientPrimaryRecoil();
		
	}
	else
	{
		StopFirePrimary();
	}
}

#pragma endregion 

//网络同步

#pragma region NetWorking

void AFPSTeachBaseCharacter::LowSpeedWalkAction()
{
	GetCharacterMovement()->MaxWalkSpeed = 300;
	ServerLowSpeedWalkAction();
}

void AFPSTeachBaseCharacter::NormalSpeedWalkAction()
{
	GetCharacterMovement()->MaxWalkSpeed = 600;
	ServerNormalSpeedWalkAction();
}

void AFPSTeachBaseCharacter::ServerLowSpeedWalkAction_Implementation()
{
	GetCharacterMovement()->MaxWalkSpeed = 300;
}

bool AFPSTeachBaseCharacter::ServerLowSpeedWalkAction_Validate()
{
	return true;
}

void AFPSTeachBaseCharacter::ServerNormalSpeedWalkAction_Implementation()
{
	GetCharacterMovement()->MaxWalkSpeed = 600;
}

bool AFPSTeachBaseCharacter::ServerNormalSpeedWalkAction_Validate()
{
	return true;
}

void AFPSTeachBaseCharacter::ServerBuyWeapon_Implementation(EWeaponType WeaponType)
{
	//卸下装备
	ServerDischargeWeapon(CurrentWeaponType,WeaponType);
}

bool AFPSTeachBaseCharacter::ServerBuyWeapon_Validate(EWeaponType WeaponType)
{
	return true;
}

void AFPSTeachBaseCharacter::ServerSwitchWeaponWeapon_Implementation(EWeapon SwitchType)
{
	//
	//int NextTag =(int8)CurrentWeaponType;
	switch (SwitchType)
	{
	case EWeapon::PrimaryWeapon:
		{
			if (!(CurrentWeaponType == EWeapon::PrimaryWeapon)&&ServerPrimaryWeapon)
			{
				UnEquip();
				ActiveWeapon = ServerPrimaryWeapon->KindOfWeapon;
				CurrentWeaponType = EWeapon::PrimaryWeapon;
				FName WeaponSocketName = TEXT("Weapon_Rifle");
				if (ActiveWeapon == EWeaponType::M4A1)
				{
					WeaponSocketName = TEXT("M4A1_Socket");
				}
				if (ActiveWeapon == EWeaponType::Knife)
				{
					WeaponSocketName = TEXT("Knife_Socket");
				}
				ServerPrimaryWeapon->K2_AttachToComponent(this->GetMesh(),WeaponSocketName,EAttachmentRule::SnapToTarget,
					EAttachmentRule::SnapToTarget,
					EAttachmentRule::SnapToTarget,
					true);
				UpdataBodyBlendPose(ServerPrimaryWeapon->AnimBlendID);
				//客户端
				ClientEquipPrimary(ServerPrimaryWeapon->ClipCurrentAmmo,ServerPrimaryWeapon->GunCurrentAmmo);
			}
		}
		break;
	case EWeapon::SecondaryWeapans:
		{
			if (!(CurrentWeaponType == EWeapon::SecondaryWeapans)&&ServerSecondaryWeapon)
			{
				//服务器端
				UnEquip();
				ActiveWeapon = ServerSecondaryWeapon->KindOfWeapon;
				CurrentWeaponType = EWeapon::SecondaryWeapans;
				FName WeaponSocketName = TEXT("Weapon_Rifle");
				if (ActiveWeapon == EWeaponType::M4A1)
				{
					WeaponSocketName = TEXT("M4A1_Socket");
				}
				if (ActiveWeapon == EWeaponType::Knife)
				{
					WeaponSocketName = TEXT("Knife_Socket");
				}
				ServerSecondaryWeapon->K2_AttachToComponent(this->GetMesh(),WeaponSocketName,EAttachmentRule::SnapToTarget,
					EAttachmentRule::SnapToTarget,
					EAttachmentRule::SnapToTarget,
					true);
				UpdataBodyBlendPose(ServerSecondaryWeapon->AnimBlendID);
				//客户端
				ClientEquipSecondary(ServerSecondaryWeapon->ClipCurrentAmmo,ServerSecondaryWeapon->GunCurrentAmmo);
			}
		}
		break;
	case EWeapon::Knife:
		{
			if (!(CurrentWeaponType == EWeapon::Knife)&&ServerKnifeWeapon)
			{
				//服务器端
				UnEquip();
				ActiveWeapon = ServerKnifeWeapon->KindOfWeapon;
				CurrentWeaponType = EWeapon::Knife;
				FName WeaponSocketName = TEXT("Weapon_Rifle");
				if (ActiveWeapon == EWeaponType::M4A1)
				{
					WeaponSocketName = TEXT("M4A1_Socket");
				}
				if (ActiveWeapon == EWeaponType::Knife)
				{
					WeaponSocketName = TEXT("Knife_Socket");
				}
				ServerKnifeWeapon->K2_AttachToComponent(this->GetMesh(),WeaponSocketName,EAttachmentRule::SnapToTarget,
					EAttachmentRule::SnapToTarget,
					EAttachmentRule::SnapToTarget,
					true);;
				UpdataBodyBlendPose(ServerKnifeWeapon->AnimBlendID);
				//客户端
				ClientEquipKnife(ServerKnifeWeapon);
			}
		}
		break;
		default:{}
		break;
	}
}

bool AFPSTeachBaseCharacter::ServerSwitchWeaponWeapon_Validate(EWeapon SwitchType)
{
	return true;
}

void AFPSTeachBaseCharacter::ServerDischargeWeapon(EWeapon CurrentWeaponType1,EWeaponType BuyWeaponType)
{
	EWeapon BuyType;
	BuyType = EWeapon::PrimaryWeapon;
	if (BuyWeaponType == EWeaponType::DesertEagle)
	{
		BuyType = EWeapon::SecondaryWeapans;
	}
	switch (CurrentWeaponType1)
	{
	case EWeapon::PrimaryWeapon:
		{
			if (BuyType == EWeapon::PrimaryWeapon)
			{
				if (ServerPrimaryWeapon)
				{
					ServerPrimaryWeapon->Destroy();
					ServerPrimaryWeapon = nullptr;
				}
				ActiveWeapon = BuyWeaponType;
				PurchaseWeapon(BuyWeaponType);
			}
			else
			{
				//服务器端
				FName DischargeWeaponSocket = TEXT("PrimaryWeaponAccept");
				ServerPrimaryWeapon->K2_AttachToComponent(this->GetMesh(),DischargeWeaponSocket,EAttachmentRule::SnapToTarget,
			EAttachmentRule::SnapToTarget,
			EAttachmentRule::SnapToTarget,
			true);
				ActiveWeapon = BuyWeaponType;
				PurchaseWeapon(BuyWeaponType);
				//客户端
			}
		}
		break;
	case EWeapon::SecondaryWeapans:
		{
			if (BuyType == EWeapon::SecondaryWeapans)
			{
				if(ServerSecondaryWeapon)
				{
					ServerSecondaryWeapon->Destroy();
					ServerSecondaryWeapon = nullptr;
				}
				ActiveWeapon = BuyWeaponType;
				PurchaseWeapon(BuyWeaponType);
			}
			else
			{
				//服务器端
				FName DischargeWeaponSocket = TEXT("SecondaryWeaponAccept");
				ServerSecondaryWeapon->K2_AttachToComponent(this->GetMesh(),DischargeWeaponSocket,EAttachmentRule::SnapToTarget,
			EAttachmentRule::SnapToTarget,
			EAttachmentRule::SnapToTarget,
			true);
				ActiveWeapon = BuyWeaponType;
				PurchaseWeapon(BuyWeaponType);
			}
		}
		break;
	default:
		{
				
		}
	}
}

void AFPSTeachBaseCharacter::ServerReloadPrimary_Implementation()
{
	if (ServerPrimaryWeapon)
	{
		if (ServerPrimaryWeapon->GunCurrentAmmo > 0 && ServerPrimaryWeapon->ClipCurrentAmmo < ServerPrimaryWeapon->MaxClipAmmo)
		{
			IsReloading = true;
			ClientReload();
			MultiBodyReload();
		}
	}
}

bool AFPSTeachBaseCharacter::ServerReloadPrimary_Validate()
{
	return true;
}

void AFPSTeachBaseCharacter::ServerReloadSecondary_Implementation()
{
	if (ServerSecondaryWeapon)
	{
		if (ServerSecondaryWeapon->GunCurrentAmmo > 0 && ServerSecondaryWeapon->ClipCurrentAmmo < ServerSecondaryWeapon->MaxClipAmmo)
		{
			IsReloading = true;
			ClientReload();
			MultiBodyReload();
		}
	}
}

bool AFPSTeachBaseCharacter::ServerReloadSecondary_Validate()
{
	return true;
}

void AFPSTeachBaseCharacter::ServerSetAimingBool_Implementation(bool AimingBool)
{
	IsAiming = AimingBool;
}

bool AFPSTeachBaseCharacter::ServerSetAimingBool_Validate(bool AimingBool)
{
	return true;
}

void AFPSTeachBaseCharacter::ServerDelaySniperShootCallBack_Implementation()
{
	IsFiring = false;
}

bool AFPSTeachBaseCharacter::ServerDelaySniperShootCallBack_Validate()
{
	return true;
}

void AFPSTeachBaseCharacter::ServerStopFiring_Implementation()
{
	IsFiring = false;
}

bool AFPSTeachBaseCharacter::ServerStopFiring_Validate()
{
	return true;
}

void AFPSTeachBaseCharacter::ClientEquipKnife_Implementation(AWeaponBaseServer* KnifeWeapon)
{
	if (KnifeWeapon)
	{
		ClientSpawnKnifeWeapon(KnifeWeapon);
	}
}

void AFPSTeachBaseCharacter::ClientEquipSecondary_Implementation(int CurrentAmmo,int CurrentGunAmmo)
{
	if(ServerSecondaryWeapon)
	{
		ClientSpawnSecondaryWeapon(CurrentAmmo,CurrentGunAmmo);
	}
}

void AFPSTeachBaseCharacter::ClientFire_Implementation()
{
	AWeaponBaseClient* CurrenClientWeapon = GetCurrenClientWeapon();
	if(CurrenClientWeapon)
	{
		//枪体播放动画
		CurrenClientWeapon->PlayShootAnimation();
		//手臂播放动画
		UAnimMontage* ClientFPArmsAnim = CurrenClientWeapon->ClientArmsFIreAnimMontage;
		ClientArmsAnimBP->Montage_SetPlayRate(ClientFPArmsAnim,1);
		ClientArmsAnimBP->Montage_Play(ClientFPArmsAnim);
		//播放声音和特效
		CurrenClientWeapon->DisplayWeaponEffect();
		//应用摄像机抖动
		FPSPlayerController->PlayFPSCameraShake(CurrenClientWeapon->CameraShake);
		//准心动画
		FPSPlayerController->DoRecoilAnim();
	}
}

void AFPSTeachBaseCharacter::ServerPrimaryFireRifleWeapon_Implementation(FVector CameraLocation,FRotator CameraRotator,bool IsMoving)
{
	if (ServerPrimaryWeapon)
	{
		//UKismetSystemLibrary::PrintString(this,FString::Printf(TEXT("2222")));
		//调用多播函数
		ServerPrimaryWeapon->MultiShootingEffect();
		//子弹数量减一
		ServerPrimaryWeapon->ClipCurrentAmmo -= 1;
		//多播——播放身体动画
		MultiShooting();
		
		//更新客户端UI
		ClientUpdataAmmoUI(ServerPrimaryWeapon->ClipCurrentAmmo,ServerPrimaryWeapon->GunCurrentAmmo);
	}

	IsFiring = true;
	
	WeaponPrimaryRifleLineTrace(CameraLocation,CameraRotator,IsMoving);

	//UKismetSystemLibrary::PrintString(this,FString::Printf(TEXT("ServerPrimaryWeapon->ClipCurrentAmmo = %d"),ServerPrimaryWeapon->ClipCurrentAmmo));
}

bool AFPSTeachBaseCharacter::ServerPrimaryFireRifleWeapon_Validate(FVector CameraLocation,FRotator CameraRotator,bool IsMoving)
{
	return true;
}

void AFPSTeachBaseCharacter::ServerSecondaryFireRifleWeapon_Implementation(FVector CameraLocation,
                                                                           FRotator CameraRotator, bool IsMoving)
{
	if (ServerSecondaryWeapon)
	{
		FLatentActionInfo ActionInfo;
		ActionInfo.CallbackTarget = this;
		ActionInfo.ExecutionFunction = TEXT("DelaySpreadWeaponShootCallBack");
		ActionInfo.UUID = FMath::Rand();
		ActionInfo.Linkage = 0;
		UKismetSystemLibrary::Delay(this,ServerSecondaryWeapon->SpreadWeaponCallBackRate,ActionInfo);
		//UKismetSystemLibrary::PrintString(this,FString::Printf(TEXT("2222")));
		//调用多播函数
		ServerSecondaryWeapon->MultiShootingEffect();
		//子弹数量减一
		ServerSecondaryWeapon->ClipCurrentAmmo -= 1;
		//多播——播放身体动画
		MultiShooting();
		
		//更新客户端UI
		ClientUpdataAmmoUI(ServerSecondaryWeapon->ClipCurrentAmmo,ServerSecondaryWeapon->GunCurrentAmmo);
	}

	IsFiring = true;
	
	WeaponSecondaryRifleLineTrace(CameraLocation,CameraRotator,IsMoving);

}

bool AFPSTeachBaseCharacter::ServerSecondaryFireRifleWeapon_Validate(FVector CameraLocation,
	FRotator CameraRotator, bool IsMoving)
{
	return true;
}

void AFPSTeachBaseCharacter::ServerSniperFireRifleWeapon_Implementation(FVector CameraLocation,
	FRotator CameraRotator, bool IsMoving)
{
	if (ServerPrimaryWeapon)
	{
		//UKismetSystemLibrary::PrintString(this,FString::Printf(TEXT("2222")));
		//调用多播函数
		ServerPrimaryWeapon->MultiShootingEffect();
		//子弹数量减一
		ServerPrimaryWeapon->ClipCurrentAmmo -= 1;
		//多播——播放身体动画
		MultiShooting();
		
		//更新客户端UI
		ClientUpdataAmmoUI(ServerPrimaryWeapon->ClipCurrentAmmo,ServerPrimaryWeapon->GunCurrentAmmo);

		ClientDelaySniperShootCallBack();
	}

	IsFiring = true;
	
	WeaponSniperRifleLineTrace(CameraLocation,CameraRotator,IsMoving);

}

bool AFPSTeachBaseCharacter::ServerSniperFireRifleWeapon_Validate(FVector CameraLocation, FRotator CameraRotator,
	bool IsMoving)
{
	return true;
}

void AFPSTeachBaseCharacter::ClientEquipPrimary_Implementation(int CurrentAmmo,int CurrentGunAmmo)
{
	if(ServerPrimaryWeapon)
	{
		ClientSpawnPrimaryWeapon(CurrentAmmo,CurrentGunAmmo);
	}
}

#pragma endregion 


#pragma region Weapon

void AFPSTeachBaseCharacter::EquipPrimary(AWeaponBaseServer* WeaponBaseServer)
{
	if (ServerPrimaryWeapon && IsBuying)
	{
		//PS 暂时不知道为什么服务器会调用两次函数，所以以下方法有问题
		ServerPrimaryWeapon->Destroy();
		ServerPrimaryWeapon = nullptr;
		ServerSpawnPrimaryWeapon(WeaponBaseServer);
	} 
	else
	{
		ServerSpawnPrimaryWeapon(WeaponBaseServer);
	}
}

void AFPSTeachBaseCharacter::EquipSecondary(AWeaponBaseServer* WeaponBaseServer)
{
	if (ServerSecondaryWeapon && IsBuying)
	{
		//PS 暂时不知道为什么服务器会调用两次函数，所以以下方法有问题
		ServerSecondaryWeapon->Destroy();
		ServerSecondaryWeapon = nullptr;
		ServerSpawnSecondaryWeapon(WeaponBaseServer);
	} 
	else
	{
		ServerSpawnSecondaryWeapon(WeaponBaseServer);
	}
}

void AFPSTeachBaseCharacter::BuyWeaponFun(EWeaponType WeaponType)
{
	if (!IsReloading)
	{
		if (!IsFiring)
		{
			ServerBuyWeapon(WeaponType);
		}
	}
}

void AFPSTeachBaseCharacter::SwitchWeaponFun(EWeapon SwitchType)
{
	if (!IsReloading)
	{
		if (!IsFiring)
		{
			ServerSwitchWeaponWeapon(SwitchType);
		}
	}
}

EWeaponType AFPSTeachBaseCharacter::GetCurrentClientWeaponType()
{
	return ActiveWeapon;
}

AWeaponBaseClient* AFPSTeachBaseCharacter::GetCurrenClientWeapon()
{
	switch (ActiveWeapon)
	{
		case EWeaponType::AK47:
			{
				return ClientPrimaryWeapon;
			}
		break;
		case EWeaponType::M4A1:
				{
					return ClientPrimaryWeapon;
				}
		break;
		case EWeaponType::MP7:
				{
					return ClientPrimaryWeapon;
				}
		break;
		case EWeaponType::DesertEagle:
				{
					return ClientSecondaryWeapon;
				}
		break;
		case EWeaponType::Sniper:
				{
					return ClientPrimaryWeapon;
				}
		break;
	}

	return nullptr;
}

AWeaponBaseServer* AFPSTeachBaseCharacter::GetCurrenServerWeapon()
{
	switch (ActiveWeapon)
	{
	case EWeaponType::AK47:
		{
			return ServerPrimaryWeapon;
		}
		break;
	case EWeaponType::M4A1:
		{
			return ServerPrimaryWeapon;
		}
		break;
	case EWeaponType::MP7:
		{
			return ServerPrimaryWeapon;
		}
		break;
	case EWeaponType::DesertEagle:
		{
			return ServerSecondaryWeapon;
		}
		break;
	case EWeaponType::Sniper:
		{
			return ServerPrimaryWeapon;
		}
		break;
	}
	
	return nullptr;
}

void AFPSTeachBaseCharacter::UnEquip()
{
	switch (CurrentWeaponType)
	{
	case EWeapon::PrimaryWeapon:
		{
			//服务器端
			FName DischargeWeaponSocket = TEXT("PrimaryWeaponAccept");
			ServerPrimaryWeapon->K2_AttachToComponent(this->GetMesh(),DischargeWeaponSocket,EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		true);
		}
		break;
	case EWeapon::SecondaryWeapans:
		{
			FName DischargeWeaponSocket = TEXT("SecondaryWeaponAccept");
			ServerSecondaryWeapon->K2_AttachToComponent(this->GetMesh(),DischargeWeaponSocket,EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		true);
		}
		break;
	case EWeapon::Knife:
		{
			FName DischargeWeaponSocket = TEXT("KnifeWeaponAccept");
			ServerKnifeWeapon->K2_AttachToComponent(this->GetMesh(),DischargeWeaponSocket,EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		true);
		}
		break;
	}
}


void AFPSTeachBaseCharacter::StartKindOfWeapon()
{
	if(HasAuthority())
	{
		switch (FPSPlayerController->KingOfGame)
		{
		case EGameType::GameDeath:
			{
				int RandInt = (int8)EWeaponType::EEND-1;
				EquipKnife();
				PurchaseWeapon(static_cast<EWeaponType>(UKismetMathLibrary::RandomIntegerInRange(0,RandInt)));
			}
			break;
		case EGameType::Game5v5:
			{
				EquipKnife();
				PurchaseWeapon(EWeaponType::DesertEagle);
			}
			break;
		default:
			{
				
			}
			break;
		}
	}
}

void AFPSTeachBaseCharacter::PurchaseWeapon(EWeaponType WeaponType)
{
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Owner = this;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	switch (WeaponType)
	{
	case EWeaponType::AK47:
		{
			UClass* BluprintVar = StaticLoadClass(AWeaponBaseServer::StaticClass(),nullptr,TEXT("Blueprint'/Game/Blueprint/Weapon/AK47/ServerBP_AK47.ServerBP_AK47_C'"));
			AWeaponBaseServer* ServerWeapon = GetWorld()->SpawnActor<AWeaponBaseServer>(BluprintVar,GetActorTransform(),SpawnInfo);
			if(ServerWeapon)
			{
				ServerWeapon->EquipWeapon();
				EquipPrimary(ServerWeapon);
			}
		}
		break;
	case EWeaponType::M4A1:
		{
			UClass* BluprintVar = StaticLoadClass(AWeaponBaseServer::StaticClass(),nullptr,TEXT("Blueprint'/Game/Blueprint/Weapon/M4A1/ServerBP_M4A1.ServerBP_M4A1_C'"));
			AWeaponBaseServer* ServerWeapon = GetWorld()->SpawnActor<AWeaponBaseServer>(BluprintVar,GetActorTransform(),SpawnInfo);
			if(ServerWeapon)
			{
				ServerWeapon->EquipWeapon();
				EquipPrimary(ServerWeapon);
			}
		}
		break;
	case EWeaponType::MP7:
		{
			UClass* BluprintVar = StaticLoadClass(AWeaponBaseServer::StaticClass(),nullptr,TEXT("Blueprint'/Game/Blueprint/Weapon/MP7/ServerBP_MP7.ServerBP_MP7_C'"));
			AWeaponBaseServer* ServerWeapon = GetWorld()->SpawnActor<AWeaponBaseServer>(BluprintVar,GetActorTransform(),SpawnInfo);
			if(ServerWeapon)
			{
				ServerWeapon->EquipWeapon();
				EquipPrimary(ServerWeapon);
			}
		}
		break;
	case EWeaponType::DesertEagle:
		{
			UClass* BluprintVar = StaticLoadClass(AWeaponBaseServer::StaticClass(),nullptr,TEXT("Blueprint'/Game/Blueprint/Weapon/DesertEagle/ServerBP_DesertEagle.ServerBP_DesertEagle_C'"));
			AWeaponBaseServer* ServerWeapon = GetWorld()->SpawnActor<AWeaponBaseServer>(BluprintVar,GetActorTransform(),SpawnInfo);
			if (ServerWeapon)
			{
				ServerWeapon->EquipWeapon();
				EquipSecondary(ServerWeapon);
			}
		}
		break;
	case EWeaponType::Sniper:
		{
			UClass* BluprintVar = StaticLoadClass(AWeaponBaseServer::StaticClass(),nullptr,TEXT("Blueprint'/Game/Blueprint/Weapon/Sniper/ServerBP_Sniper.ServerBP_Sniper_C'"));
			AWeaponBaseServer* ServerWeapon = GetWorld()->SpawnActor<AWeaponBaseServer>(BluprintVar,GetActorTransform(),SpawnInfo);
			if(ServerWeapon)
			{
				ServerWeapon->EquipWeapon();
				EquipPrimary(ServerWeapon);
			}
		}
		break;
	default:
		{
				
		}
		break;
	}
}

void AFPSTeachBaseCharacter::EquipKnife()
{
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Owner = this;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	UClass* BluprintVar = StaticLoadClass(AWeaponBaseServer::StaticClass(),nullptr,TEXT("Blueprint'/Game/Blueprint/Weapon/Knife/ServerBP_Knife.ServerBP_Knife_C'"));
	AWeaponBaseServer* KnifeWeapon = GetWorld()->SpawnActor<AWeaponBaseServer>(BluprintVar,GetActorTransform(),SpawnInfo);
	KnifeWeapon->EquipWeapon();
	if (!ServerKnifeWeapon)
	{
		ServerKnifeWeapon = KnifeWeapon;
		ServerKnifeWeapon->SetOwner(this);
		ServerKnifeWeapon->K2_AttachToComponent(this->GetMesh(),TEXT("KnifeWeaponAccept"),EAttachmentRule::SnapToTarget,
			EAttachmentRule::SnapToTarget,
			EAttachmentRule::SnapToTarget,
			true);
	} 
}

void AFPSTeachBaseCharacter::DeathMatchDeath(AActor* DamageActor)
{
	//死亡删除武器（服务器端）
	AWeaponBaseServer* CurrentServerWeapon = GetCurrenServerWeapon();
	AWeaponBaseClient* CurrentClientWeapon = GetCurrenClientWeapon();
	if (CurrentServerWeapon)
	{
		CurrentServerWeapon->Destroy();
	}
	if (CurrentClientWeapon)
	{
		CurrentClientWeapon->Destroy();
	}
	//死亡调用
	if (FPSPlayerController)
	{
		FPSPlayerController->DeathMatchDeath(DamageActor);
	}
	/*
	AMulitFPSPlayerController* MultiPlayerController = Cast<AMulitFPSPlayerController>(GetController());
	if (MultiPlayerController)
	{
		MultiPlayerController->DeathMatchDeath(DamageActor);
	}
	*/
}

#pragma endregion

//属性网络复制所需要设置的条件
void AFPSTeachBaseCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(AFPSTeachBaseCharacter,IsFiring,COND_None);
	DOREPLIFETIME_CONDITION(AFPSTeachBaseCharacter,IsReloading,COND_None);
	DOREPLIFETIME_CONDITION(AFPSTeachBaseCharacter,ActiveWeapon,COND_None);
	DOREPLIFETIME_CONDITION(AFPSTeachBaseCharacter,IsAiming,COND_None);
}