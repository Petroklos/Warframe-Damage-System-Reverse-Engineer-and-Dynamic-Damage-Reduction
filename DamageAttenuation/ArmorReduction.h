#include "Definitions.h"

#pragma once
class ArmorReduction
{
	double baseArmor;
	int level;
	int baseLevel;
	bool isEximus;
	double netArmor;
	double armorDR;
	double armorStripMultiplier;
public:
	ArmorReduction();
	ArmorReduction(double, int, int);
	ArmorReduction(double, int, int, bool);

	void setBaseArmor(double);
	void setLevel(int);
	void setBaseLevel(int);

	void calculateNetArmor();
	void calculateArmorDR();
	
	void armorStrip(double d);

	double getNetArmor();
	double getArmorDR();

	void corrosiveProcs(int);
};