// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// Create the flipbook components
	IdleAnimation = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("IdleAnimation"));
	WalkAnimation = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("WalkAnimation"));
	AttackAnimation = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("AttackAnimation"));
	DieAnimation = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("DieAnimation"));

	// Attach the flipbook components to the root component
	RootComponent = IdleAnimation;
	WalkAnimation->SetupAttachment(RootComponent);
	AttackAnimation->SetupAttachment(RootComponent);
	DieAnimation->SetupAttachment(RootComponent);

	// Create the collider component
	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("ColliderComponent"));
	Collider->SetupAttachment(RootComponent);

	Collider->SetBoxExtent(FVector(8.0f, 8.0f, 8.0f)); // Set the size of the box collider
	Collider->SetCollisionProfileName(TEXT("BlockAll")); // Set the collision profile

    // Initialize the current state
    CurrentState = EEnemyState::Idle;

    // Initialize example variables
    Health = 50.0f; // Example health value

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





    SetAnimationState(EEnemyState::Idle);

    // Example logic to update the animation state
    //if (/* condition for walking */)
    //{
    //    SetAnimationState(EEnemyState::Walking);
    //}
    //else if (/* condition for attacking */)
    //{
    //    SetAnimationState(EEnemyState::Attacking);
    //}
    //else if (Health <= 0.0f)
    //{
    //    SetAnimationState(EEnemyState::Dying);
    //}
    //else
    //{
    //    SetAnimationState(EEnemyState::Idle);
    //}

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemy::SetAnimationState(EEnemyState NewState)
{
    switch (NewState)
    {
    case EEnemyState::Idle:
        IdleAnimation->SetVisibility(true);
        WalkAnimation->SetVisibility(false);
        AttackAnimation->SetVisibility(false);
        DieAnimation->SetVisibility(false);
        break;
    case EEnemyState::Walking:
        IdleAnimation->SetVisibility(false);
        WalkAnimation->SetVisibility(true);
        AttackAnimation->SetVisibility(false);
        DieAnimation->SetVisibility(false);
        break;
    case EEnemyState::Attacking:
        IdleAnimation->SetVisibility(false);
        WalkAnimation->SetVisibility(false);
        AttackAnimation->SetVisibility(true);
        DieAnimation->SetVisibility(false);
        break;
    case EEnemyState::Dying:
        IdleAnimation->SetVisibility(false);
        WalkAnimation->SetVisibility(false);
        AttackAnimation->SetVisibility(false);
        DieAnimation->SetVisibility(true);
        break;
    }
}

