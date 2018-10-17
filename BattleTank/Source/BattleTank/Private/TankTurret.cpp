// Rodrigo Montes - Mounts Vineyard

#include "TankTurret.h"

void UTankTurret::RotateTurret(float RelativeSpeed)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("%f: Barrel->ElevateBarrel @ %f"), Time, RelativeSpeed);

	///FMath::Clamp<float> clamps (lock) a value with min and max values in <unit>:
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + RotationChange;
	//auto ClampedRotation = FMath::Clamp<float>(RawNewRotation, MinElevationDregrees, MaxElevationDegrees);

	///move the object (rotate), in this case, rotate the turret (yaw)
	SetRelativeRotation(FRotator(0, NewRotation, 0));
}

