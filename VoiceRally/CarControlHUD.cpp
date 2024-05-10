// Fill out your copyright notice in the Description page of Project Settings.


#include "CarControlHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

void ACarControlHUD::BeginPlay() {
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	FString Path = TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Rally/UI/UWBPControlCar.UWBPControlCar'");
	TSubclassOf<UUserWidget> WidgetClass = TSoftClassPtr<UUserWidget>(FSoftObjectPath(*Path)).LoadSynchronous();

	if (WidgetClass && PlayerController)
	{

		UUserWidget* UserWidget = UWidgetBlueprintLibrary::Create(GetWorld(), WidgetClass, PlayerController);

		UserWidget->AddToViewport(0);

		UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(PlayerController, UserWidget, EMouseLockMode::DoNotLock, true, false);
		PlayerController->SetShowMouseCursor(true);
	}
}
