#include "Timed/TimedPlatform.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"

ATimedPlatform::ATimedPlatform()
{
    PrimaryActorTick.bCanEverTick = false;

    // Static Mesh 생성 및 루트 설정
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    RootComponent = Mesh;

    // 기본값 설정
    DisappearTime = 3.0f;  // 3초 후에 사라짐
    appearTime = 5.0f;   // 5초 후에 다시 나타남
    bIsVisible = true;     
}

void ATimedPlatform::BeginPlay()
{
    Super::BeginPlay();


    GetWorldTimerManager().SetTimer(TimerHandle, this, &ATimedPlatform::TogglePlatform, DisappearTime, false);
}

void ATimedPlatform::TogglePlatform()
{
    bIsVisible = !bIsVisible; 

    Mesh->SetVisibility(bIsVisible);

    float NextTime = bIsVisible ? DisappearTime : appearTime;
    GetWorldTimerManager().SetTimer(TimerHandle, this, &ATimedPlatform::TogglePlatform, NextTime, false);
}