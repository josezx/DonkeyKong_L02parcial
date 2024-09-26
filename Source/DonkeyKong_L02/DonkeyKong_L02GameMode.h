// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DonkeyKong_L02GameMode.generated.h"

class AObstaculoMuro;
class AcomponentePlataforma;
class ADonkeyKong_L02Character;
class ABarril;
class AEsfera;
class ACompuertaTeletransportadora;  // Asegúrate de declarar esta clase aquí
class AMuroResorte;  // Declarar la clase AMuroResorte
class AMuroFuego;    // Declarar la clase AMuroFuego
UCLASS(minimalapi)
class ADonkeyKong_L02GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADonkeyKong_L02GameMode();

	AObstaculoMuro* obstaculo01;
	ADonkeyKong_L02Character* player01;

	TArray<AcomponentePlataforma*> componentesPlataforma;
	TArray<ABarril*> barriles;
	TMap<int32, AEsfera*> esferasMap;

	// TMap para almacenar los actores que pasan por las compuertas teletransportadoras
	TMap<AActor*, FVector> ActoresTeletransportados;
	// Referencias a las compuertas teletransportadoras
	ACompuertaTeletransportadora* Compuerta1;  // Declarar la primera compuerta
	ACompuertaTeletransportadora* Compuerta3;  // Declarar la segunda compuerta
	// Nueva variable para almacenar la clase del Blueprint del personaje
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player")
	TSubclassOf<APawn> PlayerPawnClass;

protected:
	virtual void BeginPlay() override;

private:
	FTimerHandle SpawnBarrilTimerHandle;
	void SpawnBarril();
	void SpawnMurosEnPisos();
	int32 contadorBarriles;
	const int32 numeroMaximoBarriles = 3;
	// Número de pisos
	int32 NumeroDePisos;

	// Rango de posiciones en X y Y para cada piso
	TArray<FVector2D> RangosPisos;

	// Clases de muros para spawnear
	TSubclassOf<class AMuroResorte> ClaseMuroResorte;
	TSubclassOf<class AMuroFuego> ClaseMuroFuego;
};



