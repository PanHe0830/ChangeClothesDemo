// Copyright Epic Games, Inc. All Rights Reserved.

#include "ChangeGameMode.h"
#include "ChangeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AChangeGameMode::AChangeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
