// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ChangeHUD.generated.h"

class UClothesWidget;

/**
 * 
 */
UCLASS()
class CHANGE_API AChangeHUD : public AHUD
{
	GENERATED_BODY()
public:
	void SetShowWidgetToViewPort();
	
private:
	UPROPERTY()
	class APlayerController* OwningPlayer;

	UPROPERTY(EditAnywhere, Category = "Widget")
	TSubclassOf<UClothesWidget> ShowWidget;
};
