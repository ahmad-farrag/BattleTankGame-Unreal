// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Camera/PlayerCameraManager.h"
#include "TankPlayerController.generated.h" // Must be the last include

// Forward Declaration

class UTankTankAimingComponent;

/**
 *
 * Responsible for helping the player aim.
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override; //overide because beginplay already exists somewhere else in maybe /Engine/Source/Runtime/Engine/Classes/GameFramework/Actor.h and other places .
										//so override allows us to extend the functionality of the beginplay method 

	virtual void Tick(float DeltaTime) override;


protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:

// Start the tank moving the barrel so that a shot would hit where
// the crosshair intersects the world
	void AimTowardsCrosshair();

// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;

UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333;

UPROPERTY(EditDefaultsOnly)
float LineTraceRange = 1000000;


bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
