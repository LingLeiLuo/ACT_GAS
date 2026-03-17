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

	UFUNCTION(BlueprintPure, Category = "Ro|Ability")
	ARoPlayerCharacter* GetPlayerCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Ro|Ability")
	ARoPlayerController* GetPlayerControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Ro|Ability")
	URoPlayerCombatComponent* GetPlayerCombatComponentFromActorInfo();
	
private:
	TWeakObjectPtr<ARoPlayerCharacter> CachedPlayerCharacter;
	TWeakObjectPtr<ARoPlayerController> CachedPlayerController;
	
};
