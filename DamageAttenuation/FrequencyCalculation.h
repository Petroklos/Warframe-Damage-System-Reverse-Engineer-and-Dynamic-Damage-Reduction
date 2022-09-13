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

#include "FireRate.h"
#include "MagazineCapacity.h"
#include "ReloadTime.h"
#include "Multishot.h"

#pragma once
class FrequencyCalculation
{
	FireRate FR;
	MagazineCapacity MC;
	ReloadTime RT;
	Multishot MS;
public:
	FrequencyCalculation();

	void setFireRateBase(double d);
	void setFireRateMultiplier(double d);
	void setFireRateAdditive(double d);

	void setMagazineCapacityBase(double d);
	void setMagazineCapacityMultiplier(double d);
	void setMagazineCapacityAdditive(double d);

	void setReloadTimeBase(double d);
	void setReloadTimeDivider(double d);
	void setReloadTimeAdditive(double d);

	void setMultishotBase(double d);
	void setMultishotMultiplier(double d);
	void setMultishotAdditive(double d);

	double getAdjustedFireRate();
};

