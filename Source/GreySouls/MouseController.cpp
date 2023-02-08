// Fill out your copyright notice in the Description page of Project Settings.


#include "MouseController.h"
#include "GameFramework/Character.h"

void AMouseController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (InputComponent)
	{
		InputComponent->BindAxis("MoveForward", this, &AMouseController::MoveForward);
		InputComponent->BindAxis("MoveRight", this, &AMouseController::MoveRight);

		InputComponent->BindAction("Crouch", IE_Pressed, this, &AMouseController::BeginCrouch);
		InputComponent->BindAction("Crouch", IE_Released, this, &AMouseController::EndCrouch);
	}
}

void AMouseController::MoveForward(float Value)
{
	APawn* ControlledPawn = GetPawn();
	if (!ControlledPawn) return;

	FVector Forward = ControlledPawn->GetActorForwardVector();
	ControlledPawn->AddMovementInput(Forward, Value);
}

void AMouseController::MoveRight(float Value)
{
	APawn* ControlledPawn = GetPawn();
	if (!ControlledPawn) return;

	FVector Right = ControlledPawn->GetActorRightVector();
	ControlledPawn->AddMovementInput(Right, Value);
}

void AMouseController::BeginCrouch()
{
	APawn* ControlledPawn = GetPawn();
	if (!ControlledPawn) return;

	ACharacter* MouseCharacter = Cast<ACharacter>(ControlledPawn);
	if (!MouseCharacter) return;

	MouseCharacter->Crouch();
}

void AMouseController::EndCrouch()
{
	APawn* ControlledPawn = GetPawn();
	if (!ControlledPawn) return;

	ACharacter* MouseCharacter = Cast<ACharacter>(ControlledPawn);
	if (!MouseCharacter) return;

	MouseCharacter->UnCrouch();
}


