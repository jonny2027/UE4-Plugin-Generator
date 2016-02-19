#include "HelloSocialPrivatePCH.h"
#include "HelloSocialSettings.h"
#include "ISettingsModule.h"

DEFINE_LOG_CATEGORY(LogHelloSocial);

#define LOCTEXT_NAMESPACE "HelloSocial"

class FHelloSocial : public IHelloSocial
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FHelloSocial, HelloSocial )

void FHelloSocial::StartupModule()
{
	// register settings
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "HelloSocial",
										 LOCTEXT("RuntimeSettingsName", "HelloSocial"),
										 LOCTEXT("RuntimeSettingsDescription", "Configure the HelloSocial plugin"),
										 GetMutableDefault<UHelloSocialSettings>()
										 );
	}
}


void FHelloSocial::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
