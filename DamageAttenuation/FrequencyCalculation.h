#pragma once

#include "Definitions.h"
#include "FireRate.h"
#include "MagazineCapacity.h"
#include "ReloadTime.h"
#include "Multishot.h"

class FrequencyCalculation {
public:
    // Constructor
    FrequencyCalculation();

    // Set base, multiplier, and additive values for fire rate
    void setFireRateBase(double value);
    void setFireRateMultiplier(double value);
    void setFireRateAdditive(double value);

    // Set base, multiplier, and additive values for magazine capacity
    void setMagazineCapacityBase(double value);
    void setMagazineCapacityMultiplier(double value);
    void setMagazineCapacityAdditive(double value);

    // Set base, divider, and additive values for reload time
    void setReloadTimeBase(double value);
    void setReloadTimeDivider(double value);
    void setReloadTimeAdditive(double value);

    // Set base, multiplier, and additive values for multishot
    void setMultishotBase(double value);
    void setMultishotMultiplier(double value);
    void setMultishotAdditive(double value);

    // Calculate and return the adjusted fire rate
    double getAdjustedFireRate();

private:
    FireRate FR;
    MagazineCapacity MC;
    ReloadTime RT;
    Multishot MS;
};