// Rodrigo Montes - DelMontes Software

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"

#include "TankAimingComponent.generated.h"

#define OUT

// Enum for aiming states
UENUM()
enum class EFiringState : uint8 
{
	Reloading,
	Aiming,
	Locked
};

//Forward Declarations!
class UTankBarrel;
class UTankTurret;
class AProjectile;

//Tank aiming.
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringState FiringState = EFiringState::Aiming;


public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void InitializeAiming(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable)
		void Fire();

	void AimAt(FVector HitLocation) const;


private:
	// Sets default values for this component's properties
	UTankAimingComponent();

	UTankBarrel* TankBarrel = nullptr;
	UTankTurret* TankTurret = nullptr;

	void MoveBarrelTowards(FVector AimDirection) const;
	void MoveTurretTowards(FVector AimDirection) const;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeSeconds = 3.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;
	//UClass* ProjectileBlueprint;		//https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/TSubclassOf

	//counter for reload time
	double LastFireTime = 0;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 4000.0f;
};
