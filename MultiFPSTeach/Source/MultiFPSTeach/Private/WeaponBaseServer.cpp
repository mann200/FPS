// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBaseServer.h"
#include "FPSTeachBaseCharacter.h"
#include "GeometryCollection/GeometryCollectionSimulationTypes.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AWeaponBaseServer::AWeaponBaseServer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	RootComponent = WeaponMesh;
	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SphereCollision->SetupAttachment(RootComponent);

	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	WeaponMesh->SetCollisionObjectType(ECC_WorldStatic);
	WeaponMesh->SetOwnerNoSee(true);
	WeaponMesh->SetEnableGravity(true);
	WeaponMesh->SetSimulatePhysics(true);

	SphereCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereCollision->SetCollisionObjectType(ECC_WorldDynamic);

	bReplicates = true;
}

void AWeaponBaseServer::MultiShootingEffect_Implementation()
{
	if(GetOwner()!=UGameplayStatics::GetPlayerPawn(GetWorld(),0))
	{
		//生成开火特效
		UGameplayStatics::SpawnEmitterAttached(MuzzleFlash,WeaponMesh,TEXT("Fire_FX_Slot"),
		FVector::ZeroVector,FRotator::ZeroRotator,FVector::OneVector,
		EAttachLocation::KeepRelativeOffset,true,EPSCPoolMethod::None,
		true);
		//播放声音
		UGameplayStatics::PlaySoundAtLocation(GetWorld(),FireSound,GetActorLocation());
	}
}

bool AWeaponBaseServer::MultiShootingEffect_Validate()
{
	return true;
}

// Called when the game starts or when spawned
void AWeaponBaseServer::BeginPlay()
{
	Super::BeginPlay();
	
	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &AWeaponBaseServer::OnComponentBeginOverlap);
}

// Called every frame
void AWeaponBaseServer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeaponBaseServer::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AFPSTeachBaseCharacter* FPSCharacter = Cast<AFPSTeachBaseCharacter>(OtherActor);
	if (FPSCharacter)
	{
		EquipWeapon();
		switch (KindOfWeapon)
		{
			case EWeaponType::AK47:
				{
					FPSCharacter->EquipPrimary(this);
				}
			break;
			case EWeaponType::M4A1:
				{
					FPSCharacter->EquipPrimary(this);
				}
			break;
			case EWeaponType::MP7:
				{
					FPSCharacter->EquipPrimary(this);
				}
			break;
			case EWeaponType::DesertEagle:
				{
					FPSCharacter->EquipSecondary(this);
				}
			break;
			case EWeaponType::Sniper:
				{
					FPSCharacter->EquipPrimary(this);
				}
			break;
		}
	}
}

//拾取武器触发
void AWeaponBaseServer::EquipWeapon()
{
	WeaponMesh->SetEnableGravity(false);
	WeaponMesh->SetSimulatePhysics(false);
	SphereCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

//属性网络复制所需要设置的条件
void AWeaponBaseServer::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(AWeaponBaseServer,ClipCurrentAmmo,COND_None);
}
