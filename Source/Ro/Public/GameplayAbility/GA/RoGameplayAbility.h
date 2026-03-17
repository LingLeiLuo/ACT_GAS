// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "RoGameplayAbility.generated.h"

class URoAbilitySystemComponent;
class URoCombatComponent;

UENUM(BlueprintType)
enum class ERoGameplayAbilityActivationPolicy : uint8
{
	OnGive,
	OnTriggered	
};

UCLASS()
class RO_API URoGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ro|Ability")
	ERoGameplayAbilityActivationPolicy ActivationPolicy = ERoGameplayAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category = "Ro|Ability")
	URoCombatComponent* GetCombatComponentFromActorInfo() const;

	UFUNCTION(BlueprintPure, Category = "Ro|Ability")
	URoAbilitySystemComponent* GetRoAbilitySystemComponentFromActorInfo() const;
};
