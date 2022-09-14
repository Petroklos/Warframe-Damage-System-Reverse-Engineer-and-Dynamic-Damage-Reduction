#ifndef GS
	#include "GenericStat.h"
	#define GS
#endif

#pragma once
class CriticalChance : public GenericStat
{
	double vigilanteBonus;
public:
	CriticalChance();
	CriticalChance(double b, double m, double a, double v);

	void setVigilanteBonus(double d);
	double getVigilanteBonus();
};