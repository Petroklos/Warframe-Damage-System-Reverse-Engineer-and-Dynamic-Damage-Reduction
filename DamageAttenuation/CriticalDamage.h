#ifndef GS
	#include "GenericStat.h"
	#define GS
#endif

#pragma once
class CriticalDamage : public GenericStat
{
	using GenericStat::GenericStat;
public:
	double calculateTotal(double criticalChance);
};