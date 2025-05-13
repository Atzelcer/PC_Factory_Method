// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.h"
#include "RobotEnemy.generated.h"

UCLASS()
class PC_FACTORY_METHOD_API ARobotEnemy : public AActor, public IEnemy
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARobotEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Atacar() override;
	virtual FString GetNombreIdentificador() const override;

	FString NombreIdentificador;
	float Vida;
	float Fuerza;

private:
	UPROPERTY(VisibleAnywhere)
	class UCapsuleComponent* CollisionComp;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere)
	class UParticleSystemComponent* ParticleComp;

};
