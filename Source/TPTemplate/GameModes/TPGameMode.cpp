// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TPGameMode.h"
#include "../Car/TPCar.h"
#include "../UI/TPHud.h"

ATPGameMode::ATPGameMode()
{
	//DefaultPawnClass = ATPCar::StaticClass();
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/TPCharacterBP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	HUDClass = ATPHud::StaticClass();
}
