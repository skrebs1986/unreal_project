# Core Farming Mechanics - Farming Simulator
**Version:** 1.0
**Date:** October 2025
**Project:** UE5 Farming Simulator

---

## 1. Mechanics Overview

### 1.1 Core Gameplay Loop

```
Player Actions → Field State Changes → Crop Growth → Harvest → Profit → Reinvestment → Expansion
```

### 1.2 Mechanical Pillars
1. **Field Preparation** - Soil management and cultivation
2. **Planting** - Seed selection and placement
3. **Maintenance** - Watering, fertilizing, pest control
4. **Harvesting** - Collection and storage
5. **Economy** - Selling and financial management
6. **Progression** - Upgrades and expansion

---

## 2. Field Preparation

### 2.1 Field States

#### State Progression
```
Untilled (Raw) → Plowed → Cultivated → Fertilized → Ready for Planting
```

#### State Descriptions

**Untilled (Raw)**
- Natural ground state
- Cannot plant directly
- May have rocks, debris, or overgrowth
- Requires most work to prepare

**Plowed**
- Soil has been turned with plow
- Large furrows visible
- Basic preparation complete
- Can plant low-requirement crops

**Cultivated**
- Soil broken into smaller pieces
- Smoother surface than plowed
- Better for most crops
- Improved water retention

**Fertilized**
- Nutrients added to soil
- Increases crop yield potential
- Visual: Darker soil color or applied material visible
- Limited duration before nutrients deplete

### 2.2 Soil Properties

#### Soil Quality Metrics
```cpp
struct FSoilQuality
{
    float Nitrogen;      // 0.0 - 1.0 (Depletes with each harvest)
    float Phosphorus;    // 0.0 - 1.0 (Depletes slowly)
    float Potassium;     // 0.0 - 1.0 (Depletes moderately)
    float pH;            // 4.0 - 9.0 (7.0 is neutral, optimal)
    float Moisture;      // 0.0 - 1.0 (Affected by rain/watering)
    float Compaction;    // 0.0 - 1.0 (Increases with vehicle traffic)
};
```

#### Soil Quality Effects

| Property | Low Effect | Optimal Range | High Effect |
|----------|-----------|---------------|-------------|
| Nitrogen | Slow growth, low yield | 0.6 - 0.9 | Minor benefit |
| Phosphorus | Poor root development | 0.5 - 0.8 | Minimal impact |
| Potassium | Disease susceptibility | 0.5 - 0.8 | Minimal impact |
| pH | Nutrient lockout | 6.0 - 7.5 | Nutrient lockout |
| Moisture | Wilting, death | 0.4 - 0.7 | Root rot possible |
| Compaction | Poor drainage | 0.0 - 0.3 | Stunted growth |

### 2.3 Field Preparation Actions

#### Clearing (If Needed)
- **Tool:** Hand tools or small equipment
- **Purpose:** Remove rocks, stumps, debris
- **Time:** Variable based on field condition
- **Cost:** Low (labor) to medium (if explosives/machinery needed)

#### Plowing
- **Equipment:** Tractor + Plow attachment
- **Speed:** 5-10 km/h depending on tractor power
- **Effect:** Turns soil, breaks up compaction
- **Depth:** 15-30 cm
- **Fuel Cost:** Medium-High
- **Time Required:** ~2-3 minutes per 1000 m² field

#### Cultivating
- **Equipment:** Tractor + Cultivator/Disk Harrow
- **Speed:** 8-15 km/h
- **Effect:** Breaks clumps, levels surface
- **Depth:** 5-15 cm
- **Fuel Cost:** Medium
- **Time Required:** ~1-2 minutes per 1000 m² field

#### Fertilizing
- **Equipment:** Tractor + Spreader or Sprayer
- **Types:**
  - Solid (granular) - wider spread, cheaper
  - Liquid - precise application, faster absorption
  - Organic (manure) - slow release, improves soil structure
- **Effect:** Increases soil nutrients
- **Application Rate:** 50-200 kg/hectare (configurable)
- **Cost:** $50-$200 per 1000 m² field

### 2.4 Player Experience

#### Tutorial Sequence
1. Player starts with one pre-tilled field (skip this step initially)
2. Second field requires full preparation cycle
3. Game explains each step with visual indicators
4. Player practices with guidance

#### Skill Progression
- **Level 1:** Manual tools, slow but cheap
- **Level 5:** Basic tractor attachments unlock
- **Level 10:** Advanced multi-function equipment
- **Level 15:** Automated/precision agriculture tools

