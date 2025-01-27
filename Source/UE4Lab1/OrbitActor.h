#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "OrbitActor.generated.h"

/**
 * AOrbitActor orbits around a specified target actor.
 */
UCLASS()
class UE4LAB1_API AOrbitActor : public ABaseActor
{
	GENERATED_BODY()

public:
	// Constructor
	AOrbitActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** The actor to orbit around */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotate Around")
	AActor* RotateAroundActor;

	/** Rotation speed in degrees per second */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotate Around")
	float RotationSpeed;

	/** Radius of rotation in CM */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotate Around")
	FVector RotationRadius;

	/** Axis of rotation */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotate Around")
	FVector RotationAxis;

	/** Current angle of rotation */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotate Around", meta = (ClampMin = "0.0", ClampMax = "360.0", UIMin = "0.0", UIMax = "360.0"))
	float CurrentAngle;

	/** Resets the orbit parameters */
	void Reset();
};
