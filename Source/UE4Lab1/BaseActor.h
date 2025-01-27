// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseActor.generated.h"

/**
 * ABaseActor serves as a base class for other actors.
 * It contains a root transform component and a static mesh component for visual representation.
 */
UCLASS(Abstract)
class UE4LAB1_API ABaseActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseActor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Root component for the actor's transform */
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Root Component")
	USceneComponent* RootTransformComponent;

	/** Static mesh component for visual representation */
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Actor Visual")
	UStaticMeshComponent* MeshComponent;
};
