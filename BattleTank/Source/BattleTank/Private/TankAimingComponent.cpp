// Rodrigo Montes - Mounts Vineyard

#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

}


void UTankAimingComponent::AimAt(FVector HitLocation) const
{
	auto OurTankName = GetOwner()->GetName();
	auto BarrelLocation = TankBarrel->GetComponentLocation();

	UE_LOG(LogTemp, Warning, TEXT("%s aiming from %s to %s "), *OurTankName, *BarrelLocation.ToString(), *HitLocation.ToString());
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	TankBarrel = BarrelToSet;
}

