// Copyright Epic Games, Inc. All Rights Reserved.
// Farming Simulator - Common Types and Structures

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FSTypes.generated.h"

// ========================================
// Forward Declarations
// ========================================
class UCropDataAsset;

// ========================================
// Enums
// ========================================

/** Crop growth states */
UENUM(BlueprintType)
enum class ECropGrowthState : uint8
{
	NotPlanted UMETA(DisplayName = "Not Planted"),
	Seedling UMETA(DisplayName = "Seedling"),
	Growing UMETA(DisplayName = "Growing"),
	Mature UMETA(DisplayName = "Mature"),
	Harvestable UMETA(DisplayName = "Harvestable"),
	Withered UMETA(DisplayName = "Withered")
};

/** Field preparation states */
UENUM(BlueprintType)
enum class EFieldState : uint8
{
	Untilled UMETA(DisplayName = "Untilled"),
	Plowed UMETA(DisplayName = "Plowed"),
	Cultivated UMETA(DisplayName = "Cultivated"),
	Fertilized UMETA(DisplayName = "Fertilized"),
	Ready UMETA(DisplayName = "Ready for Planting")
};

/** Weather types */
UENUM(BlueprintType)
enum class EWeatherState : uint8
{
	Clear UMETA(DisplayName = "Clear"),
	Cloudy UMETA(DisplayName = "Cloudy"),
	LightRain UMETA(DisplayName = "Light Rain"),
	HeavyRain UMETA(DisplayName = "Heavy Rain"),
	Storm UMETA(DisplayName = "Storm"),
	Snow UMETA(DisplayName = "Snow"),
	Fog UMETA(DisplayName = "Fog")
};

/** Equipment types */
UENUM(BlueprintType)
enum class EEquipmentType : uint8
{
	Tractor UMETA(DisplayName = "Tractor"),
	Plow UMETA(DisplayName = "Plow"),
	Seeder UMETA(DisplayName = "Seeder"),
	Harvester UMETA(DisplayName = "Harvester"),
	Sprayer UMETA(DisplayName = "Sprayer"),
	Cultivator UMETA(DisplayName = "Cultivator"),
	HandTool UMETA(DisplayName = "Hand Tool")
};

/** Crop quality grades */
UENUM(BlueprintType)
enum class ECropQuality : uint8
{
	Premium UMETA(DisplayName = "Premium"),
	GradeA UMETA(DisplayName = "Grade A"),
	GradeB UMETA(DisplayName = "Grade B"),
	GradeC UMETA(DisplayName = "Grade C"),
	Waste UMETA(DisplayName = "Waste")
};

// ========================================
// Structures
// ========================================

/** Soil quality data */
USTRUCT(BlueprintType)
struct FSoilData
{
	GENERATED_BODY()

	/** Nitrogen level (0.0 - 1.0) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soil", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float Nitrogen = 0.5f;

	/** Phosphorus level (0.0 - 1.0) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soil", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float Phosphorus = 0.5f;

	/** Potassium level (0.0 - 1.0) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soil", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float Potassium = 0.5f;

	/** pH level (4.0 - 9.0, optimal around 6.5-7.5) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soil", meta = (ClampMin = "4.0", ClampMax = "9.0"))
	float pH = 7.0f;

	/** Moisture level (0.0 - 1.0) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soil", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float Moisture = 0.5f;

	/** Compaction level (0.0 - 1.0, lower is better) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soil", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float Compaction = 0.2f;

	/** Number of times this soil has been harvested (tracks depletion) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soil")
	int32 TimesHarvested = 0;

	FSoilData()
		: Nitrogen(0.5f)
		, Phosphorus(0.5f)
		, Potassium(0.5f)
		, pH(7.0f)
		, Moisture(0.5f)
		, Compaction(0.2f)
		, TimesHarvested(0)
	{}

	/** Get overall soil quality as a single value (0.0 - 1.0) */
	float GetOverallQuality() const
	{
		return (Nitrogen + Phosphorus + Potassium + Moisture) / 4.0f;
	}
};

