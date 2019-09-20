#pragma once
#include "Sprite.h"

class Bullet : public Sprite
{
public:
	Bullet(sf::Vector2f position);
	~Bullet();

	void Update(float dt);
	void collisionResponse(Sprite* sp);

};

