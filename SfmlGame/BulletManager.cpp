#include "BulletManager.h"
#include <Thread>

BulletManager::BulletManager() {
	for (int i = 0; i < 6; i++) {
		bullets.push_back(new Bullet());
		bullets[i]->setAlive(false);
	}
}
BulletManager::~BulletManager() {

}

void BulletManager::Spawn() {

	for (int i = 0; i < bullets.size(); i++)
	{
		if (!bullets[i]->isAlive()){
			bullets[i]->setAlive(true);
			
			if (player_->getFlipped())
				bullets[i]->setVelocity(-600, 0);
			else if (!player_->getFlipped())
				bullets[i]->setVelocity(600, 0);

			bullets[i]->setPosition(player_->getPosition());
			
			return;
		}
	}
}

void BulletManager::Update(float dt) {

	for (Bullet * b : bullets){
		if (b->isAlive()){
			b->Update(dt);
		}
	}
}

bool BulletManager::DeathCheck(Sprite* sprite) {
	for (Bullet * b : bullets) {
		if (Collision::checkBoundingBox(b, sprite)){
			
			if (b->isAlive()) {
				b->collisionResponse(sprite);
				sprite->collisionResponse(b);
				return true;
			}
			
		}
	}
	return false;
}

void BulletManager::Render(sf::RenderWindow* window) {
	
	/*std::vector<std::thread*> threads;

	for (Bullet* b : bullets) {
		threads.push_back(new std::thread([=] { if (b->isAlive()) {
			window->draw(*b);
		}}));
	}

	for (std::thread* t : threads) {
		t->join();
	}*/

	for (Bullet * b : bullets){
		if (b->isAlive()){
			window->draw(*b);
		}
	}
}
