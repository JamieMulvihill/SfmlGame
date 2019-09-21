#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Sprite.h"
#include "Input.h"
#include "Collision.h"
#include "Map.h"
#include "Player.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "Gui.h"

class Level {
public:
	Level(sf::RenderWindow* hwnd, Input* input);
	~Level();
	void handleInput(float dt);
	void update(float dt);
	void render();
	void CollisionChecks();
private:
	sf::RenderWindow* window;
	void beginDraw();
	void endDraw();

	/// create the physics world
//	b2World* world_;

	Player player_;
	//Player sprite2;

	Map gameMap;

	Gui gui;

	BulletManager bulletManager;
	std::vector<Bullet*> bullets;

	float gravity;

	Input* inputRef;
	sf::RectangleShape backGround;
	sf::RectangleShape collsionBox;
	sf::Texture bgTex;
	sf::Texture debugTex;

	sf::RectangleShape crownSprite;
	sf::Texture crownTex;
};
