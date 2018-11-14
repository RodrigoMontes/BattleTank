// Rodrigo Montes - DelMontes Software

#include "TankBarrel.h"


void UTankBarrel::ElevateBarrel(float RelativeSpeed)
{
	///FMath::Clamp<float> clamps (lock) a value with min and max values in <unit>:
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto ClampedElevation = FMath::Clamp<float>(RawNewElevation, MinElevationDregrees, MaxElevationDegrees);

	///move the object (rotate), in this case, elevate or lower the barrel (pitch)
	SetRelativeRotation(FRotator(ClampedElevation, 0, 0));
}
