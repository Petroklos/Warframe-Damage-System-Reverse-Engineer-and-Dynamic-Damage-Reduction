#pragma once
class ReloadTime
{
	double reload;
	double divider;
public:
	ReloadTime();
	ReloadTime(double r);
	ReloadTime(double r, double d);

	void setReload(double r);
	void setDivider(double d);

	double getReload();
	double getDivider();

	double calculate();
};