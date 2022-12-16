#include "Definitions.h"

#pragma once

class ArmorReduction {
public:
    // Constructors
    ArmorReduction();
    ArmorReduction(double baseArmor, int level, int baseLevel);
    ArmorReduction(double baseArmor, int level, int baseLevel, bool isEximus);

    // Setter functions
    void setBaseArmor(double baseArmor);
    void setLevel(int level);
    void setBaseLevel(int baseLevel);

    // Calculate the net armor value and armor damage reduction
    void calculateNetArmor();
    void calculateArmorDR();

    // Apply armor stripping to the enemy
    void armorStrip(double d);

    // Get the net armor value and armor damage reduction
    double getNetArmor();
    double getArmorDR();

    // Apply corrosive procs to the enemy
    void corrosiveProcs(int);

private:
    double baseArmor;
    int level;
    int baseLevel;
    bool isEximus;
    double netArmor;
    double armorDR;
    double armorStripMultiplier;
};