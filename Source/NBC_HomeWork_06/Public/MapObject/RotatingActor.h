#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor.generated.h"

UCLASS()
class NBC_HOMEWORK_06_API ARotatingActor : public AActor
{
	GENERATED_BODY()

public:
	
	ARotatingActor();

protected:
	
	virtual void BeginPlay() override;

public:
	
	virtual void Tick(float DeltaTime) override;
};
