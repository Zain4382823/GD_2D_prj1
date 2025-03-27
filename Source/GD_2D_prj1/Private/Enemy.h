// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"
#include "Enemy.generated.h"

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

	// the objects sprite
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visuals")
	UPaperSpriteComponent* Sprite;

	// The animation to play while the enemy is idle (standing still)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* EnemyIdleAnimation;

	// The animation to play while the enemy walks around
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* EnemyWalkAnimation;

	// The animation to play while the enemy attacks
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* EnemyAttackAnimation;

	// The animation to play while the enemy dies
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* EnemyDeathAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	UBoxComponent* Collider;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
