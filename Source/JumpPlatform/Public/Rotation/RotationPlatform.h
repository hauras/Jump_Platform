#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotationPlatform.generated.h"

UCLASS()
class JUMPPLATFORM_API ARotationPlatform : public AActor
{
    GENERATED_BODY()
    
public:    
    ARotationPlatform();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Platform|Rotation")
    float MoveSpeed; // 회전 속도 
private:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* Mesh;

    UPROPERTY(EditAnywhere, Category="Platform|Rotation")
    FRotator RotationVelocity = FRotator(0, 45, 0); // 기본 회전 속도

    UPROPERTY(EditAnywhere, Category="Platform|Rotation")
    bool bReverseDirection = false; // 역방향 여부
};