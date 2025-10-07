# Technical Design Specification - Farming Simulator
**Version:** 1.0
**Date:** October 2025
**Engine:** Unreal Engine 5.4+

---

## 1. Technical Overview

### 1.1 Engine & Tools
- **Game Engine:** Unreal Engine 5.4 (or latest stable)
- **Programming Languages:** C++, Blueprints (hybrid approach)
- **Version Control:** Git with Git LFS
- **IDE:** Visual Studio 2022, Rider
- **3D Software:** Blender, Maya
- **Texture Tools:** Substance Designer/Painter

### 1.2 Target Specifications

#### Minimum PC Requirements
- **OS:** Windows 10 64-bit
- **CPU:** Intel Core i5-8400 / AMD Ryzen 5 2600
- **RAM:** 8 GB
- **GPU:** NVIDIA GTX 1060 6GB / AMD RX 580 8GB
- **Storage:** 30 GB available space
- **DirectX:** Version 12

#### Recommended PC Requirements
- **OS:** Windows 11 64-bit
- **CPU:** Intel Core i7-10700K / AMD Ryzen 7 3700X
- **RAM:** 16 GB
- **GPU:** NVIDIA RTX 3060 Ti / AMD RX 6700 XT
- **Storage:** 30 GB SSD
- **DirectX:** Version 12

---

## 2. System Architecture

### 2.1 Core Systems Hierarchy

```
GameInstance
├── SaveGameManager
├── GameDataAssets (Static Data)
└── GameSettings

GameMode
├── TimeManager (Day/Night, Seasons)
├── WeatherManager
├── EconomyManager
├── ContractManager
└── WorldGrid (Field Management)

PlayerController
├── InputHandler
├── UIManager
└── CameraManager

PlayerCharacter (Pawn)
├── InventoryComponent
├── InteractionComponent
├── EquipmentComponent
└── SkillComponent

FarmManager (Actor)
├── CropManager
├── LivestockManager (Future)
├── BuildingManager
└── StorageManager

VehicleBase (Actor)
├── VehicleMovementComponent
├── ImplementAttachmentComponent
└── FuelComponent
```

### 2.2 Data Architecture

#### Data Asset Structure
- **Primary Data:** DataAssets for all static game data
- **Crop Data:** Growth stages, requirements, yield values
- **Equipment Data:** Stats, pricing, fuel consumption
- **Building Data:** Construction costs, benefits, dimensions
- **Market Data:** Base prices, demand curves

#### Save Data Structure
```cpp
struct FSaveGameData
{
    FDateTime GameDateTime;
    float PlayerMoney;
    TArray<FFieldData> OwnedFields;
    TArray<FCropInstance> ActiveCrops;
    TArray<FVehicleData> OwnedVehicles;
    TArray<FBuildingData> Buildings;
    FInventoryData Inventory;
    FPlayerProgressionData Progression;
    TMap<FString, bool> UnlockedContent;
};
```

---

## 3. Core Systems Design

### 3.1 Time Management System

#### Implementation
- Uses custom TimeManager class (singleton pattern)
- Time scale: 1 real minute = 1 game hour (adjustable)
- Day length: 24 in-game hours
- Season length: 28 in-game days per season

#### Technical Details
```cpp
class ATimeManager : public AActor
{
    float CurrentTime; // 0-24 hours
    int32 CurrentDay;
    int32 CurrentSeason; // 0=Spring, 1=Summer, 2=Fall, 3=Winter
    float TimeScale; // Multiplier for time passage

    UFUNCTION()
    void TickTime(float DeltaTime);

    UFUNCTION(BlueprintCallable)
    void SetTimeScale(float NewScale);

    // Delegate for other systems to subscribe
    FOnDayChanged OnDayChanged;
    FOnSeasonChanged OnSeasonChanged;
};
```

### 3.2 Crop Growth System

#### State Machine
- States: NotPlanted, Seedling, Growing, Mature, Harvestable, Withered
- Transitions based on time and conditions
- Each crop instance tracks:
  - Growth progress (0.0 - 1.0)
  - Health (0.0 - 1.0)
  - Water level
  - Nutrient level
  - Days since planted

