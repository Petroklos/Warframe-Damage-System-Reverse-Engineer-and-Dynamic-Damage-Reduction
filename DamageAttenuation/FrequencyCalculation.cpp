#include "FrequencyCalculation.h"

FrequencyCalculation::FrequencyCalculation() {
	FR = FireRate();
	MC = MagazineCapacity();
	RT = ReloadTime();
	MS = Multishot();
}

void FrequencyCalculation::setFireRateBase(double d) { FR.setBase(d); }
void FrequencyCalculation::setFireRateMultiplier(double d) { FR.setMultiplier(d); }
void FrequencyCalculation::setFireRateAdditive(double d) { FR.setAdditive(d); }

void FrequencyCalculation::setMagazineCapacityBase(double d) { MC.setBase(d); }
void FrequencyCalculation::setMagazineCapacityMultiplier(double d) { MC.setMultiplier(d); }
void FrequencyCalculation::setMagazineCapacityAdditive(double d) { MC.setAdditive(d); }

void FrequencyCalculation::setReloadTimeBase(double d) { RT.setReload(d); }
void FrequencyCalculation::setReloadTimeDivider(double d) { RT.setDivider(d); }

void FrequencyCalculation::setMultishotBase(double d) { MS.setBase(d); }
void FrequencyCalculation::setMultishotMultiplier(double d) { MS.setMultiplier(d); }
void FrequencyCalculation::setMultishotAdditive(double d) { MS.setAdditive(d); }

double FrequencyCalculation::getAdjustedFireRate() {
	return (FR.calculateTotal() - RT.calculate() * MC.calculateTotal() / FR.calculateTotal()) * MS.calculateTotal();
}