// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Change/Change.h"
#include "ShowSlotWidget.generated.h"

class UButton;
class UImage;
class UEditableText;
class USizeBox;
class USkeletalMesh;

/**
 * 
 */
UCLASS()
class CHANGE_API UShowSlotWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override;
	
public:
	void SetImage(UTexture2D* Texture);

	void SetText(FText InText);

	void SetClotheID(FName ID);

	void SetClotheType(ClothesType Type);

	void SetClotheSkeletalMesh(USkeletalMesh* Mesh);

	void SetSizeBoxScale(float x,float y);

	FName GetClotheID();

private:
	UFUNCTION()
	void WearClicked();

	UPROPERTY(meta = (Bindwidget))
	UButton* Button;

	UPROPERTY(meta = (Bindwidget))
	UImage* Image;

	UPROPERTY(meta = (Bindwidget))
	UEditableText* EditableText;

	UPROPERTY()
	FName ClothesID;

	UPROPERTY()
	ClothesType ClothType;

	UPROPERTY(meta = (Bindwidget))
	USizeBox* SizeBox;

	UPROPERTY()
	USkeletalMesh* SkeletalMesh;
};
