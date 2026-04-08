#include "NBC_HomeWork_06/Public/MapObject/MovingActor.h"



AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;
	StartLocation = GetActorLocation();
	MoveSpeed = 10.f;
	MaxRange = 200.f;
	CurrentRange = 0.f;
}


void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	
}


void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

