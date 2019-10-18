#include "Bullet.h"
#include <iostream>

Bullet::Bullet() {

	//setPosition(position);
	setSize(sf::Vector2f(16, 16));
	setCollisionBox(sf::FloatRect(0, 0, 16, 16));
	setFillColor(sf::Color::Blue);
	type = BULLET;
}

Bullet::~Bullet() {

}

void Bullet::Update(float dt) {

		move(velocity * dt);
}

void Bullet::collisionResponse(Sprite* sp) {
	if (abs(getPosition().x - sp->getPosition().x) > abs(getPosition().y - sp->getPosition().y)) {

		//check for collsision on the left side of the bullet
		if (getPosition().x - sp->getPosition().x > 0) {
			setAlive(false);
		}
		// check for collsion on the right side of the bullet
		else if (getPosition().x - sp->getPosition().x < 0) {
			setAlive(false);
		}
	}

}