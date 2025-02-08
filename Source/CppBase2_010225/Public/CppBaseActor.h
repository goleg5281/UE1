// Fill out your copyright notice in the Description page of Project Settings.
#include "Engine/Engine.h"
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

UCLASS()
class CPPBASE2_010225_API ACppBaseActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACppBaseActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

protected:
	UPROPERTY(VisibleAnywhere)
	FString PlayerName = "Netology";
	UPROPERTY(EditDefaultsOnly)
	float CurrentHealth = 57.54;

	UPROPERTY(EditInstanceOnly)
	FString InstanceName = "InputInstanceNameHere";
	UPROPERTY(EditInstanceOnly)
	int EnemyNum = 0;
	UPROPERTY(EditInstanceOnly)
	bool IsAlive = 1;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void ShowInformation();
	void ShowActorInformation();
};
