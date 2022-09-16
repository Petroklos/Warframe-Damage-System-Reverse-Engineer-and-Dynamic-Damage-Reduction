#include "ElementalDamage.h"

void ElementalDamage::addElement(int i, double d) {
	// Will not differentiate between Elements yet
	setMultiplier(d);

	// First steps to implementing Elemental differentiation
	if (singleElement == -1) {
		singleElement = i;
		baseElements[i] = 1 + d;
	}
	else if (singleElement == i) {
		baseElements[i] += d;
	}
	else {
		//	Blast
		if ((singleElement == 0 && i == 2) || (singleElement == 2 && i == 0))
			combinedElements[0] = baseElements[singleElement] + d;
		//	Corrosive
		if ((singleElement == 1 && i == 3) || (singleElement == 3 && i == 1))
			combinedElements[1] = baseElements[singleElement] + d;
		//	Gas
		if ((singleElement == 2 && i == 3) || (singleElement == 3 && i == 2))
			combinedElements[2] = baseElements[singleElement] + d;
		//	Magnetic
		if ((singleElement == 0 && i == 1) || (singleElement == 1 && i == 0))
			combinedElements[3] = baseElements[singleElement] + d;
		//	Radiation
		if ((singleElement == 1 && i == 2) || (singleElement == 2 && i == 1))
			combinedElements[4] = baseElements[singleElement] + d;
		//	Viral
		if ((singleElement == 0 && i == 3) || (singleElement == 3 && i == 0))
			combinedElements[5] = baseElements[singleElement] + d;
		baseElements[singleElement] = 0;
		singleElement = -1;
	}
}

double ElementalDamage::calculateTotal() {
	#if isDebugging
	std::cout << std::endl;
	if (combinedElements[0] > 0)
		std::cout << "Blast = " << combinedElements[0] * 100 << '%' << std::endl;
	if (combinedElements[1] > 0)
		std::cout << "Corrosive = " << combinedElements[1] * 100 << '%' << std::endl;
	if (combinedElements[2] > 0)
		std::cout << "Gas = " << combinedElements[2] * 100 << '%' << std::endl;
	if (combinedElements[3] > 0)
		std::cout << "Magnetic = " << combinedElements[3] * 100 << '%' << std::endl;
	if (combinedElements[4] > 0)
		std::cout << "Radiation = " << combinedElements[4] * 100 << '%' << std::endl;
	if (combinedElements[5] > 0)
		std::cout << "Viral = " << combinedElements[5] * 100 << '%' << std::endl;
	if (baseElements[0] > 0)
		std::cout << "Cold = " << baseElements[0] * 100 << '%' << std::endl;
	if (baseElements[1] > 0)
		std::cout << "Electric = " << baseElements[1] * 100 << '%' << std::endl;
	if (baseElements[2] > 0)
		std::cout << "Heat = " << baseElements[2] * 100 << '%' << std::endl;
	if (baseElements[3] > 0)
		std::cout << "Toxin = " << baseElements[3] * 100 << '%' << std::endl << std::endl;
	std::cout << std::endl;
	#endif

	return baseElements[0] + baseElements[1] + baseElements[2] + baseElements[3] + combinedElements[0] + combinedElements[1] + combinedElements[2] + combinedElements[3] + combinedElements[4] + combinedElements[5];
}

/* Single Element IDs:
*	0: Cold
*	1: Electric
*	2: Heat
*	3: Toxin
*/

/* Combined Element IDs:
*	0: Blast
*	1: Corrosive
*	2: Gas
*	3: Magnetic
*	4: Radiation
*	5: Viral
*/

/*
#if isDebugging
std::cout << std::endl;
if (combinedElements[0] > 0)
	std::cout << "Blast = " << combinedElements[0] * 100 << '%' << std::endl;
if (combinedElements[1] > 0)
	std::cout << "Corrosive = " << combinedElements[1] * 100 << '%' << std::endl;
if (combinedElements[2] > 0)
	std::cout << "Gas = " << combinedElements[2] * 100 << '%' << std::endl;
if (combinedElements[3] > 0)
	std::cout << "Magnetic = " << combinedElements[3] * 100 << '%' << std::endl;
if (combinedElements[4] > 0)
	std::cout << "Radiation = " << combinedElements[4] * 100 << '%' << std::endl;
if (combinedElements[5] > 0)
	std::cout << "Viral = " << combinedElements[5] * 100 << '%' << std::endl;
if (baseElements[0] > 0)
	std::cout << "Cold = " << baseElements[0] * 100 << '%' << std::endl;
if (baseElements[1] > 0)
	std::cout << "Electric = " << baseElements[1] * 100 << '%' << std::endl;
if (baseElements[2] > 0)
	std::cout << "Heat = " << baseElements[2] * 100 << '%' << std::endl;
if (baseElements[3] > 0)
	std::cout << "Toxin = " << baseElements[3] * 100 << '%' << std::endl << std::endl;
std::cout << std::endl;
#endif
*/