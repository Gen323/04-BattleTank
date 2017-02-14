// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

//Tick
	// Super
	// AimTowardsCrosshair();

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));

	}

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin play"));

}

// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}



ATank* ATankPlayerController::GetControlledTank() const
{
	 return Cast<ATank>(GetPawn());

}




void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation;  // Out Parameter

	if (GetSightRayHitLocation(HitLocation))  // has side effect to line trace
	{

		
		//auto ComponentToHit = HitLocation.GetComponent(); // gets the mesh in our case
		//auto ActorHit = HitLocation.GetActor();

		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
		//TODO Tell controlled tank to aim at this point
	}
	

	


}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	return true;
	///Set up query parameters
	//FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	/// Line-trace (AKA ray-cast) out to reach distance
	//FHitLocation HitLocation;
	//GetWorld()->LineTraceSingleByObjectType(
		//HitLocation, //Out
		//GetAimLineStart(),
		//GetAimLineEnd(),
		//FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		//TraceParameters
	//);
	/// See what we hit
	/*AActor* ActorHit = HitLocation.GetActor();
	if (ActorHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Line Trace Hit: %s"),
			*ActorHit->GetName()
		);
	}
	return HitLocation;*/
}

//FVector ATankPlayerController::GetAimLineEnd()
//{
//	FVector PlayerAimPointLocation;
//	FRotator PlayerAimPointRotation;
//	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
//		PlayerAimPointLocation, //Out
//		PlayerAimPointRotation //Out
//	);
//
//	return (PlayerAimPointLocation + PlayerAimPointRotation.Vector() * 10000);
//};
//
//FVector ATankPlayerController::GetAimLineStart()
//{
//	FVector PlayerAimPointLocation;
//	FRotator PlayerAimPointRotation;
//	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
//		PlayerAimPointLocation, //Out
//		PlayerAimPointRotation  //Out
//	);
//
//	return PlayerAimPointLocation;
//};