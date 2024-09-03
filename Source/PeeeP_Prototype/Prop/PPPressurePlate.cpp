#include "Prop/PPPressurePlate.h"
#include "Gimmick/PPMovingPlate.h" // ���� Ŭ���� ��� �߰�
#include "Prop/PPDoor.h" // ���� Ŭ���� ��� �߰�
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
APPPressurePlate::APPPressurePlate()
{
    PrimaryActorTick.bCanEverTick = true;
    Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
    RootComponent = Body;

    CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
    CollisionBox->SetupAttachment(Body);
    CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &APPPressurePlate::OnOverlapBegin);
    CollisionBox->OnComponentEndOverlap.AddDynamic(this, &APPPressurePlate::OnOverlapEnd);

    MovingPlate = nullptr; // ���� �ʱ�ȭ
    Door = nullptr; // ���� �ʱ�ȭ
}

// Called when the game starts or when spawned
void APPPressurePlate::BeginPlay()
{
    Super::BeginPlay();
}

void APPPressurePlate::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (MovingPlate) // ������ ������ ��쿡��
    {
        UE_LOG(LogTemp, Log, TEXT("Switch Overlap"));
        MovingPlate->SetSwitchState(true);
    }
    if (Door) // ��� ������ ��쿡��
    {
        Door->OnInteract();
    }
}

void APPPressurePlate::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (MovingPlate) // ������ ������ ��쿡��
    {
        UE_LOG(LogTemp, Log, TEXT("Switch No"));
        MovingPlate->SetSwitchState(false);
    }
    if (Door) // ��� ������ ��쿡��
    {
        Door->OnInteract();
    }
}

// Called every frame
void APPPressurePlate::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
