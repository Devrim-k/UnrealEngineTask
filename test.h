// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "test.generated.h"

UCLASS()
class TASK5_API Atest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Atest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector CurrentLocation;  // 현재 위치
	int32 MoveCount;		  // 이동 횟수

	void MoveRandomly();	  // 랜덤 이동 함수
};
