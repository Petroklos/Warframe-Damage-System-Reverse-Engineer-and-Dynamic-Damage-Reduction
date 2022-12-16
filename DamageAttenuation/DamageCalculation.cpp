#include "DamageCalculation.h"

DamageCalculation::DamageCalculation()
	: BD(), RD(), WB(), ED(), CC(), vigilanteBonus(0), CD(), FD(), viralProcs(0), isIncarnon(false) {
	// Default constructor
}

void DamageCalculation::setDamageBase(double d) { BD.setBase(d); }
void DamageCalculation::setDamageMultiplier(double d) { BD.setMultiplier(d); }
void DamageCalculation::setDamageAdditive(double d) { BD.setAdditive(d); }

void DamageCalculation::setRadialDamageBase(double d) { RD.setBase(d); }
void DamageCalculation::setRadialDamageMultiplier(double d) { RD.setMultiplier(d); }
void DamageCalculation::setRadialDamageAdditive(double d) { RD.setAdditive(d); }

void DamageCalculation::setWeakpointBonusBase(double d) { WB.setBase(d); }
void DamageCalculation::setWeakpointBonusMultiplier(double d) { WB.setMultiplier(d); }
void DamageCalculation::setWeakpointBonusAdditive(double d) { WB.setAdditive(d); }

void DamageCalculation::setElementalMultiplier(int i, double d) { ED.addElement(i, d); }

void DamageCalculation::setCriticalChanceBase(double d) { CC.setBase(d); }
void DamageCalculation::setCriticalChanceMultiplier(double d) { CC.setMultiplier(d); }
void DamageCalculation::setCriticalChanceAdditive(double d) { CC.setAdditive(d); }
void DamageCalculation::setCriticalChanceVigilante(double d) { CC.setVigilanteBonus(d); }

void DamageCalculation::setCriticalDamageBase(double d) { CD.setBase(d); }
void DamageCalculation::setCriticalDamageMultiplier(double d) { CD.setMultiplier(d); }
void DamageCalculation::setCriticalDamageAdditive(double d) { CD.setAdditive(d); }

void DamageCalculation::setFactionDamageBase(double d) { FD.setBase(d); }
void DamageCalculation::setFactionDamageMultiplier(double d) { FD.setMultiplier(d); }
void DamageCalculation::setFactionDamageAdditive(double d) { FD.setAdditive(d); }

// Sets the number of viral procs applied to the enemy, clamps the value to be between 0 and 10 (inclusive).
void DamageCalculation::setViralProcs(int i) {
	if (i < 0)
		viralProcs = 0;
	else if (i > 10)
		viralProcs = 10;
	else
		viralProcs = i;
}

// Calculates and returns the damage multiplier applied by viral procs. If there are no viral procs applied, returns 1 (no damage multiplier).
double DamageCalculation::viralMultiplier() { return 1 + (0.75 + 0.25 * viralProcs) * (viralProcs > 0); }

// Set whether the attack is being performed by an Incarnon Weapon
void DamageCalculation::setIsIncarnon(bool b) {	isIncarnon = b; }

double DamageCalculation::getDamage() {
	// Calculate base damage
	double damage = BD.calculateTotal() * WB.calculateTotal() + RD.calculateTotal();
	#if	isDebugging
		std::cout << "Base Damage: " << damage << std::endl;
	#endif

	// Apply elemental damage
	damage *= ED.calculateTotal();
	#if	isDebugging
		std::cout << "Elemental Damage: " << damage << std::endl;
	#endif

	// Check if there are critical hits or Incarnon damage
	int critLevel = CC.calculateCritTier();
	if (critLevel > 0) {
		// Apply critical damage
		damage *= CD.calculateTotal(critLevel);
		#if	isDebugging
			std::cout << "Critical Damage: " << damage << std::endl;
		#endif
	} else if (isIncarnon) {
		// Apply Incarnon damage
		damage *= (double)(1 + 20);
		#if	isDebugging
			std::cout << "Incarnon Damage: " << damage << std::endl;
		#endif
	}

	// Apply faction damage
	damage *= FD.calculateTotal();
	#if	isDebugging
		std::cout << "Faction Damage: " << damage << std::endl;
	#endif

	// Apply viral damage
	damage *= viralMultiplier();
	#if	isDebugging
		std::cout << "Viral Damage: " << damage << std::endl << std::endl;
	#endif

	return damage;
}

double DamageCalculation::calculateFactionDamage() { return FD.calculateTotal(); }