// Rodrigo Montes - Mounts Vineyard

#include "TankAIController.h"



void ATankAIController::BeginPlay()
{
	/// hereda el Begin Play de sus ancestros antes de ampliarlo
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto PlayerControlledTank = GetPlayerControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController not possessing any tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController possessing %s"), *ControlledTank->GetName());
	}

	if (!PlayerControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController did not find Player Controlled Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found Player Controlled Tank at %s"), *PlayerControlledTank->GetName());

	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


ATank* ATankAIController::GetPlayerControlledTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn)
	{
		return nullptr;
	}
	else
	{
		return Cast<ATank>(PlayerPawn);
	}
}