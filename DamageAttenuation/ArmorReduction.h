#ifndef BASICS
	#include <stdlib.h>
	#include <math.h>
	#include <iostream>
	#define BASICS
#endif

#pragma once
class ArmorReduction
{
	double baseArmor;
	int level;
	int baseLevel;
	bool isEximus;
	double netArmor;
	double armorDR;
public:
	ArmorReduction();
	ArmorReduction(double, int, int);
	ArmorReduction(double, int, int, bool);

	void setBaseArmor(double);
	void setLevel(int);
	void setBaseLevel(int);

	void calculateNetArmor();
	void calculateArmorDR();

	double getNetArmor();
	double getArmorDR();

	void corrosiveProcs(int);
};