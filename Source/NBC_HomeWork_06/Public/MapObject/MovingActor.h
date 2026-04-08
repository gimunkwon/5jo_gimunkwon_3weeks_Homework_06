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

protected:
	
	virtual void BeginPlay() override;

public:
	
	virtual void Tick(float DeltaTime) override;
};
