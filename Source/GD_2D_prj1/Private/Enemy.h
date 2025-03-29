// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PaperSpriteComponent.h"
#include "PaperFlipbookComponent.h"
#include "Components/BoxComponent.h"
#include "Enemy.generated.h"


//Enum for animation states
UENUM(BlueprintType)
enum class EEnemyState : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	Walking UMETA(DisplayName = "Walking"),
	Attacking UMETA(DisplayName = "Attacking"),
	Dying UMETA(DisplayName = "Dying")
};


UCLASS()
class AEnemy : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	// The animation to play while the enemy is idle (standing still)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visuals")
	UPaperFlipbookComponent* IdleAnimation;

	// The animation to play while the enemy walks around
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visuals")
	UPaperFlipbookComponent* WalkAnimation;

	// The animation to play while the enemy attacks
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visuals")
	UPaperFlipbookComponent* AttackAnimation;

	// The animation to play while the enemy dies
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visuals")
	UPaperFlipbookComponent* DieAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	UBoxComponent* Collider;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Function to set the animation state
    void SetAnimationState(EEnemyState NewState);


private:
	// Current state of the enemy
	EEnemyState CurrentState;
	float Health;

};
