#ifndef CITY_HPP_
#define CITY_HPP_

#include <vector>
#include <string>
#include "building.hpp"

class City {
 private:
  std::string aCityName;
  std::vector<Building*> aBuildings;
};


#endif  //  CITY_HPP_
