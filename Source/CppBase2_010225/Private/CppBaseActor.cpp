// Fill out your copyright notice in the Description page of Project Settings.

#include "CppBaseActor.h"
#include "Engine/World.h"
#include "Kismet/KismetSystemLibrary.h"

ACppBaseActor::ACppBaseActor() : Frequency{ 4.0f }, Amplitude{ 70.0f }
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"), false);
	SetRootComponent(this->Mesh);
	
}
void ACppBaseActor::ShowInformation()
{
	/*
	int EnemyNum = 20;
	float CurrentHealth = 57.54;
	bool IsAlive = true;
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("CurrentHealth: %f"), CurrentHealth);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);
	FString PlayerName2 = "Netology";
	UE_LOG(LogTemp, Display, TEXT("PlayerName:%s"), *PlayerName2);

	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Black, PlayerName2, true, FVector2D(2.0f, 2.0f));
	UE_LOG(LogTemp, Display, TEXT("Instance name: %s"), *name)*/
}

void ACppBaseActor::ShowActorInformation() // имя объекта, количество его врагов и информацию о том, жив объект или нет вводим в UE_Editor.
{
	/*FString Name = UKismetSystemLibrary::GetObjectName(this);
	UE_LOG(LogTemp, Display, TEXT("Instance name: %s"), *Name);
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);*/

}

void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	World = GetWorld();
	this->InitialLocation = FVector(0.0f, 0.0f, 0.0f);
}

void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


FVector ACppBaseActor::SinMovement()
{
	float z0 = InitialLocation.Z;
	auto Time = World->GetTimeSeconds();
	UE_LOG(LogTemp, Display, TEXT("\nTime: %f "), Time);
	UE_LOG(LogTemp, Display, TEXT("\nFreq: %f "), Frequency);
	UE_LOG(LogTemp, Display, TEXT("\nAmplitude: %f "), Amplitude);
	float Z = Amplitude * FMath::Sin(Frequency * Time) + z0;
	UE_LOG(LogTemp, Display, TEXT("\nZ: %f"), Z);
	InitialLocation.Set(0.0f, 0.0f, Z);
	return InitialLocation;
}