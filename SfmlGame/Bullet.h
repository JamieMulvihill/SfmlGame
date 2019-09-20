#pragma once
#include "Sprite.h"

class Bullet : public Sprite
{
public:
	Bullet();
	~Bullet();

	void Update(float dt);
	void collisionResponse(Sprite* sp);

};

