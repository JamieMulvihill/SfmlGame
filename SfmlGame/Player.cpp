#include "Player.h"
#include <iostream>

Player::Player()
{
	onGround = false;
	isCrushed = false;
	isHit = false;
	setAlive(true);
	score = 0;
	counter = 0;
	deltime = 0.f;
	type = PLAYER;
	setPosition(500, 420);
	setSize(sf::Vector2f(64, 64));
	setCollisionBox(sf::FloatRect(0, 0, 64, 64));
	setTexture(&texture);

	

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

	bulletManager.setSprite(this);

	gravity = 9.8f * 50;
}
Player::~Player()
{
}

void Player::Update(float dt) {

	currentAnim->animate(dt);
	setTextureRect(currentAnim->getCurrentFrame());

	

	deltime = dt;

	velocity.y += gravity * dt;
	move(velocity * dt);

	bulletManager.Update(dt);

	BoundaryCheck();
	
	handleInput(dt);
	if (isHit) {
		counter++;
	}

	if (death.currentFrame == (death.getSize() - 1)) {
		setAlive(false);
	}
}
void Player::handleInput(float dt) {

	if (inputRef) {
		if (onGround) {
			if (inputRef->isKeyDown(sf::Keyboard::Space))
			{
				setPosition(getPosition().x, getPosition().y - 2);
				velocity.y = -9.8 * 40;
				velocity.x = .6 * velocity.x;
				onGround = false;
			}

		/*	else if (inputRef->isKeyDown(sf::Keyboard::S)) {
				velocity.y = 50.f * 3;
			}

			else if (inputRef->isKeyDown(sf::Keyboard::W)) {
				velocity.y = -50.f * 3;
			}*/
			else if (inputRef->isKeyDown(sf::Keyboard::A)) {
				velocity.x = -100.f * 3;
				isFlipped = true;

				currentAnim = &walk;
				//currentAnim->reset();
				setTextureRect(currentAnim->getCurrentFrame());
				walk.setFlipped(false);
				idle.setFlipped(false);
			}

			else if (inputRef->isKeyDown(sf::Keyboard::D)) {
				velocity.x = 100.f * 3;
				isFlipped = false;

				currentAnim = &walk;
				//currentAnim->reset();
				setTextureRect(currentAnim->getCurrentFrame());
				walk.setFlipped(true);
				idle.setFlipped(true);
			}

			else {
				velocity.x = 0;
				currentAnim = &idle;
				setTextureRect(currentAnim->getCurrentFrame());
			}
		}
		else {
			if (inputRef->isKeyDown(sf::Keyboard::A)) {
				velocity.x = -30.f * 3;
				isFlipped = true;
			}

			if (inputRef->isKeyDown(sf::Keyboard::D)) {
				velocity.x = 30.f * 3;
				isFlipped = false;
			}
		}
		
	}
}

void Player::Respawn(sf::Vector2f spawnpoint){
	if (!alive) {
		setAlive(true);
		setPosition(spawnpoint);
		isCrushed = false;
		isHit = false;
		currentAnim->reset();
		currentAnim = &idle;
		setTextureRect(currentAnim->getCurrentFrame());
	}
}

void Player::Death() {
	isHit = true;
	setVelocity(0, 0);
	currentAnim = &death; 
	setTextureRect(currentAnim->getCurrentFrame());
}


//collsions for the player object
void Player::collisionResponse(Sprite* sp) {

	if (abs(getPosition().y - sp->getPosition().y) > abs(getPosition().x - sp->getPosition().x)) {
		// check for collsions above the player
		if (getPosition().y - sp->getPosition().y > 0.f) {
			std::cout << "Debug head" << std::endl;
			if (sp->GetType() == PLAYER) {
				Death();
			}
			else {
				setPosition(getPosition().x, sp->getPosition().y + (getSize().y + 1));
				velocity.y *= -1;
			}
		}

		//check for collisions below the player
		else if (getPosition().y - sp->getPosition().y < 0.f) {
			setPosition(getPosition().x, sp->getPosition().y - getSize().y);
			onGround = true;
			velocity.y = 0;
		}
	}

	else if (abs(getPosition().x - sp->getPosition().x) > abs(getPosition().y - sp->getPosition().y)) {

		 if (!sp->GetType() == PLAYER) {
			//check for collsision on the left side of the player
			 if (sp->GetType() == BULLET) {
				 Death();
			 }
			 else {
				 if (getPosition().x - sp->getPosition().x > 0.f) {
					 setPosition(sp->getPosition().x + sp->getSize().x, getPosition().y);
				 }
				 // check for collsion on the right side of the player
				 else if (getPosition().x - sp->getPosition().x < 0.f) {
					 setPosition(sp->getPosition().x - getSize().x, getPosition().y);
				 }
			 }
		}
	}
}

void Player::BoundaryCheck(){
	if (getPosition().x < 0){
		setPosition(0, getPosition().y);
		velocity.x = -.3 * velocity.x;
	}
	if (getPosition().x > 1340){
		setPosition(750, getPosition().y);
		velocity.x = -.3 * velocity.x;
	}

	if (getPosition().y > 896){
		setPosition(getPosition().x, 0);
	}
}
