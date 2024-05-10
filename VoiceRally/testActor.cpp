// Fill out your copyright notice in the Description page of Project Settings.


#include "testActor.h"
#include "Kismet/KismetSystemLibrary.h"
#include <string>
#include <windows.h>
#include <iostream>
#include <chrono>
#include <thread>


// Called when the game starts or when spawned
void AtestActor::BeginPlay()
{
	Super::BeginPlay();
    GetWorld()->GetTimerManager().SetTimer(MyTimerHandle, this, &AtestActor::OnTimer, 1.0f, true);

    /*
    int hour = 0;
	int minute = 0;
    int second = 0;


   while (second < 59) {
        using namespace std::this_thread;
        using namespace std::chrono;


        
        sleep_for(nanoseconds(10));
        sleep_until(system_clock::now() + seconds(1));
        second++;
        //windows only takes fstring
        std::string timeStr = std::to_string(minute) + ":" + std::to_string(second);
        FString timeFString(timeStr.c_str());
        UKismetSystemLibrary::PrintString(this, timeFString, true, true, FColor::Cyan, 2.f, TEXT("None")); 
        
        
   }

    if (second > 59) {
        
        minute++;
        second = 0;
        std::string timeStr = std::to_string(minute) + ":" + std::to_string(second);
        FString timeFString(timeStr.c_str());
        UKismetSystemLibrary::PrintString(this, timeFString, true, true, FColor::Cyan, 2.f, TEXT("None"));
        
        
    }


    if (minute > 59) {
        
        hour++;
        second = 0;
        minute = 0;
        std::string timeStr = std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second);
        FString timeFString(timeStr.c_str());
        UKismetSystemLibrary::PrintString(this, timeFString, true, true, FColor::Cyan, 2.f, TEXT("None"));
        
        
    }
    */
} 

void AtestActor::OnTimer()
{
    // Increment the counter and debug
    ++TimerCount;

    std::string timeStr = std::to_string(TimerCount);
    FString timeFString(timeStr.c_str());
    UKismetSystemLibrary::PrintString(this, timeFString, true, true, FColor::Cyan, 2.f, TEXT("None"));


    
}

void AtestActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    //keep the call chain on EndPlays
    Super::EndPlay(EndPlayReason);

    GetWorld()->GetTimerManager().ClearTimer(MyTimerHandle);
}


