#pragma once

#include "HelloSocialSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class UHelloSocialSettings : public UObject
{
	GENERATED_BODY()
	
public:
	UHelloSocialSettings(const FObjectInitializer& ObjectInitializer);
	
	// UPROPERTY(Config, EditAnywhere, Category=General, meta=(DisplayName="Example Bool Setting"))
	// bool ExampleBoolSetting;
	//
	// UPROPERTY(Config, EditAnywhere, Category=iOS, meta=(DisplayName="Example String Setting"))
	// FString ExampleStringSetting;
};
