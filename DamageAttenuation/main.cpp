#ifndef BASICS
	#include <stdlib.h>
	#include <math.h>
	#include <iostream>
	#define BASICS
#endif

#include "DamageCalculation.h"
#include "FrequencyCalculation.h"
#include "ArmorReduction.h"

#define isDebugging true;

double calculateDamage(DamageCalculation & DC);
double calculateFrequency(FrequencyCalculation & FRC);
double calculateArmor(ArmorReduction & AR);
double applyViralProcs(int i);
double attenuateDamage(double totalDamage, double estimatedDPS, double notArmor);

// I'm of the opinion that Weakpoint Multipliers should be the only thing increasing our Damage AFTER it's been Attenuated,
// to reward aiming and open up design space for Bosses that are a mechanical skillcheck,
// with interesting and complicated movement patterns to be mastered instead of our Damage being just a DPS Check.
// So I would set the "attenuatedWeakspots" variable as "false".
bool attenuatedWeakspots = true;
double weakPointMultiplier = 3;


int main() {
	DamageCalculation DC;
	int viralProcs = 10;
	double totalDamage = calculateDamage(DC) * applyViralProcs(viralProcs);
	//if (attenuatedWeakspots) totalDamage = totalDamage * weakPointMultiplier;

	//jankily implemented Trumna Headshot Multiplier
	if (!attenuatedWeakspots) {
		double AoEpercent = 50 / (50 + 82);
		totalDamage = totalDamage * weakPointMultiplier * (1 - AoEpercent) + totalDamage * AoEpercent;
	}

	ArmorReduction AR;
	double armoredDamage = totalDamage * calculateArmor(AR);

//	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~

	FrequencyCalculation FRC;

	double adjustedFrequency = calculateFrequency(FRC);

	double estimatedDPS = armoredDamage * adjustedFrequency;

//	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~

	double notArmor = 1000000; // The lower this is, the faster and harsher the Attenuation will be.
	double attenuatedDamage = attenuateDamage(armoredDamage, estimatedDPS, notArmor); // won't Attenuate if notArmor == 0
	//if (!attenuatedWeakspots) attenuatedDamage = attenuatedDamage * weakPointMultiplier;

	//jankily implemented Trumna Headshot Multiplier
	if (!attenuatedWeakspots) {
		double AoEpercent = 50 / (50 + 82);
		attenuatedDamage = attenuatedDamage * weakPointMultiplier * (1 - AoEpercent) + attenuatedDamage * AoEpercent;
	}

#if isDebugging
	std::cout << "Total Damage is : " << totalDamage << std::endl
		<< "Total Damage after Armor DR is : " << armoredDamage << std::endl
		<< "Adjusted Shot Frequency is : " << adjustedFrequency << std::endl
		<< "Estimated DPS after Armor DR is : " << estimatedDPS << std::endl
		<< "Total Damage after Attenuation is : " << attenuatedDamage << std::endl
		<< "Estimated DPS after Attenuation is : " << attenuatedDamage * adjustedFrequency << std::endl;
#endif

	return 0;
}

double calculateDamage(DamageCalculation & DC) {
	DC.setDamageBase(132);
	DC.setDamageMultiplier(1.65 + 3.6 - 0.15); // Serration + Primary Arcane at Full Stacks - Vile Acceleration
	DC.setCriticalChanceBase(0.24);
	DC.setCriticalChanceMultiplier(2 + 1.35); // Critical Delay + Argon Scope
	DC.setCriticalChanceAdditive(.45); // Arcane Avenger
	DC.setCriticalDamageBase(2.2);
	DC.setCriticalDamageMultiplier(1.2 + .6); // Vital Sense + Hammer Shot
	DC.setFactionDamageBase(1);
	DC.setFactionDamageMultiplier(0.55); // Primed Faction Mod

	// DC.setDamageMultiplier(2.75 * 2); // 200% PWR STR Chroma Vex Armor
	// DC.setCriticalChanceAdditive(2); // Covenant Headshots

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
	FRC.setMagazineCapacityBase(200);
	FRC.setMagazineCapacityMultiplier(0.55); // Primed Magazine Warp
	FRC.setReloadTimeBase(5);
	FRC.setReloadTimeDivider(0.55); // Primed Fast Hands
	FRC.setMultishotBase(1);
	FRC.setMultishotMultiplier(0.8 + .3 * 5); // Galvanized Chamber at Full Stacks

	//FRC.setFireRateMultiplier(0.35 * 2); // 200% PWR STR Harrow
	//FRC.setReloadTimeDivider(0.7 * 2); // 200% PWR STR Harrow

	return FRC.getAdjustedFireRate();
}

double attenuateDamage(double totalDamage, double estimatedDPS, double notArmor) {
	if (notArmor == 0) return 1; // won't Attenuate if notArmor == 0

	double part = estimatedDPS + (1 - (estimatedDPS + totalDamage) / (estimatedDPS + totalDamage + notArmor)) * totalDamage;
	double attenuateValue = 1 - part / (part + notArmor);
	return attenuateValue * totalDamage;
}