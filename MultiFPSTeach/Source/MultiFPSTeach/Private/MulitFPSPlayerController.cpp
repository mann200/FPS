// Fill out your copyright notice in the Description page of Project Settings.


#include "MulitFPSPlayerController.h"


void AMulitFPSPlayerController::PlayFPSCameraShake(TSubclassOf<UCameraShakeBase> CameraShake)
{
	ClientPlayCameraShake(CameraShake,1,ECameraShakePlaySpace::CameraLocal,FRotator::ZeroRotator);
}
