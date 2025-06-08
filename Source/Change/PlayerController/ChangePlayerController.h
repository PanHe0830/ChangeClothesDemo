// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ChangePlayerController.generated.h"

class AChangeHUD;

/**
 * 
 */
UCLASS()
class CHANGE_API AChangePlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;

private:
	void ShowClothesView();

	UPROPERTY()
	AChangeHUD* ChangeHUD;
};
