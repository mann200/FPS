// Copyright (c) FJQ.2023.All Rights Reserved

#include "FJQMySqlBPLibrary.h"
#include "IImageWrapper.h"
#include "IImageWrapperModule.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

UFJQMySqlBPLibrary::UFJQMySqlBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UFJQMySqlBPLibrary::FJQMySqlSampleFunction(float Param)
{
	return -1;
}

char* UFJQMySqlBPLibrary::GetImageDataFromPath(FString Path)
{
	FString FlieExpandName = FPaths::GetExtension(Path);
	EImageFormat ImageFormat;
	if (FlieExpandName.Equals("jpeg",ESearchCase::IgnoreCase) || FlieExpandName.Equals("jpg",ESearchCase::IgnoreCase))
	{
		ImageFormat = EImageFormat::JPEG;
	}
	else if(FlieExpandName.Equals("png",ESearchCase::IgnoreCase))
	{
		ImageFormat = EImageFormat::PNG;
	}
		else
		{
			ImageFormat = EImageFormat::BMP;
		}

	//什么一个ImageWrapper对象接收Image数据
	IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>("ImageWrapper");
	TSharedPtr<IImageWrapper> imageWrapper = ImageWrapperModule.CreateImageWrapper(ImageFormat);
	if (!imageWrapper)
	{
		return nullptr;
	}
	TArray<uint8> Imagebytes;
	void* ImageRaw = nullptr;
	//加载图片
	if (imageWrapper.IsValid() && FFileHelper::LoadFileToArray(Imagebytes,*Path))
	{
		if (imageWrapper->SetCompressed(Imagebytes.GetData(),Imagebytes.Num()) &&
			imageWrapper->GetRaw(ERGBFormat::BGRA,8,Imagebytes))
		{
			const uint64 RawNum = Imagebytes.Num();
			ImageRaw = FMemory::Malloc(RawNum);
			FMemory::Memcpy(ImageRaw,Imagebytes.GetData(),Imagebytes.Num());
		}
	}
	char* ImageData = static_cast<char*>(ImageRaw);
	//FMemory::Free(ImageRaw);
	return ImageData;
}

UTexture2D* UFJQMySqlBPLibrary::GetTextureFromChar(char* ImageChar)
{
	char* CharData = ImageChar;  // 输入的char*数据
	int32 DataSize = strlen(CharData); // 计算char*数据大小
	TArray<uint8> Data;
	Data.Init(0, DataSize + 1);  // 初始化一个动态数组并分配足够的内存空间，加1是因为需要为null字符预留一个字节
	FMemory::Memcpy(Data.GetData(), CharData, DataSize);  // 将char*数据复制到动态数组中
	Data[DataSize] = '\0';  // 添加null字符
	//什么一个ImageWrapper对象接收Image数据
	IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>("ImageWrapper");
	TSharedPtr<IImageWrapper> imageWrapper = ImageWrapperModule.CreateImageWrapper(EImageFormat::PNG);
	if (!imageWrapper)
	{
		return nullptr;
	}
	if (imageWrapper->SetCompressed(Data.GetData(),Data.Num()))
	{
		// 获取图片信息
		TArray<uint8> RawData;
		if (imageWrapper->GetRaw(ERGBFormat::BGRA,8,RawData))
		{
			const int32 Width = imageWrapper->GetWidth();
			const int32 Height = imageWrapper->GetHeight();
			UTexture2D* NewTexture2D = UTexture2D::CreateTransient(Width, Height, PF_B8G8R8A8);
			if (!NewTexture2D)
			{
				return nullptr;
			}
			// 初始化图片数据
			void* TextureData = NewTexture2D->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
			FMemory::Memcpy(TextureData, RawData.GetData(), RawData.Num());
			// 释放锁定
			NewTexture2D->PlatformData->Mips[0].BulkData.Unlock();
			NewTexture2D->UpdateResource();
			return NewTexture2D;
		}
	}
	return nullptr;
}






