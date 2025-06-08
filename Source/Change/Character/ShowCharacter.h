// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShowCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class CHANGE_API AShowCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShowCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Look(const FInputActionValue& Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SetBodyMesh(USkeletalMesh* NewBodyMesh);

private:
	UPROPERTY(EditAnywhere, Category = "Show")
	UCameraComponent* ShowCamera;

	UPROPERTY(EditAnywhere, Category = "Show")
	USpringArmComponent* ShowSpringArm;

	UPROPERTY(EditAnywhere, Category = "Clothes")
	USkeletalMeshComponent* HeadMesh;

	UPROPERTY(EditAnywhere, Category = "Clothes")
	USkeletalMeshComponent* ArmLeftMesh;

	UPROPERTY(EditAnywhere, Category = "Clothes")
	USkeletalMeshComponent* ArmRightMesh;

	UPROPERTY(EditAnywhere, Category = "Clothes")
	USkeletalMeshComponent* LegMesh;

	UPROPERTY(EditAnywhere, Category = "Clothes")
	USkeletalMeshComponent* BodyMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* PutBigOrSmallAction;


public:
	FORCEINLINE USkeletalMeshComponent* GetBodySkeletalMeshComponent() { return BodyMesh; };
};
