# Project Structure - Farming Simulator UE5

## 1. Root Directory Structure

```
FarmingSimulator/
├── .git/                          # Git version control
├── .gitignore                     # Git ignore file
├── .gitattributes                 # Git LFS configuration
├── FarmingSimulator.uproject      # Unreal project file
├── Config/                        # Project configuration files
├── Content/                       # All game content (assets, blueprints, etc.)
├── Documentation/                 # Project documentation (this folder)
├── Plugins/                       # Third-party and custom plugins
├── Source/                        # C++ source code
├── Saved/                         # Generated files (not in version control)
├── Intermediate/                  # Build intermediate files (not in VC)
├── DerivedDataCache/              # DDC (not in version control)
└── Binaries/                      # Compiled binaries (not in VC)
```

---

## 2. Content Folder Structure

```
Content/
├── FarmingSimulator/              # Main game content (avoid root clutter)
│   ├── Core/                      # Core game systems
│   │   ├── GameMode/
│   │   ├── PlayerController/
│   │   ├── GameInstance/
│   │   └── SaveGame/
│   │
│   ├── Characters/                # Player and NPC characters
│   │   ├── Player/
│   │   │   ├── Meshes/
│   │   │   ├── Animations/
│   │   │   ├── Materials/
│   │   │   └── Blueprints/
│   │   └── NPCs/
│   │
│   ├── Vehicles/                  # All vehicles and equipment
│   │   ├── Tractors/
│   │   │   ├── Tractor_Basic/
│   │   │   │   ├── Meshes/
│   │   │   │   ├── Materials/
│   │   │   │   ├── Textures/
│   │   │   │   ├── Physics/
│   │   │   │   └── BP_Tractor_Basic.uasset
│   │   │   └── Tractor_Advanced/
│   │   ├── Implements/
│   │   │   ├── Plow/
│   │   │   ├── Seeder/
│   │   │   ├── Harvester/
│   │   │   ├── Sprayer/
│   │   │   └── Cultivator/
│   │   └── Utility/
│   │       └── Truck/
│   │
│   ├── Crops/                     # Crop systems and assets
│   │   ├── DataAssets/            # Crop data assets
│   │   │   ├── DA_Crop_Wheat.uasset
│   │   │   ├── DA_Crop_Potato.uasset
│   │   │   ├── DA_Crop_Corn.uasset
│   │   │   └── ...
│   │   ├── Meshes/
│   │   │   ├── Wheat/
│   │   │   │   ├── SM_Wheat_Stage1.uasset
│   │   │   │   ├── SM_Wheat_Stage2.uasset
│   │   │   │   ├── SM_Wheat_Stage3.uasset
│   │   │   │   └── SM_Wheat_Stage4.uasset
│   │   │   └── Potato/
│   │   ├── Materials/
│   │   │   ├── M_Crop_Master.uasset
│   │   │   └── MI_Crop_Wheat.uasset
│   │   └── Textures/
│   │
│   ├── Environment/               # Environmental assets
│   │   ├── Terrain/
│   │   │   ├── Materials/
│   │   │   │   ├── M_Landscape_Master.uasset
│   │   │   │   └── Layers/
│   │   │   └── Textures/
│   │   ├── Foliage/
│   │   │   ├── Trees/
│   │   │   ├── Grass/
│   │   │   └── Flowers/
│   │   ├── Buildings/
│   │   │   ├── Farmhouse/
│   │   │   ├── Barn/
│   │   │   ├── Silo/
│   │   │   └── Garage/
│   │   ├── Props/
│   │   │   ├── Fences/
│   │   │   ├── Tools/
│   │   │   ├── Storage/
│   │   │   └── Decorative/
│   │   └── Sky/
│   │       ├── BP_SkyAtmosphere.uasset
│   │       └── M_SkyMaterial.uasset
│   │
│   ├── Systems/                   # Game systems
│   │   ├── Time/
│   │   │   ├── BP_TimeManager.uasset
│   │   │   └── WBP_TimeDisplay.uasset
│   │   ├── Weather/
│   │   │   ├── BP_WeatherManager.uasset
│   │   │   └── NS_Rain.uasset (Niagara System)
│   │   ├── Field/
│   │   │   ├── BP_FieldManager.uasset
│   │   │   ├── BP_Field.uasset
│   │   │   └── M_SoilVisualization.uasset
│   │   ├── Crops/
│   │   │   ├── BP_CropManager.uasset
│   │   │   └── BP_CropInstance.uasset
│   │   ├── Economy/
│   │   │   ├── BP_EconomyManager.uasset
│   │   │   └── DT_MarketPrices.uasset (DataTable)
│   │   └── Inventory/
│   │       └── BP_InventoryComponent.uasset
│   │
│   ├── UI/                        # User interface
│   │   ├── Common/                # Reusable UI widgets
│   │   │   ├── WBP_Button.uasset
│   │   │   ├── WBP_Tooltip.uasset
│   │   │   └── WBP_ProgressBar.uasset
│   │   ├── HUD/
│   │   │   ├── WBP_MainHUD.uasset
│   │   │   ├── WBP_TimeDisplay.uasset
│   │   │   ├── WBP_MoneyDisplay.uasset
│   │   │   └── WBP_InteractionPrompt.uasset
│   │   ├── Menus/
│   │   │   ├── WBP_MainMenu.uasset
│   │   │   ├── WBP_PauseMenu.uasset
│   │   │   └── WBP_SettingsMenu.uasset
│   │   ├── Inventory/
│   │   │   ├── WBP_InventoryMain.uasset
│   │   │   └── WBP_ItemSlot.uasset
│   │   ├── Shop/
│   │   │   ├── WBP_ShopMain.uasset
│   │   │   └── WBP_ShopItem.uasset
│   │   ├── Icons/                 # UI icons and sprites
│   │   │   ├── Items/
│   │   │   ├── Crops/
│   │   │   └── Actions/
│   │   └── Fonts/
│   │       └── Roboto/
│   │
│   ├── VFX/                       # Visual effects
│   │   ├── Weather/
│   │   │   ├── NS_Rain.uasset
│   │   │   ├── NS_Snow.uasset
│   │   │   └── NS_Dust.uasset
│   │   ├── Farming/
│   │   │   ├── NS_Watering.uasset
│   │   │   ├── NS_Harvest.uasset
│   │   │   └── NS_Planting.uasset
│   │   └── Particles/
│   │       └── Materials/
│   │
│   ├── Audio/                     # Sound effects and music
│   │   ├── Music/
│   │   │   ├── Theme_Main.uasset
│   │   │   └── Ambient_Day.uasset
│   │   ├── SFX/
│   │   │   ├── UI/
│   │   │   ├── Environment/
│   │   │   ├── Vehicles/
│   │   │   ├── Tools/
│   │   │   └── Actions/
│   │   └── Cues/                  # Sound cues
│   │
│   ├── Data/                      # Data assets and tables
│   │   ├── Crops/                 # Crop data assets
│   │   ├── Equipment/             # Equipment data assets
│   │   ├── DataTables/            # Data tables
│   │   │   ├── DT_CropPrices.uasset
│   │   │   ├── DT_EquipmentStats.uasset
│   │   │   └── DT_SeasonalData.uasset
│   │   └── Curves/                # Curve assets
│   │
│   ├── Input/                     # Enhanced Input System
│   │   ├── IMC_Default.uasset     # Input Mapping Context
│   │   ├── IMC_Vehicle.uasset
│   │   └── Actions/               # Input Actions
│   │       ├── IA_Move.uasset
│   │       ├── IA_Look.uasset
│   │       ├── IA_Interact.uasset
│   │       └── IA_Jump.uasset
│   │
│   └── Maps/                      # Level maps
│       ├── MainMenu.umap
│       ├── Prototype_Farm.umap    # Main prototype level
│       ├── TestMaps/              # Testing levels
│       │   ├── Test_Crops.umap
│       │   ├── Test_Vehicles.umap
│       │   └── Test_UI.umap
│       └── SubLevels/             # Level streaming sub-levels
│
└── ThirdParty/                    # Third-party assets
    ├── Megascans/
    └── AudioLibrary/
```

