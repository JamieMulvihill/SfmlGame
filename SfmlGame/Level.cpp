#include "Level.h"
Level::Level(sf::RenderWindow* hwnd, Input* input)
{
	window = hwnd;
	inputRef = input;

	backGround.setPosition(645, 5);
	backGround.setSize(sf::Vector2f(120, 85));
	bgTex.loadFromFile("gfx/BGGui.png");
	backGround.setTexture(&bgTex);
	
	// debug boxes
	debugTex.loadFromFile("gfx/PlayerDebug.png");
	collsionBox.setPosition(player_.getCollisionBox().left, player_.getCollisionBox().top);
	collsionBox.setSize(sf::Vector2f(player_.getCollisionBox().width, player_.getCollisionBox().height));
	collsionBox.setTexture(&debugTex);

	//player_.texture.loadFromFile("gfx/BlobKing.png");
	//player_.setTexture(&player_.texture);
	player_.SetInput(inputRef);

	bulletManager.setSprite(&player_);


	crownSprite.setPosition(650, 316);
	crownSprite.setSize(sf::Vector2f(96, 96));
	crownTex.loadFromFile("gfx/KingCrown.png");
	crownSprite.setTexture(&crownTex);
	
	//text.setFillColor(sf::Color::Green);

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

	player_.Update(dt);

	gui.Update(dt);
	//sprite2.Update(dt);
	//for (Bullet* b : bullets) {
	//	b->Update(dt);
	//}

	crownSprite.setPosition(player_.getPosition().x- (player_.getSize().x/4), player_.getPosition().y - player_.getSize().y);

	bulletManager.Update(dt);
	collsionBox.setPosition(player_.getPosition().x, player_.getPosition().y);
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

		if (inputRef->isKeyDown(sf::Keyboard::J)) {

			
			bulletManager.Spawn();

			/*//bullets.push_back(new Bullet(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y)));
			if(sprite.getFlipped())
				bullets.back()->setVelocity(-600, 0);
			else if(!sprite.getFlipped())
				bullets.back()->setVelocity(600, 0);*/

			inputRef->setKeyUp(sf::Keyboard::J);
		}
	}
}


void Level::render()
{
	beginDraw();
	
	gameMap.tileMap.render(window);

	/*for (Bullet* b : bullets) {
		if (b->isAlive()) {
			window->draw(*b);
		}
	}*/
	
	bulletManager.Render(window);
	window->draw(player_);
	window->draw(collsionBox);
	gui.Render(window);
	window->draw(crownSprite);
	//window->draw(backGround);
	//window->draw(text);
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
		if ((*world)[i].isCollider()){
			if (Collision::checkBoundingBox(&player_, &(*world)[i]))
			{
				player_.collisionResponse(&(*world)[i]);
			}
			bulletManager.DeathCheck(&(*world)[i]);

			/*for (Bullet* b : bullets) {
				if (Collision::checkBoundingBox(b, &(*world)[i]))
				{
					b->collisionResponse(&(*world)[i]);
				}
			}*/
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
