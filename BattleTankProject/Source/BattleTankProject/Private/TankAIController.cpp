#include "TankAimingComponent.h"
#include "..\Public\TankAIController.h"
#include "..\Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto  PlayerTank= GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	
	if (!ensure(PlayerTank && AimingComponent)) { return; }
	
	MoveToActor(PlayerTank, AcceptanceRadius);
	
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	if (AimingComponent->GetFiringState() == EFiringState::LOCKED)
	{
		AimingComponent->Fire(); //TODO Limit firing rate
	}
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnTankDeath);
	}
}

void ATankAIController::OnTankDeath()
{
	if (!ensure(GetPawn())) { return; }
	GetPawn()->DetachFromControllerPendingDestroy();
}
