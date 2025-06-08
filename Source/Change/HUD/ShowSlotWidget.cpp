// Fill out your copyright notice in the Description page of Project Settings.


#include "ShowSlotWidget.h"
#include "Components/EditableText.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Change/PlayerController/ChangePlayerController.h"
#include "Change/Character/ShowCharacter.h"

bool UShowSlotWidget::Initialize()
{
	if(!Super::Initialize())
	{
		return false;
	}
	if(Button)
	{
		Button->OnClicked.AddDynamic(this,&UShowSlotWidget::WearClicked);
	}

	return true;
}

void UShowSlotWidget::SetImage(UTexture2D* Texture)
{
	Image->SetBrushFromTexture(Texture);
}

void UShowSlotWidget::SetText(FText InText)
{
	EditableText->SetText(InText);
}

void UShowSlotWidget::SetClotheID(FName ID)
{
	ClothesID = ID;
}

void UShowSlotWidget::SetClotheType(ClothesType Type)
{
	ClothType = Type;
}

void UShowSlotWidget::SetClotheSkeletalMesh(USkeletalMesh* Mesh)
{
	SkeletalMesh = Mesh;
}

void UShowSlotWidget::SetSizeBoxScale(float x, float y)
{
	SizeBox->SetWidthOverride(x);
	SizeBox->SetHeightOverride(y);
}

FName UShowSlotWidget::GetClotheID()
{
	return ClothesID;
}

void UShowSlotWidget::WearClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("WearClicked"));
	AChangePlayerController* ChangePlayerController = Cast<AChangePlayerController>(UGameplayStatics::GetPlayerController(GetWorld(),0));
	if (ChangePlayerController)
	{
		AShowCharacter* ShowCharacter = Cast<AShowCharacter>(ChangePlayerController->GetCharacter());
		if (ShowCharacter)
		{
			if (ClothType == ClothesType::CLO_BODY)
			{
				ShowCharacter->SetBodyMesh(SkeletalMesh);
			}
		}
	}
}
