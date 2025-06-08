// Fill out your copyright notice in the Description page of Project Settings.


#include "ShowCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"

// Sets default values
AShowCharacter::AShowCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	ShowSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	ShowSpringArm->SetupAttachment(RootComponent);
	ShowSpringArm->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	ShowSpringArm->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	ShowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	ShowCamera->SetupAttachment(ShowSpringArm, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	ShowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	HeadMesh = CreateDefaultSubobject<USkeletalMeshComponent>("HeadMesh");
	HeadMesh->SetupAttachment(GetMesh());

	ArmLeftMesh = CreateDefaultSubobject<USkeletalMeshComponent>("ArmLeftMesh");
	ArmLeftMesh->SetupAttachment(GetMesh());

	ArmRightMesh = CreateDefaultSubobject<USkeletalMeshComponent>("ArmRightMesh");
	ArmRightMesh->SetupAttachment(GetMesh());

	LegMesh = CreateDefaultSubobject<USkeletalMeshComponent>("LegMesh");
	LegMesh->SetupAttachment(GetMesh());

	BodyMesh = CreateDefaultSubobject<USkeletalMeshComponent>("BodyMesh");
	BodyMesh->SetupAttachment(GetMesh());

	HeadMesh->SetAnimInstanceClass(GetMesh()->AnimClass);
	ArmLeftMesh->SetAnimInstanceClass(GetMesh()->AnimClass);
	ArmRightMesh->SetAnimInstanceClass(GetMesh()->AnimClass);
	LegMesh->SetAnimInstanceClass(GetMesh()->AnimClass);
	BodyMesh->SetAnimInstanceClass(GetMesh()->AnimClass);
}

// Called when the game starts or when spawned
void AShowCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShowCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShowCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
			UE_LOG(LogTemp, Warning, TEXT("bind input success"));
		}
	}

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) 
	{
		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AShowCharacter::Look);

		UE_LOG(LogTemp, Warning, TEXT("bind look success"));
	}
}

void AShowCharacter::SetBodyMesh(USkeletalMesh* NewBodyMesh)
{
	BodyMesh->SetSkeletalMesh(NewBodyMesh);
}

void AShowCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	UE_LOG(LogTemp, Warning, TEXT("Look success"));
	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
		UE_LOG(LogTemp, Warning, TEXT("success value"));
	}
}
