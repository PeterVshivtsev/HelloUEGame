#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "MyCharacter.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class UNREAL_TEST_01_API AMyCharacter : public ACharacter {
	GENERATED_BODY()

private:
	float _playerPosX = 0.0f;
	float _playerPosY = 0.0f;
	float _playerMoveSpeed = 10.0f;

	float _defaultPlayerPosX = 0.0f;
	float _defaultPlayerPosY = 0.0f;

public:
	AMyCharacter();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputAction* MoveForwardAction;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void movePlayerManager();

	// get
	float playerPosX() const;
	float playerPosY() const;
	float defaultPlayerPosX() const;
	float defaultPlayerPosY() const;
	float playerMoveSpeed() const;

	// set
	void setPlayerPosX(float value);
	void setPlayerPosY(float value);

};
