// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/RoAbilitySystemComponent.h"

void URoAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid())
	{
		return;
	}

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
		{
			TryActivateAbility(AbilitySpec.Handle);
		}
	}
		
}

void URoAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InputTag)
{
	
}
