#include "GenericStat.h"

GenericStat::GenericStat() {
	base = 0;
	multiplier = 1;
	additive = 0;
}

GenericStat::GenericStat(double d) {
	base = d;
	multiplier = 1;
	additive = 0;
}

GenericStat::GenericStat(double d, double m) {
	base = d;
	multiplier = 1 + m;
	additive = 0;
}

GenericStat::GenericStat(double d, double m, double a) {
	base = d;
	multiplier = 1 + m;
	additive = a;
}

void GenericStat::setBase(double b) { base = b; }
void GenericStat::setMultiplier(double m) { multiplier += m; }
void GenericStat::setAdditive(double a) { additive += a; }

double GenericStat::getBase() { return base; }
double GenericStat::getMultiplier() { return multiplier; }
double GenericStat::getAdditive() { return additive; }

double GenericStat::calculateTotal() { return base * multiplier + additive; }