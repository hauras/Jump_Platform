#include "Cube/MovingCube.h"

// Sets default values
AMovingCube::AMovingCube()
{
	PrimaryActorTick.bCanEverTick = true;
    MoveSpeed = 300.0f; // 기본 이동 속도
    MaxRange = 800.0f; // 최대 이동 범위

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    RootComponent = Mesh;
}

// Called when the game starts or when spawned
void AMovingCube::BeginPlay()
{
	Super::BeginPlay();
    StartLocation = GetActorLocation(); // 시작 위치 저장
}

// Called every frame
void AMovingCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    FVector CurrentLocation = GetActorLocation();

    // 이동 범위 초과 시 방향 반전
    if (FVector::Dist(StartLocation, CurrentLocation) >= MaxRange)
    {
        MoveSpeed = -MoveSpeed;
    }

    // 대각선 이동 (X, Y 방향 모두 변경)
    FVector NewLocation = CurrentLocation + FVector(MoveSpeed * DeltaTime, 0, MoveSpeed * DeltaTime);
    SetActorLocation(NewLocation);
}