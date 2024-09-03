#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PPMovingPlate.generated.h"

UCLASS()
class PEEEP_PROTOTYPE_API APPMovingPlate : public AActor
{
    GENERATED_BODY()

public:
    APPMovingPlate();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    class UStaticMeshComponent* BeltMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    class UBoxComponent* TriggerBox;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float BeltSpeed;

    void SetSwitchState(bool bNewState); // ����ġ ���¸� �����ϴ� �Լ� �߰�

private:
    bool bIsActivated;
    bool bIsSwitchOn; // ����ġ ���¸� ��Ÿ���� ���� �߰�

    UFUNCTION()
    void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
