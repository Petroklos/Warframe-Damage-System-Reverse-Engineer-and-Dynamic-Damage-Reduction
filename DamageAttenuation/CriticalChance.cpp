#include "CriticalChance.h"

CriticalChance::CriticalChance() {
	setBase(0);
	setMultiplier(1);
	setAdditive(0);
	vigilanteBonus = -1;
}

CriticalChance::CriticalChance(double b, double m, double a, double v) {
	setBase(b);
	setMultiplier(m);
	setAdditive(a);
	vigilanteBonus = v;
}

void CriticalChance::setVigilanteBonus(double d) { vigilanteBonus = d; }
double CriticalChance::getVigilanteBonus() { return vigilanteBonus; }

int CriticalChance::calculateCritTier() {
	double criticalChance = calculateTotal();

	int critLevel = (int)(criticalChance / 1);
	
	#if isDebugging
	std::cout << std:: endl << "Minimum Crit Level: " << critLevel << std::endl;
	#endif

	srand(time(NULL));

	double remainder = criticalChance - critLevel;
	if (remainder > 0) {
		int r = rand() % 100;
		if (r <= (remainder * 100)) {
			critLevel++;
			#if isDebugging
			std::cout << "Rolled Crit Level: " << critLevel << std::endl;
			#endif
		}
	}


	if (critLevel > 0 && vigilanteBonus > 0) {
		int r = rand() % 100;
		if (r <= (vigilanteBonus * 100)) {
			critLevel++;
			#if isDebugging
			std::cout << "Vigilante Crit Level: " << critLevel << std::endl << std::endl;
			#endif
		}
	}

	#if isDebugging
	std::cout << std::endl;
	#endif

	return critLevel;
}