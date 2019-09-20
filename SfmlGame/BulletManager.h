#pragma once
#include "Bullet.h"
#include "Collision.h"

class BulletManager
{
public:
	BulletManager();
	~BulletManager();

	void Spawn();
	void Update(float dt);
	void DeathCheck(Sprite* sprite);
	void Render(sf::RenderWindow* window);
	void setSprite(Sprite* sprite) { player_ = sprite; }
	
private: 
	sf::Texture texture;
	std::vector<Bullet*> bullets;
	Sprite* player_;
	
};

