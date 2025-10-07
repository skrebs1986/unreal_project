# Phase 2 Setup Guide - Getting Started
**For Development Team**

This guide will walk you through setting up your development environment and creating the initial Unreal Engine 5 project for the Farming Simulator prototype.

---

## Part 1: Prerequisites

### 1.1 Required Software

#### Unreal Engine 5
- **Version:** 5.4.x (or latest stable 5.x)
- **Download:** Epic Games Launcher → Unreal Engine → Library → Engine Versions
- **Components to install:**
  - Engine Core
  - Starter Content (optional, for testing)
  - Templates and Feature Packs

#### IDE (Choose One)
**Option A: Visual Studio 2022 (Recommended for Windows)**
- **Edition:** Community (free) or Professional
- **Workloads:**
  - Desktop development with C++
  - Game development with C++
- **Individual Components:**
  - Windows 10/11 SDK
  - C++ profiling tools
  - C++ CMake tools
- **Download:** https://visualstudio.microsoft.com/downloads/

**Option B: Rider**
- **Version:** 2024.x
- **License:** Commercial or trial
- **Plugins:** Unreal Engine support (comes built-in)
- **Download:** https://www.jetbrains.com/rider/

#### Version Control
- **Git:** https://git-scm.com/downloads
- **Git LFS:** https://git-lfs.github.com/
- **Git Client (Optional):**
  - GitHub Desktop: https://desktop.github.com/
  - GitKraken: https://www.gitkraken.com/
  - SourceTree: https://www.sourcetreeapp.com/

### 1.2 Hardware Requirements

#### Minimum (Development Machine)
- CPU: Intel Core i7-8700 / AMD Ryzen 7 2700X
- RAM: 16 GB
- GPU: NVIDIA GTX 1660 / AMD RX 5600 XT
- Storage: 100 GB SSD available

#### Recommended
- CPU: Intel Core i9-12900K / AMD Ryzen 9 5900X
- RAM: 32 GB
- GPU: NVIDIA RTX 3070 / AMD RX 6800
- Storage: 250 GB NVMe SSD

---

## Part 2: Create Unreal Engine Project

### 2.1 Initial Project Creation

1. **Launch Unreal Engine 5**
   - Open Epic Games Launcher
   - Go to Unreal Engine → Library
   - Launch version 5.4.x

