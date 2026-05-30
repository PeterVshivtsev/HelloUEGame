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
	float _playerMoveSpeed = 2000.0f;

	float _defaultPlayerPosX = 0.0f;
	float _defaultPlayerPosY = 0.0f;

	float _deltaTime = 0.0f;

public:
	AMyCharacter();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputMappingContext* _DefaultMappingContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	class UInputAction* _MoveForwardAction;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* _FirstPersonCamera;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void movePlayerManager();
	void movePlayerForward();
	void movePlayerBackward();
	void movePlayerRight();
	void movePlayerLeft();

	void characterLogInfo();

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
