#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

UCLASS()
class BATTLETANKPROJECT_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 8000.f;


private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnTankDeath();
};
