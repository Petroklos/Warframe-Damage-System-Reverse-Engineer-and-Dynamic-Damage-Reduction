#include "DamageCalculation.h"

DamageCalculation::DamageCalculation() {
	BD = BaseDamage();
	RD = RadialDamage();
	WB = WeakpointBonus();
	ED = ElementalDamage();
	CC = CriticalChance();
	vigilanteBonus = 0;
	CD = CriticalDamage();
	FD = FactionDamage();
	viralProcs = 0;
	isIncarnon = false;
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

void DamageCalculation::setElementalBase(double d) { ED.setBase(d); }
void DamageCalculation::setElementalMultiplier(int i, double d) { ED.addElement(i, d); }
void DamageCalculation::setElementalAdditive(double d) { ED.setAdditive(d); }

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

void DamageCalculation::setViralProcs(int i) {
	if (i < 0)
		viralProcs = 0;
	else if (i > 10)
		viralProcs = 10;
	else
		viralProcs = i;
}
double DamageCalculation::viralMultiplier() { return 1 + (0.75 + 0.25 * viralProcs) * (viralProcs > 0); }

void DamageCalculation::setIsIncarnon(bool b) {	isIncarnon = b; }

double DamageCalculation::getDamage() {
	// Base Damage
	double damage = BD.calculateTotal() * WB.calculateTotal() + RD.calculateTotal();
	#if	isDebugging
	std::cout << "Base Damage: " << damage << std::endl;
	#endif

	//Elemental Damage
	damage *= ED.calculateTotal();
	#if	isDebugging
	std::cout << "Elemental Damage: " << damage << std::endl;
	#endif

	// Critical or Incaron Damage
	int critLevel = CC.calculateCritTier();
	if (critLevel > 0) {
		damage *= CD.calculateTotal(critLevel);
		#if	isDebugging
		std::cout << "Critical Damage: " << damage << std::endl;
		#endif
	} else if (isIncarnon) {
		damage *= (double)(1 + 20);
		#if	isDebugging
		std::cout << "Incarnon Damage: " << damage << std::endl;
		#endif
	}

	// Faction Damage
	damage *= FD.calculateTotal();
	#if	isDebugging
	std::cout << "Faction Damage: " << damage << std::endl;
	#endif

	// Viral Damage
	damage *= viralMultiplier();
	#if	isDebugging
	std::cout << "Viral Damage: " << damage << std::endl << std::endl;
	#endif

	return damage;
}

double DamageCalculation::calculateFactionDamage() { return FD.calculateTotal(); }