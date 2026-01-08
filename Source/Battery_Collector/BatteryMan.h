#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

#include "Blueprint/UserWidget.h"

#include "BatteryMan.generated.h"

UCLASS()
class BATTERY_COLLECTOR_API ABatteryMan : public ACharacter
{
	GENERATED_BODY()

public:
	
	ABatteryMan();
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly ,Category=Camera)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category=Camera)
	UCameraComponent* FollowCamera;

	void MoveForward(float Axis);
	void MoveRight(float Axis);
	bool bDead;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	float Power;

	UPROPERTY(EditAnywhere)
	float Power_Treshold;

	UFUNCTION()
	void OnBeginOverlap(class UPrimitiveComponent* HitComp,
		class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere,Category="UI HUD")
	    TSubclassOf<UUserWidget> Player_Power_Widget_Class;
		UUserWidget* Player_Power_Widget;

	void RestartGame();

protected:
	
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
