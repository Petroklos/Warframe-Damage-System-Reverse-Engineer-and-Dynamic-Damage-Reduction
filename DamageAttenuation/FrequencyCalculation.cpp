#include "FrequencyCalculation.h"

FrequencyCalculation::FrequencyCalculation()
    : FR(), MC(), RT(), MS() {
    // Default constructor
}

// Set base, multiplier and additive values for fire rate
void FrequencyCalculation::setFireRateBase(double value) { FR.setBase(value); }
void FrequencyCalculation::setFireRateMultiplier(double value) { FR.setMultiplier(value); }
void FrequencyCalculation::setFireRateAdditive(double value) { FR.setAdditive(value); }

// Set base, multiplier and additive values for magazine capacity
void FrequencyCalculation::setMagazineCapacityBase(double value) { MC.setBase(value); }
void FrequencyCalculation::setMagazineCapacityMultiplier(double value) { MC.setMultiplier(value); }
void FrequencyCalculation::setMagazineCapacityAdditive(double value) { MC.setAdditive(value); }

// Set base and divider values for reload time
void FrequencyCalculation::setReloadTimeBase(double value) { RT.setReload(value); }
void FrequencyCalculation::setReloadTimeDivider(double value) { RT.setDivider(value); }

// Set base, multiplier and additive value for multishot
void FrequencyCalculation::setMultishotBase(double value) { MS.setBase(value); }
void FrequencyCalculation::setMultishotMultiplier(double value) { MS.setMultiplier(value); }
void FrequencyCalculation::setMultishotAdditive(double value) { MS.setAdditive(value); }

// Calculate and return the adjusted fire rate
double FrequencyCalculation::getAdjustedFireRate() {
    // Calculate time it takes to empty the magazine
    double timeToEmpty = MC.calculateTotal() / FR.calculateTotal();

    // Calculate the total time for a full cycle (empty and reload)
    double fullCycle = timeToEmpty + RT.calculate();

    // Calculate the adjusted fire rate
    double adjustedFireRate = MC.calculateTotal() / fullCycle;

    // Return the result
    return adjustedFireRate;
}