---

## 3. Source Code Structure

```
Source/
├── FarmingSimulator/              # Main game module
│   ├── FarmingSimulator.Build.cs  # Build configuration
│   ├── FarmingSimulator.h         # Module header
│   ├── FarmingSimulator.cpp       # Module implementation
│   │
│   ├── Public/                    # Public headers (.h files)
│   │   ├── Core/
│   │   │   ├── FSGameMode.h
│   │   │   ├── FSGameInstance.h
│   │   │   ├── FSPlayerController.h
│   │   │   └── FSSaveGame.h
│   │   │
│   │   ├── Characters/
│   │   │   ├── FSCharacter.h
│   │   │   └── FSCharacterAnimInstance.h
│   │   │
│   │   ├── Vehicles/
│   │   │   ├── FSVehicleBase.h
│   │   │   ├── FSTractor.h
│   │   │   └── FSImplementBase.h
│   │   │
│   │   ├── Crops/
│   │   │   ├── CropDataAsset.h
│   │   │   ├── CropInstance.h
│   │   │   └── CropManager.h
│   │   │
│   │   ├── Systems/
│   │   │   ├── TimeManager.h
│   │   │   ├── WeatherManager.h
│   │   │   ├── FieldManager.h
│   │   │   ├── EconomyManager.h
│   │   │   └── InventoryComponent.h
│   │   │
│   │   ├── UI/
│   │   │   └── FSUIManager.h
│   │   │
│   │   └── Data/
│   │       ├── FSTypes.h          # Common structs and enums
│   │       └── FSDataAssetBase.h
│   │
│   └── Private/                   # Private implementation (.cpp files)
│       ├── Core/
│       │   ├── FSGameMode.cpp
│       │   ├── FSGameInstance.cpp
│       │   ├── FSPlayerController.cpp
│       │   └── FSSaveGame.cpp
│       │
│       ├── Characters/
│       │   ├── FSCharacter.cpp
│       │   └── FSCharacterAnimInstance.cpp
│       │
│       ├── Vehicles/
│       │   ├── FSVehicleBase.cpp
│       │   ├── FSTractor.cpp
│       │   └── FSImplementBase.cpp
│       │
│       ├── Crops/
│       │   ├── CropDataAsset.cpp
│       │   ├── CropInstance.cpp
│       │   └── CropManager.cpp
│       │
│       ├── Systems/
│       │   ├── TimeManager.cpp
│       │   ├── WeatherManager.cpp
│       │   ├── FieldManager.cpp
│       │   ├── EconomyManager.cpp
│       │   └── InventoryComponent.cpp
│       │
│       ├── UI/
│       │   └── FSUIManager.cpp
│       │
│       └── Data/
│           └── FSDataAssetBase.cpp
│
└── FarmingSimulatorEditor/        # Editor-only module (optional)
    ├── FarmingSimulatorEditor.Build.cs
    └── Private/
        └── EditorTools/
```

