// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/RoCharacterBase.h"

#include "GameplayAbility/RoAbilitySystemComponent.h"
#include "GameplayAbility/RoAttributeSet.h"

// Sets default values
ARoCharacterBase::ARoCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	AbilitySystemComponent = CreateDefaultSubobject<URoAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

	AttributeSet = CreateDefaultSubobject<URoAttributeSet>(TEXT("AttributeSet"));
}

UAbilitySystemComponent* ARoCharacterBase::GetAbilitySystemComponent() const
{
	return GetRoAbilitySystemComponent();
}

void ARoCharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);

		ensure(!CharacterStartUpData.IsNull());
	}
}

