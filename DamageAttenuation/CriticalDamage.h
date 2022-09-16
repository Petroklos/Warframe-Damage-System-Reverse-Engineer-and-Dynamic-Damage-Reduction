#include "Definitions.h"

#pragma once
class CriticalDamage : public GenericStat
{
	using GenericStat::GenericStat;
public:
	double calculateTotal(int);
};