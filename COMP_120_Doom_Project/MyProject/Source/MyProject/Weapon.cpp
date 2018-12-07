// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PointLightComponent.h"
#include "Engine/World.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USceneComponent* sceneComp = CreateDefaultSubobject<USceneComponent>("ROOT");

	SetRootComponent(sceneComp);

	weaponMesh = CreateDefaultSubobject<UStaticMeshComponent>("WEAPON_MESH");

	weaponMesh->SetupAttachment(GetRootComponent());

	weaponLight = CreateDefaultSubobject<UPointLightComponent>("WEAPON_MESH");

	weaponLight->SetupAttachment(GetRootComponent());
	weaponLight->SetHiddenInGame(true);
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

