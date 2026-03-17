// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"

#include "GameplayAbility/RoAbilitySystemComponent.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(URoAbilitySystemComponent* InAbilitySystemComponent,
                                                              int32 InLevel)
{
	check(InAbilitySystemComponent);

	GrantAbilities(ActivateOnGivenAbilities, InAbilitySystemComponent, InLevel);
	GrantAbilities(ReactiveOnGivenAbilities, InAbilitySystemComponent, InLevel);

}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<URoGameplayAbility>>& InAbilities,
	URoAbilitySystemComponent* InAbilitySystemComponent, int32 InLevel)
{
	if (InAbilities.IsEmpty())
	{
		return;
	}

	for (const TSubclassOf<URoGameplayAbility>& Ability : InAbilities)
	{
		if (!Ability)
			continue;

		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InAbilitySystemComponent->GetAvatarActor();
		AbilitySpec.Level = InLevel;

		InAbilitySystemComponent->GiveAbility(AbilitySpec);
	}
}
