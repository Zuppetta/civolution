#include <stdlib.h>
#include <vector>
#include <iostream>
#include "army.hpp"

/*! Apply the damage taken by the army to all the units.
 \param damage Damage received

Compute the average damage received by each unit, then randomize each one of
them by taking an uniform distribution that will result in a damage value
between 50% and 150% of the average value.
\todo use a gaussian?
*/
void Army::TakeDamage(int damage) {
  // compute the average damage
  float aAvgDmg = static_cast<float>(damage) /
    static_cast<float>(this->aUnits.size());
  // inflict the damage to all the units
  for (unsigned int i(0); i < this->aUnits.size(); i++) {
    // take a random value between 50% and 150%
    float rand_dmg = 1.0 +
      static_cast<float>(rand_r(&(this->aSeed)) % 1000)/1000.0;
    // apply the damage
    this->aUnits[i]->TakeDamage(rand_dmg * aAvgDmg);
  }

  // remove the dead units
  unsigned int i(0);
  while (i < this->aUnits.size()) {
    if (this->aUnits[i]->IsDead()) {
      delete this->aUnits[i];
      this->aUnits.erase(this->aUnits.begin() + i);
    } else {
      i++;
    }
  }
  this->UpdateAttribute();
}

/*! Move the army to the specify position without checking if it is possible
\param pos1 x-position of the destination
\param pos2 y-position of the destination
*/
void Army::MoveTo(int pos1, int pos2) {
  std::cout << "THIS METHOD DOES NOT CHECK IF THE DISPLACEMENT IS POSSIBLE";
  this->aPos1 = pos1;
  this->aPos2 = pos2;
}

/*! Print the army in the terminal
*/
void Army::Print() const {
  std::cout << "This army has:" << std::endl;
  std::cout << "HP: " << this->aCurrentHp << "/" << this->aMaxHp << std::endl;
  std::cout << "Defense: " << this->aDefense << std::endl;
  std::cout << "Melee Attack: " << this->aMeleeAttack << std::endl;
  std::cout << "Ranged Attack: " << this->aRangedAttack << std::endl;
  std::cout << "Building Attack: " << this->aSiegeAttack << std::endl;
  std::cout << "Displacement: " << this->aDisplacement << std::endl;
  std::cout << "Position: (" << this->aPos1 << ", " << this->aPos2 << ")"
            << std::endl;
  std::cout << "Special Abilities: ";
  for (unsigned int i(0); i < this->aSpecialAbilities.size(); i++) {
    std::cout << this->aSpecialAbilities[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "This army is composed of " << this->aUnits.size() << " units"
            << std::endl;
  for (unsigned int i(0); i < this->aUnits.size(); i++) {
    std::cout << "------" << std::endl;
    this->aUnits[i]->Print();
  }
}

/*! Check if a unit is still alive in the army
*/
bool Army::IsDead() const {
  if (this->aUnits.size() == 0) {
    return true;
  } else {
    return false;
  }
}

/*! Compute the ranged attack inflicted to an other army (use random)
\return Attack value
*/
int Army::RangedAttack() const {
  return aRangedAttack;
}

/*! Give the range distance value (computed by the min value of all the
 ranged units)
\return Range Distance
*/
int Army::Range() const {
  return aRange;
}

/*! Compute the melee attack inflicted to an other army (use random)
\return Attack value
*/
int Army::MeleeAttack() const {
  return aMeleeAttack;
}
/*! Compute the siege attack inflicted to an other army (use random)
\return Attack value
*/
int Army::SiegeAttack() const {
  return aSiegeAttack;
}

/*! Add a unit in the army
  \param pNewUnit New unit to add
 */
void Army::AddUnit(Unit *pNewUnit) {
  this->aUnits.push_back(pNewUnit);
  this->UpdateAttribute();
}

/*! Update the values of the army.
\todo call it less often
 */
void Army::UpdateAttribute() {
  // set all the values to 0
  this->aMaxHp = 0;
  this->aCurrentHp = 0;
  this->aDefense = 0;
  this->aMeleeAttack = 0;
  this->aRangedAttack = 0;
  this->aSiegeAttack = 0;
  this->aDisplacement = 0;
  this->aRange = 0;
  this->aSpecialAbilities = std::vector<SpecialAbility>(0);
  // loop over all units
  for (unsigned int i(0); i < this->aUnits.size(); i++) {
    // update basic attribute
    this->aMaxHp += this->aUnits[i]->GetMaxHp();
    this->aCurrentHp += this->aUnits[i]->GetCurrentHp();
    this->aDefense += this->aUnits[i]->GetDefense();
    this->aSiegeAttack += this->aUnits[i]->GetAttack();
    // update for ranged unit
    if (this->aUnits[i]->GetRange() > 0) {
      this->aMeleeAttack += this->aUnits[i]->GetAttack()*0.5;
      this->aRangedAttack += this->aUnits[i]->GetAttack();
      if (this->aRange > this->aUnits[i]->GetRange() ||
          this->aRange == 0) {
        this->aRange = this->aUnits[i]->GetRange();
      }
    } else {  // update for melee unit
      this->aMeleeAttack += this->aUnits[i]->GetAttack();
    }
    // update displacement
    if (this->aDisplacement == 0 ||
        this->aDisplacement > this->aUnits[i]->GetDisplacement()) {
      this->aDisplacement = this->aUnits[i]->GetDisplacement();
    }
    // update special abilities
    for (unsigned int j(0);
         j < this->aUnits[i]->GetSpecialAbilities().size(); j++) {
      SpecialAbility sp_ab = this->aUnits[i]->GetSpecialAbilities()[j];
      unsigned int k = 0;
      bool found = false;
      // check if already written in the army
      while (k < this->aSpecialAbilities.size() && !found) {
        if (this->aSpecialAbilities[k] == sp_ab) {
          found = true;
        } else {
          k++;
        }
      }
      if (!found) {
        this->aSpecialAbilities.push_back(sp_ab);
      }
    }
  }
}
