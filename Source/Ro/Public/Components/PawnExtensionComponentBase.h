// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtensionComponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RO_API UPawnExtensionComponentBase : public UActorComponent
{
	GENERATED_BODY()

protected:	// Called when the game starts
	template <class T>
	T* GetOwningPawn() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "T must be a subclass of APawn");
		return CastChecked<T>(GetOwner());
	}

	APawn* GetOwningPawn() const
	{
		return GetOwningPawn<APawn>();
	}

	template <class T>
	T* GetController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APlayerController>::Value, "T must be a subclass of APlayerController");
		return GetOwningPawn()->GetController<T>();
	}
};
