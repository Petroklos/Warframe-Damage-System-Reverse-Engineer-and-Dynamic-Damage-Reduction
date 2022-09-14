#ifndef BASICS
	#include <stdlib.h>
	#include <math.h>
	#include <iostream>
	#define BASICS
#endif

#ifndef GS
	#include "GenericStat.h"
	#define GS
#endif

#include "BaseDamage.h"
#include "RadialDamage.h"
#include "CriticalChance.h"
#include "CriticalDamage.h"
#include "WeakpointBonus.h"
#include "FactionDamage.h"

#pragma once
class DamageCalculation
{
	BaseDamage BD;
	RadialDamage RD;
	CriticalChance CC;
	CriticalDamage CD;
	WeakpointBonus WB;
	FactionDamage FD;
	double vigilanteBonus;
public:
	DamageCalculation();

	void setDamageBase(double d);
	void setDamageMultiplier(double d);
	void setDamageAdditive(double d);

	void setRadialDamageBase(double d);
	void setRadialDamageMultiplier(double d);
	void setRadialDamageAdditive(double d);

	void setCriticalChanceBase(double d);
	void setCriticalChanceMultiplier(double d);
	void setCriticalChanceAdditive(double d);
	void setCriticalChanceVigilante(double d);

	void setCriticalDamageBase(double d);
	void setCriticalDamageMultiplier(double d);
	void setCriticalDamageAdditive(double d);

	void setWeakpointBonusBase(double d);
	void setWeakpointBonusMultiplier(double d);
	void setWeakpointBonusAdditive(double d);

	void setFactionDamageBase(double d);
	void setFactionDamageMultiplier(double d);
	void setFactionDamageAdditive(double d);

	double getDamage();
};

