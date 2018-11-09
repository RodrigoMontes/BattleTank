// Rodrigo Montes - Mounts Vineyard

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::InitializeTracks(UTankTrack * LeftTrackToSet, UTankTrack * RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;

}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	//UE_LOG(LogTemp, Warning, TEXT("Intend to Move forward throw: %f"), Throw);

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

	//TODO Clamp Speed so it doesn't add different input methods!
}
