# Farming Simulator UE5 - Setup with JetBrains Rider
**Quick Start Guide Using Rider IDE**

---

## Current Status
✅ Project structure created
✅ Git repository initialized
✅ Documentation complete
✅ C++ class headers created
⏳ **Need to install: Unreal Engine 5 + JetBrains Rider**

---

## Why Rider?

JetBrains Rider is an excellent choice for UE5 development:
- ✅ Faster than Visual Studio
- ✅ Better C++ intellisense and refactoring
- ✅ Native Unreal Engine support
- ✅ Cross-platform (if you need it later)
- ✅ Great debugging tools

---

## Step 1: Install JetBrains Rider

### Download and Install

1. **Download Rider**
   - Go to: https://www.jetbrains.com/rider/download/
   - Download for Windows
   - **License Options:**
     - 30-day free trial (no credit card needed)
     - Student license (FREE with .edu email)
     - Individual license ($149/year, $89/year after year 1)
     - Company license if your studio has one

2. **Run the Installer**
   - Run the downloaded installer
   - **Installation options:**
     - ✅ Create Desktop Shortcut
     - ✅ Add "Open Folder as Project"
     - ✅ .sln file association
     - ✅ Add launchers dir to PATH

3. **Install Rider**
   - Click "Install"
   - Takes about 5-10 minutes
   - Click "Finish" when done

4. **First Launch**
   - Launch Rider
   - Choose UI theme (Darcula recommended 😎)
   - **Important:** Skip the "Open Project" dialog for now
   - You'll open the project later

---

## Step 2: Install Required Build Tools

**Important:** Even with Rider, you still need Windows build tools for UE5!

### Option A: Install Visual Studio 2022 Build Tools (Recommended - FREE)

1. **Download Visual Studio Build Tools**
   - Go to: https://visualstudio.microsoft.com/downloads/
   - Scroll down to "Tools for Visual Studio"
   - Download **"Build Tools for Visual Studio 2022"**

2. **Run Installer and Select Components**
   - When installer opens, select:

   **✅ Desktop development with C++**

   **Individual Components (also check):**
   - Windows 10 SDK (10.0.19041.0 or newer)
   - Windows 11 SDK (latest)
   - MSVC v143 - VS 2022 C++ x64/x86 build tools
   - C++ CMake tools for Windows

3. **Install**
   - Click "Install" (30-45 minutes)
   - You don't need the full Visual Studio IDE, just the build tools

### Option B: Install Full Visual Studio 2022 Community (Alternative)

If you want VS as a backup:
- Download Visual Studio 2022 Community (FREE)
- Select "Game development with C++" workload
- This gives you both VS and the build tools

---

## Step 3: Install Unreal Engine 5

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
   - Grab a coffee ☕ or read the [GameDesignDocument.md](Documentation/GameDesignDocument.md)

---

## Step 4: Create the UE5 Project

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
   - It will generate Visual Studio solution files (`.sln`) that Rider can open
   - The editor will open when ready

5. **Close the Editor** (for now)
   - We need to configure Rider first

---

## Step 5: Configure UE5 to Use Rider

### Set Rider as Default IDE

1. **Open Unreal Editor Settings**
   - Launch the editor for FarmingSimulator project
   - Edit → Editor Preferences

2. **Set Source Code Editor**
   - Search for "Source Code"
   - Under **General → Source Code**
   - Source Code Editor: **Rider Uproject (*.uproject)**
   - OR: **Rider (*.sln)**

3. **Apply and Close**

### Configure Rider Plugin (Optional but Recommended)

1. **In Rider**
   - File → Settings
   - Search for "Unreal Engine"
   - **Plugins → Unreal Engine**
   - Enable the Unreal Engine plugin (should be enabled by default)

2. **Rider Unreal Engine Settings**
   - Tools → Unreal Engine → Settings
   - ✅ Enable Unreal Engine Support
   - Path to Engine: `C:\Program Files\Epic Games\UE_5.4`

---

## Step 6: Move Our Files into the UE5 Project

After UE5 creates the project, integrate our existing files:

### Copy Files:

1. **Copy Documentation**
   ```
   From: C:\projects\unreal_project\Documentation\
   To:   C:\projects\FarmingSimulator\Documentation\
   ```

2. **Copy Our C++ Headers**
   ```
   From: C:\projects\unreal_project\Source\FarmingSimulator\Public\
   To:   C:\projects\FarmingSimulator\Source\FarmingSimulator\Public\

   (Merge with existing Public folder, don't replace it completely)
   ```

3. **Copy Git Configuration**
   ```
   Copy: C:\projects\unreal_project\.gitignore
   To:   C:\projects\FarmingSimulator\.gitignore

   Copy: C:\projects\unreal_project\.gitattributes
   To:   C:\projects\FarmingSimulator\.gitattributes
   ```

4. **Copy Project Plan**
   ```
   Copy: C:\projects\unreal_project\FarmingSimulator_ProjectPlan.md
   To:   C:\projects\FarmingSimulator\FarmingSimulator_ProjectPlan.md
   ```

---

## Step 7: Open Project in Rider

### Open the Solution

1. **Launch Rider**

