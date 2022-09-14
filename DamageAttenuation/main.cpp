#ifndef BASICS
	#include <stdlib.h>
	#include <math.h>
	#include <iostream>
	#define BASICS
#endif

#include "DamageCalculation.h"
#include "FrequencyCalculation.h"
#include "ArmorReduction.h"

#define isDebugging true; // if this is set to "false", no calculated values will be printed to the console
#if isDebugging
void printDebug(double, double, double, double, double);
#endif

double calculateDamage(DamageCalculation &);
double calculateFrequency(FrequencyCalculation &);
double calculateArmor(ArmorReduction &);
double applyViralProcs(int);
double attenuateDamage(double totalDamage, double estimatedDPS, double notArmor);


int main() {
	DamageCalculation DC;
	double totalDamage = calculateDamage(DC) * applyViralProcs(10);

	ArmorReduction AR;
	double armoredDamage = totalDamage * calculateArmor(AR);

//	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~

	FrequencyCalculation FRC;

	double adjustedFrequency = calculateFrequency(FRC);

	double estimatedDPS = armoredDamage * adjustedFrequency;

//	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~

	double notArmor = 1000000; // The lower this is, the faster and harsher the Attenuation will be.
	double attenuatedDamage = attenuateDamage(armoredDamage, estimatedDPS, notArmor); // won't Attenuate if notArmor == 0

#if isDebugging
	printDebug(totalDamage, armoredDamage, adjustedFrequency, estimatedDPS, attenuatedDamage);
#endif

	return 0;
}

double calculateDamage(DamageCalculation & DC) {
	DC.setDamageBase(82); // Direct Hit Damage Portion
	DC.setDamageMultiplier(1.65 + 3.6 - 0.15); // Serration + Primary Arcane at Full Stacks - Vile Acceleration
	// DC.setDamageMultiplier(2.75 * 2); // 200% PWR STR Chroma Vex Armor

	DC.setRadialDamageBase(50); // Radial Hit Damage Portion (AoE)
	DC.setRadialDamageMultiplier(1.65 + 3.6 - 0.15); // Serration + Primary Arcane at Full Stacks - Vile Acceleration
	// DC.setRadialDamageMultiplier(2.75 * 2); // 200% PWR STR Chroma Vex Armor

	DC.setCriticalChanceBase(0.24);
	DC.setCriticalChanceMultiplier(2 + 1.35); // Critical Delay + Argon Scope
	DC.setCriticalChanceAdditive(.45); // Arcane Avenger
	DC.setCriticalChanceVigilante(0.05 * 1); // Vigilante Armaments
	// DC.setCriticalChanceAdditive(2); // Covenant Headshots

	DC.setCriticalDamageBase(2.2);
	DC.setCriticalDamageMultiplier(1.2 + .6); // Vital Sense + Hammer Shot

	DC.setWeakpointBonusBase(3);
	DC.setWeakpointBonusAdditive(0.3); // Primary Deadhead

	DC.setElementalBase(1);
	DC.setElementalMultiplier(0, 0.6); // Cold 60/60 for Viral
	DC.setElementalMultiplier(3, 0.6); // Toxin 60/60 for Viral

	DC.setFactionDamageBase(1);
	DC.setFactionDamageMultiplier(0.55); // Primed Faction Mod


	return DC.getDamage();
}

double applyViralProcs(int i) {
	return 1 + (0.75 + 0.25 * i) * (i > 0 && i <= 10);
}

double calculateArmor(ArmorReduction& AR) {
	// Heavy Gunner Stats : Base Armor = 500, Base Level = 8
	AR.setBaseArmor(500);
	AR.setBaseLevel(8);
	AR.setLevel(100);
	// AR.corrosiveProcs(10);
	return AR.getArmorDR();
}

double calculateFrequency(FrequencyCalculation & FRC) {
	FRC.setFireRateBase(4.67);
	FRC.setFireRateMultiplier(0.9); // Vile Acceleration
	//FRC.setFireRateMultiplier(0.35 * 2); // 200% PWR STR Harrow

	FRC.setMagazineCapacityBase(200);
	FRC.setMagazineCapacityMultiplier(0.55); // Primed Magazine Warp

	FRC.setReloadTimeBase(5);
	FRC.setReloadTimeDivider(0.55); // Primed Fast Hands
	//FRC.setReloadTimeDivider(0.7 * 2); // 200% PWR STR Harrow

	FRC.setMultishotBase(1);
	FRC.setMultishotMultiplier(0.8 + .3 * 5); // Galvanized Chamber at Full Stacks


	return FRC.getAdjustedFireRate();
}

double attenuateDamage(double totalDamage, double estimatedDPS, double notArmor) {
	if (notArmor == 0) return 1; // won't Attenuate if notArmor == 0

	double part = estimatedDPS + (1 - (estimatedDPS + totalDamage) / (estimatedDPS + totalDamage + notArmor)) * totalDamage;
	double attenuateValue = 1 - part / (part + notArmor);
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