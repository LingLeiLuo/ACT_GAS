// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/GA/RoGameplayAbility.h"

#include "AbilitySystemComponent.h"
#include "Components/Combat/RoCombatComponent.h"
#include "GameplayAbility/RoAbilitySystemComponent.h"

void URoGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (ActivationPolicy == ERoGameplayAbilityActivationPolicy::OnGive)
	{
		if (ActorInfo && !Spec.IsActive())
		{
			ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
		}
	}
}

void URoGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (ActivationPolicy == ERoGameplayAbilityActivationPolicy::OnGive)
	{
		if (ActorInfo)
		{
			ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
		}
	}
}

URoCombatComponent* URoGameplayAbility::GetCombatComponentFromActorInfo() const
{
	return GetAvatarActorFromActorInfo()->FindComponentByClass<URoCombatComponent>();
}

URoAbilitySystemComponent* URoGameplayAbility::GetRoAbilitySystemComponentFromActorInfo() const
{
	return Cast<URoAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent);
}
