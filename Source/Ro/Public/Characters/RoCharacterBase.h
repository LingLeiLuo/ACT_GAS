// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RoCharacterBase.generated.h"

UCLASS()
class RO_API ARoCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ARoCharacterBase();

protected:
	virtual void BeginPlay() override;
};
