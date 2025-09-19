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

	// �� ������Ʈ ����
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComp"));
	ArrowComp = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComp"));
	CharMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharMesh"));
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));

	/// ���� �ǵ��� �̰� ���� ����� �� ���Ƽ� �ּ�
	// MyMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));

	// ������� ����
	// this->SetRootComponent(CapsuleComp); // ��Ʈ�� ĸ����
	RootComponent = CapsuleComp;
	ArrowComp->SetupAttachment(CapsuleComp); // ȭ��ǥ
	CharMesh->SetupAttachment(CapsuleComp); // ���̷���
	SpringArmComp->SetupAttachment(CapsuleComp); // �������ϵ� ĸ����
	CameraComp->SetupAttachment(SpringArmComp); // ī�޶�� �������Ͽ�
	
	// ������ �ùķ���Ʈ ���� ���� <- ���� ����
	// CapsuleComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CapsuleComp->SetSimulatePhysics(false);
	CharMesh->SetSimulatePhysics(false);

	// ��Ʈ�ѷ��� ȸ���� ���󰡵��� ����
	// SpringArmComp->bUsePawnControlRotation = true;

	// ��Ʈ�ѷ� ȸ�� �� ���
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

	/// ���ӵ��� ���� �̵� �ӵ��� ��ȭ�ǵ��� ��
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

	// �̵��� ���� �� �ణ�� �������� õõ�� �̲��������� �ϴ� ��� �߰�
	// �ٽ� move �Է��� ������ nokoriMove�� false������ ���� �̵� ���߾� �÷��̾� ���۰� ����ȭ
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
		/// �����̵��� ���� ���ø�Ƽ�� �߰�
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
		/// �ؿ��� �� ��
		//AddMovementInput(GetActorForwardVector(), MoveVector.Y * MoveSpeed);
		//AddMovementInput(GetActorRightVector(), MoveVector.X * MoveSpeed);
		// SetActorLocation(GetActorLocation() + (GetActorForwardVector() * MoveVector.Y + GetActorRightVector() * MoveVector.X) * MoveSpeed * GetWorld()->GetDeltaSeconds());

	}
}
void AReportPawn::MoveEnd(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Warning, TEXT("MoveEnd"));
	thisMove = false;

	/// ���ڸ� ���� ���� �� �ӵ� �ʱ�ȭ �ǵ��� ��
	// NowMoveSpeed = MinMoveSpeed;

	// ƽ���� ���ڸ� ���� ����
	nokoriMove = true;
}

void AReportPawn::Look(const FInputActionValue& Value)
{
	// if (!IsValid(CameraComp)) return;
	
	FVector2D LookAxis = Value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look Input: X=%f, Y=%f"), LookAxis.X, LookAxis.Y);

		//SpringArmComp->AddLocalRotation(FQuat(FRotator(0, LookAxis.X, 0))); // �¿�
		//SpringArmComp->AddLocalRotation(FQuat(FRotator(LookAxis.Y, 0, 0))); // ���Ʒ�

		// Y��(Yaw) ȸ���� Pawn�� ȸ������
		
		//FRotator CameraWorldRotation = SpringArmComp->GetComponentRotation();
		//FRotator NewPawnRotation = FRotator(0.0f, CameraWorldRotation.Yaw, 0.0f);
		//SetActorRotation(NewPawnRotation);


		// X��(Pitch) ȸ���� ī�޶� ȸ�� ������ ����
		CameraPitch += LookAxis.Y * CameraPitchSpeed;

		// Pitch ���� �����Ͽ� ī�޶� �������� �ʵ���
		CameraPitch = FMath::Clamp(CameraPitch, -80.0f, 80.0f);

		// CameraYaw += LookAxis.X * CameraYawSpeed;
		// Yaw���� ī�޶� ������ ���� Pawn ��ü�� �����°� �� �ڿ�������
		AddActorLocalRotation(FRotator(0.0f, LookAxis.X * CameraYawSpeed, 0.0f));

		if (IsValid(SpringArmComp))
		{
			// FRotator NewSpringArmRotation = FRotator(CameraPitch* DeltaTime, CameraYaw* DeltaTime, 0.0f);
			// FRotator NewSpringArmRotation = FRotator(CameraPitch, CameraYaw, 0.0f);
			FRotator NewSpringArmRotation = FRotator(CameraPitch, 0.f, 0.0f); // Yaw�� Pawn ȸ������ ó���ϹǷ� 0���� ����
			SpringArmComp->SetRelativeRotation(NewSpringArmRotation);
		}


		/// �̰� �� ��
		// SpringArmComp->AddActorLocalRotation(FQuat(FRotator(0, LookAxis.X, 0)));
		//AddControllerYawInput(LookAxis.X);
		//AddControllerPitchInput(LookAxis.Y * -1);

	}
}