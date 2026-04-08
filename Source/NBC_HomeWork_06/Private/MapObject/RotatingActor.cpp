#include "NBC_HomeWork_06/Public/MapObject/RotatingActor.h"



ARotatingActor::ARotatingActor()
{
	
	PrimaryActorTick.bCanEverTick = true;
}


void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}


void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

