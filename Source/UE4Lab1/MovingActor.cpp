#include "MovingActor.h"

// Constructor
AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;
	FirstPoint = nullptr;
	SecondPoint = nullptr;
	CurrentPoint = nullptr;
}

// Called when the game starts or when spawned
void AMovingActor::BeginPlay()
{
	Super::BeginPlay();

	// Start moving toward the first point
	if (FirstPoint)
	{
		CurrentPoint = FirstPoint;
	}
}

// Called every frame
void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// If there’s a valid current point, move toward it
	if (CurrentPoint)
	{
		FVector CurrentLocation = GetActorLocation();
		FVector TargetLocation = CurrentPoint->GetActorLocation();
		float Distance = FVector::Dist(CurrentLocation, TargetLocation);

		// Move toward the target location
		float Speed = 200.0f; // Movement speed in units per second
		SetActorLocation(FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed));

		// Check if close to the target point
		if (Distance < 10.0f)
		{
			MoveToNextPoint();
		}
	}
}

// Determines the next point to move to
void AMovingActor::MoveToNextPoint()
{
	if (CurrentPoint == FirstPoint)
	{
		CurrentPoint = SecondPoint;
	}
	else
	{
		CurrentPoint = FirstPoint;
	}
}