---

## 3. Planting

### 3.1 Seed Selection

#### Seed Categories

**Grains**
- Wheat, Barley, Oats, Corn
- High yield, moderate profit
- Seasonal: Spring/Fall planting

**Root Vegetables**
- Potatoes, Carrots, Beets, Turnips
- Medium yield, good profit
- Seasonal: Spring planting, Fall harvest

**Vegetables**
- Tomatoes, Peppers, Lettuce, Cabbage
- Lower yield, high profit
- Seasonal: Spring/Summer planting

**Legumes**
- Soybeans, Peas, Beans
- Nitrogen-fixing (improves soil)
- Seasonal: Spring planting

**Specialty**
- Sunflowers, Cotton, Tobacco
- Unique requirements, premium profit
- Unlocked through progression

#### Seed Properties
```cpp
struct FSeedData
{
    FString CropName;
    int32 GrowthDurationDays;     // 7-60 days
    int32 OptimalPlantingSeason;  // 0=Spring, 1=Summer, 2=Fall
    float YieldPerSqMeter;        // 0.5 - 5.0 kg/m²
    float BaseSellPrice;          // Per kg
    FSoilRequirements Requirements;
    bool RequiresIrrigation;
    bool RequiresFertilizer;
    int32 UnlockLevel;
};
```

### 3.2 Planting Methods

#### Manual Planting
- **Tool:** Hand-held seed bag or dibber
- **Speed:** Very slow (100 m² in 5 minutes)
- **Precision:** High (exact placement)
- **Cost:** Free (besides seed cost)
- **Use Case:** Small plots, tutorials, specialty crops

#### Mechanical Seeder
- **Equipment:** Tractor + Seeder attachment
- **Speed:** Fast (1000 m² in 2 minutes)
- **Precision:** Rows, adjustable spacing
- **Seed Efficiency:** 95-98% (some waste)
- **Cost:** Fuel + wear
- **Types:**
  - **Broadcast Seeder:** Spreads seeds widely (grain crops)
  - **Row Seeder:** Plants in neat rows (vegetables)
  - **Precision Planter:** GPS-guided, minimal waste (expensive, late-game)

### 3.3 Planting Process

#### Step-by-Step
1. **Select Seeds** from inventory or shop
2. **Load Seeder** with chosen seed type
3. **Configure Settings** (optional)
   - Row spacing (15cm - 75cm)
   - Seeding depth (1cm - 10cm)
   - Seed rate (seeds per meter)
4. **Drive Over Field** at appropriate speed
5. **Visual Feedback** shows planted areas
6. **Completion Notification** when area planted

#### Visual Indicators
- **Planted Areas:** Subtle soil disturbance or seed markers
- **Unplanted Areas:** Original tilled soil appearance
- **Progress Bar:** Shows percentage of field planted
- **Seed Counter:** Remaining seeds in seeder

### 3.4 Optimal Planting

#### Timing Windows

| Season | Optimal Crops | Risk of Early Planting | Risk of Late Planting |
|--------|---------------|------------------------|----------------------|
| Early Spring | Cold-hardy greens, peas | Frost damage | Short growing season |
| Late Spring | Corn, beans, tomatoes | Frost damage | Reduced yield |
| Summer | Quick-growing greens | Heat stress | Won't mature |
| Fall | Wheat, garlic, cover crops | Too hot | Frost before maturity |

#### Player Feedback
- **Calendar UI:** Shows optimal planting windows
- **Seed Description:** "Best planted in Spring"
- **Warning System:** "Risk of frost damage if planted now"
- **Skill Progression:** Unlock greenhouse for year-round planting

---

## 4. Crop Maintenance

### 4.1 Watering System

#### Water Requirements

**Crop Water Needs**
- **Low:** Wheat, barley (rely on natural rain)
- **Medium:** Corn, soybeans (occasional watering)
- **High:** Tomatoes, peppers, lettuce (frequent watering)

**Watering Methods**

| Method | Coverage | Speed | Cost | Unlock |
|--------|----------|-------|------|--------|
| Watering Can | 1-2 plants | Very Slow | $0 | Start |
| Hose | 10 m² | Slow | $50 | Start |
| Sprinkler (Manual) | 50 m² | Medium | $200 | Level 3 |
| Irrigation System | 500 m² | Automated | $2000 | Level 8 |
| Pivot Irrigation | 5000 m² | Automated | $10,000 | Level 15 |

