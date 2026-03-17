// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/GA/RoPlayerGameplayAbility.h"

#include "Characters/RoPlayerCharacter.h"
#include "Controllers/RoPlayerController.h"
#include "AbilitySystemComponent.h"
#include "RoGameplayTags.h"

void URoPlayerGameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	// 注册移动输入委托
	if (ARoPlayerCharacter* PlayerCharacter = GetPlayerCharacterFromActorInfo())
	{
		MoveInputDelegateHandle = PlayerCharacter->OnMoveInputDelegate.AddUObject(this, &ThisClass::OnMoveInputReceived);
	}
}

void URoPlayerGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	// 注销移动输入委托
	if (MoveInputDelegateHandle.IsValid())
	{
		if (ARoPlayerCharacter* PlayerCharacter = GetPlayerCharacterFromActorInfo())
		{
			PlayerCharacter->OnMoveInputDelegate.Remove(MoveInputDelegateHandle);
		}
		MoveInputDelegateHandle.Reset();
	}

	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void URoPlayerGameplayAbility::OnMoveInputReceived(const FVector2D& MoveVector)
{
	// 检查AvatarActor是否拥有任意一个指定的Tag
	if (UAbilitySystemComponent* ASC = GetAbilitySystemComponentFromActorInfo())
	{
		if (ASC->HasMatchingGameplayTag(RoGameplayTags::Ability_MoveCancel_Window) && bNeedMoveCancel)
		{
			// 取消能力
			EndAbility(CurrentSpecHandle, CurrentActorInfo, CurrentActivationInfo, true, true);
		}
	}
}

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
