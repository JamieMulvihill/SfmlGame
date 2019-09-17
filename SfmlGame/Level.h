#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Sprite.h"
#include "Input.h"

class Level {
public:
	Level(sf::RenderWindow* hwnd, Input* input);
	~Level();
	void handleInput(float dt);
	void update(float dt);
	void render();
private:
	sf::RenderWindow* window;
	void beginDraw();
	void endDraw();
	Sprite sprite;

	float gravity;

	Input* inputRef;
};