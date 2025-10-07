# Phase 2: Prototype & Core Systems - Task Breakdown
**Duration:** Weeks 5-12 (8 Weeks)
**Team Size:** 15 people (Full core team)
**Goal:** Build playable prototype demonstrating core farming loop

---

## 1. Phase Overview

### 1.1 Objectives
- Create functional prototype of core gameplay loop
- Validate fun factor and game feel
- Establish technical foundation for all systems
- Prove UE5 capabilities for the project
- Test and iterate on basic mechanics

### 1.2 Success Criteria
- ✅ Player can plant, grow, and harvest at least 2 crop types
- ✅ Basic equipment (tractor + implement) functional
- ✅ Day/night cycle working with time progression
- ✅ Simple economy (buy seeds, sell crops)
- ✅ Prototype is fun to play for 15-30 minutes
- ✅ Performance: 60 FPS on target hardware
- ✅ Save/Load basic functionality

### 1.3 Deliverables
- Playable prototype build
- Core systems architecture documentation
- Technical proof-of-concept
- Gameplay video for stakeholders
- Risk assessment update

---

## 2. Week-by-Week Breakdown

### Week 5: Project Setup & Foundation
**Focus:** Environment setup and core architecture

#### Programming Tasks
- [x] Create UE5 project with proper settings
- [ ] Set up version control (Git + LFS)
- [ ] Configure project structure (folders, naming conventions)
- [ ] Create core game framework classes (GameMode, GameInstance, PlayerController)
- [ ] Implement basic save/load system architecture
- [ ] Set up data asset framework

#### Art Tasks
- [ ] Create test level (1000m x 1000m terrain)
- [ ] Basic landscape material (soil, grass)
- [ ] Placeholder character model (or use UE5 Manny)
- [ ] Establish art pipeline (import/export)

#### Design Tasks
- [ ] Create initial data assets for 2 crops (wheat, potato)
- [ ] Define equipment specifications
- [ ] Create test field layouts
- [ ] Write prototype design document

**Milestone:** Project setup complete, team can start parallel work

---

### Week 6: Player Controller & Camera
**Focus:** Core player experience and controls

#### Programming Tasks
- [ ] Implement third-person player controller
- [ ] Create camera system (follow camera, zoom, rotation)
- [ ] Add basic character movement (WASD, run, walk)
- [ ] Implement interaction system (raycast, highlight objects)
- [ ] Create input mapping (keyboard/mouse, gamepad support)
- [ ] Add basic animation blueprint (idle, walk, run)

#### Art Tasks
- [ ] Create or import character animations
- [ ] Model basic farmer character or customize Manny
- [ ] Create interaction feedback (highlight shader)
- [ ] Design cursor/crosshair for interaction

#### Design Tasks
- [ ] Tune camera distances and angles
- [ ] Set movement speeds
- [ ] Define interaction ranges

**Milestone:** Player can move around and interact with world

---

### Week 7: Time & Weather Systems
**Focus:** Core environmental systems

#### Programming Tasks
- [ ] Create TimeManager class
  - [ ] Time progression (game hours)
  - [ ] Day counter and season tracking
  - [ ] Time scale adjustment
- [ ] Implement day/night cycle
  - [ ] Sun rotation and intensity
  - [ ] Sky color transitions
  - [ ] Directional light animation
- [ ] Create basic weather system
  - [ ] Weather states (Clear, Rain)
  - [ ] Transition system
  - [ ] Weather effects on gameplay (moisture)

#### Art Tasks
- [ ] Configure sky sphere/atmosphere
- [ ] Set up sun and sky light
- [ ] Create time-of-day color LUTs
- [ ] Rain particle effects (Niagara)
- [ ] Weather post-process effects

#### Design Tasks
- [ ] Set day length (1 real min = 1 game hour)
- [ ] Define season length
- [ ] Balance weather frequency

**Milestone:** Complete day/night cycle with weather

---

### Week 8: Soil & Field System
**Focus:** Foundation for farming mechanics

#### Programming Tasks
- [ ] Create field management system
  - [ ] Field data structure
  - [ ] Grid-based soil system
  - [ ] Soil property tracking (moisture, nutrients)
