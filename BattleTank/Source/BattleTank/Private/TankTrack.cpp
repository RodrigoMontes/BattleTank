// Rodrigo Montes - DelMontes Software

#include "TankTrack.h"




void UTankTrack::SetThrottle(float Throttle)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	//auto Name = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("%s: Throttle at %f"), *Name, Throttle);


	//TODO: clamp throttle value between 0 and 1

	auto ForceApplied = GetForwardVector() * Throttle * TankMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
