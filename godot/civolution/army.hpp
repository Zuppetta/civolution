#ifndef ARMY_HPP_
#define ARMY_HPP_

#include <vector>
#include "unit.hpp"

/*! The player will not play through the unit directly
 but with the armies that are more or less just a container of units
*/
class Army {
 public:
  void TakeDamage(int damage);
  void MoveTo(int pos1, int pos2);
  void PrintTerminal() const;
  bool IsDead() const;
  int RangedAttack() const;
  int MeleeAttack() const;
  int SiegeAttack() const;
  int Range() const;
  void AddUnit(Unit* pNewUnit);
  void UpdateAttribute();

 private:
  //! Units contained in the army
  std::vector<Unit*> aUnits;
  //! Max Health Point
  int aMaxHp;
  //! Current Health Point
  int aCurrentHp;
  //! Defense
  int aDefense;
  //! Melee attack value
  int aMeleeAttack;
  //! Ranged attack value
  int aRangedAttack;
  //! Distance for the range attack
  int aRange;
  //! Siege attack value
  int aSiegeAttack;
  //! Distance max that the army can travel
  int aDisplacement;
  //! X-position
  int aPos1;
  //! Y-position
  int aPos2;
  //! List of all the units' special abilities
  std::vector<SpecialAbility> aSpecialAbilities;

  //! Seed for the random generator
  unsigned int aSeed;
};

#endif  //  ARMY_HPP_
