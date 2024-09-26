// Fill out your copyright notice in the Description page of Project Settings.


#include "componenteRectangulo.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
// Sets default values
AcomponenteRectangulo::AcomponenteRectangulo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Crear la malla del rect�ngulo
        RectanguloMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RectanguloMesh"));

    // Cargar la malla est�tica (Shape_Cube) del Starter Content
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

    // Verifica si se encontr� correctamente la malla
    if (MeshAsset.Succeeded())
    {
        RectanguloMesh->SetStaticMesh(MeshAsset.Object);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("No se encontr� la malla para el rect�ngulo."));
    }

    RootComponent = RectanguloMesh;

    // Aumentar m�s la escala del rect�ngulo
    FVector Scale(6.0f, 2.0f, 1.0f);  // Aumenta el tama�o en los ejes X, Y y Z
    SetActorScale3D(Scale);
    FRotator Rotation(0.0f, 90.0f, 0.0f);  // Esto lo rotar� 90 grados en el eje Y
    SetActorRotation(Rotation);
}

// Called when the game starts or when spawned
void AcomponenteRectangulo::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AcomponenteRectangulo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
}