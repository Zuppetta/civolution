#ifndef tile_hpp
#define tile_hpp

#include <vector>
#include "army.hpp"
#include "building.hpp"

/*!
 * \enum TileType
 * \brief All possibles biomes for a tile
 */
enum TileType {COAST, OCEAN, DESERT, PLAIN, FOREST, JUNGLE, MOUNTAIN,
               HILL, DESERT_HILL, FOREST_HILL, TUNDRA, TUNDRA_FOREST,
               TUNDRA_FOREST_HILL, ICE};

/*!
 * \enum WeatherConditions
 * \brief All possibles weather conditions on a tile
 */
enum WeatherConditions {SUNNY, RAINY, SNOW, HAILSTORM, STORM};

/*!
 * \enum Ressource
 * \brief All possibles ressources produced on a tile
 */
enum Ressource {PRODUCTION, WOOD, IRON}; //Need to discuss all

/*!
 * \class Tile
 * \brief Class containing all information about the biome of a 
 *        particular zone
 * 
 * The world is dividend in zones charactherized by one biome between
 * 	- coast
 * 	- ocean
 * 	- desert
 * 	- plain
 * 	- forest
 * 	- jungle
 * 	- mountain
 * 	- hill
 * 	- hill in the desert
 *  - hill in a forest
 *  - tundra
 *  - tundra forest
 * 	- hill in tundra with forest
 *  - ice
 * 
 * 
 */
class Tile {
public:

//Constructors
  Tile();
  Tile(TileType t, int pos1, int pos2);
  
//Functions
  int[3] GetRessources(Player *pOwner);
  void ChangeWeather(WeatherConditions wt);
  Tile* Neighbor(int direction);
  
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
