// Fill out your copyright notice in the Description page of Project Settings.


#include "ClothesWidget.h"
#include "Change/Change.h"
#include "Change/HUD/ShowSlotWidget.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Change/SaveGame/ClotheSaveGame.h"
#include "Change/PlayerController/ChangePlayerController.h"
#include "Change/Character/ShowCharacter.h"

void UClothesWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (!ItemSlotWidgetClass) return;

	UDataTable* ClothesTable = LoadObject<UDataTable>(nullptr, TEXT("/Game/BluePrint/ClothesData.ClothesData"));
	if (ClothesTable)
	{
		const FString ContextString(TEXT("Clothes Table Context"));

		// 获取所有行
		TArray<FClothesRowData*> AllRows;
		ClothesTable->GetAllRows<FClothesRowData>(ContextString, AllRows);

		for (auto ite : AllRows)
		{
			if (ite->Type == ClothesType::CLO_BODY)
			{
				UShowSlotWidget* WidgetSlot = CreateWidget<UShowSlotWidget>(this, ItemSlotWidgetClass);
				if (WidgetSlot)
				{
					//NewSlot->SetSize(widghtdis, highdis);
					WidgetSlot->SetImage(ite->MeshTexture.LoadSynchronous());
					WidgetSlot->SetText(ite->FName);
					WidgetSlot->SetClotheID(ite->ClothesID);
					WidgetSlot->SetClotheSkeletalMesh(ite->ClothesMesh.LoadSynchronous());
					WidgetSlot->SetClotheType(ite->Type);
					WidgetSlot->SetSizeBoxScale(100,100);
					UUniformGridSlot* GridSlot = UniformGridPanel_Body->AddChildToUniformGrid(WidgetSlot, RowIndex, ColIndex);

					// 自动换行
					ColIndex++;
					if (ColIndex >= ColumnCount)
					{
						ColIndex = 0;
						RowIndex++;
					}
				}
			}
		}
	}
}

bool UClothesWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return true;
	}
	if (Button_Play)
	{
		Button_Play->OnClicked.AddDynamic(this,&UClothesWidget::PlayStart);
	}

	return false;
}

void UClothesWidget::PlayStart()
{
	UClotheSaveGame* SaveGameInstance = Cast<UClotheSaveGame>(UGameplayStatics::CreateSaveGameObject(UClotheSaveGame::StaticClass()));
	if (!SaveGameInstance) return;
	AChangePlayerController* ShowPlayerController = Cast<AChangePlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (ShowPlayerController)
	{
		AShowCharacter* ShowCharacter = Cast<AShowCharacter>(ShowPlayerController->GetCharacter());
		if (ShowCharacter)
		{
			SaveGameInstance->BodyMesh = ShowCharacter->GetBodySkeletalMeshComponent()->GetSkeletalMeshAsset();
			UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("CharacterSlot"), 0);

			UGameplayStatics::OpenLevel(GetWorld(), FName("ThirdPersonMap"));
		}
	}
}
