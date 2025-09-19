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
		TraceEnd.Z -= (CapsuleComp->GetScaledCapsuleHalfHeight() + 15.f); // �߷°��ӵ� �����ΰ�??? ���� +�� �����...

		// ����Ʈ���̽��� �Ķ���� ����
		FHitResult HitResult;
		FCollisionQueryParams TraceParams;
		TraceParams.AddIgnoredActor(this); // �� �ڽ��� ���Ե��� �ʵ���

		if (GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECC_Visibility, TraceParams))
		{
			if(FlightMode)
				SetFlightMode(FInputActionValue(1.f)); // �����ϸ� �ö���Ʈ ��� ����


			// ���� �ɸ��°� ������ ����
			isLanding = true;
			isJumpEnd = false;
			// UE_LOG(LogTemp, Warning, TEXT("Landed"));
			
			//   - Z�� �ӵ��� 0���� �ʱ�ȭ�Ͽ� �� �̻� �������� �ʰ�
			VerticalVelocity = 0.0f;
		}
		else
		{
			// �浹�� �������� ������ ����ؼ� ����
			isLanding = false;
		}
	}
	
	/// ���� �� ������� ���� �Ʒ��� ����ؼ� �����̵� ó���Ѵ�
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

		// Q, E�� �� �� ȸ��
		EIC->BindAction(RotateLeftAction, ETriggerEvent::Triggered, this, &AChallangeReportPawn::RotateLeft);
		EIC->BindAction(RotateRightAction, ETriggerEvent::Triggered, this, &AChallangeReportPawn::RotateRight);

		/// �����̵��� ���� ���ø�Ƽ�� �߰�
		EIC->BindAction(JumpAction, ETriggerEvent::Completed, this, &AChallangeReportPawn::MoveEnd);
		EIC->BindAction(DownAction, ETriggerEvent::Completed, this, &AChallangeReportPawn::MoveEnd);
		EIC->BindAction(FlightChangeAction, ETriggerEvent::Started, this, &AChallangeReportPawn::SetFlightMode);

	}
}

void AChallangeReportPawn::Jump(const FInputActionValue& Value)
{
	if (!FlightMode)
	{
		if (isLanding) // ���� ���� ������
		{
			// ���� ���� �ӵ� ���� ����� �������� ���� ���ǵ�� ���ÿ�
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
		// �ö���Ʈ ����� ���� ����Ű ������ ���
		if (Controller != nullptr)
		{
			// �Է� ���� 0���� ũ�� (���� Ű�� ������ ��)
			if (Value.Get<float>() > 0.f)
			{
				// ���� ����
				CurrentMoveInput = FVector(0.f, 0.f, Value.Get<float>());

				// Z��(����) �������θ� �̵� ���͸� ����
				FVector UpVector = FVector(0.0f, 0.0f, 1.0f);

				// ���� �̵� �ӵ�(NowMoveSpeed)�� ����Ͽ� ���� ���
				AddActorLocalOffset(UpVector * NowMoveSpeed * GetWorld()->GetDeltaSeconds());

				// �̵� �� ���¸� true�� �����Ͽ� ���ӵ� ����
				thisMove = true;
			}
			else
			{
				// ���� Ű�� ������ ��
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
			// �Է� ���� 0���� ũ�� (���� Ű�� ������ ��)
			if (Value.Get<float>() > 0.f)
			{
				// ���� �ݴ� -1
				CurrentMoveInput = FVector(0.f, 0.f, Value.Get<float>() * -1.f);

				// Z��(����) �������θ� �̵� ���͸� ���� << �������Ŵϱ� -1
				FVector UpVector = FVector(0.0f, 0.0f, -1.0f);

				// ���� �̵� �ӵ�(NowMoveSpeed)�� ����Ͽ� ���� ���
				AddActorLocalOffset(UpVector * NowMoveSpeed * GetWorld()->GetDeltaSeconds());

				// �̵� �� ���¸� true�� �����Ͽ� ���ӵ� ����
				thisMove = true;
			}
			else
			{
				// ���� Ű�� ������ ��
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


/// ��� ����϶��� ���콺�� �� ��ü�� �̵��ϴ°� ������ �����Ͽ�
/// �������̵� �ؼ� ���콺 ȸ�� = �� ȸ������ ��� ����
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

		// ������ ���� Roll, Pitch 0���� �̻ڰ� �����
		currentRotate.Roll = 0.f;
		currentRotate.Pitch = 0.f;
		this->SetActorRelativeRotation(currentRotate);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Entering Flight Mode"));
		FlightMode = true;
		Gravity = 0.f;
		VerticalVelocity = 0.f; // �������̾����� ������Ŵ
		/// �ϴ� ������ ������ �ϴÿ��� ������ ���� ������ false
		isJumpEnd = false;
		isLanding = false;

		// ������ �𸣰ڴµ� ���� ����� �ӵ��� 30~50%�� �����϶�� �ؼ� �߰�
		MaxMoveSpeed /= 2.f;
		// �ְ�ӿ��� ���� ������������ ���ӵǵ���
		if (NowMoveSpeed > MaxMoveSpeed)
		{
			NowMoveSpeed = MaxMoveSpeed;
		}
	}
}
