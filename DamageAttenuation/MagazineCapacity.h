#ifndef GS
	#include "GenericStat.h"
	#define GS
#endif

#pragma once
class MagazineCapacity : public GenericStat
{
	using GenericStat::GenericStat;
public:
	double timeToEmpty(double fireRate);
};

