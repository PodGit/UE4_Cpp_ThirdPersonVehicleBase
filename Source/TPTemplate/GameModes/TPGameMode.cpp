// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TPGameMode.h"
#include "TPTemplate/Car/TPCar.h"
#include "TPTemplate/Controllers/TPPlayerController.h"
#include "TPTemplate/UI/TPHud.h"

ATPGameMode::ATPGameMode()
{
	//DefaultPawnClass = ATPCar::StaticClass();
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/TPCharacterBP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	HUDClass = ATPHud::StaticClass();
	PlayerControllerClass = ATPPlayerController::StaticClass();
}
