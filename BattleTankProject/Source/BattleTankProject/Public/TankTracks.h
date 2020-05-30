#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTracks.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKPROJECT_API UTankTracks : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

private:
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 40000000.f;
};
