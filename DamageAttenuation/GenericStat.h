#pragma once
class GenericStat
{
	double base;
	double multiplier;
	double additive;
public:
	GenericStat();
	GenericStat(double b);
	GenericStat(double b, double m);
	GenericStat(double b, double m, double a);

	void setBase(double b);
	void setMultiplier(double m);
	void setAdditive(double a);

	double getBase();
	double getMultiplier();
	double getAdditive();

	double calculateTotal();
};