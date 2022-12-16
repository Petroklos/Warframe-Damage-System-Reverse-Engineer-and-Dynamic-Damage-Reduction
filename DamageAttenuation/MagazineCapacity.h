#include "Definitions.h"

#pragma once
class MagazineCapacity : public GenericStat {
public:
	// This method calculates the time it takes to empty a magazine based on the given fire rate.
	double timeToEmpty(double fireRate);
};