#### Watering Mechanics
```cpp
struct FWateringState
{
    float CurrentMoisture;    // 0.0 - 1.0
    float TargetMoisture;     // Crop-dependent (0.4 - 0.7)
    float DrainageRate;       // Soil type dependent
    float EvaporationRate;    // Weather dependent

    bool IsWilting() { return CurrentMoisture < (TargetMoisture - 0.2f); }
    bool IsOptimal() { return CurrentMoisture >= TargetMoisture - 0.1f &&
                              CurrentMoisture <= TargetMoisture + 0.1f; }
};
```

#### Water Sources
- **Rain:** Free, unpredictable, fills soil moisture
- **Well:** Limited daily capacity, free
- **Municipal Water:** Unlimited, costs per liter
- **Pond/Stream:** Free, requires pump setup

### 4.2 Fertilizing (During Growth)

#### Fertilizer Types

**Quick-Release (Chemical)**
- **Application:** Spray or granular
- **Effect:** Immediate boost to growth rate
- **Duration:** 3-7 days
- **Cost:** $100 per application
- **Impact:** +20-30% growth speed, slight soil quality decrease over time

**Slow-Release (Organic)**
- **Application:** Compost, manure spread
- **Effect:** Gradual nutrient supply
- **Duration:** 14-28 days
- **Cost:** $50 per application (cheaper if you have livestock)
- **Impact:** +10-15% growth speed, improves soil quality

**Foliar Spray**
- **Application:** Liquid sprayed on leaves
- **Effect:** Quick nutrient absorption
- **Duration:** Immediate
- **Cost:** $75 per application
- **Impact:** Emergency boost for struggling crops

#### Application Timing
- **Seedling Stage:** Light feeding, establish roots
- **Vegetative Stage:** Heavy feeding, build plant mass
- **Flowering/Fruiting:** Balanced feeding, support production
- **Late Stage:** Reduce feeding, prepare for harvest

### 4.3 Weed Control

#### Weed Growth System
- Weeds spawn randomly in planted fields
- Growth rate: Faster in high-nutrient soil
- Effect on crops: Compete for nutrients, reduce yield by 10-50%
- Visual: Distinct weed plants among crops

#### Weed Control Methods

**Manual Weeding**
- **Tool:** Hands or hoe
- **Speed:** Very slow but free
- **Effectiveness:** 100% in treated area
- **Best For:** Small areas, early game

**Mechanical Cultivation**
- **Equipment:** Tractor + Row Cultivator
- **Speed:** Medium-fast
- **Effectiveness:** 80-90%
- **Limitation:** Only works between rows, not close to plants

**Herbicides**
- **Equipment:** Sprayer
- **Speed:** Fast
- **Effectiveness:** 95-100%
- **Cost:** $150 per field application
- **Drawback:** Environmental impact (optional reputation system)

**Prevention**
- **Mulching:** Reduces weed spawn rate by 70%
- **Dense Planting:** Less space for weeds
- **Crop Rotation:** Some crops suppress weeds

### 4.4 Pest & Disease Management

#### Pest Types

**Insects**
- **Aphids:** Suck plant sap, slow growth (-10% yield)
- **Beetles:** Eat leaves, visible damage (-20% yield)
- **Caterpillars:** Devour foliage (-30% yield)
- **Root Maggots:** Underground, hard to detect (-40% yield)

**Diseases**
- **Blight:** Brown spots on leaves, spreads quickly
- **Rust:** Orange powder on leaves, weakens plant
- **Wilt:** Entire plant droops, can be fatal
- **Rot:** Affects roots or fruits, destroys crop

**Wildlife**
- **Crows/Birds:** Eat seeds and fruits (-10-20%)
- **Deer:** Trample and eat crops (-30%)
- **Rodents:** Eat stored crops and seeds

#### Detection & Identification
- **Visual Inspection:** Walk through fields, see damage
- **Scouting:** Highlighted crop shows issues on hover
- **Alert System:** Notification when pest/disease detected
- **Skill Progression:** Higher level = earlier detection

#### Control Methods

| Method | Speed | Cost | Effectiveness | Unlock |
|--------|-------|------|---------------|--------|
| Hand-picking | Very Slow | Free | 60% | Start |
| Insecticide Spray | Fast | $100 | 90% | Level 2 |
| Beneficial Insects | Slow | $200 | 70% | Level 5 |
| Crop Covers | Setup | $300 | 95% Prevention | Level 4 |
| Scarecrows | Setup | $50 | 60% Birds | Start |
| Fencing | Setup | $500 | 90% Deer | Level 3 |

