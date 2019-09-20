#pragma once
#include "TileMap.h"

class Map : public TileMap
{
public:
	Map();
	~Map();

	TileMap tileMap; // create an instance of the tilemap class
};

