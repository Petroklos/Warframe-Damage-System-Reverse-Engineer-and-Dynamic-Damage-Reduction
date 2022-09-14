#ifndef GS
	#include "GenericStat.h"
	#define GS
#endif

#pragma once
class ElementalDamage : public GenericStat {
	int singleElement;
	double baseElements[4] = {};
	double combinedElements[6] = {};
public:
	void addElement(int, double);
};