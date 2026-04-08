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
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Mesh")
	USkeletalMeshComponent* SkeletalMesh;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Spin")
	int32 RotateCount;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Spin")
	float RotateAmount;
	
	virtual void Spin(float DeltaTime);
private:
	FRotator StartRotation;
};
