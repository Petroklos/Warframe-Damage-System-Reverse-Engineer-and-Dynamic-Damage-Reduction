#include "Definitions.h"

#include "BaseDamage.h"
#include "RadialDamage.h"
#include "WeakpointBonus.h"
#include "ElementalDamage.h"
#include "CriticalChance.h"
#include "CriticalDamage.h"
#include "FactionDamage.h"

#pragma once

class DamageCalculation {
public:
    // Default constructor
    DamageCalculation();

    // Setter functions
    void setDamageBase(double d);
    void setDamageMultiplier(double d);
    void setDamageAdditive(double d);

    void setRadialDamageBase(double d);
    void setRadialDamageMultiplier(double d);
    void setRadialDamageAdditive(double d);

    void setWeakpointBonusBase(double d);
    void setWeakpointBonusMultiplier(double d);
    void setWeakpointBonusAdditive(double d);

    void setElementalMultiplier(int i, double d); // Integer denotes the Elemental Type, double denotes the Value

    void setCriticalChanceBase(double d);
    void setCriticalChanceMultiplier(double d);
    void setCriticalChanceAdditive(double d);
    void setCriticalChanceVigilante(double d);

    void setCriticalDamageBase(double d);
    void setCriticalDamageMultiplier(double d);
    void setCriticalDamageAdditive(double d);

    void setFactionDamageBase(double d);
    void setFactionDamageMultiplier(double d);
    void setFactionDamageAdditive(double d);

    void setViralProcs(int i);
    double viralMultiplier();

    void setIsIncarnon(bool b);

    // Getter functions
    double getDamage();
    double calculateFactionDamage();

private:
    BaseDamage BD;
    RadialDamage RD;
    WeakpointBonus WB;
    ElementalDamage ED;
    CriticalChance CC;
    double vigilanteBonus;
    CriticalDamage CD;
    FactionDamage FD;
    int viralProcs;
    bool isIncarnon;
};