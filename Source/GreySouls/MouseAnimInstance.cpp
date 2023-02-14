// Fill out your copyright notice in the Description page of Project Settings.


#include "MouseAnimInstance.h"

float UMouseAnimInstance::GetPawnCurrentSpeed()
{
	const APawn* Pawn = TryGetPawnOwner();
	if(Pawn)
	{
		const FVector Velocity = Pawn->GetVelocity();
		return Velocity.Size();
	}
	
	return 0.f;
}

FVector UMouseAnimInstance::GetPawnCurrentDirection() const
{
	
}
