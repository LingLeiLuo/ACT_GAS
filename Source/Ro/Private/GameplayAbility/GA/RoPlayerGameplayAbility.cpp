// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/GA/RoPlayerGameplayAbility.h"

#include "Characters/RoPlayerCharacter.h"
#include "Controllers/RoPlayerController.h"

ARoPlayerCharacter* URoPlayerGameplayAbility::GetPlayerCharacterFromActorInfo()
{
	if (!CachedPlayerCharacter.IsValid())
	{
		CachedPlayerCharacter = Cast<ARoPlayerCharacter>(CurrentActorInfo->AvatarActor);
	}
		
	return CachedPlayerCharacter.IsValid() ? CachedPlayerCharacter.Get() : nullptr;
}

ARoPlayerController* URoPlayerGameplayAbility::GetPlayerControllerFromActorInfo()
{
	if (!CachedPlayerController.IsValid())
	{
		CachedPlayerController = Cast<ARoPlayerController>(CurrentActorInfo->PlayerController);
	}
		
	return CachedPlayerController.IsValid() ? CachedPlayerController.Get() : nullptr;
}

URoPlayerCombatComponent* URoPlayerGameplayAbility::GetPlayerCombatComponentFromActorInfo()
{
	return GetPlayerCharacterFromActorInfo()->GetCombatComponent();
}
