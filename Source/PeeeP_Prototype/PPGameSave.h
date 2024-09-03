// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PPGameSave.generated.h"

/**
 * 
 */
UCLASS()
class PEEEP_PROTOTYPE_API UPPGameSave : public USaveGame
{
	GENERATED_BODY()
	
public:
    UPPGameSave();

    // 플레이어 위치
    UPROPERTY(VisibleAnywhere, Category = "SaveData")
    FVector PlayerLocation;

    // 플레이어 회전
    UPROPERTY(VisibleAnywhere, Category = "SaveData")
    FRotator PlayerRotation;

    // 플레이어 체력, 인벤?토리? 등등 추가로 저장해야할 데이터들..
    /*UPROPERTY(VisibleAnywhere, Category = "SaveData")
    float PlayerHealth;*/

};
