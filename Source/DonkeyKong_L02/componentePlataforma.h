// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "componentePlataforma.generated.h"

class UStaticMeshComponent;

UCLASS()
class DONKEYKONG_L02_API AcomponentePlataforma : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AcomponentePlataforma();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UStaticMeshComponent* meshPlataforma;
	FVector PosicionInicial;  // Almacena la posici�n inicial para mover la plataforma
	bool bDebeMoverse;  // Indica si la plataforma debe moverse

	float VelocidadMovimiento;  // Velocidad del movimiento
	float DistanciaMovimiento;  // Distancia que se mueve hacia adelante y hacia atr�s
	bool bMovimientoAdelante;  // Controla la direcci�n del movimiento (hacia adelante o atr�s)
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	/// Funci�n para inicializar el comportamiento de movimiento de la plataforma
	void InicializarPlataforma(bool bMoverse, float Velocidad, float Distancia);
};
