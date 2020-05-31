#include "TankBarrel.h"
#include "Projectile.h"
#include "Tank.h"

ATank::ATank()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::Fire()
{
	if (!ensure(Barrel)) { return; }
	bool bIsReloaded = (FPlatformTime::Seconds() - LastFireTime) >= ReloadTimeInSeconds;

	if (bIsReloaded)
	{
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("FirePoint")), Barrel->GetSocketRotation(FName("FirePoint")));
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}