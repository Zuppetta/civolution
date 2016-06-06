#ifndef tile_hpp
#define tile_hpp

#include <vector>
#include "army.hpp"
#include "building.hpp"

enum TileType {COAST, OCEAN, DESERT, PLAIN, FOREST, JUNGLE, MOUNTAIN,
               HILL, DESERT_HILL, FOREST_HILL, TUNDRA, TUNDRA_FOREST,
               TUNDRA_FOREST_HILL, ICE};

enum WeatherConditions {SUNNY, RAINY, SNOW, HAILSTORM, STORM};

enum Ressource {PRODUCTION, WOOD, IRON}; //Need to discuss all

class Tile {
public:

//Constructors
  Tile();
  Tile(TileType t, int pos1, int pos2);
  
//Functions
  int[3] GetRessources(Player *pOwner);
  void ChangeWeather(WeatherConditions wt);
  Tile* Neighbor(int direction);
  int[2] WhereAmI();
  
private:

//Tiles charactheristics
  TileType aType;
  int aHeight;
  bool aRiver;
  bool aFlooded;
  WeatherConditions aLocalWeather;
  int aPos1; //How to count? Vertical-Diagonal
  int aPos2;

//Tile content
  Army *pArmy; //army on the tile, do we need this? I think it will be faster with it, but I am not sure
  Building *pBuilding;
 
//Private Functions
  void SetType(TileType T);
};

#endif
