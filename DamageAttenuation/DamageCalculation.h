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
#include "CriticalChance.h"
#include "CriticalDamage.h"

#pragma once
class DamageCalculation
{
	BaseDamage BD;
	CriticalChance CC;
	CriticalDamage CD;
public:
	DamageCalculation();

	void setDamageBase(double d);
	void setDamageMultiplier(double d);
	void setDamageAdditive(double d);

	void setCriticalChanceBase(double d);
	void setCriticalChanceMultiplier(double d);
	void setCriticalChanceAdditive(double d);

	void setCriticalDamageBase(double d);
	void setCriticalDamageMultiplier(double d);
	void setCriticalDamageAdditive(double d);

	double getDamage();
};

