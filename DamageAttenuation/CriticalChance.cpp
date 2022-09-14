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