#include "NBC_HomeWork_06/Public/MapObject/CustomRotatingActor.h"


ACustomRotatingActor::ACustomRotatingActor()
{
	PrimaryActorTick.bCanEverTick = true;
	CurrentSpinAmount = 0.f;
	bIsSpinning = true;
	RotateCount = 1;
}


void ACustomRotatingActor::BeginPlay()
{
	Super::BeginPlay();
	RotateAmount *= RotateCount;
	
	if (SkeletalMesh)
	{
		AnimInstance = SkeletalMesh->GetAnimInstance();
	}
}


void ACustomRotatingActor::Tick(float DeltaTime)
{
	// FString IsSpinning = bIsSpinning ? TEXT("Yes") : TEXT("No");
	//
	// GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Green, IsSpinning);
	
	if (bIsSpinning)
	{
		Spin(DeltaTime);
	}
}

void ACustomRotatingActor::Spin(float DeltaTime)
{
	if (CurrentSpinAmount >= RotateAmount)
	{
		if (AnimInstance && SpinMontage)
		{
			AnimInstance->Montage_Stop(0.f, SpinMontage);
		}
		bIsSpinning = false;
		CurrentSpinAmount = 0.f;
		GetWorld()->GetTimerManager().SetTimer(SpinTimerHandle, [this]()
		{
			bIsSpinning = true;
		},4.f,false);
	}
	else
	{
		if (AnimInstance && SpinMontage)
		{
			if (!AnimInstance->Montage_IsPlaying(SpinMontage))
			{
				AnimInstance->Montage_Play(SpinMontage);
				AnimInstance->Montage_JumpToSection(FName("BeginSpin"), SpinMontage);
			}
		}
		float fRotate_Amount = RotateAmount * DeltaTime;
		AddActorLocalRotation(FRotator(0.f,fRotate_Amount,0.f));
		CurrentSpinAmount += fRotate_Amount;
	}

	UE_LOG(LogTemp,Warning,TEXT("Current SpinAmount %f"),CurrentSpinAmount);
}