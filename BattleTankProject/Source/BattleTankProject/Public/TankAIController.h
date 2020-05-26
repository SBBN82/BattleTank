// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "..\Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKPROJECT_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	ATank* GetControlledTank() const;
	
private:
	ATank* ControlledTank = nullptr;
};
