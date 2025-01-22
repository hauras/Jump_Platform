#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimedPlatform.generated.h"

UCLASS()
class JUMPPLATFORM_API ATimedPlatform : public AActor
{
    GENERATED_BODY()

public:
    ATimedPlatform();

protected:
    virtual void BeginPlay() override;

private:
    // 발판의 Mesh
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* Mesh;

    // 발판이 사라지는 시간
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform", meta = (AllowPrivateAccess = "true"))
    float DisappearTime;

    // 발판이 다시 나타나는 시간
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform", meta = (AllowPrivateAccess = "true"))
    float appearTime;

    // 발판의 상태
    bool bIsVisible;

    // 타이머 핸들
    FTimerHandle TimerHandle;

    // 발판 상태 전환 함수
    void TogglePlatform();
};