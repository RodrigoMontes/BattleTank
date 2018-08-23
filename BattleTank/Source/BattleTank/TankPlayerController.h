// Rodrigo Montes - Mounts Vineyard

#pragma once

#define OUT

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

/// Ultimo include:
#include "TankPlayerController.generated.h"


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
	bool GetSightRayHitLocation(OUT FVector& OutHitLocation) const;

	UPROPERTY(EditAnywhere, Meta = (CrosshairX))
		float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere, Meta = (CrosshairY))
		float CrossHairYLocation = 0.33333f;
	   
protected:
	// virtual significa que puede ser ampliado por sus herederos
	// override significa que amplia la definicion de sus ancestros
	virtual void BeginPlay() override;		

};
