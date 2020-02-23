// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TPPlayerController.generated.h"

class ATPCar;
class ATPCharacter;

UCLASS(config=Game)
class ATPPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATPPlayerController();

private:

	virtual void SetupInputComponent() override;
	virtual void OnPossess(APawn* InPawn) override;

	void Jump();
	void StopJumping();

	void MoveForward(float Value);
	void MoveRight(float Value);

	void AddControllerYawInput(float Value);
	void TurnAtRate(float Value);

	void AddControllerPitchInput(float Value);
	void LookUpAtRate(float Value);

private :
	UPROPERTY()
	ATPCar* Car;

	UPROPERTY()
	ATPCharacter* TPCharacter;
};

