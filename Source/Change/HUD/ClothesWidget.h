// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ClothesWidget.generated.h"

class UUniformGridPanel;
class UShowSlotWidget;
class UButton;

/**
 * 
 */
UCLASS()
class CHANGE_API UClothesWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;

	virtual bool Initialize() override;

protected:
	UFUNCTION()
	void PlayStart();
	
private:
	UPROPERTY(meta = (BindWidget))
	UUniformGridPanel* UniformGridPanel_Body;

	UPROPERTY(EditDefaultsOnly, Category = "Backpack")
	TSubclassOf<UShowSlotWidget> ItemSlotWidgetClass;

	UPROPERTY(EditAnywhere, Category = "Backpack")
	int32 ColumnCount = 4;

	UPROPERTY(EditAnywhere, Category = "Backpack")
	int32 RowIndex = 0;

	UPROPERTY(EditAnywhere, Category = "Backpack")
	int32 ColIndex = 0;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_Play;

};
