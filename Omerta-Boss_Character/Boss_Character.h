// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Boss_Character.generated.h"

UCLASS()
class PROJECTE_OMERTA_API ABoss_Character : public ACharacter
{
	GENERATED_BODY()

public:
	bool extraDamageTail;
	bool extraDamageHead;
	bool extraDamageWing;
	bool extraDamageArm;
	// Sets default values for this character's properties
	ABoss_Character();
	/*Funcion que llamamos cuando la vida del target llega a 0 o menos de 0*/
	void OnDestroy();
	/*Funciones para acceder a la vida del boss*/
	UFUNCTION(BlueprintPure, Category = "Health")
		float getMaxHealth();

	UFUNCTION(BlueprintPure, Category = "Health")
		float getCurrentHealth();

	UFUNCTION(BlueprintPure, Category = "Health")
		float getTailHealth();

	UFUNCTION(BlueprintPure, Category = "Health")
		float getHeadHealth();

	UFUNCTION(BlueprintPure, Category = "Health")
		float getWingHealth();

	UFUNCTION(BlueprintPure, Category = "Health")
		float getArmHealth();
	/*Aquesta funcio se li pasa un parametre i treu vida a el target param mostra el missatge al blueprint
	* @param Damage es el total de vida que el boss guanya o perd [valor negatiu per a sumar vida].
	*/
	UFUNCTION(BlueprintCallable, Category = "Health")
		void DamageTarget(float Damage);

	UFUNCTION(BlueprintCallable, Category = "Health")
		void DamageHead(float Damage);

	UFUNCTION(BlueprintCallable, Category = "Health")
		void DamageTail(float Damage);

	UFUNCTION(BlueprintCallable, Category = "Health")
		void DamageArm(float Damage);

	UFUNCTION(BlueprintCallable, Category = "Health")
		void DamageWing(float Damage);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	   	 	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	/*Vida del boss*/
	UPROPERTY(EditAnywhere, Category = "Health")
	float Health;

	UPROPERTY(EditAnywhere, Category = "Health")
	float MaxHealth;

	UPROPERTY(EditAnywhere, Category = "Health")
	float TailHealth;

	UPROPERTY(EditAnywhere, Category = "Health")
	float HeadHealth;

	UPROPERTY(EditAnywhere, Category = "Health")
	float WingHealth;

	UPROPERTY(EditAnywhere, Category = "Health")
	float ArmHealth;

};
