// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Camera/PlayerCameraManager.h"
#include "TankPlayerController.generated.h" // Must be the last include

// Forward Declaration
class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override; //overide because beginplay already exists somewhere else in maybe /Engine/Source/Runtime/Engine/Classes/GameFramework/Actor.h and other places .
										//so override allows us to extend the functionality of the beginplay method 

	virtual void Tick(float DeltaTime) override;

private:

// Start the tank moving the barrel so that a shot would hit where
// the crosshair intersects the world
	void AimTowardsCrosshair();

// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;

UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.3333;

UPROPERTY(EditAnywhere)
float LineTraceRange = 1000000;


bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
