#ifndef world_hpp
#define world_hpp

#include <vector>
#include "tile.hpp"
#include "player.hpp"

class World {
private:
  // maybe we should split with a class Game?
  std::vector<Player*> aPlayers;
  std::vector<std::vector<Tile*> > aWorld_map;
  int aTurn;
};


#endif
