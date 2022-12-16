#pragma once

#include "Definitions.h"  // Include the "Definitions.h" header

class GenericStat {
public:
    // Constructors
    GenericStat();
    GenericStat(double base);
    GenericStat(double base, double multiplier);
    GenericStat(double base, double multiplier, double additive);

    // Setter functions
    void setBase(double base);
    void setMultiplier(double multiplier);
    void setAdditive(double additive);

    // Getter functions
    double getBase();
    double getMultiplier();
    double getAdditive();

    // Calculate the total value of the stat
    double calculateTotal();

private:
    double base;
    double multiplier;
    double additive;
};