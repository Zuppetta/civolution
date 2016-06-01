#ifndef tile_hpp
#define tile_hpp

#include <vector>
#include "army.hpp"

class Tile {
public:
  void GetRessources();
private:
  int aTileType;
  Army* aArmy; //army on the tile, do we need this? I think it will be faster with it, but I am not sure
};

#endif
