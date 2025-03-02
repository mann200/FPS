// Copyright (c) FJQ.2023.All Rights Reserved

#pragma once

#include "Modules/ModuleManager.h"

class FFJQMySqlModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void CopyDLL(FString DLLName);
};
