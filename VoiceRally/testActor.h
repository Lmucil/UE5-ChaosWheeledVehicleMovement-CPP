// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "testActor.generated.h"

UCLASS()
class VOICERALLY_API AtestActor : public AActor
{
	GENERATED_BODY()
	
	FTimerHandle MyTimerHandle;

	int TimerCount = 0;

	virtual void BeginPlay() override;

	void OnTimer();


	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;


};
