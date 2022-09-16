#include "CriticalDamage.h"

double CriticalDamage::calculateTotal(int critLevel) {
	return 1 + (getBase() * getMultiplier() - 1) * critLevel + getAdditive();
}