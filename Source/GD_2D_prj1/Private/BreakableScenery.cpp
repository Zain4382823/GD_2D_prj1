// Fill out your copyright notice in the Description page of Project Settings.


#include "BreakableScenery.h"

// Sets default values
ABreakableScenery::ABreakableScenery()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	// Create the sprite component
	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("SpriteComponent"));
	RootComponent = Sprite;

	// Create the collider component
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("ColliderComponent"));
	Collider->SetupAttachment(RootComponent);

	Collider->SetBoxExtent(FVector(8.0f, 8.0f, 8.0f)); // Set the size of the box collider
	Collider->SetCollisionProfileName(TEXT("BlockAll")); // Set the collision profile

}

// Called when the game starts or when spawned
void ABreakableScenery::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
/*void ABreakableScenery::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}*/

