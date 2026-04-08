#include "NBC_HomeWork_06/Public/MapObject/MovingActor.h"



AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);
	StaticMesh->SetCollisionProfileName(TEXT("NoCollision"));
	
	MoveSpeed = 1.f;
	MaxRange = 200.f;
	CurrentRange = 0.f;
}


void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	
}


void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (MaxRange >= CurrentRange)
	{
		float MoveAmount = MoveSpeed * DeltaTime;
		FVector DeltaLocation = FVector::UpVector * MoveAmount;
		
		AddActorWorldOffset(DeltaLocation);
		
		CurrentRange += MoveAmount;
		UE_LOG(LogTemp,Warning,TEXT("Current Range : %f"),CurrentRange);
	}
	else
	{
		Destroy();
	}
}

