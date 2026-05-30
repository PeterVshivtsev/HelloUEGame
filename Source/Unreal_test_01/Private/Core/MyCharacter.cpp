#include "Core/MyCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AMyCharacter::AMyCharacter() {
	PrimaryActorTick.bCanEverTick = true;

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
}

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMyCharacter::movePlayerManager() {

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