#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8 { RELOADING, AIMING, LOCKED, OUTOFAMMO};

class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKPROJECT_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	UFUNCTION(BlueprintCallable, Category = "Firing")
	int32 GetRoundsLeft() const;
	
	void AimAt(FVector);
	EFiringState GetFiringState() const;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::AIMING;

private:
	UTankAimingComponent();
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3.f;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	int32 RoundsLeft = 20;

	double LastFireTime = 0;

	FVector AimDirection = FVector(0);

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
	
	void MoveBarrelTowards();
	bool IsBarrelMoving();
};