---

## 4. Config Files

```
Config/
├── DefaultEngine.ini              # Engine configuration
├── DefaultGame.ini                # Game-specific settings
├── DefaultInput.ini               # Input configuration (legacy)
├── DefaultEditor.ini              # Editor preferences
├── DefaultScalability.ini         # Scalability settings
└── Windows/
    └── WindowsEngine.ini          # Platform-specific settings
```

---

## 5. Naming Conventions

### 5.1 Asset Prefixes

| Asset Type | Prefix | Example |
|------------|--------|---------|
| Blueprint Class | BP_ | BP_Tractor_Basic |
| Widget Blueprint | WBP_ | WBP_MainHUD |
| Static Mesh | SM_ | SM_Wheat_Stage1 |
| Skeletal Mesh | SK_ | SK_PlayerCharacter |
| Material | M_ | M_Crop_Master |
| Material Instance | MI_ | MI_Wheat_Healthy |
| Texture | T_ | T_Wheat_Diffuse |
| Normal Map | T_*_N | T_Wheat_N |
| Roughness Map | T_*_R | T_Wheat_R |
| Niagara System | NS_ | NS_Rain |
| Niagara Emitter | NE_ | NE_RainDrops |
| Animation | A_ | A_Player_Walk |
| Animation Blueprint | ABP_ | ABP_Player |
| Data Asset | DA_ | DA_Crop_Wheat |
| Data Table | DT_ | DT_MarketPrices |
| Curve | Curve_ | Curve_GrowthRate |
| Sound Cue | SC_ | SC_Engine_Idle |
| Sound Wave | SW_ | SW_Button_Click |
| Particle System | PS_ | PS_Dust (legacy, use Niagara) |
| Input Action | IA_ | IA_Move |
| Input Mapping Context | IMC_ | IMC_Default |

### 5.2 C++ Class Prefixes

| Class Type | Prefix | Example |
|------------|--------|---------|
| Actor | A | ATimeManager |
| Pawn | A | AFSTractor |
| Character | A | AFSCharacter |
| Controller | A | AFSPlayerController |
| Game Mode | A | AFSGameMode |
| Game Instance | U | UFSGameInstance |
| Object | U | UCropDataAsset |
| Component | U | UInventoryComponent |
| Widget | U | UFSMainHUD |
| Struct | F | FCropInstance |
| Enum | E | ECropGrowthState |
| Interface | I | IInteractable |

### 5.3 Folder Naming
- Use PascalCase for all folder names
- Be descriptive and consistent
- Group related assets together
- Avoid deep nesting (max 4-5 levels)

---

## 6. Version Control

