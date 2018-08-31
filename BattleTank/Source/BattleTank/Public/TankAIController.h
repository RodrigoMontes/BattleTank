// Rodrigo Montes - Mounts Vineyard

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "GameFramework/Actor.h"

/// siempre el ultimo include!!
#include "TankAIController.generated.h"


UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	void AimAtPlayer();
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;
	ATank* GetPlayerControlledTank() const;

protected:
	// virtual significa que puede ser ampliado por sus herederos
	// override significa que amplia la definicion de sus ancestros
	virtual void BeginPlay() override;	
};