- [ ] Implement field states (untilled, plowed, cultivated)
- [ ] Create soil quality visualization (debug mode)
- [ ] Field boundary definition system
- [ ] Soil moisture system tied to weather

#### Art Tasks
- [ ] Create field boundary meshes (fences, markers)
- [ ] Soil texture variations (tilled vs untilled)
- [ ] Create material for soil state blending
- [ ] Visual feedback for soil quality

#### Design Tasks
- [ ] Define soil property ranges
- [ ] Create starting field layouts (2-3 fields)
- [ ] Balance soil depletion rates
- [ ] Set initial soil conditions

**Milestone:** Field system ready for crop planting

---

### Week 9: Crop System Part 1
**Focus:** Core crop mechanics

#### Programming Tasks
- [ ] Create crop data asset structure
- [ ] Implement crop instance management
- [ ] Create crop growth state machine
  - [ ] States: Seedling, Growing, Mature, Harvestable
  - [ ] Growth progress tracking
  - [ ] Health and condition monitoring
- [ ] Crop visual representation (instanced meshes)
- [ ] Growth tick system (updates based on time)
- [ ] Planting mechanic (basic placement)

#### Art Tasks
- [ ] Create crop models for 2 types (wheat, potato)
  - [ ] 4 growth stages each
  - [ ] LOD setup
- [ ] Crop materials and textures
- [ ] Wind animation setup
- [ ] Health variation (color tinting)

#### Design Tasks
- [ ] Define growth times for crops
- [ ] Set yield values
- [ ] Balance water/nutrient requirements
- [ ] Create crop data assets

**Milestone:** Crops can be planted and grow over time

---

### Week 10: Crop System Part 2 & Harvesting
**Focus:** Complete crop lifecycle

#### Programming Tasks
- [ ] Implement watering system
  - [ ] Manual watering (hand tool)
  - [ ] Moisture decrease over time
  - [ ] Visual feedback
- [ ] Create harvest mechanic
  - [ ] Manual harvesting (press E)
  - [ ] Yield calculation
  - [ ] Add to inventory
  - [ ] Remove crop from field
- [ ] Crop health system
  - [ ] Wilting if no water
  - [ ] Recovery mechanics
- [ ] Field clearing after harvest

#### Art Tasks
- [ ] Watering can model and animation
- [ ] Water particle effects
- [ ] Harvest animation
- [ ] Crop collection feedback (VFX)
- [ ] Wilted crop variations

#### Design Tasks
- [ ] Balance crop water needs
- [ ] Set harvest timing windows
- [ ] Tune yield values
- [ ] Design feedback for crop health

**Milestone:** Complete plant → grow → harvest loop

---

### Week 11: Vehicle & Equipment System
**Focus:** Tractor and basic implements

#### Programming Tasks
- [ ] Create vehicle base class
  - [ ] Chaos Vehicle physics setup
  - [ ] Vehicle movement component
  - [ ] Enter/exit vehicle system
- [ ] Implement basic tractor
  - [ ] Driving controls
  - [ ] Camera system for driving
  - [ ] Fuel consumption (basic)
- [ ] Create implement attachment system
  - [ ] Socket-based attachment
  - [ ] Implement activation/deactivation
- [ ] Basic plow implement
  - [ ] Area detection (what soil is affected)
  - [ ] Tilling functionality
  - [ ] Visual feedback

#### Art Tasks
- [ ] Basic tractor model (or placeholder)
- [ ] Plow implement model
- [ ] Vehicle wheel setup
- [ ] Attachment socket definition
- [ ] Tire track decals
- [ ] Tilled soil visual changes

#### Design Tasks
- [ ] Vehicle handling parameters
- [ ] Fuel consumption rates
- [ ] Implement work speeds
- [ ] Field preparation mechanics

**Milestone:** Player can drive tractor and till soil

---

### Week 12: UI, Economy & Integration
**Focus:** Polish and complete prototype

#### Programming Tasks
- [ ] Create HUD system
  - [ ] Time and date display
  - [ ] Money counter
  - [ ] Current tool/equipment display
- [ ] Implement basic inventory
  - [ ] Seed storage
  - [ ] Harvested crop storage
  - [ ] Simple UI display
