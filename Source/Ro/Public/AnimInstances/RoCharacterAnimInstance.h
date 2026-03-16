// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimInstances/RoAnimInstanceBase.h"
#include "RoCharacterAnimInstance.generated.h"

class UCharacterMovementComponent;
class ARoCharacterBase;
/**
 * 
 */
UCLASS()
class RO_API URoCharacterAnimInstance : public URoAnimInstanceBase
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY()
	ARoCharacterBase* OwingCharacter;

	UPROPERTY()
	UCharacterMovementComponent* OwingCharacterMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bHasAcceleration;
};
