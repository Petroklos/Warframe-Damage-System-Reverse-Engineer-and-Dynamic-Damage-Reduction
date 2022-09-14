#pragma once
class GenericStat
{
	double base;
	double multiplier;
	double additive;
public:
	GenericStat();
	GenericStat(double);
	GenericStat(double, double);
	GenericStat(double, double, double);

	void setBase(double);
	void setMultiplier(double);
	void setAdditive(double);

	double getBase();
	double getMultiplier();
	double getAdditive();

	double calculateTotal();
};