// Rodrigo Montes - DelMontes Software

#pragma once

//#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "GameFramework/Actor.h"

/// siempre el ultimo include!!
#include "TankAIController.generated.h"

//Forward Declarations!
//class ATank;
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()


private:
	virtual void BeginPlay() override;

	UTankAimingComponent* AimingComponent = nullptr;
	

public:
	// virtual significa que puede ser ampliado por sus herederos
	// override significa que amplia la definicion de sus ancestros
	/// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:
	UPROPERTY(EditAnywhere, Category = "Setup")
		float AcceptanceRadius = 8000.0f;
};
