#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.generated.h"

UCLASS()
class NBC_HOMEWORK_06_API AMovingActor : public AActor
{
	GENERATED_BODY()
public:
	AMovingActor();
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Location")
	FVector StartLocation;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Location|Speed")
	float MoveSpeed;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Location|Distance")
	float MaxRange;
	
private:
	float CurrentRange;
};
