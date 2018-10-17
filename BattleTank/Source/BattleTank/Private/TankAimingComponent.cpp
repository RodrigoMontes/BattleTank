// Rodrigo Montes - Mounts Vineyard

#include "TankAimingComponent.h"
#include "TankBarrel.h"				//se debe incluir cuando se hace forward declaration si se usan funciones del .cpp
#include "TankTurret.h"				//se debe incluir cuando se hace forward declaration si se usan funciones del .cpp


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) const
{

	if (!TankBarrel || !TankTurret) { return; }

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
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();

		auto OurTankName = GetOwner()->GetName();
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: %s aiming at %s"), Time, *OurTankName, *AimDirection.ToString());

		MoveBarrelTowards(AimDirection);
		MoveTurretTowards(AimDirection);
	}
	else
	{
		auto OurTankName = GetOwner()->GetName();
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: %s has no solution!"), Time, *OurTankName);
	}
	
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	TankBarrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret * TurretToSet)
{
	TankTurret = TurretToSet;
}


void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) const
{
	auto BarrelRotation = TankBarrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotation = AimAsRotator - BarrelRotation;

	//UE_LOG(LogTemp, Warning, TEXT("AimAsRotator %s"), *AimAsRotator.ToString());

	TankBarrel->ElevateBarrel(DeltaRotation.Pitch);

}

void UTankAimingComponent::MoveTurretTowards(FVector AimDirection) const
{
	auto TurretRotation = TankTurret->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotation = AimAsRotator - TurretRotation;

	//UE_LOG(LogTemp, Warning, TEXT("AimAsRotator %s"), *AimAsRotator.ToString());

	TankTurret->RotateTurret(DeltaRotation.Yaw);
}
