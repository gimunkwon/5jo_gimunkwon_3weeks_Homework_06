#pragma once

#include "CoreMinimal.h"
#include "RotatingActor.h"
#include "CustomRotatingActor.generated.h"

class AMovingActor;

UCLASS()
class NBC_HOMEWORK_06_API ACustomRotatingActor : public ARotatingActor
{
	GENERATED_BODY()

public:
	ACustomRotatingActor();
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	void OnMovingActorDestroyed();
	
protected:
	virtual void BeginPlay() override;
	virtual void Spin(float DeltaTime) override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Anim|Montage")
	UAnimMontage* SpinMontage;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Delegates")
	AMovingActor* DestroyMovingActor;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Spin")
	float SpinSpeed;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="SpinTest")
	bool bIsSpinning;
private:
	float CurrentSpinAmount;
	FTimerHandle SpinTimerHandle;
	UPROPERTY()
	UAnimInstance* AnimInstance;
	float TargetSpinAmount;
};
