#include "CriticalDamage.h"

#ifndef BASICS
	#include <stdlib.h>
	#include <math.h>
	#include <iostream>
	#define BASICS
#endif

double CriticalDamage::calculateTotal( double criticalChance ) {
	double toReturn = 0;

	int mod = (int)(criticalChance/1);

	double remainder = criticalChance - mod;

	if (remainder != 0) {
		srand(time(NULL));
		int r = rand() % 100;
		if (r <= (remainder * 100)) {
			toReturn = 1 + (getBase() * getMultiplier() + getAdditive() - 1) * (mod + 1);
		}
		else {
			toReturn = 1 + (getBase() * getMultiplier() + getAdditive() - 1) * mod;
		}
	} else {
		toReturn = 1 + (getBase() * getMultiplier() + getAdditive() - 1) * mod;
	}

	return toReturn;
}
