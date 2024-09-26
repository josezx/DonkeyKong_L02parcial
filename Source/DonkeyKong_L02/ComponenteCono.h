// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ComponenteCono.generated.h"

UCLASS()
class DONKEYKONG_L02_API AComponenteCono : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AComponenteCono();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
    // Malla para representar el cono visualmente
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* ConoMesh;

    // Variables para el movimiento
    FVector DireccionMovimiento;  // Dirección del movimiento
    float VelocidadMovimiento;    // Velocidad del cono
    float LimiteIzquierda;        // Límite izquierdo
    float LimiteDerecha;          // Límite derecho

    // Variables para el disparo
    float FireRate;               // Tiempo entre disparos
    FTimerHandle FireRateHandle;   // Temporizador para controlar el disparo

    // Función que dispara un proyectil
    void FireProjectile();
};
