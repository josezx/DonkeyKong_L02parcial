	// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponenteCono.h"
#include "AShooterProjectile.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
#include "TimerManager.h"
// Sets default values
AComponenteCono::AComponenteCono()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    // Crear la malla del cono
    ConoMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ConoMesh"));
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone"));
    if (MeshAsset.Succeeded())
    {
        ConoMesh->SetStaticMesh(MeshAsset.Object);
    }
    RootComponent = ConoMesh;

    // Variables para el movimiento
    VelocidadMovimiento = 150.0f;  // Velocidad de movimiento
    LimiteIzquierda = -900.0f;    // L�mite en la izquierda
    LimiteDerecha = 1400.0f;       // L�mite en la derecha
    DireccionMovimiento = FVector(0.0f, 1.0f, 0.0f);  // Mover en el eje Y (izquierda-derecha)

    // Variables para el disparo
    FireRate = 3.0f;  // Tiempo entre disparos (3 segundo)

}

// Called when the game starts or when spawned
void AComponenteCono::BeginPlay()
{
	Super::BeginPlay();
    // Configurar el temporizador para disparar proyectiles a intervalos regulares
    GetWorld()->GetTimerManager().SetTimer(FireRateHandle, this, &AComponenteCono::FireProjectile, FireRate, true);
}

// Called every frame
void AComponenteCono::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    // L�gica de movimiento

    // Obtener la posici�n actual del cono
    FVector Location = GetActorLocation();

    // Mover el cono de izquierda a derecha
    Location += DireccionMovimiento * VelocidadMovimiento * DeltaTime;

    // Verificar si el cono ha alcanzado los l�mites y cambiar la direcci�n
    if (Location.Y <= LimiteIzquierda && DireccionMovimiento.Y < 0)
    {
        DireccionMovimiento *= -1;  // Invertir la direcci�n solo cuando est� movi�ndose hacia la izquierda y toque el l�mite
    }
    else if (Location.Y >= LimiteDerecha && DireccionMovimiento.Y > 0)
    {
        DireccionMovimiento *= -1;  // Invertir la direcci�n solo cuando est� movi�ndose hacia la derecha y toque el l�mite
    }

    // Actualizar la posici�n del cono
    SetActorLocation(Location);
}
// Funci�n para disparar proyectiles
void AComponenteCono::FireProjectile()
{
    // Establecer la ubicaci�n y rotaci�n del disparo (hacia abajo)
    FVector MuzzleLocation = GetActorLocation() + FVector(0.0f, 0.0f, -50.0f);  // Disparar desde abajo del cono
    FRotator MuzzleRotation = FRotator(-90.0f, 0.0f, 0.0f);  // Rotaci�n para disparar hacia abajo

    // Crear el proyectil en el mundo
    UWorld* const World = GetWorld();
    if (World != nullptr)
    {
        World->SpawnActor<AAShooterProjectile>(MuzzleLocation, MuzzleRotation);
    }
}
