// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieEnemy.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/AudioComponent.h"
#include "UObject/ConstructorHelpers.h"
// Sets default values
AZombieEnemy::AZombieEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    CollisionComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionComp"));
    RootComponent = CollisionComp;

    MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
    MeshComp->SetupAttachment(RootComponent);

    ParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComp"));
    ParticleComp->SetupAttachment(RootComponent);


    // Asignar recursos al Zombie
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_WideCapsule.Shape_WideCapsule"));
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

	NombreIdentificador = "Zombie_Normal";
}

// Called when the game starts or when spawned
void AZombieEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AZombieEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AZombieEnemy::Atacar()
{
	UE_LOG(LogTemp, Warning, TEXT("Zombie ataca!!"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("Zombie ataca!!"));
}

FString AZombieEnemy::GetNombreIdentificador() const
{
	return FString(NombreIdentificador);
}

