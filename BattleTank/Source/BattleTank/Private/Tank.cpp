// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component")); // No need to protect pointers as added at construction

}



void ATank::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}


// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void ATank::AimAt(FVector HitLocation)
{
	//auto OurTankName = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *OurTankName, *HitLocation.ToString());
	//The above 2 lines were moved to TankAimingComponent
	TankAimingComponent->AimAt(HitLocation);
}