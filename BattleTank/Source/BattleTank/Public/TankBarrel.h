// Rodrigo Montes - DelMontes Software

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"

#include "TankBarrel.generated.h"


//Hold barrel's properties and Elevate Method.
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))   ///this puts the class into the custom cathegory within the blueprint and hides the Collision cathegory from the details view
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	

public:

	void ElevateBarrel(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxDegreesPerSecond = 10.0f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxElevationDegrees = 40.0f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinElevationDregrees = 0.0f;
};
