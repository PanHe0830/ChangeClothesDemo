// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "ClotheSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class CHANGE_API UClotheSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	FString SaveSlotName = TEXT("CharacterEquip");

	UPROPERTY()
	USkeletalMesh* BodyMesh;

	UPROPERTY()
	USkeletalMesh* LegMesh;

	UPROPERTY()
	USkeletalMesh* HeadMesh;

	UPROPERTY()
	USkeletalMesh* ArmLeftMesh;

	UPROPERTY()
	USkeletalMesh* ArmRightMesh;
};
