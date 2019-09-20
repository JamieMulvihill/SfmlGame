#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position) {

	setPosition(position);
	setSize(sf::Vector2f(16, 16));
	setCollisionBox(sf::FloatRect(0, 0, 16, 16));
	setFillColor(sf::Color::Blue);
}

Bullet::~Bullet() {

}


void Bullet::Update(float dt) {
	move((velocity * dt));
}

void Bullet::collisionResponse(Sprite* sp) {
	
}