2. **Create New Project**
   - Select "Games" category
   - Choose "Third Person" template (we'll modify this)
   - **Project Settings:**
     - Project Type: **C++** (not Blueprint only!)
     - Target Platform: **Desktop**
     - Quality Preset: **Maximum**
     - Starter Content: **No** (we'll add our own)
     - Raytracing: **No** (optional performance consideration)
   - **Project Location:** `C:\projects\unreal_project\`
   - **Project Name:** `FarmingSimulator`

3. **Click "Create"**
   - Engine will create project and generate Visual Studio solution
   - This may take 5-10 minutes

4. **Initial Build**
   - Once editor opens, close it
   - Open `FarmingSimulator.sln` in Visual Studio or Rider
   - Build the solution (Ctrl+Shift+B in VS)
   - This compiles the game module

### 2.2 Project Configuration

#### Configure Project Settings

1. **Open Project in Editor**
2. **Edit → Project Settings**

**Engine - Rendering:**
- Default RHI: DirectX 12
- ☑ Support Compute Skinning
- ☑ Lumen: Global Illumination (Enabled)
- ☑ Lumen: Reflections (Enabled)
- ☑ Nanite Support (Enabled)
- ☑ Virtual Shadow Maps (Enabled)
- Anti-Aliasing Method: TSR (Temporal Super Resolution)

**Engine - Physics:**
- Default Gravity Z: -980.0
- Chaos Physics Enabled: ☑

**Project - Description:**
- Company Name: [Your Studio Name]
- Project Name: Farming Simulator
- Project Version: 0.1.0

**Project - Maps & Modes:**
- Default GameMode: BP_FSGameMode (we'll create this)
- Editor Startup Map: MainMenu
- Game Default Map: Prototype_Farm

**Engine - Input:**
- Default Player Input Class: EnhancedPlayerInput
- Default Input Component Class: EnhancedInputComponent

#### Save Settings
- File → Save All

---

## Part 3: Set Up Version Control

### 3.1 Initialize Git Repository

**Using Command Line:**

```bash
# Navigate to project folder
cd C:\projects\unreal_project

# Initialize git repository
git init

# Configure Git LFS
git lfs install
git lfs track "*.uasset"
git lfs track "*.umap"
git lfs track "*.fbx"
git lfs track "*.png"
git lfs track "*.wav"
git lfs track "*.mp3"
git lfs track "*.psd"
git lfs track "*.tga"

# Create .gitignore
# (Use the .gitignore from ProjectStructure.md)

# Create .gitattributes
# (Use the .gitattributes from ProjectStructure.md)

# Add all files
git add .

# Initial commit
git commit -m "Initial project setup - Unreal Engine 5 Farming Simulator"

# Add remote (replace with your repo URL)
git remote add origin https://github.com/yourstudio/farming-simulator.git

# Push to remote
git push -u origin main
```

**Using GitHub Desktop:**
1. Open GitHub Desktop
2. File → Add Local Repository
3. Choose `C:\projects\unreal_project`
4. Click "Create Repository"
5. Add .gitignore and .gitattributes files (from ProjectStructure.md)
6. Commit all files: "Initial project setup"
7. Publish repository to GitHub

### 3.2 Branch Strategy

**Main Branches:**
- `main` - Production-ready code
- `develop` - Active development branch

**Feature Branches:**
- `feature/player-controller`
- `feature/crop-system`
- `feature/time-manager`
- etc.

**Command to create feature branch:**
```bash
git checkout -b feature/your-feature-name
```

---

## Part 4: Project Structure Setup

### 4.1 Create Folder Structure

**In Content Browser (Unreal Editor):**

Right-click → New Folder:

```
Content/
└── FarmingSimulator/
    ├── Core/
    ├── Characters/
    ├── Vehicles/
    ├── Crops/
    ├── Environment/
    ├── Systems/
    ├── UI/
    ├── VFX/
    ├── Audio/
    ├── Data/
    ├── Input/
    └── Maps/
```

**Create these folders now** - Having consistent structure from the start is critical.

### 4.2 Create Source Code Structure

The C++ class headers have already been created in:
- `Source/FarmingSimulator/Public/`
- `Source/FarmingSimulator/Private/`

**You need to:**
1. Create corresponding `.cpp` implementation files
2. Update `FarmingSimulator.Build.cs` with dependencies

#### Update Build.cs

Edit: `Source/FarmingSimulator/FarmingSimulator.Build.cs`

```csharp
using UnrealBuildTool;

public class FarmingSimulator : ModuleRules
{
	public FarmingSimulator(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",        // Enhanced Input System
			"UMG",                  // UI
			"Slate",
			"SlateCore",
			"Niagara",              // VFX
			"ChaosVehicles",        // Vehicle physics
			"PhysicsCore"
		});

		PrivateDependencyModuleNames.AddRange(new string[]
		{
			"AIModule",
			"NavigationSystem"
		});

		// Include paths
		PublicIncludePaths.AddRange(new string[]
		{
			"FarmingSimulator/Public"
		});

		PrivateIncludePaths.AddRange(new string[]
		{
			"FarmingSimulator/Private"
		});
	}
}
```

---

## Part 5: Create Blueprint Base Classes

### 5.1 Game Mode Blueprint

1. **Content Browser** → `Content/FarmingSimulator/Core/GameMode/`
2. Right-click → Blueprint Class
3. Parent Class: Search for "FSGameMode" (your C++ class)
4. Name: `BP_FSGameMode`
5. **Open BP_FSGameMode**
6. Set System Manager Classes:
   - Time Manager Class: `BP_TimeManager` (we'll create this)
   - Weather Manager Class: `BP_WeatherManager`
   - Field Manager Class: `BP_FieldManager`
7. **Compile and Save**

### 5.2 Player Character Blueprint

1. Navigate to: `Content/FarmingSimulator/Characters/Player/`
2. Right-click → Blueprint Class
3. Parent Class: Search for "FSCharacter"
4. Name: `BP_PlayerCharacter`
5. **Open and configure:**
   - Set skeletal mesh (use UE5 Manny for now)
   - Configure camera boom and camera settings
   - Set default walk/run speeds
6. **Compile and Save**

### 5.3 Player Controller Blueprint

1. Navigate to: `Content/FarmingSimulator/Core/PlayerController/`
2. Right-click → Blueprint Class
3. Parent Class: PlayerController
4. Name: `BP_FSPlayerController`
5. **Compile and Save**

---

## Part 6: Input System Setup

### 6.1 Create Input Actions

**Location:** `Content/FarmingSimulator/Input/Actions/`

Create these Input Actions (Right-click → Input → Input Action):

1. **IA_Move**
   - Value Type: Axis2D (Vector 2D)

2. **IA_Look**
   - Value Type: Axis2D (Vector 2D)

3. **IA_Jump**
   - Value Type: Digital (bool)

4. **IA_Interact**
   - Value Type: Digital (bool)

5. **IA_Sprint**
   - Value Type: Digital (bool)

6. **IA_OpenInventory**
   - Value Type: Digital (bool)

7. **IA_Zoom**
   - Value Type: Axis1D (float)

### 6.2 Create Input Mapping Context

**Location:** `Content/FarmingSimulator/Input/`

1. Right-click → Input → Input Mapping Context
2. Name: `IMC_Default`
3. **Open IMC_Default**
4. **Add Mappings:**

| Action | Key | Modifiers |
|--------|-----|-----------|
| IA_Move | W | Scale: X=1, Y=1 |
| IA_Move | S | Scale: X=-1, Y=1 |
| IA_Move | A | Scale: X=1, Y=-1 |
| IA_Move | D | Scale: X=1, Y=1 |
| IA_Look | Mouse XY 2D-Axis | - |
| IA_Jump | Space Bar | - |
| IA_Interact | E | - |
| IA_Sprint | Left Shift | - |
| IA_OpenInventory | Tab | - |
| IA_Zoom | Mouse Wheel Axis | - |

5. **Also add Gamepad support:**

| Action | Gamepad Input |
|--------|---------------|
| IA_Move | Left Thumbstick 2D-Axis |
| IA_Look | Right Thumbstick 2D-Axis |
| IA_Jump | Gamepad Face Button Bottom |
| IA_Interact | Gamepad Face Button Right |
| IA_Sprint | Left Thumbstick Button |

6. **Save**

### 6.3 Assign Input Context to Character

1. Open `BP_PlayerCharacter`
2. **Event BeginPlay**
3. Add node: **Add Mapping Context**
   - Mapping Context: `IMC_Default`
   - Priority: 0
4. **Connect to BeginPlay**
5. **Compile and Save**

---

## Part 7: Create Test Map

### 7.1 Create Prototype Map

1. **File → New Level**
2. Choose **Open World** template
3. **Save As:** `Content/FarmingSimulator/Maps/Prototype_Farm`

### 7.2 Configure Map

**Delete default content:**
- Remove example landscape if you want to create your own

**Add essentials:**
1. **Directional Light** (Sun)
   - Intensity: 10
   - Dynamic: Movable (for day/night cycle)
   - Tag: "Sun" (for TimeManager to find it)

2. **Sky Atmosphere**
   - Default settings

3. **Volumetric Cloud**
   - Default settings

4. **Sky Light**
   - Intensity: 1.0
   - Real Time Capture: ☑

5. **Exponential Height Fog**
   - Fog Density: 0.02

6. **Post Process Volume**
   - Infinite Extent: ☑
   - Configure tonemapping and exposure

**Add Landscape:**
1. **Landscape Mode** (Shift+2)
2. **New Landscape**
   - Section Size: 63x63 quads
   - Sections Per Component: 1x1
   - Number of Components: 8x8
   - Overall Resolution: 505x505
3. **Create**
4. **Sculpt basic terrain** (hills, valleys)

**Add Player Start:**
1. Place **Player Start** actor in world
2. Position at farmhouse location

### 7.3 Set as Default Map

1. **Edit → Project Settings**
2. **Maps & Modes**
3. Editor Startup Map: `Prototype_Farm`
4. Game Default Map: `Prototype_Farm`
5. **Save**

---

## Part 8: Verify Setup

### 8.1 Test Compilation

1. **Close Unreal Editor**
2. **Open Visual Studio**
3. **Build Solution** (Ctrl+Shift+B)
4. **Verify:** 0 Errors (warnings are okay for now)

### 8.2 Test In-Editor

1. **Launch Unreal Editor**
2. **Open Prototype_Farm**
3. **PIE (Play In Editor)** - Press Play button or Alt+P
4. **Verify:**
   - Character spawns
   - Can move with WASD
   - Camera follows character
   - No errors in Output Log

### 8.3 Common Issues & Fixes

**Issue: "FSGameMode not found"**
- Solution: Build the C++ project first before creating Blueprints

**Issue: "Module FarmingSimulator could not be loaded"**
- Solution: Rebuild solution, restart editor

**Issue: "Input not responding"**
- Solution: Check Input Mapping Context is added in BeginPlay

**Issue: "Character falls through world"**
- Solution: Add collision to landscape or floor

---

## Part 9: Team Workflow

### 9.1 Daily Workflow

**Morning:**
```bash
# Pull latest changes
git checkout develop
git pull origin develop

