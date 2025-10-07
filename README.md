# Farming Simulator - UE5 Project Setup

🎮 **Farming Simulation Game** | Unreal Engine 5 | PC

---

## 📋 Quick Status

**Current Phase:** Phase 2 - Prototype & Core Systems (Week 5)

### ✅ Completed
- Phase 1 Pre-Production (All design documents)
- Project planning and architecture
- C++ class headers
- Git repository setup

### ⏳ In Progress
- **UE5 Project Setup** ← YOU ARE HERE

---

## 🚀 START HERE

**Choose your IDE:**

### Option A: JetBrains Rider (Recommended ⭐)
👉 **Follow: [SETUP_INSTRUCTIONS_RIDER.md](SETUP_INSTRUCTIONS_RIDER.md)** 👈
- Faster, better IntelliSense
- Native Unreal Engine support
- Modern IDE experience

### Option B: Visual Studio 2022
👉 **Follow: [SETUP_INSTRUCTIONS.md](SETUP_INSTRUCTIONS.md)** 👈
- Free and fully featured
- Official Microsoft tooling
- Good UE5 integration

**Both guides walk you through:**
1. Installing your chosen IDE
2. Installing Unreal Engine 5.4
3. Creating the UE5 project
4. Setting up Git LFS
5. Building and running the project

**Estimated Time:** 2-3 hours (mostly downloads)

---

## 📚 Documentation

All project documentation is in the `/Documentation/` folder:

### Essential Reading
1. **[SETUP_INSTRUCTIONS.md](SETUP_INSTRUCTIONS.md)** - Setup guide (START HERE!)
2. **[Documentation/README.md](Documentation/README.md)** - Documentation overview
3. **[Documentation/Phase2_SetupGuide.md](Documentation/Phase2_SetupGuide.md)** - Detailed development guide
4. **[FarmingSimulator_ProjectPlan.md](FarmingSimulator_ProjectPlan.md)** - Project timeline

### Design Documents (Phase 1)
- [GameDesignDocument.md](Documentation/GameDesignDocument.md) - Complete game design
- [TechnicalDesignSpecification.md](Documentation/TechnicalDesignSpecification.md) - Technical architecture
- [ArtStyleGuide.md](Documentation/ArtStyleGuide.md) - Visual style guide
- [CoreFarmingMechanics.md](Documentation/CoreFarmingMechanics.md) - Gameplay mechanics
- [ScopeAndResourcePlanning.md](Documentation/ScopeAndResourcePlanning.md) - Budget and timeline

### Development Documents (Phase 2)
- [Phase2_PrototypeAndCoreSystems.md](Documentation/Phase2_PrototypeAndCoreSystems.md) - Week-by-week tasks
- [ProjectStructure.md](Documentation/ProjectStructure.md) - Folder organization

---

## 🛠️ Requirements

### Software Needed
- **Unreal Engine 5.4+** (via Epic Games Launcher)
- **IDE - Choose one:**
  - **JetBrains Rider** (recommended) - $149/year or free student license
  - **Visual Studio 2022 Community** (free)
- **Windows Build Tools** (required even with Rider)
- **Git** with Git LFS
- **Windows 10/11** 64-bit

### Hardware Minimum
- CPU: Intel Core i7-8700 / AMD Ryzen 7 2700X
- RAM: 16 GB
- GPU: NVIDIA GTX 1660 / AMD RX 5600 XT
- Storage: 100 GB SSD

### Hardware Recommended
- CPU: Intel Core i9-12900K / AMD Ryzen 9 5900X
- RAM: 32 GB
- GPU: NVIDIA RTX 3070 / AMD RX 6800
- Storage: 250 GB NVMe SSD

---

## 📁 Project Structure

```
FarmingSimulator/           (will be created by UE5)
├── Content/                (Unreal assets)
├── Source/                 (C++ source code)
│   └── FarmingSimulator/
│       ├── Public/         (C++ headers - already created!)
│       │   ├── Core/
│       │   ├── Characters/
│       │   ├── Systems/
│       │   ├── Crops/
│       │   └── Data/
│       └── Private/        (C++ implementations - to be created)
├── Documentation/          (All project docs)
├── Config/                 (UE5 config files)
├── Saved/                  (Generated files, not in git)
├── Intermediate/           (Build files, not in git)
└── Binaries/               (Compiled binaries, not in git)
```

---

## 🎯 Setup Checklist

Use this to track your progress:

### Installation Phase
- [ ] Choose IDE:
  - [ ] **Option A:** JetBrains Rider + VS Build Tools
  - [ ] **Option B:** Visual Studio 2022 Community (full IDE)
- [ ] Install Windows Build Tools or Visual Studio
  - [ ] Game development with C++ workload (or MSVC build tools)
  - [ ] Windows 10/11 SDK
- [ ] Install Epic Games Launcher
- [ ] Install Unreal Engine 5.4
- [ ] Install Git
- [ ] Install Git LFS

### Project Creation Phase
- [ ] Launch Unreal Engine 5.4
- [ ] Create new C++ project (Third Person template)
- [ ] Project name: FarmingSimulator
- [ ] Location: C:\projects\
- [ ] Wait for project generation

### Integration Phase
- [ ] Copy Documentation folder to UE5 project
- [ ] Copy C++ headers to Source folder
- [ ] Copy .gitignore and .gitattributes
- [ ] Initialize Git in UE5 project folder
- [ ] Configure Git LFS

### Build Phase
- [ ] Open FarmingSimulator.sln in your IDE (Rider or VS)
- [ ] Build solution (Ctrl+Shift+B or F6)
- [ ] Launch editor (F5 or Shift+F10 in Rider)
- [ ] Verify project opens successfully

### Ready to Develop! 🎉
- [ ] Read Phase2_SetupGuide.md
- [ ] Start Week 5 tasks

---

## 🆘 Common Issues

### "Module could not be loaded"
**Fix:** Rebuild the solution in your IDE (Ctrl+Shift+B)

### "Build tools not found" (Rider users)
**Fix:** Install Visual Studio Build Tools (see SETUP_INSTRUCTIONS_RIDER.md Step 2)

### "Cannot compile - compiler not found"
**Fix:** Install MSVC build tools via Visual Studio or VS Build Tools

### Build errors
**Fix:** Make sure all files copied to correct locations

### Git LFS not working
```bash
git lfs install
git lfs track "*.uasset"
git lfs track "*.umap"
```

---

## 📞 Support

**Having issues?**
- Check: [SETUP_INSTRUCTIONS.md](SETUP_INSTRUCTIONS.md)
- UE5 Docs: https://docs.unrealengine.com/
- UE5 Forums: https://forums.unrealengine.com/

---

## 🗓️ Project Timeline

**Total Duration:** 56 weeks (14 months)
**Current Week:** Week 5 of 56
**Current Phase:** Phase 2 - Prototype & Core Systems (Weeks 5-12)

### Upcoming Milestones
- **Week 6:** Player controller functional
- **Week 7:** Time/weather systems
- **Week 12:** Playable prototype complete
- **Week 36:** Alpha build
- **Week 56:** Launch! 🚀

---

## 👥 Team Info

**Team Size:** 20 people
**Budget:** $2.7M - $3.4M
**Platform:** PC (Windows), Future: PS5, Xbox Series X/S

---

**Let's build an amazing farming simulator!** 🌾🚜

**Next Step:** Read [SETUP_INSTRUCTIONS.md](SETUP_INSTRUCTIONS.md)
