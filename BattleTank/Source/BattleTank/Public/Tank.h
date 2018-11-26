// Rodrigo Montes - DelMontes Software

#pragma once

//#include "CoreMinimal.h"
//#include "GameFramework/Pawn.h"
//#include "Engine/World.h"
//#include "TankAimingComponent.h"

#include "Tank.generated.h"

//Forward Declarations!
//class UTankAimingComponent;
//class UTankBarrel;
//class UTankTurret;
//class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()


protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

	//UPROPERTY(BlueprintReadOnly)
	//	UTankAimingComponent* TankAimingComponent = nullptr;


public:	
	// Sets default values for this pawn's properties
	ATank();
	//void AimAt(FVector HitLocation);

	//UFUNCTION(BlueprintCallable)
	//	void Fire();


private:
	//UPROPERTY(EditDefaultsOnly, Category = "Firing")
	//	float ReloadTimeSeconds = 3.0f;

	//UPROPERTY(EditDefaultsOnly, Category = "Setup")
	//	TSubclassOf<AProjectile> ProjectileBlueprint;
	//	//UClass* ProjectileBlueprint;		//https://docs.unrealengine.com/latest/INT/Programming/UnrealArchitecture/TSubclassOf

	////local barrel for spawninig projectile
	//UTankBarrel* TankBarrel = nullptr;		//TODO Remove from here!
	//
	////counter for reload time
	//double LastFireTime = 0;

	//UPROPERTY(EditDefaultsOnly, Category = "Firing")
	//	float LaunchSpeed = 4000.0f;
};
