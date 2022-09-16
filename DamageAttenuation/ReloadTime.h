#include "Definitions.h"

#pragma once
class ReloadTime
{
	double reload;
	double divider;
public:
	ReloadTime();
	ReloadTime(double);
	ReloadTime(double, double);

	void setReload(double);
	void setDivider(double);

	double getReload();
	double getDivider();

	double calculate();
};