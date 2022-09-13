# Warframe Damage Calculation and Attenuation

Writing out Warframe's Damage Calculation to test out potential Damage Attenuation Formulas and Implementations.

Everything is based on data from the Warframe Wiki, except for the Attenuation formula, which is taken from https://www.reddit.com/r/Warframe/comments/owl8xu/a_better_damage_attenuation_formula/

# what it do?

First, it calculates the Damage of **one** Damage Instance. Each pellet of Multishot is considered its own Instance. Any and all Damage Multiplications should be done here, before the Damage Attenuation is applied. I also include Armor DR in this calculation, as Armor Stripping targets is in itself a Damage Multiplier that should be considered before Attenuating the Damage.

Then it calculates the Frequency of Damage Instances. This is Fire Rate adjusted with Magazine Capacity and Reload Speed, multiplied by Multishot. Putting Multishot here should solve the oddity of extremely high Multishot Weapons bypassing the current Damage Attenuation in Warframe. Any buffs to these stats should be applied here, including Ammo Efficiency, before calculating Damage Attenuation.

Lastly, based on the two final values calculated above, it calculates an estimated DPS Value and uses that to calculate the Attenuation Value and Attenuate each Damage Instance according to the formula from here https://www.reddit.com/r/Warframe/comments/owl8xu/a_better_damage_attenuation_formula/.
