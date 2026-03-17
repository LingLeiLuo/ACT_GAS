// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "DataAsset_PlayerStartUpData.generated.h"

USTRUCT(BlueprintType)
struct FRoPlayerAbilitySet
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<URoGameplayAbility> AbilityToGrant;
	
	bool IsValid() const
	{
		return InputTag.IsValid() && AbilityToGrant;
	}
};

/**
 * 
 */
UCLASS()
class RO_API UDataAsset_PlayerStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(URoAbilitySystemComponent* InAbilitySystemComponent, int32 InLevel = 1) override;
	
private:
	UPROPERTY(EditAnywhere, Category="StartUpData")
	TArray<FRoPlayerAbilitySet> PlayerStartUpAbilities;
};
