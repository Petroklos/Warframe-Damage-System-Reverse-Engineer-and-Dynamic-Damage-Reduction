#include "DamageCalculation.h"

DamageCalculation::DamageCalculation() {
	BD = BaseDamage();
	RD = RadialDamage();
	CC = CriticalChance();
	CD = CriticalDamage();
	WB = WeakpointBonus();
	FD = FactionDamage();
	vigilanteBonus = 0;
}

void DamageCalculation::setDamageBase(double d) { BD.setBase(d); }
void DamageCalculation::setDamageMultiplier(double d) { BD.setMultiplier(d); }
void DamageCalculation::setDamageAdditive(double d) { BD.setAdditive(d); }

void DamageCalculation::setRadialDamageBase(double d) { RD.setBase(d); }
void DamageCalculation::setRadialDamageMultiplier(double d) { RD.setMultiplier(d); }
void DamageCalculation::setRadialDamageAdditive(double d) { RD.setAdditive(d); }

void DamageCalculation::setCriticalChanceBase(double d) { CC.setBase(d); }
void DamageCalculation::setCriticalChanceMultiplier(double d) { CC.setMultiplier(d); }
void DamageCalculation::setCriticalChanceAdditive(double d) { CC.setAdditive(d); }
void DamageCalculation::setCriticalChanceVigilante(double d) { CC.setVigilanteBonus(d); }

void DamageCalculation::setCriticalDamageBase(double d) { CD.setBase(d); }
void DamageCalculation::setCriticalDamageMultiplier(double d) { CD.setMultiplier(d); }
void DamageCalculation::setCriticalDamageAdditive(double d) { CD.setAdditive(d); }

void DamageCalculation::setWeakpointBonusBase(double d) { WB.setBase(d); }
void DamageCalculation::setWeakpointBonusMultiplier(double d) { WB.setMultiplier(d); }
void DamageCalculation::setWeakpointBonusAdditive(double d) { WB.setAdditive(d); }

void DamageCalculation::setFactionDamageBase(double d) { FD.setBase(d); }
void DamageCalculation::setFactionDamageMultiplier(double d) { FD.setMultiplier(d); }
void DamageCalculation::setFactionDamageAdditive(double d) { FD.setAdditive(d); }

double DamageCalculation::getDamage() {
	double weakpointDamageCalculation = BD.calculateTotal() * WB.calculateTotal() + RD.calculateTotal();
	double criticalDamageCalculation = weakpointDamageCalculation * CD.calculateTotal(CC.calculateTotal(), CC.getVigilanteBonus());
	double factionDamageCalculation = criticalDamageCalculation * FD.calculateTotal();
	return factionDamageCalculation;
}