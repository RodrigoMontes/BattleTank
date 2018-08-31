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
		//UE_LOG(LogTemp, Warning, TEXT("TankPlayerController possessing %s"), *ControlledTank->GetName());
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
		GetControlledTank()->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(OUT FVector& HitLocation) const
{
	//find crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(OUT ViewportSizeX, OUT ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, OUT LookDirection))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Looking at %s"), *LookDirection.ToString());
		GetLookVectorHitLocation(LookDirection, OUT HitLocation);
	}

	return true;
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
	//GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
	//	OUT PlayerViewPortLocation,
	//	OUT PlayerViewPortRotation);

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
