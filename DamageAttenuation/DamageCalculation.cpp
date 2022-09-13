#include "DamageCalculation.h"

DamageCalculation::DamageCalculation() {
	BD = BaseDamage();
	CC = CriticalChance();
	CD = CriticalDamage();
}

void DamageCalculation::setDamageBase(double d) { BD.setBase(d); }
void DamageCalculation::setDamageMultiplier(double d) { BD.setMultiplier(d); }
void DamageCalculation::setDamageAdditive(double d) { BD.setAdditive(d); }

void DamageCalculation::setCriticalChanceBase(double d) { CC.setBase(d); }
void DamageCalculation::setCriticalChanceMultiplier(double d) { CC.setMultiplier(d); }
void DamageCalculation::setCriticalChanceAdditive(double d) { CC.setAdditive(d); }

void DamageCalculation::setCriticalDamageBase(double d) { CD.setBase(d); }
void DamageCalculation::setCriticalDamageMultiplier(double d) { CD.setMultiplier(d); }
void DamageCalculation::setCriticalDamageAdditive(double d) { CD.setAdditive(d); }

double DamageCalculation::getDamage() {
	return BD.calculateTotal() * CD.calculateTotal(CC.calculateTotal());
}