# Farming Simulator - Unreal Engine 5
**Production Documentation**

---

## Project Overview

A realistic farming simulation game built in Unreal Engine 5, targeting PC platform with potential console ports. Players manage their own farm, grow crops, operate equipment, and build a thriving agricultural business.

**Engine:** Unreal Engine 5.4+
**Platform:** PC (Windows), Future: PS5, Xbox Series X/S
**Genre:** Farming Simulation / Management
**Development Time:** 56 Weeks (14 Months)
**Team Size:** 20 people
**Budget:** $2.7M - $3.4M

---

## Current Status

### ✅ Phase 1: Pre-Production (COMPLETE)
**Duration:** Weeks 1-4
**Status:** All documentation complete

**Deliverables:**
- ✅ Game Design Document
- ✅ Technical Design Specification
- ✅ Art Style Guide
- ✅ Core Farming Mechanics Definition
- ✅ Scope and Resource Planning

### 🚧 Phase 2: Prototype & Core Systems (IN PROGRESS)
**Duration:** Weeks 5-12 (Current Phase)
**Status:** Setup and planning complete, ready for development

---

## Documentation Index

### Phase 1 Documents (Complete)
1. **[GameDesignDocument.md](GameDesignDocument.md)**
   - Complete game design including all systems, mechanics, UI, progression
   - Player experience flow and success metrics
   - Competitive analysis and market positioning

2. **[TechnicalDesignSpecification.md](TechnicalDesignSpecification.md)**
   - System architecture and core class design
   - UE5 implementation strategy
   - Performance optimization plan
   - Networking architecture for future multiplayer

3. **[ArtStyleGuide.md](ArtStyleGuide.md)**
   - Visual identity and art direction
   - Color palettes and style references
   - Asset creation standards and pipelines
   - Technical art specifications

4. **[CoreFarmingMechanics.md](CoreFarmingMechanics.md)**
   - Detailed mechanics breakdown
   - Field preparation, planting, maintenance, harvesting
   - Economy system and progression
   - Balancing considerations

5. **[ScopeAndResourcePlanning.md](ScopeAndResourcePlanning.md)**
   - Complete project timeline (56 weeks)
   - Team structure and resource allocation
   - Budget breakdown ($2.7M-$3.4M)
   - Risk assessment and mitigation

### Phase 2 Documents (Setup Complete)
6. **[Phase2_PrototypeAndCoreSystems.md](Phase2_PrototypeAndCoreSystems.md)**
   - Week-by-week task breakdown (Weeks 5-12)
   - Department-specific assignments
   - Technical specifications and class architecture
   - Success criteria and milestones

7. **[ProjectStructure.md](ProjectStructure.md)**
   - Complete folder structure for Content and Source
   - Naming conventions and best practices
   - Version control configuration
   - Blueprint vs C++ guidelines

8. **[Phase2_SetupGuide.md](Phase2_SetupGuide.md)** ⭐ START HERE
   - Step-by-step setup instructions
   - Software installation and configuration
   - Project creation and setup
   - Team workflow and daily practices

---

## Quick Start (For New Team Members)

### 1. Read Documentation (Day 1)
1. Start with [GameDesignDocument.md](GameDesignDocument.md) - Understand the game vision
2. Read [Phase2_SetupGuide.md](Phase2_SetupGuide.md) - Technical setup
3. Review [ProjectStructure.md](ProjectStructure.md) - Learn the organization
4. Browse your department's sections in [Phase2_PrototypeAndCoreSystems.md](Phase2_PrototypeAndCoreSystems.md)

### 2. Setup Development Environment (Day 1-2)
Follow **[Phase2_SetupGuide.md](Phase2_SetupGuide.md)** exactly:
- Install Unreal Engine 5.4
- Install IDE (Visual Studio 2022 or Rider)
- Install Git and Git LFS
- Clone repository
- Build project
- Verify everything works

### 3. Start Development (Day 3+)
- Attend daily stand-up
- Pick up tasks from Jira board
- Follow team workflow in setup guide
- Commit code daily
- Request code reviews

---

## Project Structure Overview

```
FarmingSimulator/
├── Content/
│   └── FarmingSimulator/
│       ├── Core/              # Game framework (GameMode, Controllers)
│       ├── Characters/        # Player and NPCs
│       ├── Vehicles/          # Tractors and equipment
│       ├── Crops/             # Crop assets and data
│       ├── Environment/       # Terrain, buildings, props
│       ├── Systems/           # Time, Weather, Economy
│       ├── UI/                # All user interfaces
│       ├── VFX/               # Visual effects (Niagara)
│       ├── Audio/             # Sounds and music
│       ├── Data/              # Data assets and tables
│       ├── Input/             # Enhanced Input setup
│       └── Maps/              # Level maps
│
├── Source/
│   └── FarmingSimulator/
│       ├── Public/            # Header files (.h)
│       │   ├── Core/
│       │   ├── Characters/
│       │   ├── Vehicles/
│       │   ├── Crops/
│       │   ├── Systems/
│       │   └── Data/
│       └── Private/           # Implementation files (.cpp)
│
└── Documentation/             # All project documentation
    ├── README.md              # This file
    ├── Phase 1 docs...        # Design documents
    └── Phase 2 docs...        # Development guides
```

---

## Key Systems

### Core Systems (C++ Classes)

