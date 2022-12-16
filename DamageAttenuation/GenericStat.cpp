#include "GenericStat.h"

// Default constructor
GenericStat::GenericStat() {
    base = 0;
    multiplier = 1;
    additive = 0;
}

// Constructor that sets the base value of the stat
GenericStat::GenericStat(double base) {
    this->base = base;
    multiplier = 1;
    additive = 0;
}

// Constructor that sets the base value and multiplier of the stat
GenericStat::GenericStat(double base, double multiplier) {
    this->base = base;
    this->multiplier = 1 + multiplier;
    additive = 0;
}

// Constructor that sets the base value, multiplier, and additive value of the stat
GenericStat::GenericStat(double base, double multiplier, double additive) {
    this->base = base;
    this->multiplier = 1 + multiplier;
    this->additive = additive;
}

// Set the base value of the stat
void GenericStat::setBase(double base) {
    this->base = base;
}

// Set the multiplier of the stat
void GenericStat::setMultiplier(double multiplier) {
    this->multiplier += multiplier;
}

// Set the additive value of the stat
void GenericStat::setAdditive(double additive) {
    this->additive += additive;
}

// Get the base value of the stat
double GenericStat::getBase() {
    return base;
}

// Get the multiplier of the stat
double GenericStat::getMultiplier() {
    return multiplier;
}

// Get the additive value of the stat
double GenericStat::getAdditive() {
    return additive;
}

// Calculate the total value of the stat
double GenericStat::calculateTotal() {
    return base * multiplier + additive;
}