// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/MeshComponent.h"
#include "Components/ActorComponent.h"
#include "MyActor.generated.h"

UCLASS()
class UNREAL5WEEK_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;
	
	FVector CurrentLocation;
	FVector2D start;

	FTimerHandle TimerHandle;

	int count = 0;
	int32 evCnt = 0;
	int totDist;

public:	
	void move();
	int32_t step();
	float distance(FVector2D first, FVector2D second);
	int32 createEvent();
};