**Game Framework:**
- `AFSGameMode` - Main game mode, spawns system managers
- `AFSGameInstance` - Persistent game data
- `AFSPlayerController` - Player input and UI management
- `AFSSaveGame` - Save/load system

**Player:**
- `AFSCharacter` - Player character with movement and interaction
- `UInventoryComponent` - Inventory management

**World Systems:**
- `ATimeManager` - Day/night cycle, seasons, time progression
- `AWeatherManager` - Dynamic weather system
- `AFieldManager` - Field and soil management
- `UEconomyManager` - Market pricing and economy

**Crops:**
- `UCropDataAsset` - Data asset defining crop properties
- `FCropInstance` - Individual crop instance data
- `UCropManager` - Manages all crops in the world

**Vehicles:**
- `AFSVehicleBase` - Base vehicle class (Chaos physics)
- `AFSTractor` - Tractors
- `AFSImplementBase` - Attachable implements

**Data Types:**
- `FSTypes.h` - Common structs and enums (soil, weather, crops, etc.)

---

## Development Guidelines

### Coding Standards
- Follow Unreal Engine C++ coding standards
- Use prefix conventions (A for Actor, U for Object, F for struct, E for enum)
- Comment all public functions
- Blueprint-exposed functions need tooltips

### Asset Naming
- Use prefixes: `BP_` Blueprint, `SM_` Static Mesh, `T_` Texture, `M_` Material
- PascalCase for all names
- Be descriptive: `SM_Wheat_Stage3` not `wheat3`

### Version Control
- Commit frequently with descriptive messages
- Create feature branches for new work
- Request code reviews before merging
- Never commit to main directly

### Performance
- Target 60 FPS on recommended specs
- Use Instanced Static Meshes for crops
- LODs for all meshes
- Profile regularly with Unreal Insights

---

## Phase 2 Milestones

| Week | Milestone | Status |
|------|-----------|--------|
| 5 | Project setup complete | 🚧 In Progress |
| 6 | Player controller functional | ⏳ Pending |
| 7 | Time & weather systems working | ⏳ Pending |
| 8 | Field system ready | ⏳ Pending |
| 9 | Crops can be planted | ⏳ Pending |
| 10 | Full crop lifecycle (plant → harvest) | ⏳ Pending |
| 11 | Vehicle system functional | ⏳ Pending |
| 12 | Complete playable prototype | ⏳ Pending |

**Success Criteria for Phase 2:**
- ✅ Player can move and interact
- ✅ Day/night cycle with weather
- ✅ Plant → Grow → Harvest loop works
- ✅ Basic tractor and plow functional
- ✅ Simple economy (buy seeds, sell crops)
- ✅ 15-30 minutes of fun gameplay
- ✅ 60 FPS on target hardware

---

## Team Contacts

### Leadership
- **Project Director:** [Name] - [Email]
- **Game Director:** [Name] - [Email]
- **Technical Director:** [Name] - [Email]

### Department Leads
- **Lead Programmer:** [Name] - [Email]
- **Lead Artist:** [Name] - [Email]
- **Lead Designer:** [Name] - [Email]
- **QA Lead:** [Name] - [Email]

### Communication Channels
- **Slack Workspace:** [URL]
- **Jira Board:** [URL]
- **Wiki:** [URL]
- **Git Repository:** [URL]

---

## Support & Resources

### Documentation
- **Unreal Engine Docs:** https://docs.unrealengine.com/
- **UE5 C++ API:** https://docs.unrealengine.com/en-US/API/
- **Enhanced Input Guide:** https://docs.unrealengine.com/5.0/en-US/enhanced-input-in-unreal-engine/
- **Chaos Vehicles:** https://docs.unrealengine.com/5.0/en-US/vehicles-in-unreal-engine/

### Learning Resources
- **Unreal Engine YouTube:** https://www.youtube.com/c/UnrealEngine
- **Unreal Engine Forums:** https://forums.unrealengine.com/
- **Unreal Slackers Discord:** https://unrealslackers.org/

### Getting Help
1. Check documentation first
2. Ask in team Slack channel
3. Post in #tech-support for technical issues
4. Escalate to leads if blocked

---

## Build Information

### Current Build
- **Version:** 0.1.0 (Prototype)
- **Engine:** Unreal Engine 5.4.x
- **Platform:** Windows 64-bit
- **Configuration:** Development

### Build Requirements
- **Minimum Specs:** See [TechnicalDesignSpecification.md](TechnicalDesignSpecification.md)
- **Recommended Specs:** See [TechnicalDesignSpecification.md](TechnicalDesignSpecification.md)

---

## License & Legal

**Copyright:** [Studio Name], 2025
**Engine:** Unreal Engine 5 (Epic Games)
**License:** Proprietary - All Rights Reserved

This project and all associated documentation are confidential and proprietary. Do not share outside the development team without authorization.

---

## Changelog

### Version 0.1.0 - Phase 2 Setup (Current)
- Initial project setup
- Phase 1 documentation complete
- Phase 2 planning and architecture complete
- C++ class headers created
- Project structure established

### Version 0.0.1 - Pre-Production
- Game design documentation
- Technical specifications
- Art direction
- Resource planning

---

**Last Updated:** October 7, 2025
**Next Milestone:** Week 5 Complete (Player Controller Functional)
**Status:** Active Development - Phase 2 🚀

---

**Let's build something amazing!** 💪🌾🚜