### 4.5 Monitoring & Optimization

#### Crop Health Display
- **Color Coding:**
  - Vibrant Green: Excellent health (90-100%)
  - Light Green: Good health (70-89%)
  - Yellowish: Fair health (50-69%)
  - Brown/Wilted: Poor health (0-49%)

#### Field Management UI
- **Field Overview:** List of all fields with status
- **Individual Crop Data:**
  - Growth stage and percentage
  - Health status
  - Days until harvest
  - Estimated yield
  - Current issues (if any)

---

## 5. Harvesting

### 5.1 Harvest Timing

#### Readiness Indicators
- **Visual:** Crop color change (golden wheat, red tomatoes)
- **UI Notification:** "Field X ready for harvest"
- **Field Map:** Harvestable fields highlighted
- **Over-Maturity:** Crops left too long decrease in quality/yield

#### Harvest Windows
- **Optimal:** Full yield and quality
- **Early:** Reduced yield, faster turnaround
- **Late:** Decreased quality, potential loss

### 5.2 Harvesting Methods

#### Manual Harvesting
- **Tool:** Scythe, sickle, or bare hands
- **Speed:** 20-50 m² per hour (crop dependent)
- **Yield:** 95-100% (minimal waste)
- **Quality:** High (gentle handling)
- **Best For:** High-value specialty crops, small plots

#### Mechanical Harvesting

**Small Harvester**
- **Coverage:** 200 m² per hour
- **Yield:** 85-90% (some waste)
- **Capacity:** 500 kg storage
- **Cost:** $15,000 to purchase, moderate fuel
- **Crops:** Grains, some vegetables

**Large Combine Harvester**
- **Coverage:** 1000 m² per hour
- **Yield:** 90-95% (efficient)
- **Capacity:** 5000 kg storage
- **Cost:** $80,000 to purchase, high fuel
- **Crops:** All grains, large-scale operations

**Specialized Harvesters**
- **Potato Harvester:** Digs and collects root vegetables
- **Picker:** For fruits (tomatoes, peppers)
- **Cotton Picker:** Specific to cotton crops

### 5.3 Harvesting Process

#### Step-by-Step
1. **Ensure Crop Ready:** Check maturity status
2. **Select Equipment:** Manual or mechanical
3. **Position & Start:** Enter field, engage harvester
4. **Drive Pattern:** Efficient routes (minimize overlap)
5. **Monitor Capacity:** Empty storage when full
6. **Complete Harvest:** Notification when field cleared

#### Storage Management
- **Harvester Storage:** Limited capacity, must unload
- **Transfer Options:**
  - Unload to truck (transport to storage)
  - Unload directly to silo (if adjacent)
  - Portable storage bags (temporary)

### 5.4 Post-Harvest

#### Yield Calculation
```cpp
struct FHarvestYield
{
    float BaseYield;           // From crop data
    float SoilQualityBonus;    // 0.0 - 0.3 multiplier
    float FertilizerBonus;     // 0.0 - 0.2 multiplier
    float WaterBonus;          // 0.0 - 0.15 multiplier
    float HealthPenalty;       // -0.5 to 0.0 multiplier (pests/disease)
    float TimingPenalty;       // -0.2 to 0.0 multiplier (late harvest)
    float MethodPenalty;       // -0.15 to 0.0 multiplier (mechanical vs manual)

    float CalculateFinalYield()
    {
        return BaseYield * (1.0f + SoilQualityBonus + FertilizerBonus + WaterBonus)
                        * (1.0f + HealthPenalty + TimingPenalty + MethodPenalty);
    }
};
```

#### Crop Quality Grades
- **Premium:** 100% base price, perfect conditions
- **Grade A:** 90% price, minor imperfections
- **Grade B:** 75% price, visible issues
- **Grade C:** 50% price, significant damage
- **Waste:** 0% price, unsellable (animal feed or compost)

#### Field State After Harvest
- **Stubble/Residue:** Remaining plant matter
- **Options:**
  - **Till Under:** Adds organic matter to soil
  - **Bale/Collect:** Straw can be sold or used
  - **Burn:** Fast clearing (environmental impact)
  - **Leave:** Natural decomposition (slow)

---

## 6. Economy & Trading

### 6.1 Pricing System

