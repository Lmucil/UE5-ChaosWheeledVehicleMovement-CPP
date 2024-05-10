// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UWStartScreen.generated.h"

/**
 * 
 */
UCLASS()
class VOICERALLY_API UUWStartScreen : public UUserWidget
{
	GENERATED_BODY()
	
	class UButton;

protected:

	void NativeConstruct() override;

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ButtonPlay;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ButtonQuit;

	UFUNCTION()
	void OnButtonPlayClicked();

	UFUNCTION()
	void OnButtonQuitClicked();
};