- [ ] Create shop system
  - [ ] Buy seeds
  - [ ] Sell crops
  - [ ] Purchase equipment (placeholder)
- [ ] Economy manager
  - [ ] Money tracking
  - [ ] Basic pricing (static for prototype)
- [ ] Save/Load implementation
  - [ ] Save player state
  - [ ] Save crop instances
  - [ ] Save time/date
- [ ] Bug fixing and integration

#### Art Tasks
- [ ] HUD design and implementation
- [ ] Inventory UI mockup and creation
- [ ] Shop UI
- [ ] Icons for crops and items
- [ ] Polish pass on all visuals

#### Design Tasks
- [ ] Set initial prices for items
- [ ] Define starting resources
- [ ] Balance earning vs spending
- [ ] Create 15-30 min prototype experience flow
- [ ] Playtest and iterate

**Milestone:** Complete playable prototype ready for demo

---

## 3. Detailed Task Lists by Department

### 3.1 Programming Team (5 Programmers)

#### Lead Gameplay Programmer
- Overall system architecture
- GameMode and framework setup
- System integration and coordination
- Code reviews and standards enforcement

#### Gameplay Programmer 1 (Player & Interaction)
- Player controller
- Camera system
- Interaction system
- Character animations
- Input handling

#### Gameplay Programmer 2 (World Systems)
- Time management
- Weather system
- Field and soil system
- Environmental interactions

#### Gameplay Programmer 3 (Crops & Farming)
- Crop system architecture
- Growth simulation
- Planting and harvesting mechanics
- Crop instancing and optimization

#### UI Programmer
- UI framework setup
- HUD implementation
- Inventory system
- Shop interface
- Save/Load system

### 3.2 Art Team (6 Artists)

#### Lead Artist
- Art direction oversight
- Quality control
- Pipeline establishment
- Asset review

#### Environment Artist 1
- Terrain setup and landscaping
- Landscape materials
- Field creation
- Foliage placement

#### Environment Artist 2
- Buildings and structures (if needed)
- Props and farm objects
- Fences and boundaries
- Scene composition

#### Character/Vehicle Artist
- Character setup (or Manny customization)
- Tractor modeling
- Implement modeling
- Rigging and setup

#### Technical Artist
- Materials and shaders
- VFX (rain, particles, etc.)
- Lighting setup
- Performance optimization

#### UI/UX Artist
- HUD design
- Menu designs
- Icon creation
- Visual feedback design

### 3.3 Design Team (2 Designers)

#### Systems Designer
- Data asset creation
- Economy balancing
- Progression tuning
- Playtesting and iteration

#### Level Designer
- Terrain layout
- Field placement
- Starting farm setup
- Playable space design

---

## 4. Technical Specifications

### 4.1 Core Class Architecture

```
FarmingSimulatorGameMode
├── TimeManager (spawned at BeginPlay)
├── WeatherManager (spawned at BeginPlay)
├── FieldManager (spawned at BeginPlay)
└── EconomyManager (spawned at BeginPlay)

FarmingSimulatorPlayerController
├── InputComponent (Enhanced Input)
├── InteractionComponent
└── UIManager

FarmingSimulatorCharacter (Player Pawn)
├── CharacterMovementComponent
├── SpringArmComponent (Camera boom)
├── CameraComponent
├── SkeletalMeshComponent
├── InventoryComponent
└── EquipmentComponent

FarmingSimulatorGameInstance
├── SaveGameManager
└── GameDataHolder (Data Assets)
```

### 4.2 Critical C++ Classes

#### TimeManager.h
```cpp
UCLASS()
class FARMINGSIMULATOR_API ATimeManager : public AActor
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadOnly, Category = "Time")
    float CurrentGameHour; // 0-24

    UPROPERTY(BlueprintReadOnly, Category = "Time")
    int32 CurrentDay;

    UPROPERTY(BlueprintReadOnly, Category = "Time")
    int32 CurrentSeason; // 0-3

    UPROPERTY(EditDefaultsOnly, Category = "Time")
    float TimeScale = 60.0f; // 1 real second = 60 game seconds

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDayChanged, int32, NewDay);
    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnDayChanged OnDayChanged;

    UFUNCTION(BlueprintCallable, Category = "Time")
    void SetTimeScale(float NewScale);

    UFUNCTION(BlueprintCallable, Category = "Time")
    FString GetFormattedTime() const;

protected:
    virtual void Tick(float DeltaTime) override;
    void UpdateSunPosition();
};
```