#### Technical Implementation
```cpp
USTRUCT()
struct FCropInstance
{
    UPROPERTY()
    FGuid CropID;

    UPROPERTY()
    UCropDataAsset* CropType;

    UPROPERTY()
    FVector Location;

    UPROPERTY()
    ECropGrowthState State;

    UPROPERTY()
    float GrowthProgress; // 0.0 to 1.0

    UPROPERTY()
    float Health;

    UPROPERTY()
    float WaterLevel;

    UPROPERTY()
    float NutrientLevel;

    UPROPERTY()
    int32 DaysPlanted;
};
```

#### Optimization
- Grid-based spatial partitioning (100x100 cells)
- Batch updates for crops in same growth stage
- LOD system for visual crop meshes
- Instanced Static Meshes for crop rendering

### 3.3 Soil Quality System

#### Soil Properties
```cpp
USTRUCT()
struct FSoilData
{
    UPROPERTY()
    float Nitrogen; // 0.0 - 1.0

    UPROPERTY()
    float Phosphorus; // 0.0 - 1.0

    UPROPERTY()
    float Potassium; // 0.0 - 1.0

    UPROPERTY()
    float pH; // 4.0 - 9.0

    UPROPERTY()
    float Moisture; // 0.0 - 1.0

    UPROPERTY()
    int32 TimesHarvested;
};
```

#### Grid Implementation
- Each field divided into 1x1 meter soil cells
- Soil data stored in 2D array
- Render soil quality as texture overlay (debug mode)

### 3.4 Weather System

#### Weather States
- Clear, Cloudy, Light Rain, Heavy Rain, Storm, Snow, Fog

#### Weather Effects
- Rain increases soil moisture
- Storm can damage crops
- Drought conditions (low moisture over time)
- Visual effects: Niagara particle systems
- Audio: Weather-specific ambient sounds

#### Implementation
```cpp
class AWeatherManager : public AActor
{
    UPROPERTY()
    EWeatherState CurrentWeather;

    UPROPERTY()
    float WeatherIntensity; // 0.0 - 1.0

    UPROPERTY()
    UNiagaraComponent* RainParticles;

    UPROPERTY()
    UPostProcessComponent* WeatherPostProcess;

    void TransitionToWeather(EWeatherState NewWeather, float Duration);
    void UpdateEnvironmentEffects();
};
```

### 3.5 Vehicle System

#### Vehicle Base Class
```cpp
class AVehicleBase : public APawn
{
    UPROPERTY()
    UChaosWheeledVehicleMovementComponent* VehicleMovement;

    UPROPERTY()
    float FuelLevel; // 0.0 - 1.0

    UPROPERTY()
    float FuelConsumptionRate;

    UPROPERTY()
    float Durability; // 0.0 - 1.0

    UPROPERTY()
    TArray<UImplementAttachmentPoint*> AttachmentPoints;

    UFUNCTION()
    void AttachImplement(AImplementBase* Implement);

    UFUNCTION()
    void DetachImplement();

    UFUNCTION()
    void ConsumeFuel(float DeltaTime);
};
```

#### Physics
- Using Chaos Vehicle Physics
- Realistic suspension and tire friction
- Weight affects handling and fuel consumption
- Implements can be attached via socket connections

### 3.6 Economy System

#### Dynamic Pricing
```cpp
class UEconomyManager : public UObject
{
    UPROPERTY()
    TMap<UCropDataAsset*, FMarketData> MarketPrices;

    struct FMarketData
    {
        float BasePrice;
        float CurrentPrice;
        float Demand; // 0.0 - 2.0 multiplier
        int32 MarketSupply;
    };

    UFUNCTION()
    void UpdateMarketPrices();

    UFUNCTION()
    float CalculateSellPrice(UCropDataAsset* Crop, int32 Quantity);

    UFUNCTION()
    void RegisterSale(UCropDataAsset* Crop, int32 Quantity);
};
```

#### Price Fluctuation
- Seasonal demand changes
- Supply/demand algorithm
- Random market events (high demand days)
- Price history tracking for player decisions

---

## 4. Performance Optimization Strategy

