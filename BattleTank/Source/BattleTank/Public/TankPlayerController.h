// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	//Start the tank moving the barrel towards the aim point intersects the world
	void AimTowardsCrosshair();

	//Return an Out parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	
	//Returns current start of reach line
	FVector GetAimLineStart();

	//Returns current end of reach line
	FVector GetAimLineEnd();

	


};
