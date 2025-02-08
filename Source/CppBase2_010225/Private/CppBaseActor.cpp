// Fill out your copyright notice in the Description page of Project Settings.

#include "CppBaseActor.h"
#include "Kismet/KismetSystemLibrary.h"

ACppBaseActor::ACppBaseActor()
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
	FString Name = UKismetSystemLibrary::GetObjectName(this);
	// auto UserName = UKismetSystemLibrary::GetPlatformUserName();
	// auto marks = UKismetSystemLibrary::GetAllMarks();
	UE_LOG(LogTemp, Display, TEXT("Instance name: %s"), *Name);
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);
	// UE_LOG(LogTemp, Display, TEXT("User name: %s"), *UserName);
}

void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	ShowActorInformation();
}

void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
