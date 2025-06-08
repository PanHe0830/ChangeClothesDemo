// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangeHUD.h"
#include "ClothesWidget.h"

void AChangeHUD::SetShowWidgetToViewPort()
{
	OwningPlayer = OwningPlayer == nullptr ? GetOwningPlayerController() : OwningPlayer;
	if (ShowWidget && OwningPlayer)
	{
		UClothesWidget* ClotherWidget = CreateWidget<UClothesWidget>(OwningPlayer, ShowWidget);
		if (ClotherWidget)
		{
			ClotherWidget->AddToViewport();
		}
	}
}