#### Base Prices (Per Kg)
| Crop | Base Price | Market Variance |
|------|------------|-----------------|
| Wheat | $0.30 | ±25% |
| Corn | $0.25 | ±20% |
| Potatoes | $0.50 | ±30% |
| Tomatoes | $1.20 | ±40% |
| Soybeans | $0.45 | ±25% |
| Cotton | $2.00 | ±35% |

#### Dynamic Pricing Factors
```cpp
struct FMarketPrice
{
    float BasePrice;
    float SeasonalModifier;    // -0.3 to +0.5
    float SupplyDemandModifier; // -0.4 to +0.6
    float QualityModifier;     // 0.5 to 1.0
    float ContractBonus;       // 0.0 to +0.3

    float GetCurrentPrice()
    {
        return BasePrice * (1.0f + SeasonalModifier + SupplyDemandModifier)
                        * QualityModifier * (1.0f + ContractBonus);
    }
};
```

### 6.2 Selling Options

#### Direct Market Sale
- **Method:** Drive to market, sell from truck
- **Price:** Current market rate
- **Speed:** Immediate payment
- **Quantity:** No minimum

#### Storage & Speculation
- **Method:** Store in silos, sell when prices rise
- **Risk:** Prices may fall, storage costs
- **Reward:** Potential for 50-100% higher prices
- **Capacity:** Limited by silo space

#### Contracts
- **Method:** Accept contract before planting
- **Terms:** Specific crop, quantity, deadline
- **Payment:** 10-30% bonus on base price
- **Penalty:** Failure to deliver = reputation loss

#### Subscription/Regular Buyers
- **Method:** Establish relationship with buyers
- **Terms:** Weekly deliveries of set quantity
- **Payment:** Guaranteed price (slightly below market)
- **Benefit:** Stable income, relationship bonuses

### 6.3 Expenses

#### Operating Costs
- **Seeds:** $10-$200 per field planting
- **Fertilizer:** $50-$200 per application
- **Fuel:** $50-$300 per day of heavy equipment use
- **Water:** $0-$50 per field (if municipal source)
- **Pesticides:** $100-$300 per application
- **Repairs:** 1-5% of equipment value annually

#### Capital Expenses
- **Land:** $5,000-$50,000 per field parcel
- **Equipment:** $500 (hand tools) to $100,000 (combines)
- **Buildings:** $2,000-$50,000 depending on type/size
- **Upgrades:** 20-50% of base equipment cost

#### Ongoing Costs
- **Loan Payments:** If borrowing for expansion
- **Property Tax:** $100 per season
- **Insurance:** Optional, protects against disasters

---

## 7. Progression Systems

### 7.1 Experience & Leveling

#### XP Sources
- **Planting:** 1 XP per m² planted
- **Harvesting:** 5 XP per kg harvested
- **Selling:** 0.1 XP per $1 earned
- **Completing Contracts:** 500-2000 XP
- **Achievements:** 100-1000 XP

#### Level Benefits
- **New Equipment Unlocks:** Every 2-3 levels
- **New Crop Varieties:** Every 3-5 levels
- **Skill Points:** 1 per level for skill trees
- **Reputation Increase:** Better contract opportunities

### 7.2 Skill Trees

#### Crop Mastery Tree
- **Tier 1:** +5% crop yield
- **Tier 2:** Reduced watering needs
- **Tier 3:** +10% crop yield (stacks)
- **Tier 4:** Unlock greenhouse growing
- **Tier 5:** +15% crop selling price

#### Equipment Efficiency Tree
- **Tier 1:** -10% fuel consumption
- **Tier 2:** +20% equipment durability
- **Tier 3:** Faster work speeds
- **Tier 4:** Unlock autopilot features
- **Tier 5:** -20% repair costs

#### Business Acumen Tree
- **Tier 1:** See 3-day price forecasts
- **Tier 2:** +10% contract rewards
- **Tier 3:** Unlock bulk buyer contracts
- **Tier 4:** Negotiation mini-game for better prices
- **Tier 5:** Access to premium markets

### 7.3 Unlockables

#### Equipment Progression
1. **Starter:** Basic tractor, hand tools
2. **Early (Level 5):** Small seeder, sprinkler system
3. **Mid (Level 10):** Combine harvester, fertilizer spreader
4. **Advanced (Level 15):** GPS-guided equipment, pivot irrigation
5. **Elite (Level 20):** Autonomous vehicles, premium brands

