#include "Core/MyPlayerController.h"
#include "Core/MyCharacter.h"

AMyPlayerController::AMyPlayerController() {
	bShowMouseCursor = false;
	PrimaryActorTick.bCanEverTick = true;
}

void AMyPlayerController::BeginPlay() {
	Super::BeginPlay();

	_myCharacter = Cast<AMyCharacter>(GetPawn());
}

void AMyPlayerController::SetupInputComponent() {
	Super::SetupInputComponent();

	InputComponent->BindAction("MoveForward", IE_Pressed, this, &AMyPlayerController::onWPressed);
	InputComponent->BindAction("MoveForward", IE_Released, this, &AMyPlayerController::onWReleased);

	InputComponent->BindAction("MoveBackward", IE_Pressed, this, &AMyPlayerController::onSPressed);
	InputComponent->BindAction("MoveBackward", IE_Released, this, &AMyPlayerController::onSReleased);

	InputComponent->BindAction("MoveLeft", IE_Pressed, this, &AMyPlayerController::onAPressed);
	InputComponent->BindAction("MoveLeft", IE_Released, this, &AMyPlayerController::onAReleased);

	InputComponent->BindAction("MoveRight", IE_Pressed, this, &AMyPlayerController::onDPressed);
	InputComponent->BindAction("MoveRight", IE_Released, this, &AMyPlayerController::onDReleased);
}

void AMyPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (!_myCharacter) {
		_myCharacter = Cast<AMyCharacter>(GetPawn());
	}

	if (!_myCharacter) {
		return;
	}

	if (_bWPressed) {
		_myCharacter->setPlayerPosX(_myCharacter ->playerPosX() + _myCharacter->playerMoveSpeed());
	}

	if (_bSPressed) {
		_myCharacter->setPlayerPosX(_myCharacter->playerPosX() - _myCharacter->playerMoveSpeed());
	}

	if (_bAPressed) {
		_myCharacter->setPlayerPosY(_myCharacter->playerPosY() - _myCharacter->playerMoveSpeed());
	}

	if (_bDPressed) {
		_myCharacter->setPlayerPosY(_myCharacter->playerPosY() + _myCharacter->playerMoveSpeed());
	}
}

void AMyPlayerController::onWPressed() {
	_bWPressed = true;
}

void AMyPlayerController::onWReleased() {
	_bWPressed = false;
}

void AMyPlayerController::onSPressed() {
	_bSPressed = true;
}

void AMyPlayerController::onSReleased() {
	_bSPressed = false;
}

void AMyPlayerController::onAPressed() {
	_bAPressed = true;
}

void AMyPlayerController::onAReleased() {
	_bAPressed = false;
}

void AMyPlayerController::onDPressed() {
	_bDPressed = true;
}

void AMyPlayerController::onDReleased() {
	_bDPressed = false;
}

// get functions
void AMyPlayerController::setMyCharacter(AMyCharacter* myCharacter) {
	_myCharacter = myCharacter;
}

// set functions