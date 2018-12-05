// Rodrigo Montes - DelMontes Software

#include "TankAimingComponent.h"
#include "TankBarrel.h"				//se debe incluir cuando se hace forward declaration si se usan metodos de la clase
#include "TankTurret.h"				//se debe incluir cuando se hace forward declaration si se usan metodos de la clase
#include "Projectile.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::BeginPlay()
{
	LastFireTime = GetWorld()->GetTimeSeconds();
}

void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	if ((GetWorld()->GetTimeSeconds() - LastFireTime) < ReloadTimeSeconds) 
	{
		FiringState = EFiringState::Reloading;
	}
	else if (IsBarrelMoving())
	{
		FiringState = EFiringState::Aiming;
	}
	else
	{
		FiringState = EFiringState::Locked;
	}
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{

	if (!ensure(TankBarrel && TankTurret)) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = TankBarrel->GetSocketLocation(FName("Projectile"));

	//calculate OutLaunchVelocity
	bool bHaveAimSolution =
		UGameplayStatics::SuggestProjectileVelocity(
			this,
			OUT OutLaunchVelocity,
			StartLocation,
			HitLocation,
			LaunchSpeed,
			false,
			0.0f,
			0.0f,
			ESuggestProjVelocityTraceOption::DoNotTrace);

	if (bHaveAimSolution)
	{
		AimDirection = OutLaunchVelocity.GetSafeNormal();

		MoveBarrelTowards(AimDirection);
		MoveTurretTowards(AimDirection);
	}
}

void UTankAimingComponent::Fire()
{
	if (!ensure(TankBarrel && ProjectileBlueprint)) { return; }

	bool isReloaded = (GetWorld()->GetTimeSeconds() - LastFireTime) > ReloadTimeSeconds;
	if (isReloaded)
	{
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			TankBarrel->GetSocketLocation(FName("Projectile")),
			TankBarrel->GetSocketRotation(FName("Projectile"))
			);

		if (!ensure(Projectile)) { return; }
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = GetWorld()->GetTimeSeconds();
	}
}

void UTankAimingComponent::InitializeAiming(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet)
{
	TankBarrel = BarrelToSet;
	TankTurret = TurretToSet;
}

bool UTankAimingComponent::IsBarrelMoving()
{
	if (!ensure(TankBarrel)) { return false; }
	auto BarrelForward = TankBarrel->GetForwardVector();

	return !BarrelForward.Equals(AimDirection, 0.01);
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) const
{
	if (!ensure(TankBarrel)) { return; }

	auto BarrelRotation = TankBarrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotation = AimAsRotator - BarrelRotation;

	TankBarrel->ElevateBarrel(DeltaRotation.Pitch);
}

void UTankAimingComponent::MoveTurretTowards(FVector AimDirection) const
{
	if (!ensure(TankTurret)) { return; }

	auto TurretRotation = TankTurret->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotation = AimAsRotator - TurretRotation;

	TankTurret->RotateTurret(DeltaRotation.Yaw);
}
