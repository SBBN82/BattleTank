// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANKPROJECT_API ATank : public APawn
{
	GENERATED_BODY()

private:
	ATank();

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000.f;

protected:
	virtual void BeginPlay() override;
	UTankAimingComponent* TankAimingComponent = nullptr;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void AimAt(FVector);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);
};
