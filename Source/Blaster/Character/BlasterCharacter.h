// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blaster/BlasterTypes/TurningInPlace.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "BlasterCharacter.generated.h"

class AWeapon;
UCLASS()
class BLASTER_API ABlasterCharacter : public ACharacter
{

	
public:

private:
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABlasterCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostInitializeComponents() override;

	FORCEINLINE float GetAO_YAW() const { return AO_Yaw; } 
	FORCEINLINE float GetAO_Pitch() const { return AO_Pitch; }
	AWeapon* GetEquippedWeapon();
	void PlayFireMontage(bool bAiming);
	void FastFly();

	UPROPERTY(EditAnywhere)
	bool bFastFlying; 
	
	FORCEINLINE bool GetFastFlying() const {return bFastFlying;}

private:
	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent *CameraBoom;

	UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UWidgetComponent* OverheadWidget;

	UPROPERTY(ReplicatedUsing= OnRep_OverlappingWeapon)
	class AWeapon* OverlappingWeapon;

	UFUNCTION()
	void OnRep_OverlappingWeapon(AWeapon* LastWeapon);

	UPROPERTY(VisibleAnywhere)
	class UCombatComponent* Combat;

	UFUNCTION(Server, Reliable)
	void ServerEquipButtonPressed();

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void EquipButtonPressed();
	void CrouchButtonPressed();
	void AimButtonPressed();
	void AimButtonReleased();
	void FireButtonPressed();
	void FireButtonReleased();
	
	
	UFUNCTION()
	void AimOffset(float DeltaTime);
	

public:

	void SetOverlappingWeapon(AWeapon* Weapon);
	bool IsWeaponEquipped();
	bool IsAiming();
	
    float AO_Yaw;
	float InterpAO_Yaw;
    float AO_Pitch;
    FRotator StartingAimRotation;

	ETurningInPlace TurningInPlace;
	FORCEINLINE ETurningInPlace GetTurningInPlace() const {return TurningInPlace;}
	void TurnInPlace(float DeltaTime);
	
	UPROPERTY(EditAnywhere, Category="Combat")
	class UAnimMontage* FireWeaponMontage;

	
	
};
