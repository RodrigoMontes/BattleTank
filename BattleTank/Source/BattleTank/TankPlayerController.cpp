// Rodrigo Montes - Mounts Vineyard

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	/// hereda el Begin Play de sus ancestros antes de ampliarlo
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController not possessing any tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController possessing %s"), *ControlledTank->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimAtCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimAtCrosshair()
{
	if (!GetControlledTank()) {	return; }

	FVector HitLocation;

	if (GetSightRayHitLocation(OUT HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("Aiming at %s"), *HitLocation.ToString());
		//TODO implement turret movement for aim
	}

}

bool ATankPlayerController::GetSightRayHitLocation(OUT FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);  //TODO remove!

	//find crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(OUT ViewportSizeX, OUT ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	//"de-project" the screen position into world position

	//cast a ray from crosshair position in de-projection direction
		//if hit something
			//return true and HitLocation equal to raycast hit location
		//else return false
	return true;
}
