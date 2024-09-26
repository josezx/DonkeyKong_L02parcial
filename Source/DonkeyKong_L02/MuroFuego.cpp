// Fill out your copyright notice in the Description page of Project Settings.


#include "MuroFuego.h"
#include "DonkeyKong_L02Character.h"
#include "UObject/ConstructorHelpers.h"

AMuroFuego::AMuroFuego()
{
    // Cargar una malla específica para el MuroFuego, si lo deseas
    static ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
    if (Mesh.Succeeded())
    {
        MuroMesh->SetStaticMesh(Mesh.Object);
    }

    Dano = 25.0f; // Ajusta este valor según sea necesario
}

void AMuroFuego::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
    const FHitResult& SweepResult)
{
    Super::OnOverlapBegin(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

    ADonkeyKong_L02Character* Character = Cast<ADonkeyKong_L02Character>(OtherActor);
    if (Character)
    {
        // Implementa la lógica para reducir la vida del personaje
        // Por ejemplo:
        // Character->ReceiveDamage(Dano);
    }
}
