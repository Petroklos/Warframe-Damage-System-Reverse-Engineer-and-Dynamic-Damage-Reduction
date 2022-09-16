#include "Definitions.h"
#pragma once
class ElementalDamage : public GenericStat {
	int singleElement = -1;
	double baseElements[4] = {};
	double combinedElements[6] = {};
public:
	void addElement(int, double);
	double calculateTotal();
};