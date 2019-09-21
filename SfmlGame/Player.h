#pragma once
#include "Sprite.h"
#include "Input.h"
#include "Animation.h"
#include "BulletManager.h"

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
	int GetScore() { return score; }

	BulletManager bulletManager;
private:
	
	bool onGround;
	int score;

	Animation walk;
	Animation idle;
	Animation* currentAnim;

	Input* inputRef;
};

