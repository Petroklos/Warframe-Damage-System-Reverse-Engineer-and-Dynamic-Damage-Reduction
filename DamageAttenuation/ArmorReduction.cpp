#include "ArmorReduction.h"

ArmorReduction::ArmorReduction() {
	baseArmor = 0;
	level = 0;
	baseLevel = 0;
	isEximus = false;
	netArmor = 0;
	armorDR = 0;
}

ArmorReduction::ArmorReduction(double d, int l, int b) {
	baseArmor = d;
	level = l;
	baseLevel = b;
	isEximus = false;
	calculateNetArmor();
	calculateArmorDR();
}

ArmorReduction::ArmorReduction(double d, int l, int b, bool e) {
	baseArmor = d;
	level = l;
	baseLevel = b;
	isEximus = b;
	calculateNetArmor();
	calculateArmorDR();
}

void ArmorReduction::setBaseArmor(double d) {
	baseArmor = d;
	calculateNetArmor();
	calculateArmorDR();
}

void ArmorReduction::setLevel(int i) {
	level = i;
	calculateNetArmor();
	calculateArmorDR();
}

void ArmorReduction::setBaseLevel(int i) {
	baseLevel = i;
	calculateNetArmor();
	calculateArmorDR();
}

void ArmorReduction::calculateNetArmor() {
	//if (isEximus == false) {
		double t = (level - baseLevel - 70) / 10;

		double s;
		if (level - baseLevel < 70) {
			s = 0;
		}
		else if (level - baseLevel > 80) {
			s = 1;
		}
		else {
			s = 3 * pow(t, 2) - 2 * pow(t, 3);
		}

		double f1 = 1 + 0.005 * pow((level - baseLevel), 1.75);
		double f2 = 1 + 0.4 * pow((level - baseLevel), 0.75);

		netArmor = ((f1 * (1 - s)) + (f2 * s)) * baseArmor;
	//}
}

void ArmorReduction::calculateArmorDR() { armorDR = 1 - (netArmor / (netArmor + 300)); }

double ArmorReduction::getNetArmor() { return netArmor; }
double ArmorReduction::getArmorDR() { return armorDR; }