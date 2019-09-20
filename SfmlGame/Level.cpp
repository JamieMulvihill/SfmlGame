#include "Level.h"
Level::Level(sf::RenderWindow* hwnd, Input* input)
{
	window = hwnd;
	inputRef = input;

	backGround.setPosition(0, 0);
	backGround.setSize(sf::Vector2f(800, 608));
	bgTex.loadFromFile("gfx/bGround.png");
	backGround.setTexture(&bgTex);
	
	debugTex.loadFromFile("gfx/PlayerDebug.png");
	collsionBox.setPosition(sprite.getCollisionBox().left, sprite.getCollisionBox().top);
	collsionBox.setSize(sf::Vector2f(sprite.getCollisionBox().width, sprite.getCollisionBox().height));
	collsionBox.setTexture(&debugTex);

	sprite.setPosition(500, 300);
	sprite.texture.loadFromFile("gfx/Mushroom.png");
	sprite.setTexture(&sprite.texture);
	sprite.SetInput(inputRef);

	
	/*sprite2.setPosition(300, 300);
	sprite2.setSize(sf::Vector2f(50, 50));
	sprite2.setCollisionBox(sf::FloatRect(0, 0, 50, 50));
	sprite2.setVelocity(50, 0);
	sprite2.texture.loadFromFile("gfx/Mushroom.png");
	sprite2.setTexture(&sprite2.texture);*/

}
Level::~Level()
{
}
void Level::update(float dt)
{
	

	// Check for collision with bottom of window
	CollisionChecks();

	sprite.Update(dt);
	//sprite2.Update(dt);
	collsionBox.setPosition(sprite.getPosition().x, sprite.getPosition().y);
	handleInput(dt);
}
void Level::handleInput(float dt)
{
	if (inputRef) {
		
		if (inputRef->isKeyDown(sf::Keyboard::Escape))
		{
			std::cout << "Input" << std::endl;
			window->close();
		}
	}
}


void Level::render()
{
	beginDraw();
	//window->draw(backGround);
	gameMap.tileMap.render(window);

	
	window->draw(sprite);
	window->draw(collsionBox);
	//window->draw(sprite2);
	endDraw();
}
void Level::CollisionChecks()
{
	// checking the collsion of the player with the map itself
	std::vector<Sprite>* world = gameMap.tileMap.getLevel();
	for (int i = 0; i < (int)world->size(); i++)
	{
		// if collision check should occur
		if ((*world)[i].isCollider())
		{
			if (Collision::checkBoundingBox(&sprite, &(*world)[i]))
			{
				sprite.collisionResponse(&(*world)[i]);
			}

		/*	if (Collision::checkBoundingBox(&sprite2, &(*world)[i]))
			{
				sprite2.collisionResponse(&(*world)[i]);
			}*/

		}
	}

	/*if (Collision::checkBoundingBox(&sprite, &sprite2))
	{
		sprite.collisionResponse(&sprite2);
		sprite2.collisionResponse(&sprite);
	}*/
}
void Level::beginDraw()
{
	window->clear(sf::Color::Black);
}
void Level::endDraw()
{
	window->display();
}
