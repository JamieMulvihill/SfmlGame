#include "Player.h"
#include <iostream>

Player::Player()
{
	onGround = false;
	health = 100.f;

	setPosition(500, 300);
	setSize(sf::Vector2f(32, 32));
	setCollisionBox(sf::FloatRect(0, 0, 32, 32));
	texture.loadFromFile("gfx/Mushroom.png");
	setTexture(&texture);

	gravity = 9.8f * 50;
}
Player::~Player()
{
}

void Player::Update(float dt) {

	// Apply gravity force, increasing velocity
	// Move shape by new velocity
	velocity.y += gravity * dt;
	move(velocity * dt);

	if (getPosition().x < 0)
	{
		setPosition(0, getPosition().y);
		velocity.x = -.3 * velocity.x;
	}
	if (getPosition().x > 750)
	{
		setPosition(750, getPosition().y);
		velocity.x = -.3* velocity.x;
	}
	if (getPosition().y > 600)
	{
		setPosition(getPosition().x, 0);
	}
	handleInput(dt);
}
void Player::handleInput(float dt) {

	if (inputRef) {
		if (onGround) {
			if (inputRef->isKeyDown(sf::Keyboard::Space))
			{
				setPosition(getPosition().x, getPosition().y - 2);
				velocity.y = -9.8*25;
				velocity.x = .6 * velocity.x;
				onGround = false;
			}

			else if (inputRef->isKeyDown(sf::Keyboard::S)) {
				velocity.y = 50.f * 3;
			}

			else if (inputRef->isKeyDown(sf::Keyboard::W)) {
				velocity.y = -50.f * 3;
			}
			else if (inputRef->isKeyDown(sf::Keyboard::A)) {
				velocity.x = -100.f * 3;
			}

			else if (inputRef->isKeyDown(sf::Keyboard::D)) {
				velocity.x = 100.f * 3;
			}

			else
				velocity.x = 0;
		}
		else {
			if (inputRef->isKeyDown(sf::Keyboard::A)) {
				velocity.x = -30.f * 3;
			}

			if (inputRef->isKeyDown(sf::Keyboard::D)) {
				velocity.x = 30.f * 3;
			}
		}
		
	}
}
//collsions for the player object
void Player::collisionResponse(Sprite* sp) {

	if (abs(getPosition().x - sp->getPosition().x) > abs(getPosition().y - sp->getPosition().y)) {

		//check for collsision on the left side of the player
		if (getPosition().x - sp->getPosition().x > 0) {
			setPosition(sp->getPosition().x + sp->getSize().x, getPosition().y);
		}
		// check for collsion on the right side of the player
		else if (getPosition().x - sp->getPosition().x < 0) {
			setPosition(sp->getPosition().x - getSize().x, getPosition().y);
		}
	}

	else if (abs(getPosition().y - sp->getPosition().y) > abs(getPosition().x - sp->getPosition().x)) {
		// check for collsions above the player
		if (getPosition().y - sp->getPosition().y > 0) {
			setPosition(getPosition().x, sp->getPosition().y + sp->getSize().y);
		}

		//check for collisions below the player
		else if (getPosition().y - sp->getPosition().y < 0) {
			setPosition(getPosition().x, sp->getPosition().y - getSize().y);
			onGround = true;
			velocity.y = 0;
		}
	}

	


	
}