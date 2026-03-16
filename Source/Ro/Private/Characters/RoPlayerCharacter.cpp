// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/RoPlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/Input/RoInputComponent.h"
#include "RoGameplayTags.h"

ARoPlayerCharacter::ARoPlayerCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 200.f;
	SpringArm->SocketOffset = FVector(0.f, 55.f, 65.f);
	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
}

void ARoPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ARoPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	checkf(InputConfigDA, TEXT("InputConfigDataAsset is null"));

	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem = ULocalPlayer::GetSubsystem<
		UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(EnhancedInputSubsystem);

	EnhancedInputSubsystem->AddMappingContext(InputConfigDA->InputMappingContext, 0);

	URoInputComponent* ActionInputComponent = Cast<URoInputComponent>(PlayerInputComponent);

	ActionInputComponent->BindNativeInputAction(InputConfigDA, RoGameplayTags::Input_Move,
												ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	ActionInputComponent->BindNativeInputAction(InputConfigDA, RoGameplayTags::Input_Look,
												ETriggerEvent::Triggered, this, &ThisClass::Input_Look);
}

void ARoPlayerCharacter::Input_Move(const FInputActionValue& InInputActionValue)
{
	const FVector2D MoveVector = InInputActionValue.Get<FVector2D>();
	const FRotator MoveRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);

	if (MoveVector.Y != 0.f)
	{
		const FVector ForwardVector = MoveRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardVector, MoveVector.Y);
	}

	if (MoveVector.X != 0.f)
	{
		const FVector RightVector = MoveRotation.RotateVector(FVector::RightVector);
		AddMovementInput(RightVector, MoveVector.X);
	}
}

void ARoPlayerCharacter::Input_Look(const FInputActionValue& InInputActionValue)
{
	const FVector2D LookVector = InInputActionValue.Get<FVector2D>();

	if (LookVector.X != 0.f)
	{
		AddControllerYawInput(LookVector.X);
	}

	if (LookVector.Y != 0.f)
	{
		AddControllerPitchInput(LookVector.Y);
	}
}


