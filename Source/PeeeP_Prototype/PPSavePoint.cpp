// Fill out your copyright notice in the Description page of Project Settings.


#include "PPSavePoint.h"
#include "Components/BoxComponent.h"
#include "Character/PPCharacterPlayer.h"

// Sets default values
APPSavePoint::APPSavePoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
    RootComponent = CollisionBox;
    CollisionBox->SetBoxExtent(FVector(100.f, 100.f, 100.f));
    CollisionBox->SetCollisionProfileName(TEXT("Trigger"));
    CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &APPSavePoint::OnOverlapBegin);

}

// Called when the game starts or when spawned
void APPSavePoint::BeginPlay()
{
	Super::BeginPlay();
	
}

void APPSavePoint::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    APPCharacterPlayer* Player = Cast<APPCharacterPlayer>(OtherActor);
    if (Player)
    {
        Player->SaveGame();
        UE_LOG(LogTemp, Log, TEXT("Player reached Save Point"));
    }
}

// Called every frame
void APPSavePoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

