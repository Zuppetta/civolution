#include <iostream>
#include "units/includeUnits.hpp"
#include "army.hpp"

int main() {
  Settler *s1 = new Settler();
  Settler *s2 = new Settler();
  Settler *s3 = new Settler();
  Settler *s4 = new Settler();
  Settler *s5 = new Settler();
  Army army1;
  Army army2;
  army1.AddUnit(s1);
  army1.AddUnit(s2);
  army2.AddUnit(s3);
  army2.AddUnit(s4);
  army2.AddUnit(s5);
  army1.Print();
  std::cout << std::endl << std::endl;
  army2.Print();
  std::cout << std::endl << std::endl;
  for (unsigned int i(0); i < 10; i++) {
    army1.TakeDamage(army2.RangedAttack());
    army2.TakeDamage(army1.RangedAttack());
    army1.TakeDamage(army2.MeleeAttack());
    army2.TakeDamage(army1.MeleeAttack());
    army1.TakeDamage(army2.SiegeAttack());
    army2.TakeDamage(army1.SiegeAttack());
  }
  std::cout << "After fight" << std::endl << std::endl;
  army1.Print();
  std::cout << std::endl << std::endl;
  army2.Print();
  return 0;
}