### 4.1 Level of Detail (LOD)
- **Crops:** 3 LOD levels (High detail 0-20m, Medium 20-50m, Low 50m+)
- **Vehicles:** 4 LOD levels
- **Buildings:** 3 LOD levels
- Auto LOD generation in UE5

### 4.2 Culling & Occlusion
- Hierarchical LOD (HLOD) for distant fields
- Occlusion culling for buildings and large objects
- Distance-based actor culling

### 4.3 Instancing
- Instanced Static Meshes for all crops (thousands per field)
- Hardware instancing for fences, posts, small props
- Foliage system for decorative plants

### 4.4 Streaming
- World Partition for large open world
- Level streaming for different farm areas
- Async loading for buildings and equipment

### 4.5 Tick Optimization
- Variable tick rates based on distance to player
- Tick groups for system dependencies
- Async tasks for heavy computations (crop growth calculations)

### 4.6 Memory Management
- Object pooling for frequently spawned actors (crop meshes)
- Lazy loading for data assets
- Texture streaming with virtual texturing

---

## 5. Rendering & Graphics

### 5.1 UE5 Features Utilized

#### Lumen
- Dynamic global illumination for day/night cycle
- Realistic lighting in barns and buildings
- Performance modes: High (Lumen), Medium (Screen Space GI), Low (Static lighting)

#### Nanite
- High detail terrain meshes
- Building and prop meshes
- Equipment models
- Not used for: animated meshes (crops with wind), translucent objects

#### Virtual Shadow Maps
- High quality shadows from sun
- Soft shadows for ambient lighting

#### Temporal Super Resolution (TSR)
- Upscaling for better performance
- Quality modes: Ultra Performance, Performance, Balanced, Quality

### 5.2 Material System
- Master materials for crops, terrain, buildings, vehicles
- Material instances for variations
- Runtime parameter adjustments (crop health affects color)

### 5.3 Post Processing
- Auto exposure for day/night transitions
- Color grading per time of day
- Motion blur (optional for player comfort)
- Depth of field for cinematic moments

---

## 6. AI & Pathfinding

### 6.1 Worker AI
- Behavior Trees for task execution
- AI perception for obstacle avoidance
- Task queue system

### 6.2 Navigation
- Nav mesh for walkable areas
- Custom vehicle pathfinding (avoid crops)
- Dynamic nav mesh updates when placing buildings

### 6.3 Traffic Management
- Multiple AI workers coordinate paths
- Parking spots and waiting zones
- Priority system for player vs AI vehicles

---

## 7. Networking Architecture (Future Multiplayer)

### 7.1 Replication Strategy
- Server-authoritative architecture
- Replicate only player actions and critical state changes
- Client-side prediction for vehicle movement

### 7.2 Sync Systems
- Time synchronized across clients
- Weather synchronized
- Market prices synchronized
- Individual crop growth can vary slightly (not critical)

---

## 8. Save/Load System

### 8.1 Save Trigger Points
- Auto-save at end of each game day
- Manual save via menu
- Quick save (F5 default)
- Exit save on game close

### 8.2 Serialization
- UE5 SaveGame object
- Compressed binary format
- Versioning system for future updates
- Backwards compatibility for at least 2 previous versions

### 8.3 Save File Location
- Windows: `%LOCALAPPDATA%/FarmingSimulator/Saved/SaveGames/`
- Save file naming: `SaveSlot_01.sav`, `SaveSlot_02.sav`, etc.
- Backup system: Keep last 3 auto-saves

---

## 9. Input System

### 9.1 Input Mapping
- Enhanced Input System (UE5)
- Context-based inputs (on foot, in vehicle, in menu)
- Rebindable keys via settings menu

### 9.2 Controller Support
- Full gamepad support (Xbox, PlayStation, Generic)
- Different control schemes for vehicles vs on-foot
- Rumble feedback for vehicle terrain and actions

---

## 10. Audio System

### 10.1 Sound Categories
- Master, Music, SFX, Ambient, UI, Voice
- Individual volume controls
- Audio ducking for important events

### 10.2 3D Audio
- Attenuation for distance-based volume
- Occlusion through buildings
- Reverb zones for indoor spaces

### 10.3 Dynamic Music
- Music layers that fade in/out based on activity
- Different themes per season
- Stingers for achievements and events

