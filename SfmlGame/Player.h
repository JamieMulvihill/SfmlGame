#pragma once
#include "Sprite.h"
#include "Input.h"

class Player : public Sprite
{
public:
	Player();
	~Player();

	// functions used in class
	void Update(float dt);
	void collisionResponse(Sprite* sp);
	void handleInput(float dt);
	void SetInput(Input* input) { inputRef = input; }

	bool getFlipped() { return isFlipped; }

private:
	
	bool onGround, isFlipped;
	float health;

	Input* inputRef;
};

