// Map Class
// Builds and store level sections based on TileMap and TileSet

#pragma once
#include <math.h>
#include "Sprite.h"

class TileMap : public Sprite
{
public:
	TileMap();
	~TileMap();

	void loadTexture(char* filename);
	void setTileSet(std::vector<Sprite> ts);
	void setTileMap(std::vector<int> tm, sf::Vector2u mapDimensions);
	void buildLevel();

	void render(sf::RenderWindow* window);
	std::vector<Sprite>* getLevel() { return &level; };

	void setPosition(sf::Vector2f pos) { position = pos; };

protected:
	std::vector<Sprite> tileSet;
	std::vector<int> tileMap;
	std::vector<Sprite> level;
	sf::Texture texture;
	sf::Texture debugTex;
	sf::RectangleShape collsionBox;
	sf::Vector2u mapSize;
	sf::Vector2f position;
};

