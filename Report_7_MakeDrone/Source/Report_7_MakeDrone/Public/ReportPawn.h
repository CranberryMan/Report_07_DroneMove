// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "ReportPawn.generated.h"

UCLASS()
class REPORT_7_MAKEDRONE_API AReportPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AReportPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	UPROPERTY(EditAnywhere, Category = "MyPawn")
	TObjectPtr<class UCapsuleComponent> CapsuleComp;
	UPROPERTY(EditAnywhere, Category = "MyPawn")
	TObjectPtr<class UArrowComponent> ArrowComp;
	UPROPERTY(EditAnywhere, Category = "MyPawn")
	TObjectPtr<class USkeletalMeshComponent> CharMesh;
	
	UPROPERTY(EditAnywhere, Category = "MyPawn")
	TObjectPtr<class USpringArmComponent> SpringArmComp;

	UPROPERTY(EditAnywhere, Category = "MyPawn")
	TObjectPtr<class UCameraComponent> CameraComp;

	/// 과제 발제 의도가 이걸 쓰지 말라는 것 같음??
	//UPROPERTY(VisibleAnywhere, Category = "MyPawn")
	//TObjectPtr<class UFloatingPawnMovement> MyMovement;

// 입력
	UPROPERTY(EditAnywhere, Category = "MyPawn")
	TObjectPtr<UInputAction> MoveAction;
	UPROPERTY(EditAnywhere, Category = "MyPawn")
	TObjectPtr<UInputAction> LookAction;

	void Move(const FInputActionValue& Value);
	void MoveEnd(const FInputActionValue& Value);
	virtual void Look(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere, Category = "MyPawn")
	float MinMoveSpeed = 100.;
	UPROPERTY(EditAnywhere, Category = "MyPawn")
	float NowMoveSpeed = 100.f;
	UPROPERTY(EditAnywhere, Category = "MyPawn")
	float MaxMoveSpeed = 1200.0f;
	UPROPERTY(EditAnywhere, Category = "MyPawn")
	float Acceleration = 300.0f;

	UPROPERTY(EditAnywhere, Category = "MyPawn")
	float JumpPower = 350.0f;

	UPROPERTY(EditAnywhere, Category = "MyPawn")
	float TurnSpeed = 10.0f;

	FVector CurrentMoveInput;
	bool thisMove = false;
	bool nokoriMove = false;

	UPROPERTY(EditAnywhere, Category = "MyPawn")
	float CameraYaw = 0.0f;
	UPROPERTY(EditAnywhere, Category = "MyPawn")
	float CameraPitch = 0.0f;
	UPROPERTY(EditAnywhere, Category = "MyPawn")
	float CameraYawSpeed = 2.0f;
	UPROPERTY(EditAnywhere, Category = "MyPawn")
	float CameraPitchSpeed = 2.0f;
};
