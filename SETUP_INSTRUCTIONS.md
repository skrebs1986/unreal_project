# Farming Simulator UE5 - Setup Instructions
**Quick Start Guide for Your Machine**

---

## Current Status
✅ Project structure created
✅ Git repository initialized
✅ Documentation complete
✅ C++ class headers created
⏳ **Need to install: Unreal Engine 5 + Visual Studio 2022**

---

## Step 1: Install Visual Studio 2022 (Required for UE5 C++)

### Download and Install

1. **Download Visual Studio 2022 Community (FREE)**
   - Go to: https://visualstudio.microsoft.com/downloads/
   - Download "Visual Studio 2022 Community"

2. **Run the Installer**
   - When the Visual Studio Installer opens, select these workloads:

   **✅ Must Have:**
   - **Game development with C++**

   **Individual Components (also select):**
   - Windows 10 SDK (10.0.19041.0 or newer)
   - Windows 11 SDK (latest)
   - C++ profiling tools
   - C++ AddressSanitizer

3. **Install**
   - Click "Install" (this will take 30-60 minutes)
   - Restart your computer when finished

---

## Step 2: Install Unreal Engine 5

### Download Epic Games Launcher

1. **Get Epic Games Launcher**
   - Go to: https://www.epicgames.com/store/en-US/download
   - Download and install Epic Games Launcher
   - Sign in or create an Epic Games account

2. **Install Unreal Engine 5**
   - Open Epic Games Launcher
   - Click on "Unreal Engine" tab on the left
   - Click "Library" at the top
   - Click the **+** button next to "ENGINE VERSIONS"
   - Select **Unreal Engine 5.4.x** (or latest 5.x version)
   - Click "Install"
   - **Installation location:** Default is fine (C:\\Program Files\\Epic Games\\UE_5.4)
   - **Installation takes:** 1-2 hours, ~80GB space required

3. **Wait for Installation to Complete**
   - You can do something else while this downloads/installs

---

## Step 3: Create the UE5 Project

### Once UE5 is Installed:

1. **Launch Unreal Engine 5.4**
   - From Epic Games Launcher → Library → Launch

2. **Create New Project**
   - Click "Games" category
   - Select **"Third Person"** template
   - **Important Settings:**
     - Project Type: **C++** (NOT Blueprint!)
     - Target Platform: **Desktop**
     - Quality Preset: **Maximum**
     - Starter Content: **No**
     - Raytracing: **No** (optional, for better performance)

3. **Project Location and Name**
   - **Location:** Browse to `C:\projects\`
   - **Project Name:** `FarmingSimulator`
   - This will create the project at: `C:\projects\FarmingSimulator\`

4. **Click "Create"**
   - UE5 will generate the project (5-10 minutes)
   - It will automatically generate Visual Studio solution files
   - The editor will open when ready

5. **Close the Editor** (for now)
   - We need to organize the project structure properly

---

## Step 4: Move Our Files into the UE5 Project

After UE5 creates the project, you'll have a new folder structure. We need to integrate our existing files:

### Here's what to do:

1. **Copy Documentation**
   ```
   Copy from: C:\projects\unreal_project\Documentation\
   To: C:\projects\FarmingSimulator\Documentation\
   ```

2. **Copy Our C++ Headers**
   ```
   Copy from: C:\projects\unreal_project\Source\FarmingSimulator\Public\
   To: C:\projects\FarmingSimulator\Source\FarmingSimulator\Public\
   ```

3. **Copy Git Configuration**
   ```
   Copy: C:\projects\unreal_project\.gitignore
   To: C:\projects\FarmingSimulator\.gitignore

   Copy: C:\projects\unreal_project\.gitattributes
   To: C:\projects\FarmingSimulator\.gitattributes
   ```

4. **Copy Project Plan**
   ```
   Copy: C:\projects\unreal_project\FarmingSimulator_ProjectPlan.md
   To: C:\projects\FarmingSimulator\FarmingSimulator_ProjectPlan.md
   ```

---

## Step 5: Configure Git for the UE5 Project

Open Command Prompt or PowerShell in `C:\projects\FarmingSimulator\`:

```bash
# Initialize Git (if not already)
git init

# Install Git LFS
git lfs install

# Track large files with LFS
git lfs track "*.uasset"
git lfs track "*.umap"
git lfs track "*.fbx"
git lfs track "*.png"

# Add all files
git add .

# Commit
git commit -m "Initial UE5 project setup"

# Set remote (use your existing repo or create new one)
git remote add origin https://github.com/skrebs1986/FarmingSimulator.git

# Push
git push -u origin main
```

---

## Step 6: Open and Build the Project

1. **Open the Solution in Visual Studio**
   - Navigate to: `C:\projects\FarmingSimulator\`
   - Double-click `FarmingSimulator.sln`

2. **Build the Project**
   - In Visual Studio, press `Ctrl+Shift+B` to build
   - OR: Build → Build Solution
   - Wait for compilation (5-10 minutes first time)
   - You should see: "Build succeeded"

3. **Launch the Editor**
   - In Visual Studio: Press `F5` to debug
   - OR: Open Epic Games Launcher → Library → My Projects → FarmingSimulator → Launch

---

## Step 7: Verify Everything Works

Once the editor opens:

1. **Check the Content Browser**
   - Should see "Content" folder

2. **Create a Test Level**
   - File → New Level → Basic
   - Save as: `Content/Maps/TestLevel`

3. **Test Play**
   - Click the "Play" button (or Alt+P)
   - You should spawn in an empty level
   - Press Escape to exit

---

## Troubleshooting

### "Module FarmingSimulator could not be loaded"
- **Solution:** Rebuild the project in Visual Studio

### "Visual Studio not found"
- **Solution:** Make sure you installed "Game development with C++" workload

### "Failed to open descriptor file"
- **Solution:** Make sure the .uproject file exists in the project root

### Build Errors
- **Solution:** Make sure you copied the files to the correct locations
- Check that Source folder structure matches what UE5 expects

---

## Next Steps (After Setup Complete)

Once your project is running:

1. ✅ Read: [Phase2_SetupGuide.md](Documentation/Phase2_SetupGuide.md)
2. ✅ Create folder structure in Content browser
3. ✅ Set up Enhanced Input system
4. ✅ Create Blueprint base classes
5. ✅ Start implementing C++ functionality

---

## Estimated Timeline

- **Visual Studio Install:** 30-60 minutes
- **UE5 Install:** 1-2 hours
- **Project Creation:** 10 minutes
- **First Build:** 10 minutes
- **Total:** ~2-3 hours (mostly waiting for downloads)

---

## Need Help?

- **UE5 Documentation:** https://docs.unrealengine.com/
- **UE5 Forums:** https://forums.unrealengine.com/
- **Discord:** Unreal Slackers - https://unrealslackers.org/

---

**You're doing great! Follow these steps and you'll have a working UE5 project soon!** 🚀
