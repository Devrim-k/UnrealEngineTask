// Fill out your copyright notice in the Description page of Project Settings.


#include "test.h"
#include "Math/UnrealMathUtility.h"	// FMath 사용을 위해 포함

// Sets default values
Atest::Atest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CurrentLocation = FVector(0.0f, 0.0f, 0.0f);	// 초기 위치 설정
	MoveCount = 0;	// 이동 횟수 초기화
}

// Called when the game starts or when spawned
void Atest::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Log, TEXT("Starting Location: (%f, %f, %f)"), CurrentLocation.X, CurrentLocation.Y, CurrentLocation.Z);
}

// Called every frame
void Atest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MoveCount < 10)	// 이동 횟수가 10회 미만일 때만 실행
	{
		MoveRandomly();
		UE_LOG(LogTemp, Log, TEXT("Move %d: New Location: (%f, %f, %f)"), MoveCount, CurrentLocation.X, CurrentLocation.Y, CurrentLocation.Z);
	}
	else
	{
		// Tick 비활성화 및 로그 출력
		if (PrimaryActorTick.bCanEverTick) 
		{

			PrimaryActorTick.bCanEverTick = false;	// 이동 완료 후 Tick 비활성화
			UE_LOG(LogTemp, Log, TEXT("Movement Complete"));
		}
	}
}

// 랜덤 이동 함수
void Atest::MoveRandomly() {

	int32 StepX = FMath::RandRange(0, 2); // X축 이동 거리 ( 0 ~ 2 중 랜덤)
	int32 StepY = FMath::RandRange(0, 2); // Y축 이동 거리 ( 0 ~ 2 중 랜덤)

	// X + Y의 합이 2 이하인지 확인
	while (StepX + StepY > 2)
	{
		StepX = FMath::RandRange(0, 2);	// X축 다시 계산
		StepY = FMath::RandRange(0, 2);	// Y축 다시 계산
	}

	// 새로운 위치 계산 및 이동 횟수 증가
	CurrentLocation.X += StepX;
	CurrentLocation.Y += StepY;
	MoveCount++;
}

