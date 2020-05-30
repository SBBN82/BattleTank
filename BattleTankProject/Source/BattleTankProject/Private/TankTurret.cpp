#include "Components/SceneComponent.h"
#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto TurretRotation = GetComponentRotation();
	auto Rotation = TurretRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, Rotation, 0));
}