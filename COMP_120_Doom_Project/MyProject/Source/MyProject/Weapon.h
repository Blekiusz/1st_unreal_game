// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class MYPROJECT_API AWeapon : public AActor
{
	GENERATED_BODY()

	UPROPERTY(Category = DoomCharacter, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* weaponMesh;

	UPROPERTY(Category = DoomCharacter, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UPointLightComponent* weaponLight;

public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponSettings)
		float rateOfFire = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponSettings)
		float maxAmmo = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponSettings)
		float currentAmmo = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponSettings)
		bool isSemiAuto = false;
	
protected:
	virtual void OnWeaponShoot();

private:
	float nextFire = -1;

public:
	bool Shoot();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Weapon Shoot"))
		void BPEVENT_OnWeaponShoot();
};
