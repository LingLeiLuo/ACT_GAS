// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/RoCharacterBase.h"
#include "RoPlayerCharacter.generated.h"

class URoPlayerCombatComponent;
class URoGameplayAbility;
struct FInputActionValue;
class UDataAsset_InputConfig;
class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class RO_API ARoPlayerCharacter : public ARoCharacterBase
{
	GENERATED_BODY()

public:
	ARoPlayerCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	// -----------------组件-----------------
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta=(AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta=(AllowPrivateAccess = "true"))
	UCameraComponent* Camera;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta=(AllowPrivateAccess = "true"))
	URoPlayerCombatComponent* CombatComponent;


	// ------------------输入------------------
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData", meta=(AllowPrivateAccess = "true"))
	UDataAsset_InputConfig* InputConfigDA;
	
	void Input_Move(const FInputActionValue& InInputActionValue);
	void Input_Look(const FInputActionValue& InInputActionValue);

	void InputAbilityInputPressed(FGameplayTag InInputTag);
	void InputAbilityInputReleased(FGameplayTag InInputTag);

public:
	FORCEINLINE URoPlayerCombatComponent* GetCombatComponent() const { return CombatComponent; }
};
