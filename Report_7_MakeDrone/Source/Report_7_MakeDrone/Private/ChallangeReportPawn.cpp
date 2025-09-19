// Fill out your copyright notice in the Description page of Project Settings.


#include "ChallangeReportPawn.h"
#include "Components/CapsuleComponent.h"




AChallangeReportPawn::AChallangeReportPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChallangeReportPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AChallangeReportPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// UE_LOG(LogTemp, Warning, TEXT("isLanding : %d"), isLanding);
	if (!isJumpEnd)
	{
		FVector TraceStart = GetActorLocation();
		TraceStart.Z += (CapsuleComp->GetScaledCapsuleHalfHeight());
		FVector TraceEnd = GetActorLocation();
		TraceEnd.Z -= (CapsuleComp->GetScaledCapsuleHalfHeight() + 15.f); // 중력가속도 때문인가??? 조금 +로 해줘야...

		// 라인트레이스용 파라미터 설정
		FHitResult HitResult;
		FCollisionQueryParams TraceParams;
		TraceParams.AddIgnoredActor(this); // 나 자신은 포함되지 않도록

		if (GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECC_Visibility, TraceParams))
		{
			if(FlightMode)
				SetFlightMode(FInputActionValue(1.f)); // 착지하면 플라이트 모드 해제


			// 뭐든 걸리는게 있으면 착지
			isLanding = true;
			isJumpEnd = false;
			// UE_LOG(LogTemp, Warning, TEXT("Landed"));
			
			//   - Z축 속도를 0으로 초기화하여 더 이상 떨어지지 않게
			VerticalVelocity = 0.0f;
		}
		else
		{
			// 충돌이 감지되지 않으면 계속해서 낙하
			isLanding = false;
		}
	}
	
	/// 땅에 안 닿았으면 위던 아래던 계속해서 수직이동 처리한다
	if (!isLanding)
	{
		VerticalVelocity -= Gravity * DeltaTime;

		AddActorLocalOffset(FVector(0, 0, VerticalVelocity) * DeltaTime, false);
		if (GetActorLocation().Z >= JumpTargetPoint)
		{
			JumpTargetPoint = 0.f;
			isJumpEnd = false;
			if (VerticalVelocity >= 0.f)
				VerticalVelocity *= -1.f;
		}
	}
}

// Called to bind functionality to input
void AChallangeReportPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EIC->BindAction(JumpAction, ETriggerEvent::Triggered, this, &AChallangeReportPawn::Jump);
		EIC->BindAction(DownAction, ETriggerEvent::Triggered, this, &AChallangeReportPawn::Down);
		EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &AChallangeReportPawn::Look);

		// Q, E로 좌 우 회전
		EIC->BindAction(RotateLeftAction, ETriggerEvent::Triggered, this, &AChallangeReportPawn::RotateLeft);
		EIC->BindAction(RotateRightAction, ETriggerEvent::Triggered, this, &AChallangeReportPawn::RotateRight);

		/// 관성이동을 위해 컴플리티드 추가
		EIC->BindAction(JumpAction, ETriggerEvent::Completed, this, &AChallangeReportPawn::MoveEnd);
		EIC->BindAction(DownAction, ETriggerEvent::Completed, this, &AChallangeReportPawn::MoveEnd);
		EIC->BindAction(FlightChangeAction, ETriggerEvent::Started, this, &AChallangeReportPawn::SetFlightMode);

	}
}

