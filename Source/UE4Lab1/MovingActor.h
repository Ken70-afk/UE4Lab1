#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "MovingActor.generated.h"

/**
 * AMovingActor moves between two specified points in the level.
 */
UCLASS()
class UE4LAB1_API AMovingActor : public ABaseActor
{
	GENERATED_BODY()

public:
	// Constructor
	AMovingActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** First point to move between */
	UPROPERTY(EditInstanceOnly, Category = "Movement Points")
	AActor* FirstPoint;

	/** Second point to move between */
	UPROPERTY(EditInstanceOnly, Category = "Movement Points")
	AActor* SecondPoint;

	/** The current point the actor is moving to */
	AActor* CurrentPoint;

	/** Determines the next point to move to */
	void MoveToNextPoint();
};
