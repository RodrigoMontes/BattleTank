// Rodrigo Montes - DelMontes Software

#include "Tank.h"
//#include "TankAimingComponent.h"
//#include "TankBarrel.h"
//#include "Projectile.h"


/// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	/// Make the component class a default on the main blueprint
	//TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	//TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement Component"));

	//auto TankName = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("%s ASDF: Tank C++ Construct"), *TankName);
}

/// Called when the game starts or when spawned
//void ATank::BeginPlay()
//{
//	Super::BeginPlay();
//	
//	//TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
//
//	//auto TankName = GetName();
//	//UE_LOG(LogTemp, Warning, TEXT("%s ASDF: Tank C++ Begin Play"), *TankName);
//}

//void ATank::AimAt(FVector HitLocation)
//{
//	if (!ensure(TankAimingComponent)) { return; }
//	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
//}

//void ATank::Fire()
//{
//	if (!ensure(TankBarrel)) { return; }
//
//	bool isReloaded = (GetWorld()->GetTimeSeconds() - LastFireTime) > ReloadTimeSeconds;
//	if (isReloaded)
//	{
//		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
//			ProjectileBlueprint,
//			TankBarrel->GetSocketLocation(FName("Projectile")),
//			TankBarrel->GetSocketRotation(FName("Projectile"))
//			);
//
//		if (!ensure(Projectile)) { return; }
//		Projectile->LaunchProjectile(LaunchSpeed);
//		LastFireTime = GetWorld()->GetTimeSeconds();
//	}
//}