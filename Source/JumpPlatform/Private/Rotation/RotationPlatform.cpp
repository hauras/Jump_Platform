#include "Rotation/RotationPlatform.h"

ARotationPlatform::ARotationPlatform()
{
    PrimaryActorTick.bCanEverTick = true;
    MoveSpeed = 300.0f; // 기본 이동 속도

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    RootComponent = Mesh;
}

void ARotationPlatform::BeginPlay()
{
    Super::BeginPlay();
}

void ARotationPlatform::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // 역방향이면 RotationVelocity를 반전
    FRotator CurrentRotationVelocity = RotationVelocity;

    if (bReverseDirection)
    {
        CurrentRotationVelocity = FRotator(
            -RotationVelocity.Pitch,
            -RotationVelocity.Yaw,
            -RotationVelocity.Roll
        ); // 각 축의 값을 반전
    }

    FRotator AdjustedRotationVelocity = CurrentRotationVelocity * (MoveSpeed * DeltaTime);
    // 회전 처리
    AddActorLocalRotation(CurrentRotationVelocity * DeltaTime);
}