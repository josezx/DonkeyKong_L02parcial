// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DonkeyKong_L02Character.generated.h"

class AObstaculo;

UCLASS(config=Game)
class ADonkeyKong_L02Character : public ACharacter
{
	GENERATED_BODY()

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

protected:

	/** Called for side to side input */
	void MoveRight(float Val);

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

	void Parar();
	bool detener;
	/**Funci�n para disparar un proyectil */
	void FireShot();

	/** Funci�n para resetear la capacidad de disparar */
	void ResetFire();

	/** Offset desde la ubicaci�n del personaje para generar proyectiles */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FVector GunOffset;

	/** Tasa de disparo (en segundos) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	float FireRate;

	/** Bandera para controlar si el personaje puede disparar */
	uint32 bCanFire : 1;

	/** Handle para manejar el temporizador del disparo */
	FTimerHandle FireRateHandle;

public:
	ADonkeyKong_L02Character();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
public:
	AObstaculo* obstaculo01;

public:
	/** Returns obstaculo01 subobject **/
	FORCEINLINE AObstaculo* GetObstaculo() const { return obstaculo01; }
	FORCEINLINE void SetObstaculo(AObstaculo* _obstaculo) { obstaculo01 = _obstaculo; }

};
