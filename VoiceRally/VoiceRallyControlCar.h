// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "VoiceRallyControlCar.generated.h"

/**
 * 
 */
UCLASS()
class VOICERALLY_API AVoiceRallyControlCar : public AWheeledVehiclePawn
{
	GENERATED_BODY()

public:

	AVoiceRallyControlCar();
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class USpringArmComponent* SpringArmC;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UCameraComponent* CameraC;

protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
private:
	void MoveForward(float value);
	void MoveBackward(float value);
	void MoveRL(float value);

	void BrakePressed();
	void BrakeReleased();

	void LookUpDown(float value);
	void LookRL(float value);

	void Menu();



};
