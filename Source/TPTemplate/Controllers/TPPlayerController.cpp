// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TPPlayerController.h"
#include "TPTemplate/Characters/TPCharacter.h"
#include "TPTemplate/Car/TPCar.h"

//////////////////////////////////////////////////////////////////////////
// ATPPlayerController

ATPPlayerController::ATPPlayerController()
	: Car(nullptr)
	, TPCharacter(nullptr)
{
}

void ATPPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Jump", IE_Pressed,	this, &ATPPlayerController::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ATPPlayerController::StopJumping);

	InputComponent->BindAxis("MoveForward", this, &ATPPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight",	this, &ATPPlayerController::MoveRight);

	InputComponent->BindAxis("LookRight",		this, &ATPPlayerController::AddControllerYawInput);
	InputComponent->BindAxis("LookRightRate",	this, &ATPPlayerController::TurnAtRate);
	InputComponent->BindAxis("LookUp",			this, &ATPPlayerController::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate",		this, &ATPPlayerController::LookUpAtRate);
}

void ATPPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (GetCharacter())
	{
		TPCharacter = Cast<ATPCharacter>(GetCharacter());
	}
}

void ATPPlayerController::Jump()
{
	if (GetCharacter())
	{
		GetCharacter()->Jump();
	}
}

void ATPPlayerController::StopJumping()
{
	if (GetCharacter())
	{
		GetCharacter()->StopJumping();
	}
}

void ATPPlayerController::MoveForward(float Value)
{
	if (TPCharacter)
	{
		TPCharacter->MoveForward(Value);
	}
}

void ATPPlayerController::MoveRight(float Value)
{
	if (TPCharacter)
	{
		TPCharacter->MoveRight(Value);
	}
}

void ATPPlayerController::AddControllerYawInput(float Value)
{
	if (GetPawn())
	{
		GetCharacter()->AddControllerYawInput(Value);
	}
}

void ATPPlayerController::TurnAtRate(float Value)
{
	if (TPCharacter)
	{
		TPCharacter->TurnAtRate(Value);
	}
}

void ATPPlayerController::AddControllerPitchInput(float Value)
{
	if (GetPawn())
	{
		GetPawn()->AddControllerPitchInput(Value);
	}
}

void ATPPlayerController::LookUpAtRate(float Value)
{
	if (TPCharacter)
	{
		TPCharacter->LookUpAtRate(Value);
	}
}