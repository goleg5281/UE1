// Fill out your copyright notice in the Description page of Project Settings.
#include "Engine/Engine.h"
//#include <math.h>
//#include <UnrealMathUtility>
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

UCLASS()
class CPPBASE2_010225_API ACppBaseActor : public AActor
{
	GENERATED_BODY()

public:
	ACppBaseActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

protected:
	/* UPROPERTY(VisibleAnywhere)
	FString PlayerName = "Netology";
	UPROPERTY(EditDefaultsOnly)
	float CurrentHealth = 57.54;
	UPROPERTY(EditInstanceOnly)
	FString InstanceName = "InputInstanceNameHere";
	UPROPERTY(EditInstanceOnly)
	int EnemyNum = 0;
	UPROPERTY(EditInstanceOnly)
	bool IsAlive = 1;*/
	UPROPERTY()
	UWorld* World;

	UPROPERTY(EditAnywhere)
	float Frequency;
	UPROPERTY(EditAnywhere)
	float Amplitude;
	UPROPERTY(EditAnywhere)
	FVector InitialLocation;


	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void ShowInformation();
	void ShowActorInformation();
public:
	UFUNCTION(BlueprintCallable)
	FVector SinMovement();
};
