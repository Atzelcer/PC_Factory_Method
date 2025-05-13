// Fill out your copyright notice in the Description page of Project Settings.


#include "RobotEnemy.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundWave.h"
#include "UObject/ConstructorHelpers.h"
// Sets default values
ARobotEnemy::ARobotEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    CollisionComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionComp"));
    RootComponent = CollisionComp;

    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
    MeshComp->SetupAttachment(RootComponent);

    ParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComp"));
    ParticleComp->SetupAttachment(RootComponent);

    // Asignar recursos al Robot
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Tube.Shape_Tube"));
    if (MeshAsset.Succeeded())
    {
        MeshComp->SetStaticMesh(MeshAsset.Object);
    }

    static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("/Game/StarterContent/Particles/P_Explosion.P_Explosion"));
    if (ParticleAsset.Succeeded())
    {
        ParticleComp->SetTemplate(ParticleAsset.Object);
        ParticleComp->bAutoActivate = false;
    }

	NombreIdentificador = "Robot_normal";

}

// Called when the game starts or when spawned
void ARobotEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARobotEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARobotEnemy::Atacar()
{
	UE_LOG(LogTemp, Warning, TEXT("Atacando con el robot"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Atacando con el robot"));
}

FString ARobotEnemy::GetNombreIdentificador() const
{
	return FString("NombreIdentificador");
}

