// Fill out your copyright notice in the Description page of Project Settings.


#include "VoiceRallyControlCar.h"
#include "GameFramework\SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "ChaosVehicleMovementComponent.h"

AVoiceRallyControlCar::AVoiceRallyControlCar() {
	SpringArmC = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmC->SetupAttachment(RootComponent);
	SpringArmC->TargetArmLength = 600;
	SpringArmC->bUsePawnControlRotation;
	CameraC = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraC->SetupAttachment(SpringArmC);
}

void AVoiceRallyControlCar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &AVoiceRallyControlCar::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveBackward"), this, &AVoiceRallyControlCar::MoveBackward);
	PlayerInputComponent->BindAxis(FName("MoveLR"), this, &AVoiceRallyControlCar::MoveRL);
	PlayerInputComponent->BindAxis(FName("LookUpDown"), this, &AVoiceRallyControlCar::LookUpDown);
	PlayerInputComponent->BindAxis(FName("lookLR"), this, &AVoiceRallyControlCar::LookRL);

	PlayerInputComponent->BindAction(FName("Brakes"), EInputEvent::IE_Pressed, this, &AVoiceRallyControlCar::BrakePressed);
	PlayerInputComponent->BindAction(FName("Brakes"), EInputEvent::IE_Released, this, &AVoiceRallyControlCar::BrakeReleased);


}

void AVoiceRallyControlCar::MoveForward(float value) {
	GetVehicleMovementComponent()->SetThrottleInput(value);
}

void AVoiceRallyControlCar::MoveBackward(float value) {
	GetVehicleMovementComponent()->SetBrakeInput(value);
}

void AVoiceRallyControlCar::MoveRL(float value) {
	GetVehicleMovementComponent()->SetSteeringInput(value);
}

void AVoiceRallyControlCar::BrakePressed() {
	GetVehicleMovementComponent()->SetHandbrakeInput(true);

}

void AVoiceRallyControlCar::BrakeReleased() {
	GetVehicleMovementComponent()->SetHandbrakeInput(false);

}

void AVoiceRallyControlCar::LookUpDown(float value) {
	//AddControllerPitchInput(value*-1);
}

void AVoiceRallyControlCar::LookRL(float value) {
	AddControllerYawInput(value);
}

void AVoiceRallyControlCar::Menu() {

}