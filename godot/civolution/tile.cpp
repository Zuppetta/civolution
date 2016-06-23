#include "tile.hpp"

//Constructors

Tile::Tile()//Default
:type(PLAIN), height(0), river(false), flooded(false), local_weather(SUNNY),
	pos1(0), pos2(0), army(0), building(0){
	
}

Tile::Tile(TileType _type, int _pos1, int _pos2)
:type(_type), height(0), river(false), flooded(false), local_weather(SUNNY),
	pos1(_pos1), pos2(_pos2), army(0), building(0) {
	
}

//Public functions

int[3] GetRessources(Player *pOwner) {
	
	switch (type)
	{
		
	}
}

void ChangeWeather(WeatherConditions wt) {
	
	local_weather = wt;
}

/* Tile* neighbor(int direction) {
	switch (direction)
	{
		
	}
}*/

int[2] WhereAmI() {
	
	return {pos1, pos2};
}
