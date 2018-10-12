// Rodrigo Montes - Mounts Vineyard

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"

#include "TankAimingComponent.generated.h"

#define OUT

//Forward Declarations!
class UTankBarrel;

//Tank aiming.
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

protected:


public:
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed) const;

private:
	UPROPERTY(EditAnywhere)
		UTankBarrel* TankBarrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection) const;
};
