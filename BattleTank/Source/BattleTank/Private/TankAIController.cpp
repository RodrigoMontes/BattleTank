// Rodrigo Montes - DelMontes Software

#include "TankAIController.h"
#include "TankAimingComponent.h"
//#include "Tank.h"
// Depends on movement component via pathfinding system (MoveToActor)


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerControlledTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!ensure(PlayerControlledTank)) { return; }
	MoveToActor(PlayerControlledTank, AcceptanceRadius);

	AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	AimingComponent->AimAt(PlayerControlledTank->GetActorLocation());
	AimingComponent->Fire();
}