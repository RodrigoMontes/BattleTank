// Rodrigo Montes - DelMontes Software


#include "TankPlayerController.h"
#include "TankAimingComponent.h"
//#include "Tank.h"

void ATankPlayerController::BeginPlay()
{
	/// hereda el Begin Play de sus ancestros antes de ampliarlo
	Super::BeginPlay();

	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

	AimingComponentFound(AimingComponent);

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimAtCrosshair();
}

//ATank* ATankPlayerController::GetControlledTank() const
//{
//	return GetPawn();
//}

void ATankPlayerController::AimAtCrosshair()
{
	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) {	return; }

	FVector HitLocation;

	bool bGotHitLocation = GetSightRayHitLocation(OUT HitLocation);
	if (bGotHitLocation)
	{
		AimingComponent->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(OUT FVector& HitLocation) const
{
	//find cross hair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(OUT ViewportSizeX, OUT ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, OUT LookDirection))
	{
		return GetLookVectorHitLocation(LookDirection, OUT HitLocation);
	}

	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, OUT FVector & LookDirection) const
{
	FVector CameraWorldLocation; //not used but needed
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		OUT CameraWorldLocation, 
		OUT LookDirection);

}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, OUT FVector & HitLocation) const
{
	FHitResult HitResult;
	auto LineStart = PlayerCameraManager->GetCameraLocation();
	auto LineEnd = LineStart + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
			OUT HitResult,
			LineStart,
			LineEnd,
			ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation = HitResult.Location;
		return true;
	}
	
	return false;
}
