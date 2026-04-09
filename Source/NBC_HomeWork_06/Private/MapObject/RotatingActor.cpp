#include "NBC_HomeWork_06/Public/MapObject/RotatingActor.h"

ARotatingActor::ARotatingActor()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SceneRootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	RootComponent = SceneRootComp;
	
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMesh->SetupAttachment(SceneRootComp);
	
	RotateMinCount = 1;
	RotateMaxCount = 1;
	RotateAmount = 360.f;
	StartRotation = GetActorRotation();
}


void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();
}

void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Spin(DeltaTime);
}

void ARotatingActor::Spin(float DeltaTime)
{
	float fRotate_Amount = RotateAmount * DeltaTime;
	
	AddActorLocalRotation(FRotator(0.f,fRotate_Amount,0.f));
	
}