#### Crop Variety Progression
- **Start:** 5 basic crops (wheat, corn, potatoes, carrots, tomatoes)
- **Level 5:** Add soybeans, lettuce, cabbage
- **Level 10:** Add sunflowers, peppers, beets
- **Level 15:** Add cotton, specialty grains
- **Level 20:** Exotic/premium crops (saffron, truffles via foraging)

---

## 8. Advanced Mechanics (Post-MVP)

### 8.1 Crop Rotation
- **Benefit:** Improved soil health, reduced pests
- **Mechanic:** Bonuses for not planting same crop consecutively
- **Implementation:** Tracking last 3 crops per field
- **Reward:** +10-20% yield on properly rotated crops

### 8.2 Greenhouse Farming
- **Benefit:** Year-round growing, controlled environment
- **Cost:** High initial investment ($20,000+)
- **Advantage:** Ignore seasons, optimal conditions
- **Limitation:** Smaller scale, higher operating costs

### 8.3 Livestock Integration
- **Manure Production:** Free organic fertilizer
- **Dual Income:** Sell animal products + crops
- **Feed Requirements:** Grow feed crops or purchase
- **Synergy:** Crop waste feeds animals, animals fertilize crops

### 8.4 Automation
- **AI Workers:** Hire NPCs to handle tasks
- **Scheduling:** Set daily routines (water at 8 AM, etc.)
- **Cost:** Daily wages + supervision
- **Benefit:** Manage larger farms, passive income

---

## 9. Balancing Considerations

### 9.1 Difficulty Curve
- **Early Game:** Simple, guided, forgiving
- **Mid Game:** Complexity increases, multiple fields, timing management
- **Late Game:** Optimization challenge, large-scale management

### 9.2 Risk vs Reward
| Strategy | Risk | Reward | Best For |
|----------|------|--------|----------|
| Low-cost crops (wheat) | Low | Low | Beginners, safe income |
| High-value crops (tomatoes) | Medium | High | Mid-game, active players |
| Contracts | Medium | High | Guaranteed income |
| Market speculation | High | Very High | Experienced, risk-takers |
| Diversification | Low | Medium | Stable, long-term |

### 9.3 Time Investment
- **Casual (30 min session):** Tend 1-2 small fields, simple tasks
- **Moderate (1 hour):** Manage 3-5 fields, complete contracts
- **Hardcore (2+ hours):** Large farm, optimization, multiple tasks

---

## 10. Player Feedback & Tutorials

### 10.1 Tutorial Structure

#### Phase 1: Basics (Day 1-2)
- Movement and interaction
- Plant first crop (pre-tilled field)
- Wait and observe growth
- Harvest and sell

#### Phase 2: Preparation (Day 3-5)
- Buy seeds and supplies
- Prepare new field (tilling, fertilizing)
- Introduce watering
- Introduce equipment rental/purchase

#### Phase 3: Management (Day 6-10)
- Multiple fields simultaneously
- Deal with weeds or pests
- Introduce contracts
- Time and resource management

#### Phase 4: Expansion (Day 11+)
- Purchase new land
- Upgrade equipment
- Diversify crops
- Player is now independent

### 10.2 In-Game Help Systems

#### Contextual Tooltips
- Hover over crops: Show health, days to harvest
- Hover over equipment: Show stats, fuel level
- Hover over fields: Show soil quality summary

#### Encyclopedia/Compendium
- **Crops:** Full details on each crop type
- **Equipment:** Specifications and comparisons
- **Mechanics:** Explain systems (soil, weather, etc.)

#### Advisor/Helper NPC
- Optional hints and tips
- Suggests next actions for players who want guidance
- Can be disabled for experienced players

---

## 11. Success Metrics for Mechanics

### 11.1 Engagement Metrics
- **Tutorial Completion:** Target 85%+
- **Crop Diversity:** Players plant at least 3 different crops by Day 10
- **Equipment Upgrades:** First upgrade by Day 7 on average
- **Contract Completion:** 70%+ of accepted contracts completed

### 11.2 Balance Metrics
- **Income Progression:** Steady growth, no exploits
- **Time to First Profit:** 30-60 minutes
- **Time to First Expansion:** 2-4 hours
- **Playtime to "Endgame":** 20-40 hours

---

## Approval Sign-Off

| Role | Name | Date | Signature |
|------|------|------|-----------|
| Lead Designer | | | |
| Systems Designer | | | |
| Gameplay Programmer | | | |
| Economy Designer | | | |

---

**Document Status:** Draft
**Next Review Date:** [To be scheduled]
**Change Log:** Initial version created
