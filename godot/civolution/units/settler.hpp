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
  virtual int GetMaxHp() const;
  virtual std::string GetName() const;
  virtual int GetProductionCost() const;
  virtual std::vector<SpecialAbility> GetSpecialAbilities() const;
  virtual int GetAttack() const;
  virtual int GetRange() const;
  virtual int GetDefense() const;
  virtual int GetDisplacement() const;
};

#endif   //  UNITS_SETTLER_HPP_
