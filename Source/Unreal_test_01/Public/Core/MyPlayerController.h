#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

class AMyCharacter;

UCLASS()
class UNREAL_TEST_01_API AMyPlayerController : public APlayerController {
	GENERATED_BODY()

private:
	AMyCharacter* _myCharacter = nullptr;

	bool _bWPressed = false;
	bool _bSPressed = false;
	bool _bAPressed = false;
	bool _bDPressed = false;

public:
	AMyPlayerController();

	virtual void Tick(float DeltaTime) override;

	void onWPressed();
	void onWReleased();
	void onSPressed();
	void onSReleased();
	void onAPressed();
	void onAReleased();
	void onDPressed();
	void onDReleased();

	// get-set
	void setMyCharacter(AMyCharacter* myCharacter);

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
};
