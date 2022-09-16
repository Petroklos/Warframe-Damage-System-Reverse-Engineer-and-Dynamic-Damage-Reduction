#include "Definitions.h"

#include "DamageCalculation.h"
#include "FrequencyCalculation.h"
#include "ArmorReduction.h"

#if isDebugging
void printDebug(double, double, double, double, double);
#endif

void calculateDamage(DamageCalculation &);
void calculateArmor(ArmorReduction &);
void calculateFrequency(FrequencyCalculation &);

// The lower the value of inverseAttenuationIntensity, the faster and stronger the Attenuation will be.
// If inverseAttenuationIntensity is set to 0, Attenuation will not affect the Damage.
double attenuateDamage(double totalDamage, double estimatedDPS, double inverseAttenuationIntensity);

int main() {
	DamageCalculation DC;
	calculateDamage(DC);

	// Any changes to DC must be applied before the following commands.

	double totalDamage = DC.getDamage();

	// totalDamage *= (1 + 2 * 2); // 200% PWR STR Mirage Eclipse
	// totalDamage *= (1 + 5 * 2); // 200% PWR STR Banshee Sonar
	// totalDamage *= (1 + 1 * 2); // 200% PWR STR Nezha Blazing Chakram
	// totalDamage += totalDamage * 0.3 * 2 * DC.calculateFactionDamage(); // 200% PWR STR Saryn Toxic Lash

	// Any changes to totalDamage must be applied before the following commands.

	ArmorReduction AR;
	// AR.armorStrip(1); //Any 100% Armor Strip
	calculateArmor(AR);

	// Any changes to AR must be applied before the following command.

	double armoredDamage = totalDamage * AR.getArmorDR();

//	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~

	FrequencyCalculation FRC;
	calculateFrequency(FRC);

	// Any changes to FRC must be applied before the following command.

	double adjustedFrequency = FRC.getAdjustedFireRate();
	double estimatedDPS = armoredDamage * adjustedFrequency;

//	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~

	// The lower the value of inverseAttenuationIntensity, the faster and stronger the Attenuation will be.
	// If inverseAttenuationIntensity is set to 0, Attenuation will not affect the Damage.
	double inverseAttenuationIntensity = 69420;
	double attenuatedDamage = attenuateDamage(armoredDamage, estimatedDPS, inverseAttenuationIntensity);

#if isDebugging
	printDebug(totalDamage, armoredDamage, adjustedFrequency, estimatedDPS, attenuatedDamage);
#endif

	return 0;
}
// Trumna
/*
void calculateDamage(DamageCalculation & DC) {
	DC.setDamageBase(82);
	DC.setDamageMultiplier(1.55 + 3.6 - 0.15); // Amalgam Serration + Primary Deadhead at Full Stacks - Vile Acceleration
	// DC.setDamageMultiplier(2.75 * 2); // 200% PWR STR Chroma Vex Armor
	// DC.setRadialDamageMultiplier(10 * 100); // Madurai Void Strike 

	DC.setRadialDamageBase(50);
	DC.setRadialDamageMultiplier(1.55 + 3.6 - 0.15); // Amalgam Serration + Primary Arcane at Full Stacks - Vile Acceleration
	// DC.setRadialDamageMultiplier(2.75 * 2); // 200% PWR STR Chroma Vex Armor
	// DC.setRadialDamageMultiplier(10 * 100); // Madurai Void Strike 

	DC.setCriticalChanceBase(0.24);
	DC.setCriticalChanceMultiplier(2); // Critical Delay
	DC.setCriticalChanceAdditive(.45); // Arcane Avenger
	DC.setCriticalChanceVigilante(0.05 * 1); // Vigilante Supplies
	// DC.setCriticalChanceAdditive(2); // Covenant Headshots

	DC.setCriticalDamageBase(2.2);
	DC.setCriticalDamageMultiplier(1.2 + .6); // Vital Sense + Hammer Shot

	DC.setWeakpointBonusBase(3);
	DC.setWeakpointBonusAdditive(0.3); // Primary Deadhead

	DC.setElementalBase(1);
	DC.setElementalMultiplier(0, 0.6); // Cold 60/60 for Viral
	DC.setElementalMultiplier(3, 0.6); // Toxin 60/60 for Viral

	DC.setFactionDamageBase(1);
	// DC.setFactionDamageMultiplier(0.5 * 2); // 200% PWR STR Rhino Roar
	DC.setFactionDamageMultiplier(0.3 * 2); // 200% PWR STR Subsumed Roar

	DC.setIsIncarnon(false);

	DC.setViralProcs(1);
}

void calculateFrequency(FrequencyCalculation & FRC) {
	FRC.setFireRateBase(4.67);
	FRC.setFireRateMultiplier(0.9); // Vile Acceleration
	//FRC.setFireRateMultiplier(0.35 * 2); // 200% PWR STR Harrow

	FRC.setMagazineCapacityBase(200);
	//FRC.setMagazineCapacityMultiplier(0.55); // Primed Magazine Warp

	FRC.setReloadTimeBase(5);
	//FRC.setReloadTimeDivider(0.55); // Primed Fast Hands
	//FRC.setReloadTimeDivider(0.7 * 2); // 200% PWR STR Harrow

	FRC.setMultishotBase(1);
	FRC.setMultishotMultiplier(0.8 + .3 * 5); // Galvanized Chamber at Full Stacks
}
*/

