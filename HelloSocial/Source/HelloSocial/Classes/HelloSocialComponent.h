#pragma once

#include "HelloSocialComponent.generated.h"

UCLASS(ClassGroup=HelloSocial, HideCategories=(Activation, "Components|Activation", Collision), meta=(BlueprintSpawnableComponent))
class UHelloSocialComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:	
	void OnRegister() override;
	void OnUnregister() override;	
};