### 6.1 .gitignore (Important Sections)

```
# Unreal Engine
Binaries/
Build/
DerivedDataCache/
Intermediate/
Saved/
*.sln
*.suo
*.sdf
*.opensdf
*.db
.vs/

# Visual Studio
.vs/
*.opendb
*.VC.db

# Rider
.idea/

# OS
.DS_Store
Thumbs.db
```

### 6.2 .gitattributes (Git LFS)

```
# Unreal Engine file types for LFS
*.uasset filter=lfs diff=lfs merge=lfs -text
*.umap filter=lfs diff=lfs merge=lfs -text
*.upk filter=lfs diff=lfs merge=lfs -text
*.udk filter=lfs diff=lfs merge=lfs -text

# 3D Formats
*.fbx filter=lfs diff=lfs merge=lfs -text
*.obj filter=lfs diff=lfs merge=lfs -text
*.blend filter=lfs diff=lfs merge=lfs -text
*.ma filter=lfs diff=lfs merge=lfs -text
*.mb filter=lfs diff=lfs merge=lfs -text

# Textures
*.png filter=lfs diff=lfs merge=lfs -text
*.tga filter=lfs diff=lfs merge=lfs -text
*.jpg filter=lfs diff=lfs merge=lfs -text
*.jpeg filter=lfs diff=lfs merge=lfs -text
*.exr filter=lfs diff=lfs merge=lfs -text
*.hdr filter=lfs diff=lfs merge=lfs -text
*.psd filter=lfs diff=lfs merge=lfs -text

# Audio
*.wav filter=lfs diff=lfs merge=lfs -text
*.mp3 filter=lfs diff=lfs merge=lfs -text
*.ogg filter=lfs diff=lfs merge=lfs -text

# Video
*.mp4 filter=lfs diff=lfs merge=lfs -text
*.mov filter=lfs diff=lfs merge=lfs -text
*.avi filter=lfs diff=lfs merge=lfs -text

# Archives
*.zip filter=lfs diff=lfs merge=lfs -text
*.rar filter=lfs diff=lfs merge=lfs -text
*.7z filter=lfs diff=lfs merge=lfs -text
```

---

## 7. Best Practices

### 7.1 Content Organization
1. **Never put assets in Content root** - Always use FarmingSimulator subfolder
2. **One asset per file** - Don't pack multiple meshes into one file
3. **Logical grouping** - Keep related assets together
4. **Avoid duplication** - Use shared folders for common assets
5. **Clean up regularly** - Delete unused assets

### 7.2 Blueprint vs C++
- **C++ for:** Core systems, performance-critical code, framework
- **Blueprints for:** Gameplay tweaking, content creation, quick iteration
- **Data Assets for:** All configuration data, avoid hardcoding

### 7.3 Performance
- Keep draw calls low (use instancing)
- LODs for all meshes
- Texture compression and mipmaps
- Minimize blueprint tick when possible
- Use object pooling for frequently spawned actors

---

## 8. Quick Reference Commands

### 8.1 Git Commands
```bash
# Initial setup
git init
git lfs install
git lfs track "*.uasset"
git lfs track "*.umap"

# Daily workflow
git status
git add .
git commit -m "Description of changes"
git push origin main

# Branch workflow
git checkout -b feature/crop-system
git merge main
git push origin feature/crop-system
```

### 8.2 Unreal Engine Commands
```
# Console commands (~ key)
stat fps                    # Show FPS
stat unit                   # Show frame time breakdown
stat gpu                    # Show GPU stats
r.ScreenPercentage 100      # Set screen percentage
t.MaxFPS 144                # Set max FPS
```

---

## 9. Documentation Standards

### 9.1 Code Documentation
- **C++ Classes:** Doxygen-style comments
- **Blueprint Nodes:** Tooltip and description
- **Functions:** Purpose, parameters, return value
- **Complex Logic:** Inline comments explaining why

### 9.2 Asset Documentation
- Use "Asset User Data" for complex assets
- README files in important folders
- Wiki pages for system documentation

---

## 10. Onboarding Checklist

### For New Team Members:
- [ ] Install Unreal Engine 5.4.x
- [ ] Install Visual Studio 2022 or Rider
- [ ] Install Git and Git LFS
- [ ] Clone repository
- [ ] Generate project files (.sln)
- [ ] Build project in editor
- [ ] Open test map and verify it works
- [ ] Read all documentation in Documentation/
- [ ] Review coding standards
- [ ] Set up IDE formatting rules
- [ ] Join team communication channels

---

**This structure is designed for scalability and can accommodate the full game as it grows through all development phases.**
