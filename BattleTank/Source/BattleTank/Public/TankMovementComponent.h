// Rodrigo Montes - DelMontes Software

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

// Fly by Wire movement control component
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendMoveForward(float Throw);
	UFUNCTION(BlueprintCallable, Category = "Input")
		void IntendTurnRight(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void InitializeTracks(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet);

private:

	/** path finding: request new velocity */
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
};
