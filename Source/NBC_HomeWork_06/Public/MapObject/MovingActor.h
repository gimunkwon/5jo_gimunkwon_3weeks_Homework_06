#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMovingActorDestroyed);

UCLASS()
class NBC_HOMEWORK_06_API AMovingActor : public AActor
{
	GENERATED_BODY()
public:
	AMovingActor();
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY()
	FOnMovingActorDestroyed OnMovingDestroyed;
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="Components")
	USceneComponent* SceneRootComp;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category="Mesh")
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Location")
	FVector StartLocation;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Location|Speed")
	float MoveSpeed;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Location|Distance")
	float MaxRange;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="SpawnActor")
	TSubclassOf<class AActor> RotatingActorClass;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="SpawnActor")
	TSubclassOf<class ALight> PointLightClass;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Sound")
	USoundBase* BGMSound;
private:
	float CurrentRange;
	UPROPERTY()
	UAudioComponent* AudioComp;
	void PlayBGM();
	void SpawnRotatingActor();
	void SpawnPointLight();
};
