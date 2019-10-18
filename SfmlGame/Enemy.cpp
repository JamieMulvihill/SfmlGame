#include "Enemy.h"
Enemy::Enemy() {
	setSize(sf::Vector2f(64, 64));
	bounds.setRadius(350);
	bounds.setOrigin(getPosition().x + bounds.getRadius(), getPosition().y + bounds.getRadius());
	setAlive(true);
	debug.loadFromFile("gfx/BoundingSphere.png");
	bounds.setTexture(&debug);
	setTexture(&debug);
	setVelocity(30, 20);


	// Setup walk animation.
	walk.addFrame(sf::IntRect(0, 0, 288, 288));
	walk.addFrame(sf::IntRect(286, 0, 286, 288));
	walk.addFrame(sf::IntRect(575, 0, 285, 286));
	walk.addFrame(sf::IntRect(867, 0, 288, 288));
	walk.addFrame(sf::IntRect(0, 288, 286, 285));
	walk.addFrame(sf::IntRect(288, 288, 288, 288));
	walk.addFrame(sf::IntRect(576, 289, 288, 288));
	walk.setFrameSpeed(1.f / 20.f);

	idle.addFrame(sf::IntRect(0, 0, 288, 288));
	idle.addFrame(sf::IntRect(286, 0, 286, 288));
	idle.addFrame(sf::IntRect(575, 0, 285, 286));
	idle.addFrame(sf::IntRect(867, 0, 288, 288));
	idle.addFrame(sf::IntRect(0, 288, 286, 285));
	idle.addFrame(sf::IntRect(288, 288, 288, 288));
	idle.addFrame(sf::IntRect(576, 289, 288, 288));
	idle.setFrameSpeed(1.f / 5.f);

	death.addFrame(sf::IntRect(0, 576, 288, 285));
	death.addFrame(sf::IntRect(287, 576, 285, 285));
	death.addFrame(sf::IntRect(576, 576, 288, 285));
	death.addFrame(sf::IntRect(0, 865, 287, 285));
	death.addFrame(sf::IntRect(288, 865, 287, 285));
	death.addFrame(sf::IntRect(576, 865, 288, 285));
	death.setLooping(false);
	death.setFrameSpeed(1.f / 5.f);

	currentAnim = &idle;
	setTextureRect(currentAnim->getCurrentFrame());

}

Enemy::~Enemy() {

}

void Enemy::Update(float dt) {
	//move(velocity * dt);
	bounds.setPosition(getPosition().x + (getSize().x /2), getPosition().y + (getSize().y / 2));

	currentAnim->animate(dt);
	setTextureRect(currentAnim->getCurrentFrame());



}

void Enemy::collisionResponse(Sprite* sp) {
	
}