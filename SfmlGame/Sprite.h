#pragma once
#include "SFML\Graphics.hpp"



class Sprite : public sf::RectangleShape 
{
public :
	Sprite();
	~Sprite();

	enum Direction { LEFT, RIGHT };

	// sprite speed and direction
	void setVelocity(sf::Vector2f vel);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity();

	virtual void Update(float dt);
	// sprite state
	bool isAlive() { return alive; };
	void setAlive(bool b) { alive = b; };
	bool getFlipped() { return isFlipped; }

	// for sprite collision
	bool isCollider() { return collider; };
	void setCollider(bool b) { collider = b; };
	void setCollisionBox(float x, float y, float width, float height) { collisionBox = sf::FloatRect(x, y, width, height); };
	void setCollisionBox(sf::FloatRect fr) { collisionBox = fr; };
	sf::FloatRect getCollisionBox();
	virtual void collisionResponse(Sprite* sp);

	sf::Texture texture;

	// input component
	//void setInput(Input* in) { inputRef = in; };
	sf::Vector2f velocity;
protected:
	// Sprite properties
	Direction direction;

	bool alive, isFlipped;;
	float gravity;
	// Collision vars
	sf::FloatRect collisionBox;
	bool collider;

	// input component
	//Input* inputRef;
};

