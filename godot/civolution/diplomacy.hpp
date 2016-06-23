#ifndef DIPLOMACY_HPP_
#define DIPLOMACY_HPP_

#include <vector>
#include "trading.hpp"

class Diplomacy {
 private:
  int aFirstPlayer;  //  player linked together with this diplomacy
  int aSecondPlayer;  //  maybe we should put a pointer to the players?
  int aWar;  //  is the players in war, peace, ally?
  std::vector<Trading*> aTrading;
};

#endif  //  DIPLOMACY_HPP_
