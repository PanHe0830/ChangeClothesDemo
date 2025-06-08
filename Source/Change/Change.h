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

    // 唯一ID（DataTable Row 名称也会作为ID）
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FName ClothesID; // 这个时装的ID 

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    ClothesType Type; // 时装的部位类型

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText FName; // 时装的名字

    UPROPERTY(EditAnywhere , BlueprintReadWrite)
    TSoftObjectPtr<UTexture2D> MeshTexture;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSoftObjectPtr<USkeletalMesh> ClothesMesh; // 时装的骨骼网格体
};