// Damage Attenuation Mathematic Formula taken from :
// https://www.reddit.com/r/Warframe/comments/owl8xu/a_better_damage_attenuation_formula/

#pragma once
class DamageAttenuation
{
	double notArmor;
	double attenuationValue;
public:
	DamageAttenuation(double d);

	void setNotArmor(double d);

	void calculateAttenuationValue();

	double getAttenuationValue();

	double attenuateDamage(double damageInstance, double DPS, double damageFrequency);
};