#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameMode.generated.h"

class AMyCharacter;
class AMyPlayerController;

UCLASS()
class UNREAL_TEST_01_API AMyGameMode : public AGameModeBase {
	GENERATED_BODY()

public:
	AMyGameMode();

	// get-set
	AMyCharacter* myCharacter();
	AMyPlayerController* myPlayerController();
};
