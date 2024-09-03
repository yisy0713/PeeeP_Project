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

    // �÷��̾� ��ġ
    UPROPERTY(VisibleAnywhere, Category = "SaveData")
    FVector PlayerLocation;

    // �÷��̾� ȸ��
    UPROPERTY(VisibleAnywhere, Category = "SaveData")
    FRotator PlayerRotation;

    // �÷��̾� ü��, �κ�?�丮? ��� �߰��� �����ؾ��� �����͵�..
    /*UPROPERTY(VisibleAnywhere, Category = "SaveData")
    float PlayerHealth;*/

};
