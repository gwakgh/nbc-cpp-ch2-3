// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "GameFramework/Actor.h"
#include "Engine/Engine.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	CurrentLocation = GetActorLocation();
	start = FVector2D(CurrentLocation.X,CurrentLocation.Y);
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMyActor::move, 0.3f, true);
}

void AMyActor::move()
{
	CurrentLocation = FVector(CurrentLocation.X + step(), CurrentLocation.Y + step(), 0);
	SetActorLocation(CurrentLocation);
	UE_LOG(LogTemp, Warning, TEXT("X: %f, Y: %f"), CurrentLocation.X, CurrentLocation.Y);
	if (count != 0 && count % 10 <= 0)
	{
		float dist = distance(start, FVector2D(CurrentLocation.X, CurrentLocation.Y));
		totDist += dist;
		if (createEvent())
		{
			evCnt++;
			UE_LOG(LogTemp, Warning, TEXT("Event!"));
		}
		UE_LOG(LogTemp, Warning, TEXT("Distance: %f"), dist);
		UE_LOG(LogTemp, Warning, TEXT("Total Distance: %d, Event Count: %d"), totDist, evCnt);
		start = FVector2D(CurrentLocation.X, CurrentLocation.Y);
	}
	count++;
}

int32_t AMyActor::step()
{
	return FMath::RandRange(0, 1);	
}

float AMyActor::distance(FVector2D first, FVector2D second)
{
	float a = FMath::Square(second.X - first.X);
	float b = FMath::Square(second.Y - first.Y);

	return sqrt(a + b);
}

int32 AMyActor::createEvent()
{
	return FMath::RandRange(0, 1);
}
