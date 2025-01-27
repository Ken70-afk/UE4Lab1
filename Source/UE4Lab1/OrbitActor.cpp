#include "OrbitActor.h"

// Constructor
AOrbitActor::AOrbitActor()
{
	PrimaryActorTick.bCanEverTick = true;

	// Default values
	RotateAroundActor = nullptr;
	RotationSpeed = 50.0f;
	RotationRadius = FVector::ZeroVector;
	RotationAxis = FVector::UpVector;
	CurrentAngle = 0.0f;
}

// Called when the game starts or when spawned
void AOrbitActor::BeginPlay()
{
	Super::BeginPlay();

	// If no radius is set, calculate it based on the distance to the target actor
	if (RotateAroundActor)
	{
		FVector Distance = GetActorLocation() - RotateAroundActor->GetActorLocation();
		RotationRadius = Distance.Size() * FVector::OneVector;
	}
}

// Called every frame
void AOrbitActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (RotateAroundActor)
	{
		// Update the angle
		CurrentAngle += RotationSpeed * DeltaTime;
		if (CurrentAngle > 360.0f)
		{
			CurrentAngle -= 360.0f;
		}

		// Calculate new position
		FVector TargetLocation = RotateAroundActor->GetActorLocation();
		FVector Offset = RotationRadius.RotateAngleAxis(CurrentAngle, RotationAxis);
		SetActorLocation(TargetLocation + Offset);
	}
}

// Reset orbit parameters
void AOrbitActor::Reset()
{
	CurrentAngle = 0.0f;
	if (RotateAroundActor)
	{
		FVector Distance = GetActorLocation() - RotateAroundActor->GetActorLocation();
		RotationRadius = Distance.Size() * FVector::OneVector;
	}
}
