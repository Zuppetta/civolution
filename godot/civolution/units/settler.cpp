#include <string>
#include <vector>

#include "settler.hpp"

int Settler::GetMaxHp() const {
  return 100;
}
std::string Settler::GetName() const {
  return "Settler";
}
int Settler::GetProductionCost() const {
  return 100;
}
std::vector<SpecialAbility> Settler::GetSpecialAbilities() const {
  return std::vector<SpecialAbility>(1, SETTLER);
}
int Settler::GetAttack() const {
  return 5;
}
int Settler::GetRange() const {
  return 0;
}
int Settler::GetDefense() const {
  return 5;
}
int Settler::GetDisplacement() const {
  return 5;
}
