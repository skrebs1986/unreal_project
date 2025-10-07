// Copyright Epic Games, Inc. All Rights Reserved.
// Farming Simulator - Crop Data Asset

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Data/FSTypes.h"
#include "CropDataAsset.generated.h"

/**
 * Data Asset defining a crop type
 * Create Blueprint-based data assets from this for each crop variety
 */
UCLASS(BlueprintType)
class FARMINGSIMULATOR_API UCropDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	// ========================================
	// Basic Information
	// ========================================

	/** Display name of the crop */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Info")
	FText CropName;

	/** Description of the crop */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Info", meta = (MultiLine = true))
	FText Description;

	/** Icon for UI display */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Info")
	TObjectPtr<UTexture2D> Icon;

	/** Category (for shop filtering) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Info")
	FText Category; // e.g., "Grains", "Vegetables", "Root Crops"

	// ========================================
	// Growth Parameters
	// ========================================

	/** How many game days it takes to grow from seed to harvestable */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Growth", meta = (ClampMin = "1", ClampMax = "60"))
	int32 GrowthDurationDays = 7;

	/** Meshes for each growth stage (should be 4-5 meshes) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Growth")
	TArray<TObjectPtr<UStaticMesh>> GrowthStageMeshes;

	/** Materials for growth stages (optional, can tint health) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Growth")
	TArray<TObjectPtr<UMaterialInstance>> GrowthStageMaterials;

	/** Scale of the crop at each growth stage */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Growth")
	TArray<float> GrowthStageScales;

	/** Optimal season for planting (0=Spring, 1=Summer, 2=Fall, 3=Winter) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Growth")
	TArray<int32> OptimalPlantingSeasons;

	/** Can this crop survive winter? */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Growth")
	bool bWinterHardy = false;

	// ========================================
	// Requirements
	// ========================================

	/** Soil requirements for optimal growth */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Requirements")
	FSoilRequirements SoilRequirements;

	/** How much water this crop needs (0.0 = drought resistant, 1.0 = needs constant watering) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Requirements", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float WaterRequirement = 0.5f;

	/** How much nutrients this crop consumes from soil */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Requirements", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float NutrientConsumption = 0.5f;

	/** Does this crop require fertilizer to grow? */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Requirements")
	bool bRequiresFertilizer = false;

	/** Does this crop need irrigation system or can rely on rain? */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Requirements")
	bool bRequiresIrrigation = false;

	// ========================================
	// Yield & Economy
	// ========================================

	/** Base yield per plant in kg */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Economy", meta = (ClampMin = "0.1", ClampMax = "50.0"))
	float BaseYieldPerPlant = 1.0f;

	/** Yield multiplier if grown in optimal conditions (1.0 - 2.0) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Economy", meta = (ClampMin = "1.0", ClampMax = "2.0"))
	float OptimalConditionYieldBonus = 1.3f;

	/** Base sell price per kg */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Economy", meta = (ClampMin = "0.01", ClampMax = "100.0"))
	float BaseSellPrice = 0.30f;

	/** Cost of seeds per planting */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Economy", meta = (ClampMin = "0.01", ClampMax = "10.0"))
	float SeedCost = 0.10f;

	/** Market demand variance (how much price fluctuates) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Economy", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float PriceVolatility = 0.2f;

	// ========================================
	// Gameplay
	// ========================================

	/** Experience points gained when harvesting this crop */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gameplay")
	int32 HarvestXP = 5;

	/** Minimum player level to unlock this crop */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gameplay")
	int32 UnlockLevel = 1;

	/** Difficulty rating (1-5 stars) */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Gameplay", meta = (ClampMin = "1", ClampMax = "5"))
	int32 DifficultyRating = 1;

	// ========================================
	// Special Properties
	// ========================================

	/** Does this crop fix nitrogen in soil (like legumes)? */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Special")
	bool bNitrogenFixing = false;

	/** Can this crop be grown in greenhouse? */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Special")
	bool bGreenhouseCompatible = true;

	/** Can this crop spread disease to neighboring crops? */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Special")
	bool bDiseaseVector = false;

	// ========================================
	// Functions
	// ========================================

	/** Get the mesh for a specific growth stage */
	UFUNCTION(BlueprintPure, Category = "Crop")
	UStaticMesh* GetMeshForGrowthStage(ECropGrowthState GrowthState) const;

	/** Get the material for a specific growth stage */
	UFUNCTION(BlueprintPure, Category = "Crop")
	UMaterialInstance* GetMaterialForGrowthStage(ECropGrowthState GrowthState) const;

	/** Calculate expected yield based on conditions */
	UFUNCTION(BlueprintPure, Category = "Crop")
	float CalculateYield(float Health, const FSoilData& SoilData) const;

	/** Check if current season is optimal for planting */
	UFUNCTION(BlueprintPure, Category = "Crop")
	bool IsOptimalSeason(int32 CurrentSeason) const;

	/** Get crop quality based on health and conditions */
	UFUNCTION(BlueprintPure, Category = "Crop")
	ECropQuality DetermineQuality(float Health, const FSoilData& SoilData) const;

protected:
	/** Convert growth state enum to stage index */
	int32 GrowthStateToStageIndex(ECropGrowthState State) const;
};
