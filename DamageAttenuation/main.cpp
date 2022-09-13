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
bool attenuatedWeakspots = false;
double weakPointMultiplier = 3;

int main() {
	DamageCalculation DC;
	int viralProcs = 1;
	double totalDamage = calculateDamage(DC) * applyViralProcs(viralProcs);
	if (attenuatedWeakspots) totalDamage = totalDamage * weakPointMultiplier;

	ArmorReduction AR;
	double armoredDamage = totalDamage * calculateArmor(AR);

//	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~

	FrequencyCalculation FRC;	
	double adjustedFrequency = calculateFrequency(FRC);

	double estimatedDPS = armoredDamage * adjustedFrequency;


//	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~	~

	double notArmor = 1000000; // The lower this is, the faster and harsher the Attenuation will be.
	double attenuatedDamage = attenuateDamage(armoredDamage, estimatedDPS, notArmor); // won't Attenuate if notArmor == 0
	if (!attenuatedWeakspots) attenuatedDamage = attenuatedDamage * weakPointMultiplier;

#if isDebugging
	std::cout << "Total Damage is : " << totalDamage << std::endl
		<< "Total Damage after Armor DR is : " << totalDamage << std::endl
		<< "Adjusted Shot Frequency is : " << adjustedFrequency << std::endl
		<< "Estimated DPS, after Armor DR if applicable, is : " << estimatedDPS << std::endl
		<< "Total Damage after Attenuation is : " << attenuatedDamage << std::endl
		<< "Estimated DPS after Attenuation is : " << attenuatedDamage * adjustedFrequency << std::endl;
#endif

	return 0;
}

double calculateDamage(DamageCalculation & DC) {
	DC.setDamageBase(10);
	DC.setDamageMultiplier(1.65 + 3.6);
	DC.setCriticalChanceBase(0.25);
	DC.setCriticalChanceMultiplier(2 + 1.35);
	DC.setCriticalChanceAdditive(.45);
	DC.setCriticalDamageBase(2.2);
	DC.setCriticalDamageMultiplier(1.2 + .6);
	return DC.getDamage();
}

double calculateFrequency(FrequencyCalculation & FRC) {
	FRC.setFireRateBase(10);
	FRC.setFireRateMultiplier(0.6);
	FRC.setMagazineCapacityBase(25);
	FRC.setMagazineCapacityMultiplier(0.3);
	FRC.setReloadTimeBase(1);
	FRC.setReloadTimeDivider(0.3);
	FRC.setMultishotBase(1);
	FRC.setMultishotMultiplier(0.8 + .3 * 5);
	return FRC.getAdjustedFireRate();
}

double calculateArmor(ArmorReduction & AR) {
	// Heavy Gunner Stats : Base Armor = 500, Base Level = 8
	AR.setBaseArmor(500);
	AR.setBaseLevel(8);
	AR.setLevel(100);
	return AR.getArmorDR();
}

double applyViralProcs(int i) {
	return 1 + (0.75 + 0.25 * i) * (i > 0 && i < 10);
}

double attenuateDamage(double totalDamage, double estimatedDPS, double notArmor) {
	if (notArmor == 0) return 1;

	double part = (2 * estimatedDPS) + (1 - (2 * estimatedDPS + totalDamage) / (2 * estimatedDPS + totalDamage + notArmor)) * totalDamage;
	double attenuateValue = part / (part + notArmor);
	return (1 - attenuateValue) * totalDamage;
}