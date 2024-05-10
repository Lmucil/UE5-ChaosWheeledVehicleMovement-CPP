// Fill out your copyright notice in the Description page of Project Settings.


#include "startScreenBP.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"


void UstartScreenBP::NativeConstruct()
{
	/*
	Super::NativeConstruct();

	ButtonPlay->OnClicked.AddUniqueDynamic(this, &UstartScreenBP::OnButtonPlayClicked);

	ButtonQuit->OnClicked.AddUniqueDynamic(this, &UstartScreenBP::OnButtonQuitClicked);
	*/
}

void UstartScreenBP::OnButtonPlayClicked()
{
	/*
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0)) {
		UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("VoiceRallyDirtRoad")));

	}
	*/
}

void UstartScreenBP::OnButtonQuitClicked()
{
	/*
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		UKismetSystemLibrary::QuitGame(GetWorld(), PlayerController, EQuitPreference::Quit, false);
	}
	*/
}