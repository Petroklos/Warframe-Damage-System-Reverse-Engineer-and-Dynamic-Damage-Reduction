#include "Definitions.h"

#pragma once
class ReloadTime {
public:
	// Constructors
	ReloadTime();
	ReloadTime(double);
	ReloadTime(double, double);

	// Setter functions
	void setReload(double);
	void setDivider(double);

	// Getter functions
	double getReload();
	double getDivider();

	// Calculate the adjusted reload time
	double calculate();

private:
	// The base reload time of the weapon
	double reload;
	// The reload time divider, which is used to reduce the reload time
	double divider;
};