/** Individual crop instance data */
USTRUCT(BlueprintType)
struct FCropInstance
{
	GENERATED_BODY()

	/** Unique identifier for this crop */
	UPROPERTY(BlueprintReadWrite, Category = "Crop")
	FGuid CropID;

	/** Reference to crop type data */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crop")
	TObjectPtr<UCropDataAsset> CropType;

	/** World location of this crop */
	UPROPERTY(BlueprintReadWrite, Category = "Crop")
	FVector Location;

	/** Current growth state */
	UPROPERTY(BlueprintReadWrite, Category = "Crop")
	ECropGrowthState GrowthState;

	/** Growth progress within current state (0.0 - 1.0) */
	UPROPERTY(BlueprintReadWrite, Category = "Crop", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float GrowthProgress;

	/** Overall crop health (0.0 - 1.0) */
	UPROPERTY(BlueprintReadWrite, Category = "Crop", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float Health;

	/** Water level for this crop (0.0 - 1.0) */
	UPROPERTY(BlueprintReadWrite, Category = "Crop", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float WaterLevel;

	/** Nutrient level for this crop (0.0 - 1.0) */
	UPROPERTY(BlueprintReadWrite, Category = "Crop", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float NutrientLevel;

	/** Number of days since planted */
	UPROPERTY(BlueprintReadWrite, Category = "Crop")
	int32 DaysPlanted;

	/** Is this crop currently wilting? */
	UPROPERTY(BlueprintReadWrite, Category = "Crop")
	bool bIsWilting;

	/** Has this crop been affected by disease/pests? */
	UPROPERTY(BlueprintReadWrite, Category = "Crop")
	bool bIsDiseased;

	FCropInstance()
		: CropID(FGuid::NewGuid())
		, CropType(nullptr)
		, Location(FVector::ZeroVector)
		, GrowthState(ECropGrowthState::NotPlanted)
		, GrowthProgress(0.0f)
		, Health(1.0f)
		, WaterLevel(0.5f)
		, NutrientLevel(0.5f)
		, DaysPlanted(0)
		, bIsWilting(false)
		, bIsDiseased(false)
	{}

	/** Check if crop is ready to harvest */
	bool IsHarvestable() const
	{
		return GrowthState == ECropGrowthState::Harvestable && Health > 0.0f;
	}

	/** Check if crop needs water */
	bool NeedsWater() const
	{
		return WaterLevel < 0.4f;
	}
};

/** Soil requirements for crops */
USTRUCT(BlueprintType)
struct FSoilRequirements
{
	GENERATED_BODY()

	/** Minimum nitrogen level (0.0 - 1.0) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Requirements")
	float MinNitrogen = 0.3f;

	/** Minimum phosphorus level (0.0 - 1.0) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Requirements")
	float MinPhosphorus = 0.2f;

	/** Minimum potassium level (0.0 - 1.0) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Requirements")
	float MinPotassium = 0.2f;

	/** Optimal pH range */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Requirements")
	FVector2D OptimalPHRange = FVector2D(6.0f, 7.5f);

	/** Optimal moisture range */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Requirements")
	FVector2D OptimalMoistureRange = FVector2D(0.4f, 0.7f);

	/** Can this crop tolerate low soil quality? */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Requirements")
	bool bToleratePoorSoil = false;
};

/** Harvest yield data */
USTRUCT(BlueprintType)
struct FHarvestYield
{
	GENERATED_BODY()

	/** Crop type that was harvested */
	UPROPERTY(BlueprintReadWrite, Category = "Harvest")
	TObjectPtr<UCropDataAsset> CropType;

	/** Amount harvested in kg */
	UPROPERTY(BlueprintReadWrite, Category = "Harvest")
	float AmountKg;

	/** Quality grade of harvest */
	UPROPERTY(BlueprintReadWrite, Category = "Harvest")
	ECropQuality Quality;

	/** Price per kg at time of harvest */
	UPROPERTY(BlueprintReadWrite, Category = "Harvest")
	float PricePerKg;

	FHarvestYield()
		: CropType(nullptr)
		, AmountKg(0.0f)
		, Quality(ECropQuality::GradeB)
		, PricePerKg(0.0f)
	{}

	/** Get total value of this harvest */
	float GetTotalValue() const
	{
		float qualityMultiplier = 1.0f;
		switch (Quality)
		{
			case ECropQuality::Premium: qualityMultiplier = 1.0f; break;
			case ECropQuality::GradeA: qualityMultiplier = 0.9f; break;
			case ECropQuality::GradeB: qualityMultiplier = 0.75f; break;
			case ECropQuality::GradeC: qualityMultiplier = 0.5f; break;
			case ECropQuality::Waste: qualityMultiplier = 0.0f; break;
		}
		return AmountKg * PricePerKg * qualityMultiplier;
	}
};

/** Inventory item data */
USTRUCT(BlueprintType)
struct FInventoryItem
{
	GENERATED_BODY()

	/** Item name/identifier */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName ItemID;

	/** Display name */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FText DisplayName;

	/** Quantity */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 Quantity;

	/** Item icon */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	TObjectPtr<UTexture2D> Icon;

	FInventoryItem()
		: ItemID(NAME_None)
		, DisplayName(FText::GetEmpty())
		, Quantity(0)
		, Icon(nullptr)
	{}
};

/** Market price data */
USTRUCT(BlueprintType)
struct FMarketPrice
{
	GENERATED_BODY()

	/** Base price per kg */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Market")
	float BasePrice;

	/** Current price per kg (after modifiers) */
	UPROPERTY(BlueprintReadWrite, Category = "Market")
	float CurrentPrice;

	/** Seasonal price modifier (-1.0 to 1.0) */
	UPROPERTY(BlueprintReadWrite, Category = "Market")
	float SeasonalModifier;

	/** Supply/demand modifier (-1.0 to 1.0) */
	UPROPERTY(BlueprintReadWrite, Category = "Market")
	float SupplyDemandModifier;

	FMarketPrice()
		: BasePrice(1.0f)
		, CurrentPrice(1.0f)
		, SeasonalModifier(0.0f)
		, SupplyDemandModifier(0.0f)
	{}

	/** Calculate final price with all modifiers */
	float GetFinalPrice() const
	{
		return BasePrice * (1.0f + SeasonalModifier + SupplyDemandModifier);
	}
};

/** Field data */
USTRUCT(BlueprintType)
struct FFieldData
{
	GENERATED_BODY()

	/** Unique field identifier */
	UPROPERTY(BlueprintReadWrite, Category = "Field")
	FGuid FieldID;

	/** Field name */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Field")
	FText FieldName;

	/** Field center location */
	UPROPERTY(BlueprintReadWrite, Category = "Field")
	FVector Location;

	/** Field size (width x length in meters) */
	UPROPERTY(BlueprintReadWrite, Category = "Field")
	FVector2D Size;

	/** Current field state */
	UPROPERTY(BlueprintReadWrite, Category = "Field")
	EFieldState FieldState;

	/** Average soil quality for this field */
	UPROPERTY(BlueprintReadWrite, Category = "Field")
	FSoilData SoilQuality;

	/** Is this field owned by the player? */
	UPROPERTY(BlueprintReadWrite, Category = "Field")
	bool bIsOwned;

	/** Purchase price for this field */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Field")
	float PurchasePrice;

	FFieldData()
		: FieldID(FGuid::NewGuid())
		, FieldName(FText::FromString(TEXT("Unnamed Field")))
		, Location(FVector::ZeroVector)
		, Size(FVector2D(50.0f, 50.0f))
		, FieldState(EFieldState::Untilled)
		, bIsOwned(false)
		, PurchasePrice(5000.0f)
	{}
};
