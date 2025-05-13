// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemySpawner.h"
#include "Robotpawner.generated.h"


UCLASS()
class PC_FACTORY_METHOD_API URobotpawner : public UEnemySpawner
{
	GENERATED_BODY()
	
public:
	// Método que crea el enemigo
	virtual UObject* CreateEnemy(UWorld* World) override;

};
