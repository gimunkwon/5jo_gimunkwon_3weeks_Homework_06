#include "NBC_HomeWork_06/Public/MapObject/MovingActor.h"



AMovingActor::AMovingActor()
{
	
	PrimaryActorTick.bCanEverTick = true;
}


void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	
}


void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

