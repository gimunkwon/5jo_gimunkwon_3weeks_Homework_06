#include "NBC_HomeWork_06/Public/MapObject/CustomRotatingActor.h"



ACustomRotatingActor::ACustomRotatingActor()
{
	PrimaryActorTick.bCanEverTick = true;
	CurrentSpinAmount = 0.f;
	bIsSpinning = true;
}


void ACustomRotatingActor::BeginPlay()
{
	Super::BeginPlay();
}


void ACustomRotatingActor::Tick(float DeltaTime)
{
	FString IsSpinning = bIsSpinning ? TEXT("Yes") : TEXT("No");
	
	GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Green, IsSpinning);
	
	if (bIsSpinning)
	{
		Spin(DeltaTime);
	}
}

void ACustomRotatingActor::Spin(float DeltaTime)
{
	if (CurrentSpinAmount >= RotateAmount)
	{
		bIsSpinning = false;
		CurrentSpinAmount = 0.f;
		GetWorld()->GetTimerManager().SetTimer(SpinTimerHandle, [this](){bIsSpinning = true;},4.f,false);
	}
	else
	{
		float fRotate_Amount = RotateAmount * DeltaTime;
		AddActorLocalRotation(FRotator(0.f,fRotate_Amount,0.f));
		CurrentSpinAmount += fRotate_Amount;
	}

	UE_LOG(LogTemp,Warning,TEXT("Current SpinAmount %f"),CurrentSpinAmount);
}