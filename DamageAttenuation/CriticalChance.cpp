#include "CriticalChance.h"

// Default constructor
CriticalChance::CriticalChance() {
	setBase(0);
	setMultiplier(1);
	setAdditive(0);
	vigilanteBonus = -1;
}

// Parametrized constructor
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

	// Determine the crit tier by dividing the critical chance by 1 and rounding down to the nearest integer.
	int critLevel = (int)(criticalChance / 1);
	
	#if isDebugging
	std::cout << std:: endl << "Minimum Crit Level: " << critLevel << std::endl;
	#endif

	std::srand(std::time(nullptr));

	// If there is a remainder, generate a random number between 0 and 100.
	// Add 1 to the crit tier if the random number is less than or equal to the remainder multiplied by 100.
	double remainder = criticalChance - critLevel;
	if (remainder > 0) {
		int r = std::rand() % 100;
		if (r <= (remainder * 100)) {
			critLevel++;
			#if isDebugging
			std::cout << "Rolled Crit Level: " << critLevel << std::endl;
			#endif
		}
	}

	// If the crit tier is positive and the vigilante bonus is positive, generate another random number between 0 and 100.
	// Add 1 to the crit tier if the random number is less than or equal to the Vigilante Set Bonus multiplied by 100.
	if (critLevel > 0 && vigilanteBonus > 0) {
		int r = std::rand() % 100;
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