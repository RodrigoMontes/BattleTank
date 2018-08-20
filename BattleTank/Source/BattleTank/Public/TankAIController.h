// Rodrigo Montes - Mounts Vineyard

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"

/// siempre el ultimo include!!
#include "TankAIController.generated.h"


UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;

protected:
	// virtual significa que puede ser ampliado por sus herederos
	// override significa que amplia la definicion de sus ancestros
	virtual void BeginPlay() override;	
};
