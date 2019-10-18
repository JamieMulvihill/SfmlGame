#pragma once
#include "Sprite.h"
#include "Animation.h"

class Enemy : public Sprite
{
public:
	Enemy();
	~Enemy();

	void Update(float dt);
	void collisionResponse(Sprite* sp);

	sf::CircleShape bounds;
	sf::Texture debug;

	Animation walk;
	Animation idle;
	Animation death;
	Animation* currentAnim;
};

