// Copyright Epic Games, Inc. All Rights Reserved.
// Farming Simulator - Player Character

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FSCharacter.generated.h"

class UInventoryComponent;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * Player Character
 * Handles movement, camera, interaction, and inventory
 */
UCLASS()
class FARMINGSIMULATOR_API AFSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AFSCharacter();

	//~ Begin APawn Interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//~ End APawn Interface

	//~ Begin AActor Interface
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	//~ End AActor Interface

	// ========================================
	// Components
	// ========================================

	/** Camera boom positioning the camera behind character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FollowCamera;

	/** Inventory component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UInventoryComponent> InventoryComponent;

	// ========================================
	// Enhanced Input
	// ========================================

	/** Input Mapping Context */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> LookAction;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;

	/** Interact Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> InteractAction;

	/** Sprint Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputAction> SprintAction;

	// ========================================
	// Camera Settings
	// ========================================

	/** Camera distance from character */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float CameraDistance = 400.0f;

	/** Camera height offset */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float CameraHeight = 50.0f;

	/** Camera zoom speed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float ZoomSpeed = 50.0f;

	/** Minimum zoom distance */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float MinZoomDistance = 200.0f;

	/** Maximum zoom distance */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	float MaxZoomDistance = 800.0f;

	// ========================================
	// Movement Settings
	// ========================================

	/** Walk speed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float WalkSpeed = 300.0f;

	/** Run speed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float RunSpeed = 600.0f;

	/** Is character currently sprinting? */
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	bool bIsSprinting = false;

	// ========================================
	// Interaction
	// ========================================

	/** Maximum interaction distance */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	float InteractionDistance = 200.0f;

	/** Currently focused interactable actor */
	UPROPERTY(BlueprintReadOnly, Category = "Interaction")
	TObjectPtr<AActor> FocusedActor;

	/** Perform interaction with focused actor */
	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void Interact();

	/** Check for interactable objects in front of player */
	UFUNCTION(BlueprintCallable, Category = "Interaction")
	void UpdateInteractionTrace();

	// ========================================
	// State
	// ========================================

	/** Is player currently in a vehicle? */
	UPROPERTY(BlueprintReadOnly, Category = "State")
	bool bIsInVehicle = false;

	/** Current vehicle (if in one) */
	UPROPERTY(BlueprintReadOnly, Category = "State")
	TObjectPtr<APawn> CurrentVehicle;

	/** Enter a vehicle */
	UFUNCTION(BlueprintCallable, Category = "Vehicle")
	void EnterVehicle(APawn* Vehicle);

	/** Exit current vehicle */
	UFUNCTION(BlueprintCallable, Category = "Vehicle")
	void ExitVehicle();

	// ========================================
	// Accessors
	// ========================================

	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	FORCEINLINE UInventoryComponent* GetInventoryComponent() const { return InventoryComponent; }

protected:
	// ========================================
	// Input Callbacks
	// ========================================

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	/** Called when sprint is pressed */
	void StartSprinting();

	/** Called when sprint is released */
	void StopSprinting();

	/** Called when interact key is pressed */
	void OnInteract();

	// ========================================
	// Internal Functions
	// ========================================

	/** Update camera position based on settings */
	void UpdateCamera();

	/** Highlight focused actor for interaction feedback */
	void HighlightFocusedActor(AActor* Actor, bool bHighlight);
};
