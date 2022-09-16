#include "Definitions.h"

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

	void setFireRateBase(double);
	void setFireRateMultiplier(double);
	void setFireRateAdditive(double);

	void setMagazineCapacityBase(double);
	void setMagazineCapacityMultiplier(double);
	void setMagazineCapacityAdditive(double);

	void setReloadTimeBase(double);
	void setReloadTimeDivider(double);
	void setReloadTimeAdditive(double);

	void setMultishotBase(double);
	void setMultishotMultiplier(double);
	void setMultishotAdditive(double);

	double getAdjustedFireRate();
};

