#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKPROJECT_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTankAimingComponent();
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

public:	
	void AimAt(FVector, float);

private:
	UStaticMeshComponent* Barrel = nullptr;
	void MoveBarrelTowards(FVector);
};
