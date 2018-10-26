// Rodrigo Montes - Mounts Vineyard

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"

#include "TankAimingComponent.generated.h"

#define OUT

//Forward Declarations!
class UTankBarrel;
class UTankTurret;

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
	void SetTurretReference(UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed) const;

private:
	UPROPERTY(EditDefaultsOnly)
		UTankBarrel* TankBarrel = nullptr;

	UPROPERTY(EditDefaultsOnly)
		UTankTurret* TankTurret = nullptr;

	void MoveBarrelTowards(FVector AimDirection) const;
	void MoveTurretTowards(FVector AimDirection) const;
};
