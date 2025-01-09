// Fill out your copyright notice in the Description page of Project Settings.


#include "test.h"
#include "Math/UnrealMathUtility.h"	// FMath ����� ���� ����

// Sets default values
Atest::Atest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CurrentLocation = FVector(0.0f, 0.0f, 0.0f);	// �ʱ� ��ġ ����
	MoveCount = 0;	// �̵� Ƚ�� �ʱ�ȭ
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

	if (MoveCount < 10)	// �̵� Ƚ���� 10ȸ �̸��� ���� ����
	{
		MoveRandomly();
		UE_LOG(LogTemp, Log, TEXT("Move %d: New Location: (%f, %f, %f)"), MoveCount, CurrentLocation.X, CurrentLocation.Y, CurrentLocation.Z);
	}
	else
	{
		// Tick ��Ȱ��ȭ �� �α� ���
		if (PrimaryActorTick.bCanEverTick) 
		{

			PrimaryActorTick.bCanEverTick = false;	// �̵� �Ϸ� �� Tick ��Ȱ��ȭ
			UE_LOG(LogTemp, Log, TEXT("Movement Complete"));
		}
	}
}

// ���� �̵� �Լ�
void Atest::MoveRandomly() {

	int32 StepX = FMath::RandRange(0, 2); // X�� �̵� �Ÿ� ( 0 ~ 2 �� ����)
	int32 StepY = FMath::RandRange(0, 2); // Y�� �̵� �Ÿ� ( 0 ~ 2 �� ����)

	// X + Y�� ���� 2 �������� Ȯ��
	while (StepX + StepY > 2)
	{
		StepX = FMath::RandRange(0, 2);	// X�� �ٽ� ���
		StepY = FMath::RandRange(0, 2);	// Y�� �ٽ� ���
	}

	// ���ο� ��ġ ��� �� �̵� Ƚ�� ����
	CurrentLocation.X += StepX;
	CurrentLocation.Y += StepY;
	MoveCount++;
}

