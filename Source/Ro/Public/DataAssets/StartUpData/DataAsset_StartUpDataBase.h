// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayAbility/GA/RoGameplayAbility.h"
#include "DataAsset_StartUpDataBase.generated.h"

class URoAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class RO_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(URoAbilitySystemComponent* InAbilitySystemComponent, int32 InLevel = 1);
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<URoGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<URoGameplayAbility>> ReactiveOnGivenAbilities;

	static void GrantAbilities(const TArray<TSubclassOf<URoGameplayAbility>>& InAbilities, URoAbilitySystemComponent* InAbilitySystemComponent, int32 InLevel = 1);
};
