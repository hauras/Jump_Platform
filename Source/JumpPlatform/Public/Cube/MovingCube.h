// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingCube.generated.h"

UCLASS()
class JUMPPLATFORM_API AMovingCube : public AActor
{
	GENERATED_BODY()
    
public:
    AMovingCube();

protected:
    virtual void BeginPlay() override;

    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Platform|Settings")
    float MoveSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Platform|Settings")
    float MaxRange;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* Mesh;

private:
    FVector StartLocation;
};