#### CropInstance.h
```cpp
USTRUCT(BlueprintType)
struct FCropInstance
{
    GENERATED_BODY()

    UPROPERTY()
    FGuid CropID;

    UPROPERTY()
    class UCropDataAsset* CropType;

    UPROPERTY()
    FVector Location;

    UPROPERTY()
    ECropGrowthState GrowthState;

    UPROPERTY()
    float GrowthProgress; // 0.0 to 1.0

    UPROPERTY()
    float Health; // 0.0 to 1.0

    UPROPERTY()
    float MoistureLevel; // 0.0 to 1.0

    UPROPERTY()
    int32 DaysPlanted;
};

UCLASS()
class FARMINGSIMULATOR_API UCropManager : public UActorComponent
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Crops")
    void PlantCrop(UCropDataAsset* CropType, FVector Location);

    UFUNCTION(BlueprintCallable, Category = "Crops")
    void UpdateCropGrowth(float DeltaTime);

    UFUNCTION(BlueprintCallable, Category = "Crops")
    TArray<FCropInstance> GetCropsInRadius(FVector Center, float Radius);

    UFUNCTION(BlueprintCallable, Category = "Crops")
    bool HarvestCrop(FGuid CropID, int32& OutYield);

protected:
    UPROPERTY()
    TArray<FCropInstance> AllCrops;

    UPROPERTY()
    TMap<FGuid, UInstancedStaticMeshComponent*> CropMeshes;
};
```

### 4.3 Data Asset Examples

#### CropDataAsset (Blueprint inheritable)
```cpp
UCLASS(BlueprintType)
class UCropDataAsset : public UPrimaryDataAsset
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Info")
    FText CropName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Info")
    UTexture2D* Icon;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Growth")
    int32 GrowthDurationDays = 7;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Growth")
    TArray<UStaticMesh*> GrowthStageMeshes;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Requirements")
    float OptimalMoisture = 0.6f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Economy")
    float BaseYieldPerPlant = 1.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Economy")
    float SellPricePerKg = 0.30f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Economy")
    float SeedCost = 0.10f;
};
```

---

## 5. Performance Targets

### 5.1 Prototype Performance Goals
- **Target FPS:** 60 FPS on recommended specs
- **Acceptable:** 30 FPS on minimum specs
- **Resolution:** 1080p

### 5.2 Optimization Priorities
1. Crop instancing (critical - thousands of instances)
2. Terrain rendering (large landscape)
3. Weather effects (particle systems)
4. Vehicle physics (Chaos vehicle overhead)

### 5.3 Performance Budgets
- **Draw Calls:** < 1500
- **Triangles:** < 2 million on-screen
- **Frame Time:** < 16.6ms (60 FPS)
- **Memory:** < 4GB VRAM usage

---

## 6. Testing Plan

### 6.1 Daily Testing
- Build verification test (BVT) every morning
- Crash testing
- Basic functionality checks

### 6.2 Weekly Testing
- Full playthrough of implemented features
- Performance profiling
- Bug triage and prioritization

### 6.3 End-of-Phase Testing (Week 12)
- Complete prototype playtest (15-30 min session)
- Gather feedback from team
- Document issues for Phase 3
- Stakeholder demo and review

---

## 7. Risk Management

### 7.1 Technical Risks

#### Risk: Crop Instancing Performance
- **Mitigation:** Test with 10,000 instances by Week 9
- **Backup Plan:** Reduce visual complexity or implement more aggressive LODs

#### Risk: Vehicle Physics Issues
- **Mitigation:** Start vehicle work early (Week 11), use proven Chaos Vehicle
- **Backup Plan:** Simplify physics model or use arcade-style handling

#### Risk: System Integration Problems
- **Mitigation:** Integration testing throughout, not just at end
- **Backup Plan:** Modular design allows fallback to Blueprint-only

