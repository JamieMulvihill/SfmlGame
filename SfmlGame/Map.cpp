#include "Map.h"
#include <iostream>

Map::Map()
{

	tileMap.loadTexture((char*)"gfx/robot.png");// initialize texture
	Sprite tile; // create sprite called tile
	std::vector<Sprite> tiles; //create a vector of sprites called tiles 

	//for loop to add tiles to vector
	for (int i = 0; i < 5; i++)
	{
		tile.setSize(sf::Vector2f(32, 32));
		tile.setCollisionBox(0, 0, 32, 32);
		tile.setCollider(true);
		tiles.push_back(tile);
	}
	// created tiles
	tiles[0].setCollider(false);
	tiles[0].setTextureRect(sf::IntRect(187, 51, 16, 16));
	tiles[1].setTextureRect(sf::IntRect(0, 0, 16, 16));//solid single block with 2 dots
	tiles[2].setTextureRect(sf::IntRect(96, 16, 16, 16)); // 2-4 vertical 3 block section, dots on 2 and 4
	tiles[3].setTextureRect(sf::IntRect(96, 32, 16, 16));
	tiles[4].setTextureRect(sf::IntRect(96, 48, 16, 16));
	tileMap.setTileSet(tiles);

	// Map dimensions
	sf::Vector2u mapSize(25, 19);
	// build map
	std::vector<int> map = {
		1, 1, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,1,1,
		1, 1, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,1,1,
		1, 1, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,1,1,
		1, 1, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 1,0, 0, 0, 0, 0,0, 0, 0, 0, 0,1,1,
		1, 1, 0,0, 0, 1, 1, 1, 1, 0, 0, 0, 1,0, 0, 0, 1, 1, 1, 1, 0, 0, 0,1,1,
		1, 1, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 1,0, 0, 0, 0, 0,0, 0, 0, 0, 0,1,1,
		1, 1, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 1,0, 0, 0, 0, 0,0, 0, 0, 0, 0,1,1,
		1, 1, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 1,0, 0, 0, 0, 0,0, 0, 0, 0, 0,1,1,
		1, 1, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 1,0, 0, 0, 0, 0,0, 0, 0, 0, 0,1,1,
		1, 1, 0,0, 0, 0, 0, 0,0, 1, 1, 1, 1, 1, 1, 1, 0, 0,0, 0, 0, 0, 0,1,1,
		1, 1, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,1,1,
		1, 1, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,1,1,
		1, 1, 1,1,1,1, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 1,1,1,1,1,1	,
		1, 1, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,1,1,
		1, 1, 0,0, 0, 0, 0, 0,0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,0, 0, 0, 0, 1,1,
		1, 1, 0,0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,0, 1,1,
		1, 1, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,1,1,
		1, 1, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,1,1,
	
	};

	tileMap.setTileMap(map, mapSize);
	tileMap.setPosition(sf::Vector2f(0, 0));
	tileMap.buildLevel();
}

Map::~Map()
{
}

