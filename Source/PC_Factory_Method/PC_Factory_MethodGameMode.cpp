// Copyright Epic Games, Inc. All Rights Reserved.

#include "PC_Factory_MethodGameMode.h"
#include "PC_Factory_MethodPlayerController.h"
#include "PC_Factory_MethodCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Enemy.h"
#include "EnemySpawner.h"
#include "ZombieSpawner.h"
#include "Robotpawner.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

APC_Factory_MethodGameMode::APC_Factory_MethodGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = APC_Factory_MethodPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void APC_Factory_MethodGameMode::BeginPlay()
{
	Super::BeginPlay();

	CrearEnemigos();
}

void APC_Factory_MethodGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APC_Factory_MethodGameMode::CrearEnemigos()
{
	UEnemySpawner* Factory = nullptr;

	int32 Tipo = FMath::RandRange(0, 1);

	if (Tipo == 0)
	{
		Factory = NewObject<UZombieSpawner>();
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, TEXT("Seleccionado: ZOMBIE"));
	}
	else
	{
		Factory = NewObject<URobotpawner>();
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, TEXT("Seleccionado: ROBOT"));
	}

	if (Factory)
	{
		Factory->InvocarEnemigoYAtacar(GetWorld());
	}
}
