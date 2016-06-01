#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include <vector>
#include <string>
#include "army.hpp"
#include "city.hpp"
#include "diplomacy.hpp"

class Player {
 public:
  void Print();

 private:
  std::vector<Army*> aArmies;
  std::string aPlayerName;
  std::vector<City*> aCities;
  std::vector<Diplomacy*> aDiplomacy;
};

#endif  //  PLAYER_HPP_
