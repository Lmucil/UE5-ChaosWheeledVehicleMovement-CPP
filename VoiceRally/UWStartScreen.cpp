// Fill out your copyright notice in the Description page of Project Settings.


#include "UWStartScreen.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Framework/UVoiceRallyGameInstance.h"


void UUWStartScreen::NativeConstruct() {
	Super::NativeConstruct();

	ButtonPlay->OnClicked.AddUniqueDynamic(this, &UMainMenuWidget::OnButtonPlayClicked);

	ButtonQuit->OnClicked.AddUniqueDynamic(this, &UMainMenuWidget::OnButtonQuitClicked);
}

void UUWStartScreen::OnButtonPlayClicked()
{
	UVoiceRallyGameInstance* GameInstance = Cast<URollingBallGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	GameInstance->Initialize();

	UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("VoiceRallyDirtRoad")));
}

void UUWStartScreen::OnButtonQuitClicked()
{
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{

		UKismetSystemLibrary::QuitGame(GetWorld(), PlayerController, EQuitPreference::Quit, false);
	}
}
