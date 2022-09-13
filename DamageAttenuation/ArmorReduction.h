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
	ArmorReduction(double d, int l, int b);
	ArmorReduction(double d, int l, int b, bool e);

	void setBaseArmor(double d);
	void setLevel(int i);
	void setBaseLevel(int i);

	void calculateNetArmor();
	void calculateArmorDR();

	double getNetArmor();
	double getArmorDR();

	void corrosiveProcs(int i);
};