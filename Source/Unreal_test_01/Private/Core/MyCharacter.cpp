#include "Core/MyCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


AMyCharacter::AMyCharacter() {
	PrimaryActorTick.bCanEverTick = true;

	_FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	_FirstPersonCamera->SetupAttachment(GetCapsuleComponent());
	_FirstPersonCamera->SetRelativeLocation(FVector(0.0f, 0.0f, 64.0f));
	_FirstPersonCamera->bUsePawnControlRotation = true;

	_playerPosX = _defaultPlayerPosX;
	_playerPosY = _defaultPlayerPosY;
	
	FVector Location = GetActorLocation();
	Location.X = _playerPosX;
	Location.Y = _playerPosY;
	SetActorLocation(Location);
}

void AMyCharacter::BeginPlay() {
	Super::BeginPlay();
}

void AMyCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	_deltaTime = DeltaTime;
}

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::AddControllerPitchInput);
}

void AMyCharacter::movePlayerManager() {
	

}

void AMyCharacter::movePlayerForward() {
	FRotator CameraRotation = GetControlRotation();

	double YawRotationToDegrees = CameraRotation.Yaw;
	double YawRotationToRadians = FMath::DegreesToRadians(YawRotationToDegrees);
	double PitchRotationToDegrees = CameraRotation.Pitch;
	if ((PitchRotationToDegrees > 80.0 && PitchRotationToDegrees < 90.0) ||
		(PitchRotationToDegrees < 280.0 && PitchRotationToDegrees > 270.0)) {
		PitchRotationToDegrees = 80.0;
	}
	double PitchRotationToRadians = FMath::DegreesToRadians(PitchRotationToDegrees);

	FVector LocationPlayer = GetActorLocation();
	double rotateDistanceX = _playerMoveSpeed * _deltaTime * FMath::Cos(YawRotationToRadians) * FMath::Cos(PitchRotationToRadians);
	double rotateDistanceY = _playerMoveSpeed * _deltaTime * FMath::Sin(YawRotationToRadians) * FMath::Cos(PitchRotationToRadians);

	LocationPlayer.X = LocationPlayer.X + rotateDistanceX;
	LocationPlayer.Y = LocationPlayer.Y + rotateDistanceY;

	SetActorLocation(LocationPlayer);
}

void AMyCharacter::movePlayerBackward() {
	FRotator CameraRotation = GetControlRotation();

	double YawRotationToDegrees = CameraRotation.Yaw;
	double YawRotationToRadians = FMath::DegreesToRadians(YawRotationToDegrees);
	double PitchRotationToDegrees = CameraRotation.Pitch;
	if ((PitchRotationToDegrees > 80.0 && PitchRotationToDegrees < 90.0) ||
		(PitchRotationToDegrees < 280.0 && PitchRotationToDegrees > 270.0)) {
		PitchRotationToDegrees = 80.0;
	}
	double PitchRotationToRadians = FMath::DegreesToRadians(PitchRotationToDegrees);

	FVector LocationPlayer = GetActorLocation();
	double rotateDistanceX = _playerMoveSpeed * _deltaTime * FMath::Cos(YawRotationToRadians) * FMath::Cos(PitchRotationToRadians);
	double rotateDistanceY = _playerMoveSpeed * _deltaTime * FMath::Sin(YawRotationToRadians) * FMath::Cos(PitchRotationToRadians);

	LocationPlayer.X = LocationPlayer.X - rotateDistanceX;
	LocationPlayer.Y = LocationPlayer.Y - rotateDistanceY;

	SetActorLocation(LocationPlayer);
}

void AMyCharacter::movePlayerRight() {
	FRotator CameraRotation = GetControlRotation();

	double YawRotationToDegrees = CameraRotation.Yaw + 90.0;
	double YawRotationToRadians = FMath::DegreesToRadians(YawRotationToDegrees);
	double PitchRotationToDegrees = CameraRotation.Pitch;
	if ((PitchRotationToDegrees > 80.0 && PitchRotationToDegrees < 90.0) ||
		(PitchRotationToDegrees < 280.0 && PitchRotationToDegrees > 270.0)) {
		PitchRotationToDegrees = 80.0;
	}
	double PitchRotationToRadians = FMath::DegreesToRadians(PitchRotationToDegrees);

	FVector LocationPlayer = GetActorLocation();
	double rotateDistanceX = _playerMoveSpeed * _deltaTime * FMath::Cos(YawRotationToRadians) * FMath::Cos(PitchRotationToRadians);
	double rotateDistanceY = _playerMoveSpeed * _deltaTime * FMath::Sin(YawRotationToRadians) * FMath::Cos(PitchRotationToRadians);

	LocationPlayer.X = LocationPlayer.X + rotateDistanceX;
	LocationPlayer.Y = LocationPlayer.Y + rotateDistanceY;

	SetActorLocation(LocationPlayer);
}

void AMyCharacter::movePlayerLeft() {
	FRotator CameraRotation = GetControlRotation();

	double YawRotationToDegrees = CameraRotation.Yaw + 90.0;
	double YawRotationToRadians = FMath::DegreesToRadians(YawRotationToDegrees);
	double PitchRotationToDegrees = CameraRotation.Pitch;
	if ((PitchRotationToDegrees > 80.0 && PitchRotationToDegrees < 90.0) ||
		(PitchRotationToDegrees < 280.0 && PitchRotationToDegrees > 270.0)) {
		PitchRotationToDegrees = 80.0;
	}
	double PitchRotationToRadians = FMath::DegreesToRadians(PitchRotationToDegrees);

	FVector LocationPlayer = GetActorLocation();
	double rotateDistanceX = _playerMoveSpeed * _deltaTime * FMath::Cos(YawRotationToRadians) * FMath::Cos(PitchRotationToRadians);
	double rotateDistanceY = _playerMoveSpeed * _deltaTime * FMath::Sin(YawRotationToRadians) * FMath::Cos(PitchRotationToRadians);

	LocationPlayer.X = LocationPlayer.X - rotateDistanceX;
	LocationPlayer.Y = LocationPlayer.Y - rotateDistanceY;

	SetActorLocation(LocationPlayer);
}

void AMyCharacter::characterLogInfo() {
	FRotator CameraRotationLog = GetControlRotation();
	UE_LOG(LogTemp, Warning, TEXT("Camer rotation: %s"), *CameraRotationLog.ToString());

	FVector LocationPlayer = GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("Player position: %s"), *LocationPlayer.ToString());
}

// getters
float AMyCharacter::defaultPlayerPosX() const {
	return _defaultPlayerPosX;
}

float AMyCharacter::defaultPlayerPosY() const {
	return _defaultPlayerPosY;
}

float AMyCharacter::playerPosX() const {
	return _playerPosX;
}

float AMyCharacter::playerPosY() const {
	return _playerPosY;
}

float AMyCharacter::playerMoveSpeed() const {
	return _playerMoveSpeed;
}

// setters
void AMyCharacter::setPlayerPosX(float value) {
	_playerPosX = value;

	FVector Location = GetActorLocation();
	Location.X = _playerPosX;
	Location.Y = _playerPosY;
	SetActorLocation(Location);
}

void AMyCharacter::setPlayerPosY(float value) {
	_playerPosY = value;

	FVector Location = GetActorLocation();
	Location.X = _playerPosX;
	Location.Y = _playerPosY;
	SetActorLocation(Location);
}
