// Fill out your copyright notice in the Description page of Project Settings.


#include "ReportPawn.h"
#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AReportPawn::AReportPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 각 컴포넌트 생성
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComp"));
	ArrowComp = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComp"));
	CharMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharMesh"));
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));

	/// 과제 의도가 이걸 쓰지 말라는 것 같아서 주석
	// MyMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));

	// 순서대로 부착
	// this->SetRootComponent(CapsuleComp); // 루트는 캡슐로
	RootComponent = CapsuleComp;
	ArrowComp->SetupAttachment(CapsuleComp); // 화살표
	CharMesh->SetupAttachment(CapsuleComp); // 스켈레톤
	SpringArmComp->SetupAttachment(CapsuleComp); // 스프링암도 캡슐에
	CameraComp->SetupAttachment(SpringArmComp); // 카메라는 스프링암에
	
	// 피직스 시뮬레이트 판정 삭제 <- 과제 내용
	// CapsuleComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CapsuleComp->SetSimulatePhysics(false);
	CharMesh->SetSimulatePhysics(false);

	// 컨트롤러의 회전을 따라가도록 설정
	// SpringArmComp->bUsePawnControlRotation = true;

	// 컨트롤러 회전 요 사용
	// bUseControllerRotationYaw = true;
}

// Called when the game starts or when spawned
void AReportPawn::BeginPlay()
{
	Super::BeginPlay();
	SpawnDefaultController();
	
}

// Called every frame
void AReportPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/// 가속도에 맞춰 이동 속도가 변화되도록 함
	if (thisMove && NowMoveSpeed < MaxMoveSpeed)
	{
		// UE_LOG(LogTemp, Warning, TEXT("DT : %f"), DeltaTime);
		NowMoveSpeed += Acceleration * DeltaTime * 10.f;

		// UE_LOG(LogTemp, Warning, TEXT("NowMoveSpeed : %f"), NowMoveSpeed);
		if (NowMoveSpeed > MaxMoveSpeed) 
		{
			NowMoveSpeed = MaxMoveSpeed;
		}
	}

	// 이동을 멈출 때 약간의 관성으로 천천히 미끄러지도록 하는 기능 추가
	// 다시 move 입력이 들어오면 nokoriMove가 false됨으로 관성 이동 멈추어 플레이어 조작감 최적화
	if (nokoriMove)
	{
		UE_LOG(LogTemp, Warning, TEXT("Nokori Move"));
		NowMoveSpeed -= Acceleration * DeltaTime * 10.f;
		UE_LOG(LogTemp, Warning, TEXT("NowMoveSpeed : %f"), NowMoveSpeed);
		if (NowMoveSpeed < MinMoveSpeed)
		{
			UE_LOG(LogTemp, Warning, TEXT("Nokori Move End"));
			NowMoveSpeed = MinMoveSpeed;
			nokoriMove = false;
		}
		AddActorLocalOffset(CurrentMoveInput * NowMoveSpeed * DeltaTime, true);
		
	}


}

// Called to bind functionality to input
void AReportPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AReportPawn::Move);
		/// 관성이동을 위해 컴플리티드 추가
		EIC->BindAction(MoveAction, ETriggerEvent::Completed, this, &AReportPawn::MoveEnd);
		EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &AReportPawn::Look);
	}
}

void AReportPawn::Move(const FInputActionValue& Value)
{
	FVector2D MoveVector = Value.Get<FVector2D>();
	CurrentMoveInput = FVector(MoveVector.X, MoveVector.Y, 0.0f);

	if(Controller != nullptr)
	{
		if (nokoriMove)
		{
			NowMoveSpeed = MinMoveSpeed;
			nokoriMove = false;
		}
		// UE_LOG(LogTemp, Warning, TEXT("Move Input: X=%f, Y=%f"), MoveVector.X, MoveVector.Y);
		AddActorLocalOffset(FVector(MoveVector.X, MoveVector.Y, 0) * NowMoveSpeed * GetWorld()->GetDeltaSeconds(), true);
		thisMove = true;
		/// 밑에는 안 씀
		//AddMovementInput(GetActorForwardVector(), MoveVector.Y * MoveSpeed);
		//AddMovementInput(GetActorRightVector(), MoveVector.X * MoveSpeed);
		// SetActorLocation(GetActorLocation() + (GetActorForwardVector() * MoveVector.Y + GetActorRightVector() * MoveVector.X) * MoveSpeed * GetWorld()->GetDeltaSeconds());

	}
}
void AReportPawn::MoveEnd(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Warning, TEXT("MoveEnd"));
	thisMove = false;

	/// 노코리 무브 끝날 때 속도 초기화 되도록 함
	// NowMoveSpeed = MinMoveSpeed;

	// 틱에서 노코리 무브 진행
	nokoriMove = true;
}

void AReportPawn::Look(const FInputActionValue& Value)
{
	// if (!IsValid(CameraComp)) return;
	
	FVector2D LookAxis = Value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look Input: X=%f, Y=%f"), LookAxis.X, LookAxis.Y);

		//SpringArmComp->AddLocalRotation(FQuat(FRotator(0, LookAxis.X, 0))); // 좌우
		//SpringArmComp->AddLocalRotation(FQuat(FRotator(LookAxis.Y, 0, 0))); // 위아래

		// Y축(Yaw) 회전은 Pawn의 회전으로
		
		//FRotator CameraWorldRotation = SpringArmComp->GetComponentRotation();
		//FRotator NewPawnRotation = FRotator(0.0f, CameraWorldRotation.Yaw, 0.0f);
		//SetActorRotation(NewPawnRotation);


		// X축(Pitch) 회전은 카메라 회전 변수에 누적
		CameraPitch += LookAxis.Y * CameraPitchSpeed;

		// Pitch 값을 제한하여 카메라가 뒤집히지 않도록
		CameraPitch = FMath::Clamp(CameraPitch, -80.0f, 80.0f);

		// CameraYaw += LookAxis.X * CameraYawSpeed;
		// Yaw값은 카메라를 돌리지 말고 Pawn 자체를 돌리는게 더 자연스럽다
		AddActorLocalRotation(FRotator(0.0f, LookAxis.X * CameraYawSpeed, 0.0f));

		if (IsValid(SpringArmComp))
		{
			// FRotator NewSpringArmRotation = FRotator(CameraPitch* DeltaTime, CameraYaw* DeltaTime, 0.0f);
			// FRotator NewSpringArmRotation = FRotator(CameraPitch, CameraYaw, 0.0f);
			FRotator NewSpringArmRotation = FRotator(CameraPitch, 0.f, 0.0f); // Yaw는 Pawn 회전으로 처리하므로 0으로 설정
			SpringArmComp->SetRelativeRotation(NewSpringArmRotation);
		}


		/// 이거 안 씀
		// SpringArmComp->AddActorLocalRotation(FQuat(FRotator(0, LookAxis.X, 0)));
		//AddControllerYawInput(LookAxis.X);
		//AddControllerPitchInput(LookAxis.Y * -1);

	}
}