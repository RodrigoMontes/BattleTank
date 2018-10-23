// Rodrigo Montes - Mounts Vineyard

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
//#include "TankAimingComponent.h"

#include "Tank.generated.h"

//Forward Declarations!
class UTankAimingComponent;
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UTankAimingComponent* TankAimingComponent = nullptr;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Sets default values for this pawn's properties
	ATank();
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = CustomActions)
		void Fire() const;

private:
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 4000.0f;

	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;
		//UClass* ProjectileBlueprint;		//https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/TSubclassOf

	//local barrel for spawninig projectile
	UTankBarrel* Barrel = nullptr;
};
