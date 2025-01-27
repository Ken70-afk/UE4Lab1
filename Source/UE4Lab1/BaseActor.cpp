#include "BaseActor.h"

// Constructor
ABaseActor::ABaseActor()
{
	// Enable ticking for this actor
	PrimaryActorTick.bCanEverTick = true;

	// Initialize the root component
	RootTransformComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootTransformComponent"));
	SetRootComponent(RootTransformComponent);

	// Initialize the mesh component
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootTransformComponent);
}

// Called when the game starts or when spawned
void ABaseActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
