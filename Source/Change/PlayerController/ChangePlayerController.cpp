// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangePlayerController.h"
#include "Change/HUD/ChangeHUD.h"

void AChangePlayerController::BeginPlay()
{
	Super::BeginPlay();

	ChangeHUD = Cast<AChangeHUD>(GetHUD());

	ShowClothesView();
}

void AChangePlayerController::ShowClothesView()
{
	ChangeHUD == nullptr ? Cast<AChangeHUD>(GetHUD()) : ChangeHUD;

	if (ChangeHUD)
	{
		FInputModeGameAndUI Mode;
		SetInputMode(Mode);
		SetShowMouseCursor(true);
		ChangeHUD->SetShowWidgetToViewPort();
	}
}