### 7.2 Schedule Risks

#### Risk: Feature Creep
- **Mitigation:** Strict scope adherence, defer extras to Phase 3
- **Response:** Daily stand-ups to monitor progress

#### Risk: Team Member Unavailability
- **Mitigation:** Cross-training, documentation
- **Response:** Task reassignment, overtime if critical path

---

## 8. Success Metrics

### 8.1 Completion Criteria
- [ ] All Week 12 tasks completed
- [ ] Prototype is playable end-to-end
- [ ] No critical bugs (crashes, data loss)
- [ ] Performance targets met
- [ ] Positive team feedback on fun factor

### 8.2 Demo Requirements
- 5-minute gameplay video showing:
  - Player movement and camera
  - Day/night cycle
  - Tilling soil with tractor
  - Planting crops
  - Time passage (accelerated)
  - Crop growth visible
  - Harvesting crops
  - Selling at market
  - Money earned displayed

---

## 9. Deliverables Checklist

### Code Deliverables
- [ ] UE5 project in version control
- [ ] Core framework classes (C++)
- [ ] Player controller and camera
- [ ] Time and weather systems
- [ ] Crop system implementation
- [ ] Vehicle system basic implementation
- [ ] UI framework
- [ ] Save/Load basic functionality

### Art Deliverables
- [ ] Test environment (terrain)
- [ ] 2 crop types (4 stages each)
- [ ] Basic tractor model
- [ ] 1 implement (plow)
- [ ] Character (Manny customized or original)
- [ ] UI elements (HUD, menus)
- [ ] VFX (rain, particles)

### Design Deliverables
- [ ] Crop data assets (2 crops)
- [ ] Balance document
- [ ] Prototype design document
- [ ] Playtest feedback report

### Documentation
- [ ] Technical architecture document (updated)
- [ ] Class hierarchy diagrams
- [ ] Setup and build instructions
- [ ] Known issues list
- [ ] Phase 3 planning notes

---

## 10. Phase 2 to Phase 3 Transition

### 10.1 Review Meeting
- Demo prototype to stakeholders
- Present metrics and performance data
- Discuss feedback and learnings
- Approve or adjust Phase 3 scope

### 10.2 Retrospective
- What went well?
- What challenges did we face?
- What should we change for Phase 3?
- Team morale check

### 10.3 Phase 3 Preparation
- Update task list based on Phase 2 learnings
- Adjust resource allocation if needed
- Plan for expanded team (if contractors joining)
- Finalize tool pipeline improvements

---

## 11. Daily Stand-up Format

### Questions (5 minutes per person)
1. What did you complete yesterday?
2. What are you working on today?
3. Any blockers or needs?

### Weekly Planning (Monday)
- Review week goals
- Assign tasks
- Identify dependencies

### Weekly Review (Friday)
- Demo completed work
- Update task board
- Plan next week

---

## 12. Tools & Setup

### 12.1 Development Environment
- **Engine:** Unreal Engine 5.4.x
- **IDE:** Visual Studio 2022 or Rider
- **Version Control:** Git with Git LFS
- **Repository:** [Git URL to be set up]
- **Project Management:** Jira/Trello/Linear
- **Communication:** Slack/Discord

### 12.2 Project Settings
- **Target Platform:** Windows 64-bit
- **C++ Standard:** C++20
- **Rendering:** DX12
- **Lumen:** Enabled (High quality)
- **Nanite:** Enabled for static meshes
- **Virtual Shadow Maps:** Enabled

### 12.3 Code Standards
- Follow Unreal Engine coding standards
- Use clang-format for consistency
- Comment all public functions
- Blueprint-C++ hybrid approach (C++ for core, BP for content)

---

## Approval Sign-Off

| Role | Name | Date | Approval |
|------|------|------|----------|
| Project Director | | | ☐ |
| Technical Director | | | ☐ |
| Lead Programmer | | | ☐ |
| Lead Artist | | | ☐ |
| Lead Designer | | | ☐ |

---

**Document Status:** Active Development Phase
**Next Review:** End of Week 8 (Mid-phase checkpoint)
**Final Review:** End of Week 12 (Phase completion)

---

**Ready to begin Phase 2!** 🚀
