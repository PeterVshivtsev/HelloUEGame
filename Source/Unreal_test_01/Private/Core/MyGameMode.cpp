// MyGameMode.h
#include "Core/MyGameMode.h"
#include "Core/MyCharacter.h"
#include "Core/MyPlayerController.h"
#include "Kismet/GameplayStatics.h"

AMyGameMode::AMyGameMode() {
	DefaultPawnClass = AMyCharacter::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();
}

// get-set
AMyCharacter* AMyGameMode::myCharacter() {
	return Cast<AMyCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
}

AMyPlayerController* AMyGameMode::myPlayerController() {
	return Cast<AMyPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
}