// Kuva Hek - Alt Fire
void calculateDamage(DamageCalculation& DC) {
	DC.setDamageBase(87 * 1.6); // Has 60% Progenitor Element
	DC.setDamageMultiplier(0.6 + 3.6); // Blaze + Primary Deadhead at Full Stacks

	DC.setCriticalChanceBase(0.23);
	DC.setCriticalChanceMultiplier(2); // Critical Deceleration
	DC.setCriticalChanceAdditive(.45); // Arcane Avenger

	DC.setCriticalDamageBase(2.1);
	DC.setCriticalDamageMultiplier(1.1); // Primed Ravage

	DC.setWeakpointBonusBase(3);
	DC.setWeakpointBonusAdditive(0.3); // Primary Deadhead

	DC.setElementalBase(1);
	DC.setElementalMultiplier(0, 1.65); // Cold 165% for Viral
	DC.setElementalMultiplier(3, 0.9); // Toxin 90% for Viral
	DC.setElementalMultiplier(1, 1.65); // Electric 165% for Radiation
	DC.setElementalMultiplier(2, 0.6); // Heat 60% for Viral

	DC.setFactionDamageBase(1);
	DC.setFactionDamageMultiplier(0.5 * 2); // 200% PWR STR Rhino Roar

	DC.setIsIncarnon(false);

	DC.setViralProcs(1);
}

void calculateFrequency(FrequencyCalculation& FRC) {
	FRC.setFireRateBase(4.67);
	FRC.setFireRateMultiplier(-0.2); // Critical Deceleration
	//FRC.setFireRateMultiplier(0.35 * 2); // 200% PWR STR Harrow

	FRC.setMagazineCapacityBase(1); // dirty way to implement using 4/4 shots with alt fire
	//FRC.setMagazineCapacityMultiplier(0.55); // Primed Magazine Warp

	FRC.setReloadTimeBase(2);
	//FRC.setReloadTimeDivider(0.55); // Primed Fast Hands
	//FRC.setReloadTimeDivider(0.7 * 2); // 200% PWR STR Harrow

	FRC.setMultishotBase(28);
	FRC.setMultishotMultiplier(1.1 + .3 * 4); // Galvanized Hell at Full Stacks
}

void calculateArmor(ArmorReduction& AR) {
	// Heavy Gunner Stats : Base Armor = 500, Base Level = 8
	AR.setBaseArmor(500);
	AR.setBaseLevel(8);
	AR.setLevel(100);
	// AR.corrosiveProcs(10);
}

double attenuateDamage(double totalDamage, double estimatedDPS, double inverseAttenuationIntensity) {
	// The lower the value of inverseAttenuationIntensity, the faster and stronger the Attenuation will be.
	// If inverseAttenuationIntensity is set to 0, Attenuation will not affect the Damage.
	if (inverseAttenuationIntensity == 0) return 1;

	double part = estimatedDPS + (1 - (estimatedDPS + totalDamage) / (estimatedDPS + totalDamage + inverseAttenuationIntensity)) * totalDamage;
	double attenuateValue = 1 - part / (part + inverseAttenuationIntensity);
	return attenuateValue * totalDamage;
}

#if isDebugging
void printDebug(double totalDamage, double armoredDamage, double adjustedFrequency, double estimatedDPS, double attenuatedDamage) {
	std::cout << "Total Damage is : " << totalDamage << std::endl
		<< "Total Damage after Armor DR is : " << armoredDamage << std::endl
		<< "Adjusted Shot Frequency is : " << adjustedFrequency << std::endl
		<< "Estimated DPS after Armor DR is : " << estimatedDPS << std::endl
		<< "Total Damage after Attenuation is : " << attenuatedDamage << std::endl
		<< "Estimated DPS after Attenuation is : " << attenuatedDamage * adjustedFrequency << std::endl;
}
#endif