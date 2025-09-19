// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ReportPawn.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "ChallangeReportPawn.generated.h"

/**
 * 
 */
UCLASS()
class REPORT_7_MAKEDRONE_API AChallangeReportPawn : public AReportPawn
{
	GENERATED_BODY()
public:
	// Sets default values for this pawn's properties
	AChallangeReportPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	UPROPERTY(EditAnywhere, Category = "ChallangePawn")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, Category = "ChallangePawn")
	TObjectPtr<UInputAction> DownAction;

	UPROPERTY(EditAnywhere, Category = "ChallangePawn")
	TObjectPtr<UInputAction> RotateLeftAction;

	UPROPERTY(EditAnywhere, Category = "ChallangePawn")
	TObjectPtr<UInputAction> RotateRightAction;

	UPROPERTY(EditAnywhere, Category = "ChallangePawn")
	TObjectPtr<UInputAction> FlightChangeAction;

	void Jump(const FInputActionValue& Value);
	void Down(const FInputActionValue& Value);

	void RotateLeft(const FInputActionValue& Value);
	void RotateRight(const FInputActionValue& Value);
	
	virtual void Look(const FInputActionValue& Value) override;

	void SetFlightMode(const FInputActionValue& Value);

private:
	UPROPERTY(EditAnywhere, Category = "ChallangePawn")
	float Gravity = 980.0f;

	// 현재 수직 속도 (점프, 낙하 등)
	UPROPERTY(VisibleAnywhere, Category = "ChallangePawn")
	float VerticalVelocity = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "ChallangePawn")
	bool isJumpEnd = false;
	
	UPROPERTY(VisibleAnywhere, Category = "ChallangePawn")
	bool isLanding = false;
	
	UPROPERTY(EditAnywhere, Category = "ChallangePawn")
	float JumpTargetPoint = 0.f;

	UPROPERTY(VisibleAnywhere, Category = "ChallangePawn")
	bool FlightMode = false;

	float ReturnMaxMoveSpeed = MaxMoveSpeed;
};
