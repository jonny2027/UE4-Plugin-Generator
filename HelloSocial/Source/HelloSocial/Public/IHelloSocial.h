#pragma once

#include "ModuleManager.h"

class IHelloSocial : public IModuleInterface
{

public:

	static inline IHelloSocial& Get()
	{
		return FModuleManager::LoadModuleChecked< IHelloSocial >( "HelloSocial" );
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded( "HelloSocial" );
	}
};

