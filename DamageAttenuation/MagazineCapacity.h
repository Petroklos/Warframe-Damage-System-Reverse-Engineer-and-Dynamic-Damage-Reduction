#include "Definitions.h"

#pragma once
class MagazineCapacity : public GenericStat
{
	using GenericStat::GenericStat;
public:
	double timeToEmpty(double fireRate);
};

