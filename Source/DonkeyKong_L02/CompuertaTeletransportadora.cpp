// Fill out your copyright notice in the Description page of Project Settings.


#include "CompuertaTeletransportadora.h"
#include "Components/StaticMeshComponent.h"
#include "DonkeyKong_L02GameMode.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
// Sets default values
ACompuertaTeletransportadora::ACompuertaTeletransportadora()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Crear y configurar la malla est�tica de la compuerta
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;

	// Asignar una malla espec�fica para la compuerta
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Geometry/Meshes/1M_Cube.1M_Cube"));
	if (MeshAsset.Succeeded())
	{
		MeshComp->SetStaticMesh(MeshAsset.Object);
	}

    // Configuraci�n de colisiones
    MeshComp->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    MeshComp->SetGenerateOverlapEvents(true);  // Habilitar eventos de superposici�n
    MeshComp->OnComponentBeginOverlap.AddDynamic(this, &ACompuertaTeletransportadora::OnOverlapBegin);
    // Inicializar las variables miembro, no localmente
    bPuedeTeletransportar = true;  // Inicialmente, la compuerta puede teletransportar
    TiempoEsperaTeletransporte = 2.0f;  // 2 segundos de espera entre teletransportaciones
}

// Called when the game starts or when spawned
void ACompuertaTeletransportadora::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACompuertaTeletransportadora::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Funci�n de detecci�n de colisi�n
void ACompuertaTeletransportadora::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

    // Verificar si el OtherActor no es nullptr y no es el propio actor
    if (!OtherActor || OtherActor == this)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Actor inv�lido para teletransporte."));
        return;
    }

    // Verificar si la CompuertaDestino est� asignada
    if (!CompuertaDestino)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("CompuertaDestino no asignada."));
        return;
    }

    // Agregar mensaje de depuraci�n para confirmar que la colisi�n fue detectada
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("OnOverlapBegin activado: %s ha entrado a la Compuerta %s"), *OtherActor->GetName(), *GetName()));

    // Verificar si el actor puede ser teletransportado
    if (bPuedeTeletransportar)
    {
        // Desactivar el teletransporte temporalmente
        bPuedeTeletransportar = false;

        // Obtener la posici�n de la CompuertaDestino
        FVector NuevaPosicion = CompuertaDestino->GetActorLocation();

        // Agregar mensaje de depuraci�n antes del teletransporte
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Teletransportando %s a la nueva posici�n: %s"), *OtherActor->GetName(), *NuevaPosicion.ToString()));

        // Desactivar eventos de superposici�n temporalmente en ambas compuertas
        MeshComp->SetGenerateOverlapEvents(false);
        CompuertaDestino->MeshComp->SetGenerateOverlapEvents(false);

        // Teletransportar al actor
        OtherActor->SetActorLocation(NuevaPosicion);

        // Mensaje de depuraci�n despu�s del teletransporte
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("Actor %s teletransportado a Compuerta 3"), *OtherActor->GetName()));

        // Almacenar el actor en el TMap del GameMode
        GameModeRef->ActoresTeletransportados.Add(OtherActor, NuevaPosicion);

        // Restablecer el teletransporte despu�s de un tiempo y habilitar las colisiones nuevamente
        FTimerHandle TimerHandle;
        GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]()
            {
                bPuedeTeletransportar = true;

                // Reactivar los eventos de superposici�n en ambas compuertas
                MeshComp->SetGenerateOverlapEvents(true);
                if (CompuertaDestino) {
                    CompuertaDestino->MeshComp->SetGenerateOverlapEvents(true);
                }

                GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, TEXT("Teletransporte restablecido, se puede teletransportar de nuevo."));
            }, TiempoEsperaTeletransporte, false);
    }
    else
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Teletransporte desactivado temporalmente."));
    }
    }

// Funci�n para establecer la referencia al GameMode
void ACompuertaTeletransportadora::SetGameMode(ADonkeyKong_L02GameMode* GameMode)
{
	GameModeRef = GameMode;
}   