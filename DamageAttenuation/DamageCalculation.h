#include "Definitions.h"

#include "BaseDamage.h"
#include "RadialDamage.h"
#include "WeakpointBonus.h"
#include "ElementalDamage.h"
#include "CriticalChance.h"
#include "CriticalDamage.h"
#include "FactionDamage.h"

#pragma once
class DamageCalculation
{
	BaseDamage BD;
	RadialDamage RD;
	WeakpointBonus WB;
	ElementalDamage ED;
	CriticalChance CC;
	double vigilanteBonus;
	CriticalDamage CD;
	FactionDamage FD;
	int viralProcs;
	bool isIncarnon;

public:
	DamageCalculation();

	void setDamageBase(double);
	void setDamageMultiplier(double);
	void setDamageAdditive(double);

	void setRadialDamageBase(double);
	void setRadialDamageMultiplier(double);
	void setRadialDamageAdditive(double);

	void setWeakpointBonusBase(double);
	void setWeakpointBonusMultiplier(double);
	void setWeakpointBonusAdditive(double);

	void setElementalBase(double);
	void setElementalMultiplier(int, double);
	void setElementalAdditive(double);

	void setCriticalChanceBase(double);
	void setCriticalChanceMultiplier(double);
	void setCriticalChanceAdditive(double);
	void setCriticalChanceVigilante(double);

	void setCriticalDamageBase(double);
	void setCriticalDamageMultiplier(double);
	void setCriticalDamageAdditive(double);

	void setFactionDamageBase(double);
	void setFactionDamageMultiplier(double);
	void setFactionDamageAdditive(double);

	void setViralProcs(int);
	double viralMultiplier();

	void setIsIncarnon(bool);

	double getDamage();
	double calculateFactionDamage();
};