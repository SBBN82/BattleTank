#include "TankAimingComponent.h"
#include "..\Public\TankAIController.h"

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
	AimingComponent->Fire(); //TODO Limit firing rate
}