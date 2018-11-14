// Rodrigo Montes - DelMontes Software

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::InitializeTracks(UTankTrack * LeftTrackToSet, UTankTrack * RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}


//controls forward and backwards (-1 throw) movement
void UTankMovementComponent::IntendMoveForward(float Throw)
{
	//UE_LOG(LogTemp, Warning, TEXT("Intend to Move forward throw: %f"), Throw);
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	//TODO Clamp Speed so it doesn't add different input methods!
}

//controls right and left (-1 throw) turning
void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
	//TODO Clamp Speed so it doesn't add different input methods!
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForwardDirection = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntent = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankForwardDirection, AIForwardIntent);
	IntendMoveForward(ForwardThrow);

	auto RightThrow = FVector::CrossProduct(TankForwardDirection, AIForwardIntent).Z;
	IntendTurnRight(RightThrow);
}

