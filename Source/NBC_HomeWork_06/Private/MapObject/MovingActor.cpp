#include "NBC_HomeWork_06/Public/MapObject/MovingActor.h"

#include "Components/AudioComponent.h"
#include "Components/PointLightComponent.h"
#include "Engine/PointLight.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "MapObject/CustomRotatingActor.h"
#include "MapObject/RotatingActor.h"

AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SceneRootComp = CreateDefaultSubobject<USceneComponent>(FName("SceneRootComp"));
	RootComponent = SceneRootComp;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(SceneRootComp);
	StaticMesh->SetCollisionProfileName(TEXT("NoCollision"));
	
	MoveSpeed = 1.f;
	MaxRange = 600.f;
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
		// UE_LOG(LogTemp,Warning,TEXT("Current Range : %f"),CurrentRange);
	}
	else
	{
		SpawnRotatingActor();
		SpawnPointLight();
		PlayBGM();
		Destroy();
	}
	
}

void AMovingActor::PlayBGM()
{
	if (AudioComp && AudioComp->IsPlaying())
	{
		UE_LOG(LogTemp,Warning,TEXT("BGM already Playing!!"));
		return;
	}
	
	if (BGMSound)
	{
		AudioComp = UGameplayStatics::SpawnSound2D(GetWorld(), BGMSound);
	}
}

void AMovingActor::SpawnRotatingActor()
{
	if (RotatingActorClass)
	{
		if (GetWorld())
		{
			FVector Location(GetActorLocation().X,GetActorLocation().Y,1530.f);
			FRotator Rotation = FRotator::ZeroRotator;
			FVector Scale(2.f,2.f,2.f);
				
			FTransform SpawnTransform(Rotation,Location,Scale);
			GetWorld()->SpawnActor<AActor>(RotatingActorClass, SpawnTransform);
		}
	}
}

void AMovingActor::SpawnPointLight()
{
	if (PointLightClass)
	{
		if (GetWorld())
		{
			FVector LightLocation = GetActorLocation() - FVector(0.f,0.f,100.f);
				
			GetWorld()->SpawnActor<APointLight>(PointLightClass, LightLocation, FRotator::ZeroRotator);
		}
	}
	if (OnMovingDestroyed.IsBound())
	{
		OnMovingDestroyed.Broadcast();
	}
}
