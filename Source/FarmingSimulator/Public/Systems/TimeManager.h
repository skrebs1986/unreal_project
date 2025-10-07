// Copyright Epic Games, Inc. All Rights Reserved.
// Farming Simulator - Time Management System

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeManager.generated.h"

/** Season enum */
UENUM(BlueprintType)
enum class ESeason : uint8
{
	Spring UMETA(DisplayName = "Spring"),
	Summer UMETA(DisplayName = "Summer"),
	Fall UMETA(DisplayName = "Fall"),
	Winter UMETA(DisplayName = "Winter")
};

/** Delegates for time events */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDayChanged, int32, NewDay);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSeasonChanged, ESeason, NewSeason);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHourChanged, int32, NewHour);

/**
 * Time Manager
 * Handles day/night cycle, season progression, and time-based events
 */
UCLASS()
class FARMINGSIMULATOR_API ATimeManager : public AActor
{
	GENERATED_BODY()

public:
	ATimeManager();

	//~ Begin AActor Interface
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	//~ End AActor Interface

	// ========================================
	// Time Properties
	// ========================================

	/** Current time in game hours (0.0 - 24.0) */
	UPROPERTY(BlueprintReadOnly, Category = "Time")
	float CurrentGameHour;

	/** Current day number (1-based) */
	UPROPERTY(BlueprintReadOnly, Category = "Time")
	int32 CurrentDay;

	/** Current season */
	UPROPERTY(BlueprintReadOnly, Category = "Time")
	ESeason CurrentSeason;

	/** How many game seconds pass per real-world second (default: 60 = 1 real second = 1 game minute) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time", meta = (ClampMin = "0.1", ClampMax = "3600.0"))
	float TimeScale;

	/** Days per season */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Time")
	int32 DaysPerSeason;

	// ========================================
	// Events
	// ========================================

	/** Called when a new day starts (at midnight) */
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnDayChanged OnDayChanged;

	/** Called when season changes */
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnSeasonChanged OnSeasonChanged;

	/** Called every game hour */
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnHourChanged OnHourChanged;

	// ========================================
	// Public Functions
	// ========================================

	/** Set the time scale (how fast time passes) */
	UFUNCTION(BlueprintCallable, Category = "Time")
	void SetTimeScale(float NewScale);

	/** Set the current time directly */
	UFUNCTION(BlueprintCallable, Category = "Time")
	void SetTime(int32 Day, float Hour, ESeason Season);

	/** Advance time by a number of game hours */
	UFUNCTION(BlueprintCallable, Category = "Time")
	void AdvanceTime(float Hours);

	/** Get formatted time string (e.g., "08:30 AM") */
	UFUNCTION(BlueprintPure, Category = "Time")
	FString GetFormattedTime() const;

	/** Get formatted date string (e.g., "Spring Day 15") */
	UFUNCTION(BlueprintPure, Category = "Time")
	FString GetFormattedDate() const;

	/** Get current hour as integer (0-23) */
	UFUNCTION(BlueprintPure, Category = "Time")
	int32 GetCurrentHour() const;

	/** Get current minute (0-59) */
	UFUNCTION(BlueprintPure, Category = "Time")
	int32 GetCurrentMinute() const;

	/** Check if it's currently daytime */
	UFUNCTION(BlueprintPure, Category = "Time")
	bool IsDaytime() const;

	/** Get sun angle for current time (0-360 degrees) */
	UFUNCTION(BlueprintPure, Category = "Time")
	float GetSunAngle() const;

	/** Pause/unpause time progression */
	UFUNCTION(BlueprintCallable, Category = "Time")
	void SetTimePaused(bool bPaused);

	/** Check if time is paused */
	UFUNCTION(BlueprintPure, Category = "Time")
	bool IsTimePaused() const { return bTimePaused; }

protected:
	/** Update sun position and lighting based on time */
	void UpdateSunPosition();

	/** Update sky colors based on time of day */
	void UpdateSkyColors();

	/** Check for time-based events (day change, season change, etc.) */
	void CheckTimeEvents();

	/** Directional Light (sun) reference */
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Lighting")
	TObjectPtr<class ADirectionalLight> SunLight;

	/** Sky Light reference */
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Lighting")
	TObjectPtr<class ASkyLight> SkyLightActor;

	/** Hour at which day starts */
	UPROPERTY(EditDefaultsOnly, Category = "Time")
	float DayStartHour;

	/** Hour at which night starts */
	UPROPERTY(EditDefaultsOnly, Category = "Time")
	float NightStartHour;

private:
	/** Is time progression paused? */
	bool bTimePaused;

	/** Last hour value (for detecting hour changes) */
	int32 LastHour;

	/** Last day value (for detecting day changes) */
	int32 LastDay;

	/** Last season value (for detecting season changes) */
	ESeason LastSeason;
};
