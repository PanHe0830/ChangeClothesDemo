// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Change.generated.h"

UENUM(BlueprintType)
enum class ClothesType: uint8
{
    CLO_HEAD UMETA(DisplayName = "Head"),
    CLO_BODY UMETA(DisplayName = "Body"),
    CLO_ARM UMETA(DisplayName = "ARM"),
    CLO_REG UMETA(DisplayName = "Reg"),

    CLO_MAX UMETA(DisplayName = "Max")
};

USTRUCT(BlueprintType)
struct FClothesRowData : public FTableRowBase
{
    GENERATED_BODY()

    // ΨһID��DataTable Row ����Ҳ����ΪID��
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FName ClothesID; // ���ʱװ��ID 

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    ClothesType Type; // ʱװ�Ĳ�λ����

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText FName; // ʱװ������

    UPROPERTY(EditAnywhere , BlueprintReadWrite)
    TSoftObjectPtr<UTexture2D> MeshTexture;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSoftObjectPtr<USkeletalMesh> ClothesMesh; // ʱװ�Ĺ���������
};