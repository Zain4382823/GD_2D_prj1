// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

