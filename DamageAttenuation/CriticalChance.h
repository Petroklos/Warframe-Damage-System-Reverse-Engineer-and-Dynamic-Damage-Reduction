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
	CriticalChance(double, double, double, double);

	void setVigilanteBonus(double);
	double getVigilanteBonus();
};