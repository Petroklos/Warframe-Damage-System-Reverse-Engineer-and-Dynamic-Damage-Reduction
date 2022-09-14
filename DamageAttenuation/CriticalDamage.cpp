#include "CriticalDamage.h"

#ifndef BASICS
	#include <stdlib.h>
	#include <math.h>
	#include <iostream>
	#define BASICS
#endif

double CriticalDamage::calculateTotal( double criticalChance, double vigilanteBonus ) {
	int critLevel = (int)(criticalChance/1);
	//std::cout << criticalChance * 100 << std::endl << " Minimum Crit Level: " << critLevel << std::endl;

	srand(time(NULL));

	double remainder = criticalChance - critLevel;
	if (remainder > 0) {
		int r = rand() % 100;
		if (r <= (remainder * 100))
			critLevel++;
		//std::cout << r << std::endl << " Rolled Crit Level: " << critLevel << std::endl;
	}

	if (critLevel > 0 && vigilanteBonus > 0) {
		int r = rand() % 100;
		if (r <= (vigilanteBonus * 100))
			critLevel++;
		//std::cout << r << std::endl << " Vigilante Crit Level: " << critLevel << std::endl;
	}
	
	return 1 + (getBase() * getMultiplier() - 1) * critLevel + getAdditive();
}