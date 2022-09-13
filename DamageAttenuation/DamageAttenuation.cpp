#include "DamageAttenuation.h"

DamageAttenuation::DamageAttenuation(double d) {
	notArmor = d;
	calculateAttenuationValue();
}

void DamageAttenuation::setNotArmor(double d) {
	notArmor = d;
	calculateAttenuationValue();
}

void DamageAttenuation::calculateAttenuationValue() {

}

double notArmor = 100000;
double part = (2 * estimatedDPS) + (1 - (2 * estimatedDPS + totalDamage) / (2 * estimatedDPS + totalDamage + notArmor)) * totalDamage;
double attenuateValue = part / (part + notArmor);

double attenuatedDamage = (1 - attenuateValue) * totalDamage;
if (!attenuatedWeakspots) attenuatedDamage *= 3;
std::cout << "Attenuated Damage: " << attenuatedDamage << std::endl;
double attenuatedDPS = (1 - attenuateValue) * attenuatedDamage * adjustedFrequency;
std::cout << "Attenuated DPS: " << attenuatedDPS << std::endl;