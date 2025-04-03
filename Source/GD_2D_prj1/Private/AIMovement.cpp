// Fill out your copyright notice in the Description page of Project Settings.


#include "AIMovement.h"

// Sets default values for this component's properties
UAIMovement::UAIMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	CurrentPatrolNodeIndex = 0; // track our current node

	
}


// Called when the game starts
void UAIMovement::BeginPlay()
{
	Super::BeginPlay();

	OwnerPawn = Cast<AEnemy>(GetOwner());
	if (!OwnerPawn) // if the owner of this component is null
	{
		UE_LOG(LogTemp, Error, TEXT("AIMovementComponent can only be attached to a Pawn."));
		this->DestroyComponent();
	}
	
	
}


// Called every frame
void UAIMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UAIMovement::MoveToNextPatrolNode()
{
	// If we have no patrol nodes, return
	if (PatrolNodes.Num() == 0)
	{
		return;
	}
	else if (PatrolNodes.Num() == 1) // If we have only one patrol node, set the owner's location to that node's location
	{
		OwnerPawn->SetActorLocation(PatrolNodes[0]->GetActorLocation());
		return;
	}

	if (OwnerPawn->GetActorLocation().X > PatrolNodes[CurrentPatrolNodeIndex]->GetActorLocation().X) // are we moving left or right?
	{
		// move left
	}
	else
	{
		// move right
	}

	// check if we have reached the patrol node

}