---

## 11. UI Framework

### 11.1 Technology
- UMG (Unreal Motion Graphics)
- Widget components for 3D world UI (shop signs, etc.)

### 11.2 UI Patterns
- Screen-space UI for menus and HUD
- Radial menu for quick actions (hold Q)
- Tooltip system for hover information

### 11.3 Responsiveness
- Support for 16:9, 21:9, 32:9 aspect ratios
- UI scaling options
- Safe zones for console (future)

---

## 12. Debugging & Tools

### 12.1 Debug Tools
- Visual debug for soil grid
- Crop growth state overlay
- Time manipulation console commands
- Weather forcing commands
- Money/resource cheat codes (dev builds only)

### 12.2 Console Commands
```
farm.SetTime [0-24]
farm.SetSeason [0-3]
farm.SetWeather [Clear/Rain/Storm/Snow]
farm.AddMoney [amount]
farm.GrowAllCrops
farm.ShowSoilDebug
farm.ShowCropDebug
```

### 12.3 Editor Tools
- Custom editor modes for field layout
- Crop placement tool
- Soil painter for initial setup

---

## 13. Testing Strategy

### 13.1 Unit Tests
- Crop growth calculations
- Economy price calculations
- Save/load functionality
- Inventory management

### 13.2 Performance Profiling
- Unreal Insights for frame analysis
- Memory profiling
- Draw call optimization
- Target: 16.6ms frame time on recommended specs

### 13.3 Automated Testing
- Gauntlet Framework for smoke tests
- Automated saves and loads
- Navigation validation

---

## 14. Build Pipeline

### 14.1 Build Configurations
- **Development:** Full debugging, fast iteration
- **Debug:** Maximum debug info, slower
- **Shipping:** Optimized, no debug features
- **Test:** Optimized but with limited debug

### 14.2 Continuous Integration
- Jenkins or GitHub Actions
- Automated builds on commit to main
- Automated test runs
- Packaging for distribution

### 14.3 Version Naming
- Format: Major.Minor.Patch (e.g., 1.0.0)
- Major: Significant features, breaking changes
- Minor: New features, no breaking changes
- Patch: Bug fixes only

---

## 15. Risks & Mitigation

### Technical Risks

| Risk | Probability | Impact | Mitigation |
|------|-------------|--------|------------|
| Performance issues with many crops | Medium | High | Early profiling, aggressive LOD, instancing |
| Vehicle physics instability | Low | Medium | Use proven Chaos Vehicle, extensive testing |
| Save file corruption | Low | High | Versioning, validation, backup system |
| Memory leaks | Medium | High | Regular profiling, proper garbage collection |
| Multiplayer sync issues | Medium | High | Deferred to post-MVP, thorough testing |

---

## 16. Code Standards

### 16.1 Naming Conventions
- Classes: `AMyActor`, `UMyObject`, `FMyStruct`, `EMyEnum`
- Variables: `PascalCase` for public, `camelCase` for private
- Functions: `PascalCase`, descriptive verb phrases
- Constants: `ALL_CAPS_WITH_UNDERSCORES`

### 16.2 Code Organization
- One class per file
- Header/Source separation
- Group related functionality in modules
- Use forward declarations to reduce dependencies

### 16.3 Documentation
- Doxygen-style comments for public APIs
- Function contracts (preconditions, postconditions)
- Blueprint-exposed functions must have tooltips

---

## 17. Third-Party Assets & Plugins

### 17.1 Planned Assets
- Megascans for terrain materials (Quixel)
- Audio library subscription (licensing pending)
- Crop and plant assets (custom creation)

### 17.2 Plugins
- **Required:** None (using engine features)
- **Potential:**
  - Advanced Vehicle System (if Chaos insufficient)
  - Save Extension (for enhanced save features)
  - Console Enhanced (better debug tools)

---

## Approval Sign-Off

| Role | Name | Date | Signature |
|------|------|------|-----------|
| Technical Director | | | |
| Lead Programmer | | | |
| Engine Specialist | | | |
| Producer | | | |

---

**Document Status:** Draft
**Next Review Date:** [To be scheduled]
**Change Log:** Initial version created
