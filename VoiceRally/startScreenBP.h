// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "startScreenBP.generated.h"

/**
 * 
 */

class UButton;

UCLASS()
class VOICERALLY_API UstartScreenBP : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	// NativeConstruct
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
