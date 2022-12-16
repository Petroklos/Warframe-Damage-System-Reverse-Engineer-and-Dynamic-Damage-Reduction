#include "MagazineCapacity.h"

// This method calculates the time it takes to empty a magazine based on the given fire rate.
double MagazineCapacity::timeToEmpty(double fireRate) {
	return calculateTotal() / fireRate;
}