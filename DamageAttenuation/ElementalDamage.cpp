#include "ElementalDamage.h"

void ElementalDamage::addElement(int i, double d) {
	// Will not differentiate between Elements yet
	//setMultiplier(d);

	// Check if there is no previous uncombined singleElement
	if (singleElement == -1) {
		// Set the singleElement to the given index.
		singleElement = i;
		// Set the baseElements value for the given element to 1 + d.
		baseElements[i] = 1 + d;
	}
	// Check if this element is the same as the singleElement.
	else if (singleElement == i) {
		// Increment the baseElements value for the given element by d.
		baseElements[i] += d;
	}
	else {
		// Set the combinedElements value for the combined element to the baseElements value for the singleElement plus d.
		switch (singleElement) {
		case COLD:
			if (i == ELECTRIC) combinedElements[MAGNETIC] = baseElements[COLD] + d;
			if (i == HEAT) combinedElements[BLAST] = baseElements[COLD] + d;
			if (i == TOXIN) combinedElements[VIRAL] = baseElements[COLD] + d;
			break;
		case ELECTRIC:
			if (i == COLD) combinedElements[MAGNETIC] = baseElements[ELECTRIC] + d;
			if (i == HEAT) combinedElements[RADIATION] = baseElements[ELECTRIC] + d;
			if (i == TOXIN) combinedElements[CORROSIVE] = baseElements[ELECTRIC] + d;
			break;
		case HEAT:
			if (i == COLD) combinedElements[BLAST] = baseElements[ELECTRIC] + d;
			if (i == ELECTRIC) combinedElements[RADIATION] = baseElements[COLD] + d;
			if (i == TOXIN) combinedElements[GAS] = baseElements[COLD] + d;
			break;
		case TOXIN:
			if (i == COLD) combinedElements[VIRAL] = baseElements[ELECTRIC] + d;
			if (i == ELECTRIC) combinedElements[CORROSIVE] = baseElements[COLD] + d;
			if (i == HEAT) combinedElements[GAS] = baseElements[COLD] + d;
			break;
		}
		// Reset the value of the now combined previous baseElement to 0
		baseElements[singleElement] = 0;
		// Reset the singleElement index to -1 == no uncombined singleElement
		singleElement = -1;
	}
}

double ElementalDamage::calculateTotal() {
	#if isDebugging
		std::cout << std::endl;

		if (combinedElements[BLAST] > 0)
			std::cout << "Blast = " << combinedElements[BLAST] * 100 << '%' << std::endl;
		if (combinedElements[CORROSIVE] > 0)
			std::cout << "Corrosive = " << combinedElements[CORROSIVE] * 100 << '%' << std::endl;
		if (combinedElements[GAS] > 0)
			std::cout << "Gas = " << combinedElements[GAS] * 100 << '%' << std::endl;
		if (combinedElements[MAGNETIC] > 0)
			std::cout << "Magnetic = " << combinedElements[MAGNETIC] * 100 << '%' << std::endl;
		if (combinedElements[RADIATION] > 0)
			std::cout << "Radiation = " << combinedElements[RADIATION] * 100 << '%' << std::endl;
		if (combinedElements[VIRAL] > 0)

			std::cout << "Viral = " << combinedElements[VIRAL] * 100 << '%' << std::endl;
		if (baseElements[COLD] > 0)
			std::cout << "Cold = " << baseElements[COLD] * 100 << '%' << std::endl;
		if (baseElements[ELECTRIC] > 0)
			std::cout << "Electric = " << baseElements[ELECTRIC] * 100 << '%' << std::endl;
		if (baseElements[HEAT] > 0)
			std::cout << "Heat = " << baseElements[HEAT] * 100 << '%' << std::endl;
		if (baseElements[TOXIN] > 0)
			std::cout << "Toxin = " << baseElements[TOXIN] * 100 << '%' << std::endl << std::endl;

		std::cout << std::endl;
	#endif

	return 1 + baseElements[0] + baseElements[1] + baseElements[2] + baseElements[3] + combinedElements[0] + combinedElements[1] + combinedElements[2] + combinedElements[3] + combinedElements[4] + combinedElements[5];
}