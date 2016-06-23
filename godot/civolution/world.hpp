#ifndef WORLD_HPP
#define WORLD_HPP

#include <vector>
#include "tile.hpp"
#include "player.hpp"

enum WorldSize {Mini, Small, Medium, Large, Huge};

class World {
public:
  World(std::vector<std::vector<int> > world_comp);
  
  Tile* operator[] (int i, int j);
  
  int[2] WhereAmI(float x, float y);
  
  void Weather(int magnitude);
  void NaturalCatastrophe();
  
private:
  
  std::vector<std::vector<Tile*> > aWorld_map;
  
  int aAverageHumidity;
  
};


#endif
