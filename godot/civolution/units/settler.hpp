#ifndef UNITS_SETTLER_HPP_
#define UNITS_SETTLER_HPP_

#include <string>
#include <vector>
#include "../unit.hpp"

/*! Unit specialized in the construction of cities */
class Settler: public Unit {
 public:
  /*! Default constructor */
  Settler(): Unit(GetMaxHp()) {}
  int GetMaxHp() const;
  std::string GetName() const;
  int GetProductionCost() const;
  std::vector<SpecialAbility> GetSpecialAbilities() const;
  int GetAttack() const;
  int GetRange() const;
  int GetDefense() const;
  int GetDisplacement() const;
};

#endif   //  UNITS_SETTLER_HPP_
