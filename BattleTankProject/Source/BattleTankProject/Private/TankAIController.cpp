// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "..\Public\TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller posesses no tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller posesses the tank: %s"), *(ControlledTank->GetName()));
	}

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI hasn't found player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI attacking: %s"), *(PlayerTank->GetName()));
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
