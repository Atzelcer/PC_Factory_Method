// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PC_Factory_MethodGameMode.generated.h"

UCLASS(minimalapi)
class APC_Factory_MethodGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APC_Factory_MethodGameMode();

public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
    void CrearEnemigos();
};



