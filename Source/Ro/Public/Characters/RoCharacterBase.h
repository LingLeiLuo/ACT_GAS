// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/Character.h"
#include "RoCharacterBase.generated.h"

class UDataAsset_StartUpDataBase;
class URoAttributeSet;
class URoAbilitySystemComponent;

UCLASS()
class RO_API ARoCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ARoCharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;

protected:
	virtual void PossessedBy(AController* NewController) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AbilitySystem")
	URoAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="AbilitySystem")
	URoAttributeSet* AttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CharacterData")
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;
	
public:
	FORCEINLINE URoAbilitySystemComponent* GetRoAbilitySystemComponent() const { return AbilitySystemComponent; }
	FORCEINLINE URoAttributeSet* GetRoAttributeSet() const { return AttributeSet; }
};
