// Copyright Epic Games, Inc. All Rights Reserved.
// Farming Simulator - Game Mode

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FSGameMode.generated.h"

class ATimeManager;
class AWeatherManager;
class AFieldManager;
class UEconomyManager;

/**
 * Main Game Mode for Farming Simulator
 * Manages core game systems and spawns system managers
 */
UCLASS()
class FARMINGSIMULATOR_API AFSGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFSGameMode();

	//~ Begin AActor Interface
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	//~ End AActor Interface

	// System Managers
	UPROPERTY(BlueprintReadOnly, Category = "Systems")
	TObjectPtr<ATimeManager> TimeManager;

	UPROPERTY(BlueprintReadOnly, Category = "Systems")
	TObjectPtr<AWeatherManager> WeatherManager;

	UPROPERTY(BlueprintReadOnly, Category = "Systems")
	TObjectPtr<AFieldManager> FieldManager;

	UPROPERTY(BlueprintReadOnly, Category = "Systems")
	TObjectPtr<UEconomyManager> EconomyManager;

	/** Get the singleton game mode instance */
	UFUNCTION(BlueprintPure, Category = "Game", meta = (WorldContext = "WorldContextObject"))
	static AFSGameMode* GetFSGameMode(const UObject* WorldContextObject);

protected:
	/** Spawn and initialize all system managers */
	virtual void InitializeSystemManagers();

	/** Classes to use for system managers (can be overridden in Blueprints) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Systems")
	TSubclassOf<ATimeManager> TimeManagerClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Systems")
	TSubclassOf<AWeatherManager> WeatherManagerClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Systems")
	TSubclassOf<AFieldManager> FieldManagerClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Systems")
	TSubclassOf<UEconomyManager> EconomyManagerClass;
};
