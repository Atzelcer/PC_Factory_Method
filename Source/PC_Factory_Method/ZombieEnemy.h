// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.h"
#include "ZombieEnemy.generated.h"

class UCapsuleComponent;
class USkeletalMeshComponent;
class UParticleSystemComponent;

UCLASS()
class PC_FACTORY_METHOD_API AZombieEnemy : public AActor, public IEnemy
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AZombieEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	virtual void Atacar() override;
	virtual FString GetNombreIdentificador() const override;

	FString NombreIdentificador;
	float Vida;
	float Fuerza;

private:
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* CollisionComp;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* ParticleComp;
};
