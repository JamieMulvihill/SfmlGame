#include "Map.h"
#include <iostream>

Map::Map()
{

	tileMap.loadTexture((char*)"gfx/WoodTile.png");// initialize texture
	Sprite tile; // create sprite called tile
	std::vector<Sprite> tiles; //create a vector of sprites called tiles 

	//for loop to add tiles to vector
	for (int i = 0; i < 36; i++)
	{
		tile.setSize(sf::Vector2f(64, 48));
		tile.setCollisionBox(0, 0, 64, 48);
		tile.setCollider(true);
		tiles.push_back(tile);
	}
	//// created tiles
	//tiles[0].setCollider(false);
	//tiles[0].setTextureRect(sf::IntRect(187, 51, 16, 16));
	//tiles[1].setTextureRect(sf::IntRect(0, 0, 16, 16));//solid single block with 2 dots
	//tiles[2].setTextureRect(sf::IntRect(96, 16, 16, 16)); // 2-4 vertical 3 block section, dots on 2 and 4
	//tiles[3].setTextureRect(sf::IntRect(96, 32, 16, 16));
	//tiles[4].setTextureRect(sf::IntRect(96, 48, 16, 16));
	//tileMap.setTileSet(tiles);

	tiles[0].setCollider(false);
	tiles[0].setTextureRect(sf::IntRect(160, 160, 64, 64));
	//tree right boundary
	tiles[1].setTextureRect(sf::IntRect(576, 0, 64, 64));//solid single block with 2 dots
	tiles[2].setTextureRect(sf::IntRect(640, 0, 64, 64)); // 2-4 vertical 3 block section, dots on 2 and 4
	tiles[3].setTextureRect(sf::IntRect(704, 0, 64, 64));
	tiles[4].setTextureRect(sf::IntRect(576, 64, 64, 64));
	tiles[5].setTextureRect(sf::IntRect(640, 64, 64, 64));
	tiles[6].setTextureRect(sf::IntRect(704, 64, 64, 64));
	tiles[7].setTextureRect(sf::IntRect(576, 128, 64, 64));
	tiles[8].setTextureRect(sf::IntRect(640, 128, 64, 64));
	tiles[9].setTextureRect(sf::IntRect(704, 128, 64, 64));
	// tree left boundary
	tiles[10].setTextureRect(sf::IntRect(768, 0, 64, 64));//solid single block with 2 dots
	tiles[11].setTextureRect(sf::IntRect(832, 0, 64, 64)); // 2-4 vertical 3 block section, dots on 2 and 4
	tiles[12].setTextureRect(sf::IntRect(896, 0, 64, 64));
	tiles[13].setTextureRect(sf::IntRect(768, 64, 64, 64));
	tiles[14].setTextureRect(sf::IntRect(832, 64, 64, 64));
	tiles[15].setTextureRect(sf::IntRect(896, 64, 64, 64));
	tiles[16].setTextureRect(sf::IntRect(768, 128, 64, 64));
	tiles[17].setTextureRect(sf::IntRect(832, 128, 64, 64));
	tiles[18].setTextureRect(sf::IntRect(896, 128, 64, 64));
	//tree float blocks
	tiles[19].setTextureRect(sf::IntRect(384, 0, 64, 64));
	tiles[20].setTextureRect(sf::IntRect(448, 0, 64, 64));
	tiles[21].setTextureRect(sf::IntRect(512, 0, 64, 64));
	//vertical down block
	tiles[22].setTextureRect(sf::IntRect(0, 0, 64, 64));
	tiles[23].setTextureRect(sf::IntRect(64, 0, 64, 64));
	tiles[24].setTextureRect(sf::IntRect(0, 64, 64, 64));
	tiles[25].setTextureRect(sf::IntRect(64, 64, 64, 64));
	tiles[26].setTextureRect(sf::IntRect(0, 128, 64, 64));
	tiles[27].setTextureRect(sf::IntRect(64, 128, 64, 64));
	tiles[28].setTextureRect(sf::IntRect(0, 192, 64, 64));
	tiles[29].setTextureRect(sf::IntRect(64, 192, 64, 64));
	//horizontal blocks
	tiles[30].setTextureRect(sf::IntRect(128, 0, 64, 64));
	tiles[31].setTextureRect(sf::IntRect(192, 0, 64, 64));
	tiles[32].setTextureRect(sf::IntRect(256, 0, 64, 64));
	tiles[33].setTextureRect(sf::IntRect(128, 64, 64, 64));
	tiles[34].setTextureRect(sf::IntRect(192, 64, 64, 64));
	tiles[35].setTextureRect(sf::IntRect(256, 64, 64, 64));

	tileMap.setTileSet(tiles);

	// Map dimensions
	sf::Vector2u mapSize(22, 14);
	// build map
	std::vector<int> map = {
		/*1, 1, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,1,1,
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
		1, 1, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,1,1,1,
		1, 1, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,0, 0, 0, 0, 0,1,1,1,*/

		1, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 11, 12,
		4, 5, 6, 0, 0, 0, 0, 0, 0, 0, 22, 23, 0, 0, 0, 0, 0, 0, 0, 13, 14, 15,
		4, 5, 6, 0, 0, 19, 21, 0, 0, 0, 24, 25, 0, 0, 0, 19, 21, 0, 0, 13, 14, 15,
		4, 5, 6, 0, 0, 0, 0, 0, 0, 0, 26, 27, 0, 0, 0, 0, 0, 0, 0, 13, 14, 15,
		4, 5, 6, 0, 0, 0, 0, 0, 0, 19, 26, 27, 21, 0, 0, 0, 0, 0, 0, 13, 14, 15,
		4, 5, 6, 0, 0, 0, 0, 0, 0, 0, 28, 29, 0, 0, 0, 0, 0, 0, 0, 13, 14, 15,
		4, 5, 6, 19, 20, 20, 21, 0, 0, 0, 0, 0, 0, 0, 0, 19, 20, 20, 21, 13, 14, 15,
		4, 5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 14, 15,
		4, 5, 6, 0, 0, 0, 0, 0, 0, 30, 31, 31, 32, 0, 0, 0, 0, 0, 0, 13, 14, 15,
		4, 5, 6, 0, 0, 0, 0, 0, 0, 33, 34, 34, 35, 0, 0, 0, 0, 0, 0, 13, 14, 15,
		4, 5, 6, 0, 0, 0, 30, 31, 31, 31, 31, 31, 31, 31, 31, 32, 0, 0, 0, 13, 14, 15,
		4, 5, 6, 0, 0, 0, 33, 34, 34, 34, 34, 34, 34, 34, 34, 35, 0, 0, 0, 13, 14, 15,
		4, 5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 14, 15,
		7, 8, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 17, 18
	};

	tileMap.setTileMap(map, mapSize);
	tileMap.setPosition(sf::Vector2f(0, 0));
	tileMap.buildLevel();
}

Map::~Map()
{
}

