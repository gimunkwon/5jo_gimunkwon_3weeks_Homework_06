#pragma once

#include "CoreMinimal.h"
#include "RotatingActor.h"
#include "CustomRotatingActor.generated.h"

UCLASS()
class NBC_HOMEWORK_06_API ACustomRotatingActor : public ARotatingActor
{
	GENERATED_BODY()

public:
	ACustomRotatingActor();
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	virtual void Spin(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Anim|Montage")
	UAnimMontage* SpinMontage;
	
	
private:
	float CurrentSpinAmount;
	bool bIsSpinning;
	FTimerHandle SpinTimerHandle;
	UPROPERTY()
	UAnimInstance* AnimInstance;
};
