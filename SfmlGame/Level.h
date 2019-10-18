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
#include "Crown.h"
#include "Enemy.h"
#include <SFML/System/Thread.hpp>
#include "UdpClient.h"

class Level {
public:
	Level(sf::RenderWindow* hwnd, Input* input);
	~Level();
	void handleInput(float dt);
	void update(float dt);
	void render();
	void CollisionChecks();
	void ScreenShake(bool isShaking);

private:
	sf::RenderWindow* window;
	void beginDraw();
	void endDraw();

	/// create the physics world
//	b2World* world_;

	Player players[2];
	Player player_;
	Player player_2;
	Enemy enemy;

	sf::Vector2f spawnPoints[4];

	Map gameMap;

	Crown * crown;

	Gui * gui;

	sf::CircleShape bounds;
	sf::Texture debug;

	UdpClient client;

	float gravity;
	int timer;
	bool isShaking;
	Input* inputRef;
	sf::RectangleShape backGround;
	sf::RectangleShape collsionBox;
	sf::Texture bgTex;
	sf::Texture debugTex;
};
