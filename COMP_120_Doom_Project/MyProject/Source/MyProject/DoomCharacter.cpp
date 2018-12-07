// Fill out your copyright notice in the Description page of Project Settings.

#include "DoomCharacter.h"

#include "Components/InputComponent.h"
#include "Engine.h"


// Sets default values
ADoomCharacter::ADoomCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoomCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoomCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADoomCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ADoomCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Strafe", this, &ADoomCharacter::Strafe);
	PlayerInputComponent->BindAxis("Turn", this, &ADoomCharacter::Turn);
}

void ADoomCharacter::MoveForward(float scale)
{
	//GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::Red, "MOVE FORWARD!!!");
	AddMovementInput(GetActorForwardVector(), scale);
}

void ADoomCharacter::Strafe(float scale)
{
	//GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::Blue, "Strafe!!!");
	AddMovementInput(GetActorRightVector(), scale);
}

void ADoomCharacter::Turn(float scale)
{
	//GEngine->AddOnScreenDebugMessage(-1, 0.2f, FColor::Emerald, "TURN!!!");
	AddControllerYawInput(scale);
}

