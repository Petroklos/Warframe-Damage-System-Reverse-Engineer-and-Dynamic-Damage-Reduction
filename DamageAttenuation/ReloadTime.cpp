#include "ReloadTime.h"

// Default constructor
ReloadTime::ReloadTime() : reload(0), divider(0) {}

// Constructor that sets the reload time.
ReloadTime::ReloadTime(double r) : reload(r), divider(0) {}

// Constructor that sets the reload time and divider.
ReloadTime::ReloadTime(double r, double d) : reload(r), divider(d) {}

// Set the reload time of the weapon.
void ReloadTime::setReload(double r) { reload = r; }

// Set the divider used to decrease the reload time.
void ReloadTime::setDivider(double d) { divider = d; }

// Get the reload time of the weapon.
double ReloadTime::getReload() { return reload; }

// Get the divider used to decrease the reload time.
double ReloadTime::getDivider() { return divider; }

// Calculate and return the actual reload time of the weapon.
// This is the base reload time divided by (1 + the divider).
double ReloadTime::calculate() { return reload / (1 + divider); }