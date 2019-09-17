#include "Sprite.h"

Sprite::Sprite()
{
	velocity.x = 0.f;
	velocity.y = 0.f;
}

Sprite::~Sprite()
{}

// Sets the velocity of the sprite
void Sprite::setVelocity(sf::Vector2f vel)
{
	velocity = vel;
}
void Sprite::setVelocity(float vx, float vy)
{
	velocity.x = vx;
	velocity.y = vy;
}

// get sprite velocity
sf::Vector2f Sprite::getVelocity()
{
	return velocity;
}