void AChallangeReportPawn::Jump(const FInputActionValue& Value)
{
	if (!FlightMode)
	{
		if (isLanding) // 이중 점프 방지용
		{
			// 따로 점프 속도 변수 만들긴 귀찮으니 무브 스피드랑 동시에
			VerticalVelocity = MaxMoveSpeed;

			isLanding = false;
			isJumpEnd = true; // 
			JumpTargetPoint = GetActorLocation().Z + JumpPower;

			UE_LOG(LogTemp, Warning, TEXT("nowPoint : %f"), GetActorLocation().Z);
			UE_LOG(LogTemp, Warning, TEXT("JumpTargetPoint : %f"), JumpTargetPoint);
		}
	}
	else
	{
		// 플라이트 모드일 때는 점프키 누르면 상승
		if (Controller != nullptr)
		{
			// 입력 값이 0보다 크면 (점프 키가 눌렸을 때)
			if (Value.Get<float>() > 0.f)
			{
				// 관성 세팅
				CurrentMoveInput = FVector(0.f, 0.f, Value.Get<float>());

				// Z축(수직) 방향으로만 이동 벡터를 생성
				FVector UpVector = FVector(0.0f, 0.0f, 1.0f);

				// 현재 이동 속도(NowMoveSpeed)를 사용하여 수직 상승
				AddActorLocalOffset(UpVector * NowMoveSpeed * GetWorld()->GetDeltaSeconds());

				// 이동 중 상태를 true로 설정하여 가속도 적용
				thisMove = true;
			}
			else
			{
				// 점프 키를 떼었을 때
				thisMove = false;
				nokoriMove = true;
			}
		}
	}
}
void AChallangeReportPawn::Down(const FInputActionValue& Value)
{
	if (FlightMode)
	{
		if (Controller != nullptr)
		{
			// 입력 값이 0보다 크면 (점프 키가 눌렸을 때)
			if (Value.Get<float>() > 0.f)
			{
				// 관성 반대 -1
				CurrentMoveInput = FVector(0.f, 0.f, Value.Get<float>() * -1.f);

				// Z축(수직) 방향으로만 이동 벡터를 생성 << 내려갈거니까 -1
				FVector UpVector = FVector(0.0f, 0.0f, -1.0f);

				// 현재 이동 속도(NowMoveSpeed)를 사용하여 수직 상승
				AddActorLocalOffset(UpVector * NowMoveSpeed * GetWorld()->GetDeltaSeconds());

				// 이동 중 상태를 true로 설정하여 가속도 적용
				thisMove = true;
			}
			else
			{
				// 점프 키를 떼었을 때
				thisMove = false;
				nokoriMove = true;
			}
		}
	}
}

void AChallangeReportPawn::RotateLeft(const FInputActionValue& Value)
{
	if (FlightMode)
	{
		FVector2D LookAxis = Value.Get<FVector2D>();
		if (Controller != nullptr)
		{
			AddActorLocalRotation(FRotator(0.0f, 0.f, -5.0f));
		}
	}
}

void AChallangeReportPawn::RotateRight(const FInputActionValue& Value)
{
	if (FlightMode)
	{
		FVector2D LookAxis = Value.Get<FVector2D>();
		if (Controller != nullptr)
		{
			AddActorLocalRotation(FRotator(0.0f, 0.f, +5.0f));
		}
	}
}


/// 드론 모드일때는 마우스로 폰 자체를 이동하는게 조작이 쾌적하여
/// 오버라이드 해서 마우스 회전 = 폰 회전으로 모드 변경
void AChallangeReportPawn::Look(const FInputActionValue& Value)
{
	if (FlightMode)
	{
		FVector2D LookAxis = Value.Get<FVector2D>();
		if (Controller != nullptr)
		{
			AddActorLocalRotation(FRotator(LookAxis.Y * CameraPitchSpeed, LookAxis.X * CameraYawSpeed, 0.0f));
		}
	}
	else
	{
		Super::Look(Value);
	}
}

void AChallangeReportPawn::SetFlightMode(const FInputActionValue& Value)
{
	if (FlightMode)
	{
		UE_LOG(LogTemp, Warning, TEXT("Exiting Flight Mode"));
		FlightMode = false;
		Gravity = 980.f;

		MaxMoveSpeed = ReturnMaxMoveSpeed;

		FRotator currentRotate = this->GetActorRotation();

		// 착지할 때는 Roll, Pitch 0으로 이쁘게 만들기
		currentRotate.Roll = 0.f;
		currentRotate.Pitch = 0.f;
		this->SetActorRelativeRotation(currentRotate);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Entering Flight Mode"));
		FlightMode = true;
		Gravity = 0.f;
		VerticalVelocity = 0.f; // 낙하중이었으면 정지시킴
		/// 일단 땅에서 눌렀든 하늘에서 눌렀든 관련 변수는 false
		isJumpEnd = false;
		isLanding = false;

		// 이유를 모르겠는데 공중 날기는 속도를 30~50%로 제어하라고 해서 추가
		MaxMoveSpeed /= 2.f;
		// 최고속에서 날기 시작했을때도 감속되도록
		if (NowMoveSpeed > MaxMoveSpeed)
		{
			NowMoveSpeed = MaxMoveSpeed;
		}
	}
}