# Create/switch to feature branch
git checkout -b feature/your-task
```

**During Work:**
```bash
# Check status frequently
git status

# Stage and commit changes
git add .
git commit -m "Descriptive message of what you did"
```

**End of Day:**
```bash
# Push your branch
git push origin feature/your-task

# Create Pull Request on GitHub/GitLab
# Request code review from lead
```

### 9.2 Communication

**Daily Stand-up (15 min):**
- What did you complete yesterday?
- What are you working on today?
- Any blockers?

**Weekly Review (Friday):**
- Demo completed work
- Review progress vs schedule
- Plan next week

### 9.3 Code Review Checklist

Before submitting Pull Request:
- [ ] Code compiles with no errors
- [ ] Tested in PIE (Play In Editor)
- [ ] No critical performance issues
- [ ] Follows coding standards
- [ ] Comments added for complex logic
- [ ] No debug/test code left in

---

## Part 10: Next Steps

### Week 5 Tasks (First Week)

**Programming Team:**
- Implement `.cpp` files for created `.h` headers
- Create TimeManager implementation
- Set up save/load system architecture

**Art Team:**
- Create basic landscape materials
- Set up placeholder character
- Create test field meshes

**Design Team:**
- Create first crop data assets (Wheat, Potato)
- Define balancing spreadsheet
- Write tutorial script

### Resources

**Documentation:**
- Unreal Engine Docs: https://docs.unrealengine.com/
- C++ API Reference: https://docs.unrealengine.com/en-US/API/
- Enhanced Input: https://docs.unrealengine.com/5.0/en-US/enhanced-input-in-unreal-engine/

**Team Communication:**
- Slack/Discord: [Your channel]
- Jira: [Your board URL]
- Wiki: [Your wiki URL]

---

## Troubleshooting

### Can't Find Custom C++ Classes in Blueprint

**Solution:**
1. Close Editor
2. Delete `Binaries/`, `Intermediate/`, `Saved/` folders
3. Right-click `.uproject` → Generate Visual Studio project files
4. Open `.sln` and rebuild
5. Launch editor

### Git LFS Not Working

**Solution:**
```bash
git lfs install
git lfs track "*.uasset"
git lfs track "*.umap"
git add .gitattributes
git commit -m "Configure Git LFS"
```

### Performance Issues in Editor

**Solution:**
1. Edit → Editor Preferences
2. General → Performance
3. Use Less CPU when in Background: ☑
4. Lower "Editor Viewport Resolution"

---

## Support

**Technical Lead:** [Name/Email]
**Art Lead:** [Name/Email]
**Design Lead:** [Name/Email]

**For urgent issues:**
- Post in #tech-support channel
- Tag @leads in message

---

**Ready to start Phase 2!** 🚀

Once everyone has completed this setup, we'll begin Week 5 tasks.

Good luck team!
