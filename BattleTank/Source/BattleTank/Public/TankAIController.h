// Rodrigo Montes - DelMontes Software

#pragma once

//#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "GameFramework/Actor.h"

/// siempre el ultimo include!!
#include "TankAIController.generated.h"

//Forward Declarations!
class ATank;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	virtual void BeginPlay() override;
	
public:
	// virtual significa que puede ser ampliado por sus herederos
	// override significa que amplia la definicion de sus ancestros
	/// Called every frame
	virtual void Tick(float DeltaTime) override;

	float AcceptanceRadius = 3000.0f;

//protected:

};
