#include "Definitions.h"
#pragma once

constexpr int COLD = 0;
constexpr int ELECTRIC = 1;
constexpr int HEAT = 2;
constexpr int TOXIN = 3;

constexpr int BLAST = 0;
constexpr int CORROSIVE = 1;
constexpr int GAS = 2;
constexpr int MAGNETIC = 3;
constexpr int RADIATION = 4;
constexpr int VIRAL = 5;

class ElementalDamage {
public:
	void addElement(int, double);
	double calculateTotal();
private:
	int singleElement = -1;
	double baseElements[4] = {};
	double combinedElements[6] = {};
};