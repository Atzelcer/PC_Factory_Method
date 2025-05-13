// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "Enemy.h"
#include "Engine/World.h"

void UEnemySpawner::InvocarEnemigoYAtacar(UWorld* World)
{

    UObject* Enemy = CreateEnemy(World);
    if (!Enemy)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("[Factory] No se pudo crear enemigo."));
        }
        return;
    }

    IEnemy* EnemyInterface = Cast<IEnemy>(Enemy);
    if (EnemyInterface)
    {
        FString Msg = FString::Printf(TEXT("[Factory] Enemigo creado: %s"), *EnemyInterface->GetNombreIdentificador());
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, Msg);

        EnemyInterface->Atacar();
    }
}
