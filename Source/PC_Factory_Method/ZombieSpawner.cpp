// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieSpawner.h"
#include "ZombieEnemy.h"

UObject* UZombieSpawner::CreateEnemy(UWorld* World)
{
	if (!World) return nullptr;

	FActorSpawnParameters SpawnParams;
	UObject* LastSpawnedEnemy = nullptr;

	for (int i = 0; i < 5; ++i)
	{
		float X = FMath::RandRange(-500.f, 500.f);
		float Y = FMath::RandRange(-500.f, 500.f);
		float Z = 230.f;

		LastSpawnedEnemy = World->SpawnActor<AZombieEnemy>(
			AZombieEnemy::StaticClass(),
			FVector(X, Y, Z),
			FRotator::ZeroRotator,
			SpawnParams
		);
	}

	return LastSpawnedEnemy;
}
