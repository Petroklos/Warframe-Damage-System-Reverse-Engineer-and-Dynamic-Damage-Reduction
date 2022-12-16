#include "ArmorReduction.h"

// Default constructor
ArmorReduction::ArmorReduction() {
    baseArmor = 0;
    level = 0;
    baseLevel = 0;
    isEximus = false;
    netArmor = 0;
    armorDR = 0;
    armorStripMultiplier = 1;
}

// Constructor that sets the base armor, level, and base level of the enemy
ArmorReduction::ArmorReduction(double baseArmor, int level, int baseLevel) {
    this->baseArmor = baseArmor;
    this->level = level;
    this->baseLevel = baseLevel;
    isEximus = false;
    calculateNetArmor();
    calculateArmorDR();
    armorStripMultiplier = 1;
}

// Constructor that sets the base armor, level, base level, and eximus status of the enemy
ArmorReduction::ArmorReduction(double baseArmor, int level, int baseLevel, bool isEximus) {
    this->baseArmor = baseArmor;
    this->level = level;
    this->baseLevel = baseLevel;
    this->isEximus = isEximus;
    calculateNetArmor();
    calculateArmorDR();
    armorStripMultiplier = 1;
}

// Set the base armor value
void ArmorReduction::setBaseArmor(double baseArmor) {
    this->baseArmor = baseArmor;
    calculateNetArmor();
    calculateArmorDR();
}

// Set the level of the enemy
void ArmorReduction::setLevel(int level) {
    this->level = level;
    calculateNetArmor();
    calculateArmorDR();
}

// Set the base level of the enemy
void ArmorReduction::setBaseLevel(int baseLevel) {
    this->baseLevel = baseLevel;
    calculateNetArmor();
    calculateArmorDR();
}

// Calculate the net armor value of the enemy
void ArmorReduction::calculateNetArmor() {
    // Apply Armor Reduction
    double currentArmor = baseLevel * armorStripMultiplier;
    if (currentArmor > 0) {
        //if (isEximus == false) {
        double t = (level - baseLevel - 70) / 10;

        double s;
        if (level - baseLevel < 70) {
            s = 0;
        } else if (level - baseLevel > 80) {
            s = 1;
        } else {
            s = 3 * pow(t, 2) - 2 * pow(t, 3);
        }

        double f1 = 1 + 0.005 * pow((level - baseLevel), 1.75);
        double f2 = 1 + 0.4 * pow((level - baseLevel), 0.75);

        netArmor = ((f1 * (1 - s)) + (f2 * s)) * baseArmor;
        //}
    }
}

// Calculate the armor damage reduction of the enemy
void ArmorReduction::calculateArmorDR() {
    armorDR = 1 - (netArmor / (netArmor + 300));
}

// Apply armor stripping to the enemy
void ArmorReduction::armorStrip(double d) {
    if (d < 0) d = 0;
    if (d > 1) d = 1;
    armorStripMultiplier -= d;
    if (armorStripMultiplier < 0) armorStripMultiplier = 0;
    calculateNetArmor();
    calculateArmorDR();
}

// Get the net armor value of the enemy
double ArmorReduction::getNetArmor() {
    return netArmor;
}

// Get the armor damage reduction of the enemy
double ArmorReduction::getArmorDR() {
    return armorDR;
}

// Apply corrosive procs to the enemy
void ArmorReduction::corrosiveProcs(int i) {
    double corrosiveModifier = 1 - (0.20 + 0.06 * i) * (i > 0 && i <= 10);
    netArmor *= corrosiveModifier;
    calculateArmorDR();
}