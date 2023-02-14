// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MouseController.generated.h"


UCLASS()
class GREYSOULS_API AMouseController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetupInputComponent() override;

private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void BeginCrouch();
	void EndCrouch();
	void LookUp(float Value);
	void Turn(float Value);

private:
	UPROPERTY(EditAnywhere)
	float TurnRate;

	UPROPERTY(EditAnywhere)
	float LookUpRate;
};