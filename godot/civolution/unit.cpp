#include <math.h>
#include <iostream>
#include "unit.hpp"


// ---------------------------- UNIT -------------------------------------

/*!
\param damage Damage received by the unit

The first part of the computation consists in computing the damage reduction
due to the armor. This value is computed with the ratio Defense/Damage and
the error function (the parameters are defined in the class Unit).
The reason of the error function is that the function is strictly increasing
and is bounded between 0 and 1.

The second part consists in substacting the current health point by the
multiplication of the damage reduction with the initial damage.
*/
void Unit::TakeDamage(float damage) {
  if (damage != 0.0) {
    float ratio_dmg = static_cast<float>(this->GetDefense()) /
      static_cast<float>(damage);
    ratio_dmg = 0.5 * (erf((ratio_dmg - Unit::MU)/(sqrt(2)*Unit::STD)) + 1.0);
    this->aCurrentHp -= (1.0 - ratio_dmg) * damage;
  }
}

// Functions

int Unit::GetMaxHp() const {
  return 0;
}

int Unit::GetCurrentHp() const {
  return this->aCurrentHp;
}

bool Unit::IsDead() const {
  if (this->aCurrentHp <= 0) {
    return true;
  } else {
    return false;
  }
}



// Print -----------------------------------------------------------------
void Unit::PrintTerminal() const {
  std::cout << "Unit Name: " << this->GetName() << std::endl;
  std::cout << "Health Point: " << this->GetCurrentHp() << "/" <<
    this->GetMaxHp() << std::endl;
  std::cout << "Special Abilities:";
  for (unsigned int i(0); i < this->GetSpecialAbilities().size(); i ++) {
    std::cout << this->GetSpecialAbilities()[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "Attack: " << this->GetAttack() << std::endl;
  std::cout << "Range: " << this->GetRange() << std::endl;
  std::cout << "Defense: " << this->GetDefense() << std::endl;
  std::cout << "Displacement: " << this->GetDisplacement() << std::endl;
}
