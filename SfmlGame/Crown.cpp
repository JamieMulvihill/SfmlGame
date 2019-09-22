#include "Crown.h"

Crown::Crown(Player* player)
{
	setPosition(650, 316);
	setSize(sf::Vector2f(96, 96));
	setCollisionBox(0, 0, 96, 96);
	texture.loadFromFile("gfx/KingCrown.png");
	setTexture(&texture);
	type = PICKUP;
	player_ = player;

	isPickedUp = false;
}

Crown::~Crown()
{
}

void Crown::Update(float dt)
{
	if (isPickedUp) {
		setPosition(player_->getPosition().x - (player_->getSize().x / 4), player_->getPosition().y - player_->getSize().y);
		player_->SetScore(dt);
	}
}

void Crown::collisionResponse(Sprite* sp)
{
	if (!isPickedUp) {
		if (abs(getPosition().x - sp->getPosition().x) > abs(getPosition().y - sp->getPosition().y)) {


			//check for collsision on the left side of the player
			if (getPosition().x - sp->getPosition().x > 0) {
				player_ = (Player*)sp;
				isPickedUp = true;

			}
			// check for collsion on the right side of the player
			else if (getPosition().x - sp->getPosition().x < 0) {
				player_ = (Player*)sp;
				isPickedUp = true;
			}
		}

		else if (abs(getPosition().y - sp->getPosition().y) > abs(getPosition().x - sp->getPosition().x)) {

			isPickedUp = true;
			// check for collsions above the player
			if (getPosition().y - sp->getPosition().y > 0) {
				player_ = (Player*)sp;
				isPickedUp = true;
			}

			//check for collisions below the player
			else if (getPosition().y - sp->getPosition().y < 0) {
				player_ = (Player*)sp;
				isPickedUp = true;
			}
		}
	}
}
