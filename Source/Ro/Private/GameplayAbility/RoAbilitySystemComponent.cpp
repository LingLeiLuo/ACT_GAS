// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/RoAbilitySystemComponent.h"

#include "RoDebugHelper.h"
#include "Characters/RoPlayerCharacter.h"
#include "RoGameplayTags.h"

void URoAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid())
	{
		return;
	}

	ARoPlayerCharacter* PlayerCharacter = Cast<ARoPlayerCharacter>(GetOwner());
	
	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		// DebugHelper::Log(TEXT("AbilitySpec.DynamicAbilityTags"));
		if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
		{
			// DebugHelper::Log(TEXT("TryActivateAbility"));
			TryActivateAbility(AbilitySpec.Handle);
			
			if (PlayerCharacter->GetCanPreInput())
			{
				PlayerCharacter->CanPreInputTag = InputTag;
			}
		}
	}
		
}

void URoAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InputTag)
{
	
}
