// Fill out your copyright notice in the Description page of Project Settings.


#include "PPGameSave.h"

UPPGameSave::UPPGameSave()
{
    PlayerLocation = FVector::ZeroVector;
    PlayerRotation = FRotator::ZeroRotator;
    //PlayerHealth = 100.0f; // 추가로 저장한 데이터 설정(기본 체력 값 설정)
}
