// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbility/GA/RoGameplayAbility.h"
#include "RoPlayerGameplayAbility.generated.h"

class URoPlayerCombatComponent;
class ARoPlayerController;
class ARoPlayerCharacter;
/**
 * 
 */
UCLASS()
class RO_API URoPlayerGameplayAbility : public URoGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Ro|Ability")
	ARoPlayerCharacter* GetPlayerCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Ro|Ability")
	ARoPlayerController* GetPlayerControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Ro|Ability")
	URoPlayerCombatComponent* GetPlayerCombatComponentFromActorInfo();

protected:
	// 移动输入回调函数
	UFUNCTION()
	void OnMoveInputReceived(const FVector2D& MoveVector);

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ro|Ability")
	bool bNeedMoveCancel;
	
private:
	TWeakObjectPtr<ARoPlayerCharacter> CachedPlayerCharacter;
	TWeakObjectPtr<ARoPlayerController> CachedPlayerController;
	FDelegateHandle MoveInputDelegateHandle;
};
