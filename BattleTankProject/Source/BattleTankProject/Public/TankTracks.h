#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTracks.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKPROJECT_API UTankTracks : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);


private:
	UTankTracks();
	virtual void BeginPlay() override;

	void ApplySidewaysForce();

	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 40000000.f;

	UFUNCTION()
	void OnHit(UPrimitiveComponent * HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void DriveTrack();

	float CurrentThrottle = 0;
};