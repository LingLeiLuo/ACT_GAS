// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_PlayerStartUpData.h"

#include "GameplayAbility/RoAbilitySystemComponent.h"

void UDataAsset_PlayerStartUpData::GiveToAbilitySystemComponent(URoAbilitySystemComponent* InAbilitySystemComponent,
                                                                int32 InLevel)
{
	Super::GiveToAbilitySystemComponent(InAbilitySystemComponent, InLevel);

	for (const FRoPlayerAbilitySet& AbilitySet : PlayerStartUpAbilities)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec AbilitySpec(AbilitySet.AbilityToGrant);
		AbilitySpec.SourceObject = InAbilitySystemComponent->GetAvatarActor();
		AbilitySpec.Level = InLevel;
		AbilitySpec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);
		
		InAbilitySystemComponent->GiveAbility(AbilitySpec);
	}
}
