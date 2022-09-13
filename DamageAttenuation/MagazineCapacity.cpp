#include "MagazineCapacity.h"

double MagazineCapacity::timeToEmpty(double fireRate) {
	return calculateTotal() / fireRate;
}