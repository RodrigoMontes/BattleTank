// Rodrigo Montes - Mounts Vineyard

#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto ControlledTank = Cast<ATank>(GetPawn());
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController not possessing any tank"));
		return;
	}

	auto PlayerControlledTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!PlayerControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController did not find Player Controlled Tank"));
		return;
	}

	ControlledTank->AimAt(PlayerControlledTank->GetActorLocation());
	ControlledTank->Fire();		//TODO Cambiar el fire rate!
}