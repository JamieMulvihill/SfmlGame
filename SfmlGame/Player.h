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
	void Respawn(sf::Vector2f* spawnpoint);

	BulletManager bulletManager;
private:
	

	bool onGround;
	float score;

	Animation walk;
	Animation idle;
	Animation* currentAnim;

	Input* inputRef;
};