2. **Open Project**
   - File → Open
   - Navigate to: `C:\projects\FarmingSimulator\`
   - Select `FarmingSimulator.sln`
   - Click "OK"

3. **First Time Setup**
   - Rider will index the project (2-5 minutes)
   - You'll see progress in the bottom status bar
   - Wait for indexing to complete

4. **Configure Build Configuration**
   - At the top of Rider window:
   - Configuration: **Development Editor**
   - Platform: **Win64**
   - Target: **FarmingSimulator**

---

## Step 8: Build the Project

### Build in Rider

1. **Build Solution**
   - Click: **Build → Build Solution**
   - OR: Press `Ctrl+Shift+B`
   - OR: Press `F6`

2. **Wait for Build**
   - First build takes 5-10 minutes
   - Watch the Build output panel at bottom
   - Should end with: "Build succeeded"

3. **If Build Fails**
   - Make sure build tools are installed (Step 2)
   - Check Build output for errors
   - Common fix: Tools → Unreal Engine → Regenerate Project Files

### Launch the Editor

1. **Run from Rider**
   - Click the green "Run" button (▶️)
   - OR: Press `Shift+F10`
   - OR: Debug with `Shift+F9`

2. **Editor Should Launch**
   - Unreal Engine editor will open
   - May take 1-2 minutes first time
   - You should see the default Third Person level

---

## Step 9: Configure Git for the UE5 Project

Open Command Prompt or PowerShell in `C:\projects\FarmingSimulator\`:

```bash
# Initialize Git
git init

# Install Git LFS
git lfs install

# Track large files with LFS (our .gitattributes already configured this)
git lfs track "*.uasset"
git lfs track "*.umap"

# Add all files
git add .

# Commit
git commit -m "Initial UE5 project with Rider setup"

# Set remote (update URL if needed)
git remote add origin https://github.com/skrebs1986/FarmingSimulator.git

# Push (may need to force push if repo exists)
git push -u origin main
```

---

## Step 10: Verify Everything Works

### In Rider:

1. **Check Solution Explorer**
   - You should see the FarmingSimulator project structure
   - Expand Source/FarmingSimulator
   - You should see our header files (FSGameMode.h, etc.)

2. **Test IntelliSense**
   - Open any .h file
   - Type some code
   - IntelliSense should work (autocomplete)

### In Unreal Editor:

1. **Create Test Level**
   - File → New Level → Basic
   - Save as: `Content/Maps/TestLevel`

2. **Test Play**
   - Click "Play" button (or Alt+P)
   - Should spawn in empty level with working character
   - Press Escape to exit

---

## Rider-Specific Tips & Shortcuts

### Essential Shortcuts

| Action | Shortcut |
|--------|----------|
| Build Solution | `Ctrl+Shift+B` or `F6` |
| Run | `Shift+F10` |
| Debug | `Shift+F9` |
| Find in Files | `Ctrl+Shift+F` |
| Go to Definition | `F12` |
| Quick Fix | `Alt+Enter` |
| Refactor This | `Ctrl+Shift+R` |
| Generate Code | `Alt+Insert` |

### Rider Features for UE5

1. **Unreal Engine Toolbar**
   - Tools → Unreal Engine
   - Refresh Blueprints
   - Generate Project Files
   - Hot Reload

2. **Blueprint Support**
   - Right-click .uasset files → Open in Unreal Editor
   - Rider can view Blueprint structure

3. **Debugging**
   - Set breakpoints with `F9`
   - Rider attaches to UE5 process automatically
   - View variables, call stack, etc.

4. **Live Templates**
   - Type `uclass` → Tab (generates UCLASS boilerplate)
   - Type `uprop` → Tab (generates UPROPERTY)
   - Type `ufunc` → Tab (generates UFUNCTION)

---

## Troubleshooting

### "Cannot compile - build tools not found"
- **Solution:** Install Visual Studio Build Tools (Step 2)
- Rider needs MSVC compiler even though it's the IDE

### "Solution could not be opened"
- **Solution:** Right-click .uproject → Generate Visual Studio project files
- This recreates the .sln file

### Rider is slow/laggy
- **Solution:**
  - File → Invalidate Caches → Invalidate and Restart
  - Increase Rider heap size: Help → Change Memory Settings → 4096 MB

### IntelliSense not working
- **Solution:**
  - Tools → Unreal Engine → Refresh Blueprints
  - File → Invalidate Caches

### Build fails with "missing Windows SDK"
- **Solution:** Install Windows 10 or 11 SDK via Visual Studio Build Tools

### Editor won't launch from Rider
- **Solution:**
  - Launch editor manually from Epic Games Launcher
  - Then attach Rider debugger: Run → Attach to Process
  - Search for "UE5Editor"

---

## Next Steps (After Setup Complete)

Once your project is building and running:

1. ✅ Read: [Phase2_SetupGuide.md](Documentation/Phase2_SetupGuide.md)
2. ✅ Create folder structure in Content browser
3. ✅ Set up Enhanced Input system
4. ✅ Create Blueprint base classes
5. ✅ Start implementing C++ functionality (Week 5 tasks)

---

## Estimated Timeline

- **Rider Install:** 10 minutes
- **Build Tools Install:** 30-45 minutes
- **UE5 Install:** 1-2 hours
- **Project Creation:** 10 minutes
- **First Build in Rider:** 10 minutes
- **Total:** ~2-3 hours (mostly waiting for downloads)

---

## Rider Resources

- **Rider for Unreal Engine:** https://www.jetbrains.com/rider/unreal/
- **Rider Documentation:** https://www.jetbrains.com/help/rider/
- **Unreal Engine Plugin:** https://plugins.jetbrains.com/plugin/18416-unreal-engine
- **Keyboard Shortcuts:** Help → Keyboard Shortcuts PDF

---

## Need Help?

- **Rider Support:** https://rider-support.jetbrains.com/
- **UE5 Documentation:** https://docs.unrealengine.com/
- **Rider UE5 Guide:** https://www.jetbrains.com/help/rider/Unreal_Engine.html

---

**Rider is an excellent choice! Follow these steps and you'll be coding in no time!** 🚀

**Pro Tip:** Rider has a "Learn Rider" interactive tutorial in Help → Learn Rider. Worth doing if you're new to it!
