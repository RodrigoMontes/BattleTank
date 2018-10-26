// Rodrigo Montes - Mounts Vineyard

#pragma once

#define OUT

//#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

/// Ultimo include:
#include "TankPlayerController.generated.h"

//Forward Declarations!
class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	ATank* GetControlledTank() const;
	void AimAtCrosshair();
	bool GetSightRayHitLocation(OUT FVector& HitLocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, OUT FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, OUT FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly, Meta = (CrosshairX))
		float CrossHairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly, Meta = (CrosshairY))
		float CrossHairYLocation = 0.33333f;

	UPROPERTY(EditDefaultsOnly, Meta = (HitRange))
		float LineTraceRange = 1000000.0f;
	   
protected:
	// virtual significa que puede ser ampliado por sus herederos
	// override significa que amplia la definicion de sus ancestros
	virtual void BeginPlay() override;		
};
