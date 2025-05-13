// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EnemySpawner.generated.h"


UCLASS(Abstract)
class PC_FACTORY_METHOD_API UEnemySpawner : public UObject
{
	GENERATED_BODY()

public:
    // Método puramente virtual: cada subclase debe implementarlo
    virtual UObject* CreateEnemy(UWorld* World) PURE_VIRTUAL(UP01_FM_EnemyFactory::CreateEnemy, return nullptr;);

    void InvocarEnemigoYAtacar(UWorld * World);

};
