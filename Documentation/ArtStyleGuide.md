# Art Style Guide - Farming Simulator
**Version:** 1.0
**Date:** October 2025
**Project:** UE5 Farming Simulator

---

## 1. Art Direction Overview

### 1.1 Visual Identity
**Core Aesthetic:** Realistic with subtle stylization - grounded in reality but with enhanced colors and optimized details for visual appeal and performance.

**Key Pillars:**
- **Authenticity:** Believable farm equipment and environments
- **Warmth:** Inviting, comfortable atmosphere
- **Clarity:** Clear visual communication of gameplay elements
- **Beauty:** Showcase the natural beauty of rural landscapes

### 1.2 Mood & Tone
- Peaceful and serene
- Nostalgic and wholesome
- Aspirational (player's farm can become beautiful)
- Rewarding (visual feedback for player progress)

### 1.3 Reference Games
- **Primary:** Farming Simulator 25 (realism), Forza Horizon 5 (environment quality)
- **Secondary:** Red Dead Redemption 2 (natural environments), Microsoft Flight Simulator (realistic landscapes)
- **Lighting:** The Last of Us Part II (time of day transitions)

---

## 2. Color Palette

### 2.1 Primary Colors

#### Natural Greens (Fields & Vegetation)
- **Spring Green:** `#7CB342` - Fresh, vibrant new growth
- **Summer Green:** `#558B2F` - Rich, mature crops
- **Fall Green:** `#9E9D24` - Yellowing harvest season

#### Earth Tones (Soil & Ground)
- **Rich Soil:** `#5D4037` - Fertile, dark soil
- **Dry Soil:** `#A1887F` - Unwatered or poor quality
- **Clay:** `#8D6E63` - Natural earth variations

#### Sky & Atmosphere
- **Day Sky:** `#87CEEB` - Clear, bright blue
- **Golden Hour:** `#FFB74D` - Warm sunset/sunrise
- **Overcast:** `#B0BEC5` - Cloudy, diffused light

### 2.2 Accent Colors

#### Seasonal Accents
- **Spring:** Pastel flowers, light greens, soft yellows
- **Summer:** Vibrant greens, golden wheat, blue sky
- **Fall:** Oranges, browns, warm reds
- **Winter:** Cool blues, white snow, gray skies

#### UI & Highlights
- **Primary UI:** `#4CAF50` - Green (farming theme)
- **Secondary UI:** `#795548` - Brown (earth tones)
- **Success:** `#8BC34A` - Light green
- **Warning:** `#FFC107` - Amber
- **Error:** `#F44336` - Red
- **Info:** `#2196F3` - Blue

### 2.3 Color Treatment Rules
- Slightly elevated saturation (+10-15%) compared to pure realism
- Warm bias for daytime lighting (color temperature 5800K)
- Cool bias for night and overcast (color temperature 6500K)
- Avoid pure black and pure white in textures

---

## 3. Environmental Art

### 3.1 Terrain

#### Landscape
- **Scale:** Realistic proportions, rolling hills, gentle slopes
- **Resolution:** 1 vertex per meter (adjustable LODs)
- **Textures:** 4K PBR material blending (grass, soil, gravel, mud)
- **Detail:** Nanite-enabled rocks and detail meshes

#### Fields
- **Grid System:** Clearly defined field boundaries
- **Size:** Variable (10x10m minimum to 100x100m maximum)
- **Visual Markers:** Fence posts, stone walls, wooden borders
- **Soil States:** Tilled rows, smooth, rough, planted visible differences

### 3.2 Vegetation

#### Crops
- **LOD System:**
  - LOD 0 (0-20m): Full geometry with individual leaves
  - LOD 1 (20-50m): Simplified geometry
  - LOD 2 (50m+): Billboard imposters
- **Stages:** Distinct visual changes at each growth stage
- **Variations:** 3-5 mesh variations per crop type to avoid repetition
- **Wind Animation:** Subtle vertex animation (GPU-based)

#### Trees & Foliage
- **Tree Types:** Oak, pine, birch, willow (regional appropriate)
- **Foliage:** SpeedTree or high-quality modeled
- **Density:** Moderate (balance beauty with performance)
- **Seasonal Variations:** Leaf color changes, winter bare trees

#### Ground Cover
- **Grass:** UE5 foliage system, density-based on player distance
- **Flowers:** Scattered wildflowers in uncultivated areas
- **Weeds:** Visual indicator on fields (gameplay element)

### 3.3 Sky & Atmosphere

#### Sky System
- **Technology:** Ultra Dynamic Sky or custom volumetric clouds
- **Cloud Types:** Cumulus (fair weather), stratus (overcast), cumulonimbus (storms)
- **Movement:** Slow, realistic cloud movement
- **Stars:** Visible at night with proper constellations

#### Time of Day
- **Sunrise:** 06:00, warm orange/pink gradient
- **Midday:** 12:00, bright neutral lighting
- **Golden Hour:** 18:00-19:00, long shadows, warm light
- **Sunset:** 20:00, deep oranges and purples
- **Night:** 22:00-05:00, moonlight, stars, cool tones

#### Weather Effects
- **Rain:** Niagara particles, surface wetness, puddles
- **Fog:** Volumetric, morning mist in low areas
- **Snow:** Particle system, ground accumulation, roof coverage
- **Dust:** Farm equipment kicks up dirt/dust clouds

---

## 4. Architecture & Structures

### 4.1 Buildings

#### Farmhouse (Player Home)
- **Style:** Traditional rural architecture (American barn-style)
- **Materials:** Wood siding, metal roof, stone foundation
- **Details:** Weathering, aged wood, functional windows
- **Color:** Warm tones (reds, browns, white trim)

#### Barns & Storage
- **Design:** Functional, recognizable silhouettes
- **Scale:** Large enough to fit equipment visually
- **Details:** Sliding doors, hay loft, ventilation openings
- **Wear:** Slightly weathered but maintained

#### Silos & Tanks
- **Material:** Metal with specular reflection
- **Details:** Ladder rungs, seams, bolts
- **Branding:** Decals for variety (fictional brands)

### 4.2 Props & Details

#### Small Props
- **Tools:** Shovels, rakes, buckets, watering cans
- **Storage:** Crates, barrels, sacks
- **Decoration:** Hay bales, tires, farm signs
- **Clutter:** Organized chaos around work areas

#### Fencing
- **Types:** Wooden post-and-rail, wire, stone walls
- **Condition:** Weathered but functional
- **Placement:** Follows terrain naturally

---

## 5. Vehicles & Equipment

### 5.1 Tractors

#### Design Philosophy
- **Realistic Proportions:** Based on real-world equipment
- **Recognizable Forms:** Inspired by major brands (generic versions)
- **Color Schemes:** Bold primary colors (green, red, blue, yellow)
- **Detailing:** Hydraulic lines, exhaust pipes, warning decals

#### Materials
- **Paint:** Slightly metallic finish, subtle weathering
- **Metal:** Bare metal on wear points (edges, steps)
- **Rubber:** Matte tires with dirt accumulation
- **Glass:** Slightly dirty cab windows, interior visible

#### Technical Specs
- **Polycount:** 50k-100k per vehicle (LOD 0)
- **Texture Resolution:** 4K for main body, 2K for details
- **PBR Materials:** Albedo, Normal, Roughness, Metallic, AO

### 5.2 Implements

#### Visual Clarity
- **Purpose:** Player should instantly recognize function
- **Color Coding:** Different from tractors (grays, silvers, oranges)
- **Wear Patterns:** Soil stains on plows, scratches on harvesters

#### Attachment System
- **Hitch Points:** Clearly visible connection points
- **Animation:** Moving parts (plow blades, seeder mechanisms)

### 5.3 Customization

#### Paint Jobs
- **Default:** Manufacturer colors
- **Unlockable:** Special liveries, patterns, decals
- **Custom:** Player-selected colors (future feature)

---

## 6. User Interface Design

### 6.1 HUD Style

#### Visual Language
- **Minimal Intrusion:** Small, unobtrusive elements
- **Clear Iconography:** Universally understandable symbols
- **Consistent Layout:** Elements in predictable locations

#### Design Elements
- **Frames:** Subtle borders with transparency
- **Fonts:** Sans-serif for clarity (Roboto or similar)
- **Icons:** Flat design with single accent color
- **Background:** Dark semi-transparent panels (#000000 40% opacity)

### 6.2 Menu Design

#### Style
- **Layout:** Grid-based, clean organization
- **Navigation:** Breadcrumb trail, clear hierarchy
- **Hover States:** Subtle color shift and scale (105%)
- **Selected State:** Border highlight or background fill

#### Visual Elements
- **Background:** Blurred game scene or static farm images
- **Buttons:** Rounded corners (8px radius), subtle shadows
- **Input Fields:** Light background, clear labels
- **Dividers:** Thin lines, earth tone colors

### 6.3 Icon Design

#### Requirements
- **Size:** Base 128x128px, scalable vector when possible
- **Style:** Flat design with subtle depth (long shadow or gradient)
- **Recognition:** Distinct silhouettes, test at small sizes
- **Color:** Use accent colors from palette

#### Icon Categories
- **Items:** Crops, seeds, tools, resources
- **Actions:** Plant, water, harvest, sell
- **Status:** Weather, time, notifications
- **Navigation:** Map, menu, inventory

---

## 7. Character Art (Player & NPCs)

### 7.1 Player Character

#### Design
- **Style:** Realistic proportions, practical attire
- **Customization:** Multiple preset faces, clothing options
- **Clothing:** Work-appropriate (jeans, flannel, boots, hat)
- **Accessories:** Gloves, tool belt, backpack

#### Technical
- **Polycount:** 30k-50k
- **Textures:** 4K for character, 2K for clothing
- **Skeleton:** UE5 Manny/Quinn skeleton for compatibility

### 7.2 NPCs

#### Shopkeepers & Townspeople
- **Variety:** 5-10 unique characters minimum
- **Personality:** Clothing and accessories reflect roles
- **Animation:** Idle behaviors, gestures during dialogue

#### Farmhands (AI Workers)
- **Generic Design:** Reusable meshes with color variations
- **Functionality:** Clearly visible for player tracking

---

## 8. VFX & Particle Effects

### 8.1 Gameplay VFX

#### Farming Actions
- **Planting:** Small dirt puff when seeds placed
- **Watering:** Water droplets, splashes, wet soil shader
- **Harvesting:** Plant pieces, dust, falling crops
- **Fertilizing:** Spray particles, chemical mist

#### Equipment VFX
- **Exhaust:** Engine smoke (subtle, not obstructive)
- **Dust Clouds:** Behind vehicles, size based on speed
- **Sparks:** Repair actions, metal grinding
- **Lights:** Headlights, taillights, warning beacons

### 8.2 Environmental VFX

#### Weather
- **Rain Drops:** Impact splashes on surfaces
- **Puddles:** Real-time forming and drying
- **Lightning:** Flash with delayed thunder
- **Snow:** Falling particles, wind gusts, accumulation

#### Atmospheric
- **Dust Motes:** Visible in sunbeams (volumetric)
- **Pollen:** Spring season ambiance
- **Fireflies:** Evening/night ambient life
- **Birds:** Occasional flock movements

### 8.3 UI VFX
- **Button Presses:** Subtle flash or ripple
- **Notifications:** Slide-in animation with glow
- **Currency Gain:** Floating numbers, particle burst
- **Level Up:** Screen flash, particle celebration

---

## 9. Animation Standards

### 9.1 Player Animation

#### Movement
- **Walk Cycle:** Natural, relaxed pace (4 km/h)
- **Run Cycle:** Faster, more energetic (12 km/h)
- **Idle:** Subtle weight shifts, breathing, occasional stretch
- **Turn:** Foot planting, natural body rotation

#### Actions
- **Planting:** Kneeling, hand-to-ground motion
- **Harvesting:** Reaching, pulling, collecting
- **Tool Use:** Context-specific (rake, shovel, watering can)
- **Entering/Exiting Vehicles:** Climbing, opening door

### 9.2 Vehicle Animation

#### Driving
- **Wheel Rotation:** Accurate to speed
- **Suspension:** React to terrain (springs, dampers)
- **Steering:** Visible wheel turn in cab
- **Engine:** Vibration/shake when running

#### Implements
- **Plow:** Blades cutting through soil
- **Seeder:** Seed drops, mechanical movement
- **Harvester:** Rotating reels, conveyor belts

### 9.3 Environmental Animation

#### Vegetation
- **Wind:** Procedural grass/crop movement
- **Trees:** Branch sway, leaf flutter
- **Growth:** Smooth interpolation between stages (timeline)

---

## 10. Lighting Strategy

### 10.1 Global Illumination

#### Lumen Setup
- **Quality:** High for main gameplay, scalable in settings
- **Bounce Lighting:** 2-3 bounces for realism
- **Reflections:** Screen space with fallback to reflection captures

#### Lighting Scenarios
- **Daytime:** Sun as primary directional light
- **Night:** Moonlight (blue-tinted), artificial lights
- **Overcast:** Soft, diffused skylight
- **Storms:** Dark, dramatic, high contrast

### 10.2 Artificial Lighting

#### Farm Lights
- **Floodlights:** Bright, cool-toned, for work areas
- **Building Lights:** Warm interior spill from windows
- **Vehicle Lights:** Functional headlights, working beacons
- **Decorative:** String lights, lanterns (optional decorations)

#### Light Properties
- **Intensity:** Realistic falloff (inverse square law)
- **Color Temperature:** Match fixture type
- **Shadows:** Dynamic for moving objects, static where possible

### 10.3 Post-Process Effects

#### Color Grading
- **Morning:** Slight blue tint, cooler shadows
- **Midday:** Neutral, high brightness
- **Evening:** Warm oranges, long shadows
- **Night:** Desaturated, blue moonlight

#### Effects
- **Bloom:** Subtle on bright surfaces (sun glints, vehicle lights)
- **Lens Flares:** Optional, can be toggled
- **Vignette:** Very subtle, only in specific scenarios
- **Chromatic Aberration:** Minimal or off (player preference)

---

## 11. Sound Design Direction

### 11.1 Audio Aesthetic
- **Naturalistic:** Real-world sounds, no fantastical elements
- **Layered:** Ambient beds with detail sounds
- **Responsive:** Sounds react to player actions and environment

### 11.2 Sound Categories & Examples

#### Ambient Environment
- **Day:** Birds chirping, wind rustling, distant cow moos
- **Evening:** Crickets, frogs, owl hoots
- **Weather:** Rain patter, thunder rumble, wind gusts

#### Equipment
- **Engine:** Deep rumble, throttle changes, idle purr
- **Implements:** Metal clanking, hydraulic hiss, mechanical whir
- **Actions:** Seed drops, soil crunching, harvest rustling

#### UI
- **Buttons:** Soft clicks, satisfying feedback
- **Notifications:** Gentle chimes, not jarring
- **Success:** Uplifting "ding" or "chime"

---

## 12. Technical Art Guidelines

### 12.1 Asset Creation Standards

#### Modeling
- **Scale:** 1 UE unit = 1 cm (use real-world measurements)
- **Pivot:** Bottom center for props, center for vehicles
- **Normals:** All faces correct direction, no flipped normals
- **UV:** Non-overlapping (except mirrored), proper density

#### Texturing
- **Workflow:** PBR (Physically Based Rendering)
- **Maps Required:** Base Color, Normal, Roughness, Metallic, AO
- **Resolution:** Match to on-screen size (1024px² per meter²)
- **Tiling:** Seamless tiles for terrain and large surfaces

#### Materials
- **Master Materials:** Create base for each category
- **Instancing:** Always use material instances
- **Parameters:** Expose useful values (color, roughness, detail strength)
- **Complexity:** Target ≤ 300 shader instructions for common materials

### 12.2 Performance Budgets

#### Per-Frame Budgets (1080p High Settings)
- **Draw Calls:** ≤ 3000
- **Triangles:** ≤ 5 million on-screen
- **Texture Memory:** ≤ 3 GB
- **Material Shaders:** ≤ 20ms combined

#### Per-Asset Budgets
- **Characters:** 30k-50k tris
- **Vehicles:** 50k-100k tris
- **Buildings:** 20k-80k tris (based on size)
- **Props:** 500-5k tris
- **Crops:** 100-500 tris per instance (heavily instanced)

---

## 13. Reference Library

### 13.1 Photo References

#### Environment
- Real farm photography (various seasons)
- Agricultural equipment catalogs
- Rural landscape photos
- Weather phenomena

#### Specific Elements
- Crop growth stages (close-up photos)
- Soil textures and colors
- Building materials (wood grain, metal, stone)
- Vehicle paint and weathering patterns

### 13.2 Video References
- Farm documentary footage
- Equipment operation videos
- Time-lapse of crop growth
- Weather systems and atmospheric effects

### 13.3 Art References (Other Games/Media)
- Farming Simulator 22: UI, equipment models
- Red Dead Redemption 2: Nature environments
- Forza Horizon 5: Vehicle detail and lighting
- Studio Ghibli films: Warm, inviting countryside (inspiration only)

---

## 14. Concept Art Requirements

### 14.1 Pre-Production Concepts

#### Essential Concept Art
1. **Key Visual:** Hero shot of farm at golden hour
2. **Environment:** Main farm layout and surrounding area
3. **Buildings:** Farmhouse, barn, silos (exterior and interior)
4. **Vehicles:** At least 3 tractor designs, 5 implement types
5. **UI Mockups:** HUD, main menu, inventory screen
6. **Character:** Player character with clothing variations

#### Color Scripts
- 24-hour color progression
- Seasonal variation studies
- Weather mood boards

### 14.2 Iteration & Feedback
- Weekly art review meetings
- Iterative refinement based on gameplay needs
- Maintain concept art repository for team reference

---

## 15. Asset Pipeline

### 15.1 Workflow

```
Concept → Blockout → Model → UV → Texture → Material → Import → Optimize → Integrate
```

#### Software Pipeline
- **Concept:** Photoshop, Procreate
- **3D Modeling:** Blender, Maya
- **Sculpting:** ZBrush (for high-detail elements)
- **Texturing:** Substance Painter, Substance Designer
- **Animation:** Maya, Blender, UE5 Sequencer
- **VFX:** Niagara (UE5), Houdini (complex simulations)

### 15.2 File Naming Conventions

```
[Type]_[Name]_[Variant]_[LOD]

Examples:
SM_Tractor_Red_LOD0
T_Soil_Tilled_D (Diffuse/BaseColor)
M_Crop_Wheat_Inst (Material Instance)
SK_Player_Male
```

#### Prefixes
- `SM_` Static Mesh
- `SK_` Skeletal Mesh
- `T_` Texture
- `M_` Material
- `MI_` Material Instance
- `BP_` Blueprint
- `A_` Animation

---

## 16. Quality Assurance

### 16.1 Visual Quality Checklist

#### Before Asset Approval
- [ ] Matches concept art and art direction
- [ ] Proper scale in-engine
- [ ] All LODs generated and tested
- [ ] Materials assigned correctly
- [ ] Textures properly sized and compressed
- [ ] No visual glitches (Z-fighting, flickering, etc.)
- [ ] Fits performance budget
- [ ] Proper collision setup

### 16.2 Art Review Process
- **Frequency:** Weekly art meetings
- **Attendees:** Art Director, Lead Artist, relevant artists
- **Format:** In-engine presentations, screenshot comparisons
- **Outcome:** Approved, needs revision, or rejected with feedback

---

## 17. Accessibility Considerations

### 17.1 Visual Accessibility

#### Color Blindness
- **UI:** Never rely on color alone (use icons + color)
- **Gameplay:** Colorblind modes (protanopia, deuteranopia, tritanopia)
- **Testing:** Simulate modes during development

#### Visual Clarity
- **Contrast:** Important elements have sufficient contrast
- **Size:** UI elements minimum 32px for readability
- **Text:** High contrast, clear fonts, scalable sizes

### 17.2 Performance Accessibility
- **Scalability:** Wide range of graphics settings
- **Options:** Toggle individual effects (motion blur, bloom, etc.)
- **Presets:** Easy-to-understand quality presets

---

## Approval Sign-Off

| Role | Name | Date | Signature |
|------|------|------|-----------|
| Art Director | | | |
| Lead Environment Artist | | | |
| Lead Character Artist | | | |
| UI/UX Lead | | | |
| Technical Art Lead | | | |

---

**Document Status:** Draft
**Next Review Date:** [To be scheduled]
**Change Log:** Initial version created

---

## Appendix A: Color Palette Swatches

[To be created: Visual swatch sheet with hex codes and RGB values]

## Appendix B: Material Examples

[To be created: Screenshots of key materials in various lighting conditions]

## Appendix C: Reference Image Gallery

[To be created: Curated reference images organized by category]
