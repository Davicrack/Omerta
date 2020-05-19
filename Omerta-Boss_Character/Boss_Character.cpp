// Fill out your copyright notice in the Description page of Project Settings.


#include "Boss_Character.h"
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine.h"
#include <iostream>
#include <string>
// Sets default values
ABoss_Character::ABoss_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MaxHealth = 1000;
	Health = MaxHealth;
	TailHealth = 50;
	HeadHealth = 50;
	WingHealth = 50;
	ArmHealth = 50;
	extraDamageTail = false;
	extraDamageHead = false;
	extraDamageWing = false;
	extraDamageArm = false;
}





// Called when the game starts or when spawned
void ABoss_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoss_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABoss_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
}

void ABoss_Character::OnDestroy() //creo esta funcion por si quiero hacer algo antes de destruir al boss (cinematica, sonido...)
{
	Destroy();
}

float ABoss_Character::getMaxHealth()
{
	return MaxHealth;
}

float ABoss_Character::getCurrentHealth()
{
	return Health;
}

float ABoss_Character::getTailHealth()
{
	return TailHealth;
}

float ABoss_Character::getHeadHealth()
{
	return HeadHealth;
}


float ABoss_Character::getWingHealth()
{
	return WingHealth;
}

float ABoss_Character::getArmHealth()
{
	return ArmHealth;
}

void ABoss_Character::DamageTarget(float Damage)
{
	Health -= Damage;

	if (Health <= 0) {
		OnDestroy();
	}
}

void ABoss_Character::DamageHead(float Damage)
{
	Health -= Damage;
	HeadHealth -= Damage;
	if (HeadHealth <= 0 && !extraDamageHead) {
		extraDamageHead = true;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("EXTRA 200 Damage ->HEAD"));
		Health -= 200;
	}
	if (Health <= 0) {
		OnDestroy();
	}
}

void ABoss_Character::DamageTail(float Damage)
{
	Health -= Damage;
	TailHealth -= Damage;
	if (TailHealth <= 0 && !extraDamageTail) {
		extraDamageTail = true;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("EXTRA 200 Damage ->TAIL"));
		Health -= 200;
	}
	if (Health <= 0) {
		OnDestroy();
	}
}

void ABoss_Character::DamageArm(float Damage)
{
	Health -= Damage;
	ArmHealth -= Damage;
	if (ArmHealth <= 0 && !extraDamageArm) {
		extraDamageArm = true;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("EXTRA 200 Damage ->ARM"));
		Health -= 200;
	}
	if (Health <= 0) {
		OnDestroy();
	}
}

void ABoss_Character::DamageWing(float Damage)
{
	Health -= Damage;
	WingHealth -= Damage;
	if (WingHealth<=0 && !extraDamageWing) {
		extraDamageWing = true;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("EXTRA 200 Damage ->WING"));
		Health -= 200;
	}
	if (Health <= 0) {
		OnDestroy();
	}
}
