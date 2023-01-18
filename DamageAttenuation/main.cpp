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

double attenuateDamage(double totalDamage, double estimatedDPS, double inverseAttenuationIntensity);
double compressDamage(double totalDamage, double estimatedDPS, double desiredDPS, float compressionModifier);

int main() {
	DamageCalculation DC;
	calculateDamage(DC);

	ArmorReduction AR;
	AR.armorStrip(0);
	calculateArmor(AR);

	FrequencyCalculation FRC;
	calculateFrequency(FRC);

	double totalDamage = DC.getDamage() * AR.getArmorDR();
	double adjustedFireRate = FRC.getAdjustedFireRate();
	double estimatedDPS = totalDamage * adjustedFireRate;

	std::cout << "1. Damage Attenuation" << std::endl << "2. Damage Compressor" << std::endl;
	char i;
	std::cin >> i;

	double reducedDamage;
	if (i == '1') {
		// "A Better Damage Attenuation Formula" as penned by DrBorris
		double inverseAttenuationIntensity = 69420;
		reducedDamage = attenuateDamage(totalDamage, estimatedDPS, inverseAttenuationIntensity);
	} else if (i == '2') {
		// Damage Compressor, inspired by Audio Compressors
		float desiredDPS = 6000;
		reducedDamage = compressDamage(totalDamage, estimatedDPS, desiredDPS, 1);
	}

	#if isDebugging
		printDebug(totalDamage, totalDamage, adjustedFireRate, estimatedDPS, reducedDamage);
	#endif

	return 0;
}

// Kuva Hek - Alt Fire
void calculateDamage(DamageCalculation& DC) {
	DC.setDamageBase(87 * 1.6);					// Has 60% Progenitor Element
	DC.setDamageMultiplier(0.6 + 3.6);			// This is Blaze + Primary Deadhead at Full Stacks

	DC.setCriticalChanceBase(0.23);
	DC.setCriticalChanceMultiplier(2);			// Critical Deceleration
	DC.setCriticalChanceAdditive(.45);			// Arcane Avenger

	DC.setCriticalDamageBase(2.1);
	DC.setCriticalDamageMultiplier(1.1);		// This is Primed Ravage

	DC.setWeakpointBonusBase(3);
	DC.setWeakpointBonusAdditive(0.3);			// This is Primary Deadhead

	DC.setElementalMultiplier(1, 1.65);			// This is Primed Charge Shell for Electric
	DC.setElementalMultiplier(2, 0.6);			// This is Blaze for Radiation
	DC.setElementalMultiplier(0, 1.65);			// This is Primed Chilling Grasp for Cold
	DC.setElementalMultiplier(3, 0.9);			// This is Contagious Spread for Viral

	DC.setFactionDamageBase(1);
	DC.setFactionDamageMultiplier(0.5 * 2);		// This is 200% PWR STR Rhino Roar

	DC.setIsIncarnon(false);

	DC.setViralProcs(1);
}

void calculateFrequency(FrequencyCalculation& FRC) {
	FRC.setFireRateBase(4.67);
	FRC.setFireRateMultiplier(-0.2);			// this is Critical Deceleration

	FRC.setMagazineCapacityBase(1);
	FRC.setMagazineCapacityMultiplier(0.55);	// this is Primed Magazine Warp

	FRC.setReloadTimeBase(2);
	FRC.setReloadTimeDivider(0.55);				// this is Primed Fast hands

	FRC.setMultishotBase(28);
	FRC.setMultishotMultiplier(1.1 + .3 * 4);	// this is Galvanized Hell at Full Stacks
}

void calculateArmor(ArmorReduction& AR) {
	// eg: Heavy Gunner Stats : Base Armor = 500, Base Level = 8
	AR.setBaseArmor(500);
	AR.setBaseLevel(8);
	AR.setLevel(100);
	AR.corrosiveProcs(0);
}

double attenuateDamage(double totalDamage, double estimatedDPS, double inverseAttenuationIntensity) {
		if (inverseAttenuationIntensity == 0) {
		return 1;
	}

	double partOfFormula = estimatedDPS + (1 - (estimatedDPS + totalDamage) / (estimatedDPS + totalDamage + inverseAttenuationIntensity)) * totalDamage;
	double attenuateValue = 1 - partOfFormula / (partOfFormula + inverseAttenuationIntensity);
	return attenuateValue * totalDamage;
}

double compressDamage(double totalDamage, double estimatedDPS, double desiredDPS, float compressionModifier) {
	if (estimatedDPS < desiredDPS) {
		return estimatedDPS;
	}

	double compressionRatio = compressionModifier * desiredDPS / estimatedDPS;
	if (compressionRatio > 1) compressionRatio = 1;

	double instanceCompressionRatio = (desiredDPS + (estimatedDPS - desiredDPS) * compressionRatio) / estimatedDPS;

	return totalDamage * instanceCompressionRatio;
}

#if isDebugging
void printDebug(double totalDamage, double armoredDamage, double adjustedFireRate, double estimatedDPS, double attenuatedDamage) {
    std::cout << std::fixed << std::setprecision(2) 
			<< "Total Damage is : " << totalDamage << std::endl
			<< "Total Damage after Armor DR is : " << armoredDamage << std::endl
			<< "Adjusted Shot Frequency is : " << adjustedFireRate << std::endl
			<< "Estimated DPS after Armor DR is : " << estimatedDPS << std::endl << std::endl
			<< "Total Damage after Attenuation/Compression is : " << attenuatedDamage << std::endl
			<< "Estimated DPS after Attenuation/Compression is : " << attenuatedDamage * adjustedFireRate << std::endl
			<< "Damage is reduced to : " << attenuatedDamage / armoredDamage * 100 << '%' << std::endl;
}
#endif