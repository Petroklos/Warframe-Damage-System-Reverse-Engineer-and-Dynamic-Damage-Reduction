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
	}
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