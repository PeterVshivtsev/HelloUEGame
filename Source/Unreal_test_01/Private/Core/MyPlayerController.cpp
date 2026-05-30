#include "Core/MyPlayerController.h"
#include "Core/MyCharacter.h"
#include "InputCoreTypes.h"

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


	InputComponent->BindKey(EKeys::I, IE_Pressed, _myCharacter, &AMyCharacter::characterLogInfo);
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
		_myCharacter->movePlayerForward();
	}

	if (_bSPressed) {
		_myCharacter->movePlayerBackward();
	}

	if (_bAPressed) {
		_myCharacter->movePlayerLeft();
	}

	if (_bDPressed) {
		_myCharacter->movePlayerRight();
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