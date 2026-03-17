// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "RoInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class RO_API URoInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template <class UserObject, typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag,
	                                  ETriggerEvent TriggerEvent, UserObject* ContextObject,
	                                  CallbackFunc InCallbackFunc)
	{
		checkf(InInputConfig, TEXT("Input Config Data Asset is null"));

		if (UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
		{
			BindAction(FoundAction, TriggerEvent, ContextObject, InCallbackFunc);
		}
	}

	template <class UserObject, typename CallbackFunc>
	void BindAbilityInputAction(const UDataAsset_InputConfig* InInputConfig, UserObject* ContextObject, CallbackFunc InputPressFunc, CallbackFunc InputReleaseFunc)
	{
		checkf(InInputConfig, TEXT("Input Config Data Asset is null"));

		for (const FRoInputActionConfig& ActionConfig : InInputConfig->AbilityInputActions)
		{
			if (!ActionConfig.IsValid())
			{
				continue;
			}

			BindAction(ActionConfig.InputAction, ETriggerEvent::Started, ContextObject, InputPressFunc, ActionConfig.InputTag);
			BindAction(ActionConfig.InputAction, ETriggerEvent::Completed, ContextObject, InputReleaseFunc, ActionConfig.InputTag);
		}
	}
};
