#include "Definitions.h"

#include "DamageCalculation.h"
#include "FrequencyCalculation.h"
#include "ArmorReduction.h"

#if isDebugging
void printDebug(double, double, double, double, double);
#endif

void calculateDamage(DamageCalculation&);
void calculateArmor(ArmorReduction&);
void calculateFrequency(FrequencyCalculation&);

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

// Kuva Hek - Alt Fire
void calculateDamage(DamageCalculation& DC) {
	// Set damage base
	DC.setDamageBase(87 * 1.6);					// Has 60% Progenitor Element
	// Increase damage with damage multiplier
	DC.setDamageMultiplier(0.6 + 3.6);			// This is Blaze + Primary Deadhead at Full Stacks

	// Set base critical chance
	DC.setCriticalChanceBase(0.23);
	// Increase critical chance with critical chance multiplier
	DC.setCriticalChanceMultiplier(2);			// Critical Deceleration
	// Increase critical chance with critical chance addend
	DC.setCriticalChanceAdditive(.45);			// Arcane Avenger

	// Set base critical damage
	DC.setCriticalDamageBase(2.1);
	// Increase critical damage with critical damage multiplier
	DC.setCriticalDamageMultiplier(1.1);		// This is Primed Ravage

	// Set base weakpoint bonus
	DC.setWeakpointBonusBase(3);
	// Increase weakpoint bonus with weakpoint bonus addend
	DC.setWeakpointBonusAdditive(0.3);			// This is Primary Deadhead

	// Set base elemental damage and apply elemental types and multipliers
	DC.setElementalMultiplier(1, 1.65);			// This is Primed Charge Shell for Electric
	DC.setElementalMultiplier(2, 0.6);			// This is Blaze for Radiation
	DC.setElementalMultiplier(0, 1.65);			// This is Primed Chilling Grasp for Cold
	DC.setElementalMultiplier(3, 0.9);			// This is Contagious Spread for Viral

	// Set base faction damage
	DC.setFactionDamageBase(1);
	// Increase faction damage with faction damage multiplier
	DC.setFactionDamageMultiplier(0.5 * 2);		// This is 200% PWR STR Rhino Roar

	// Set Incarnon status, if true it will calculate for Devouring Attrition
	DC.setIsIncarnon(false);

	// Apply viral procs
	DC.setViralProcs(1);
}

void calculateFrequency(FrequencyCalculation& FRC) {
	// Set base fire rate
	FRC.setFireRateBase(4.67);
	// Increase fire rate with multiplier
	FRC.setFireRateMultiplier(-0.2);			// this is Critical Deceleration
//	FRC.setFireRateMultiplier(0.35 * 2);		// this is 200% PWR STR Harrow

	// Set base magazine capacity
	FRC.setMagazineCapacityBase(1);
	// Increase magazine capacity with multiplier
	FRC.setMagazineCapacityMultiplier(0.55);	// this is Primed Magazine Warp

	// Set base reload time
	FRC.setReloadTimeBase(2);
	// Decrease reload time with divider
	FRC.setReloadTimeDivider(0.55);				// this is Primed Fast hands
//	FRC.setReloadTimeDivider(0.7 * 2);			// this is 200% PWR STR Harrow

	// Set base multishot
	FRC.setMultishotBase(28);
	// Increase multishot with multiplier
	FRC.setMultishotMultiplier(1.1 + .3 * 4);	// this is Galvanized Hell at Full Stacks
}

void calculateArmor(ArmorReduction& AR) {
	// Set base armor and base level
	AR.setBaseArmor(500);
	AR.setBaseLevel(8);

	// Set current level
	AR.setLevel(100);

	// Apply corrosive procs
	AR.corrosiveProcs(0);
}
// eg: Heavy Gunner Stats : Base Armor = 500, Base Level = 8

double attenuateDamage(double totalDamage, double estimatedDPS, double inverseAttenuationIntensity) {
	// The lower the value of inverseAttenuationIntensity, the faster and stronger the Attenuation will be.
	// If inverseAttenuationIntensity is set to 0, Attenuation will not affect the Damage.
		if (inverseAttenuationIntensity == 0) {
		return 1;
	}

	// Calculate part of the attenuation value
	double part = estimatedDPS + (1 - (estimatedDPS + totalDamage) / (estimatedDPS + totalDamage + inverseAttenuationIntensity)) * totalDamage;
	// Calculate the attenuation value
	double attenuateValue = 1 - part / (part + inverseAttenuationIntensity);
	// Return the attenuated damage
	return attenuateValue * totalDamage;
}

#if isDebugging
void printDebug(double totalDamage, double armoredDamage, double adjustedFrequency, double estimatedDPS, double attenuatedDamage) {
    std::cout << std::fixed << std::setprecision(2) 
			<< "Total Damage is : " << totalDamage << std::endl
			<< "Total Damage after Armor DR is : " << armoredDamage << std::endl
			<< "Adjusted Shot Frequency is : " << adjustedFrequency << std::endl
			<< "Estimated DPS after Armor DR is : " << estimatedDPS << std::endl << std::endl
			<< "Total Damage after Attenuation is : " << attenuatedDamage << std::endl
			<< "Estimated DPS after Attenuation is : " << attenuatedDamage * adjustedFrequency << std::endl
			<< "Damage is reduced to : " << attenuatedDamage / armoredDamage * 100 << '%' << std::endl;
}
#endif