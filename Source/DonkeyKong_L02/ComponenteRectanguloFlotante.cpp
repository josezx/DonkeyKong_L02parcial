// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponenteRectanguloFlotante.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
// Sets default values
AComponenteRectanguloFlotante::AComponenteRectanguloFlotante()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    // Crear la malla del rect�ngulo
        RectanguloMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RectanguloMesh"));

    // Cargar la malla est�tica (puede ser un cubo del Starter Content)
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
    if (MeshAsset.Succeeded())
    {
        RectanguloMesh->SetStaticMesh(MeshAsset.Object);
    }
    RootComponent = RectanguloMesh;

    // Escalar el rect�ngulo para que sea m�s largo
    FVector Scale(4.0f, 1.0f, 0.5f);  // Escala ajustada
    SetActorScale3D(Scale);
    // Rotar el rect�ngulo para que est� de costado
    FRotator Rotation(0.0f, 90.0f, 0.0f);  // Rotar 90 grados en el eje Y
    SetActorRotation(Rotation);
    // Inicializar variables de movimiento
    VelocidadMovimiento = 200.0f;  // Velocidad de movimiento
    LimiteIzquierda = -1700.0f;     // L�mite en la izquierda
    LimiteDerecha = 1000.0f;        // L�mite en la derecha
    DireccionMovimiento = FVector(0.0f, 1.0f, 0.0f);  // Mover en el eje X
}

// Called when the game starts or when spawned
void AComponenteRectanguloFlotante::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AComponenteRectanguloFlotante::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    // Obtener la ubicaci�n actual del rect�ngulo
    FVector Location = GetActorLocation();

    // Mover el rect�ngulo de izquierda a derecha
    Location += DireccionMovimiento * VelocidadMovimiento * DeltaTime;

    // Cambiar la direcci�n cuando alcance los l�mites
    if (Location.Y <= LimiteIzquierda || Location.Y >= LimiteDerecha)
    {
        DireccionMovimiento *= -1;  // Cambiar la direcci�n
    }

    // Actualizar la nueva posici�n
    SetActorLocation(Location);
}

