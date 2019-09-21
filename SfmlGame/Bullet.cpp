#include "Bullet.h"
#include <iostream>

Bullet::Bullet() {

	//setPosition(position);
	setSize(sf::Vector2f(16, 16));
	setCollisionBox(sf::FloatRect(0, 0, 16, 16));
	setFillColor(sf::Color::Blue);
}

Bullet::~Bullet() {

}

void Bullet::Update(float dt) {
	//if (isAlive()) {
		move(velocity * dt);
	//setPosition(getPosition().x + 1, getPosition().y);
		//std::cout << " position.x: " << getPosition().x << " position.y :" << getPosition().y << std::endl;
		//std::cout << " velocity.x: " << getVelocity().x << " velocity.y :" << getVelocity().y << std::endl;
	//}
}

void Bullet::collisionResponse(Sprite* sp) {
	if (abs(getPosition().x - sp->getPosition().x) > abs(getPosition().y - sp->getPosition().y)) {

		//check for collsision on the left side of the bullet
		if (getPosition().x - sp->getPosition().x > 0) {
			setAlive(false);
			sp->setAlive(false);
		}
		// check for collsion on the right side of the bullet
		else if (getPosition().x - sp->getPosition().x < 0) {
			setAlive(false);
			sp->setAlive(false);
		}
	}

}