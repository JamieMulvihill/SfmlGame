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
	void BoundaryCheck();
	void handleInput(float dt);
	void SetInput(Input* input) { inputRef = input; }
	float GetScore() { return score; }
	void SetScore(float newScore) { score += newScore; }
	void Respawn(sf::Vector2f spawnpoint);
	bool GetCrushed() { return isCrushed; }
	void Crushed();
	void Death();
	BulletManager bulletManager;

	bool isHit;

private:
	bool onGround, isCrushed;
	float score, counter, deltime;

	Animation walk;
	Animation idle;
	Animation death;
	Animation* currentAnim;

	Input* inputRef;
};

