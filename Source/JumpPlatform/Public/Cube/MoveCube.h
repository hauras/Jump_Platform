// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveCube.generated.h"

UCLASS()
class JUMPPLATFORM_API AMoveCube : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AMoveCube();

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Platform|Settings")
    float MoveSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Platform|Settings")
    float MaxRange;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* Mesh;

public:	
	virtual void Tick(float DeltaTime) override;
	FVector StartLocation;

};
