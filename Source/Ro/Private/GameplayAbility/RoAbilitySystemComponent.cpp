// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/RoAbilitySystemComponent.h"

#include "RoDebugHelper.h"

void URoAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid())
	{
		return;
	}

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		// DebugHelper::Log(TEXT("AbilitySpec.DynamicAbilityTags"));
		if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
		{
			// DebugHelper::Log(TEXT("TryActivateAbility"));
			TryActivateAbility(AbilitySpec.Handle);
		}
	}
		
}

void URoAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InputTag)
{
	
}
