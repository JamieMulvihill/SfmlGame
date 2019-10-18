#include "Level.h"
Level::Level(sf::RenderWindow* hwnd, Input* input)
{
	window = hwnd;
	inputRef = input;

	spawnPoints[0] = sf::Vector2f(500, 420);
	spawnPoints[1] = sf::Vector2f(960, 220);
	spawnPoints[2] = sf::Vector2f(350, 220);
	spawnPoints[3] = sf::Vector2f(900, 420);

	backGround.setPosition(0, 0);
	backGround.setSize(sf::Vector2f(1248, 672));
	bgTex.loadFromFile("gfx/Sky.png");
	backGround.setTexture(&bgTex);
	
	// debug boxes
	debugTex.loadFromFile("gfx/PlayerDebug.png");
	collsionBox.setPosition(player_.getCollisionBox().left, player_.getCollisionBox().top);
	collsionBox.setSize(sf::Vector2f(player_.getCollisionBox().width, player_.getCollisionBox().height));
	collsionBox.setTexture(&debugTex);

	//player_.texture.loadFromFile("gfx/BlobKing.png");
	//player_.setTexture(&player_.texture);
	players[0].SetInput(inputRef);
	players[0].texture.loadFromFile("gfx/BlueBlobTile.png");

	players[1].SetInput(NULL);
	players[1].texture.loadFromFile("gfx/GreenBlobTile.png");
	players[1].setTexture(&players[1].texture);
	players[1].setPosition(spawnPoints[1]);

	enemy.setPosition(spawnPoints[3]);
	enemy.texture.loadFromFile("gfx/RedBlobTile.png");
	enemy.setTexture(&enemy.texture);

	timer = 0;
	gui = new Gui(&players[0], &players[1]);
	//text.setFillColor(sf::Color::Green);

	isShaking = false;
	crown = new Crown(NULL);

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

	players[0].Update(dt);
	players[1].Update(dt);

	//client.SendFucntion(players[0].getPosition().x, players[0].getPosition().y);
	//client.RecieveFucntion();
	enemy.Update(dt);
	
	if (!players[1].isAlive()) {
		players[1].Respawn(spawnPoints[timer]);
		timer++;
		if (timer >= 4) {
			timer = 0;
		}
	}

	crown->Update(dt);
	gui->Update(dt);
	//sprite2.Update(dt);
	//for (Bullet* b : bullets) {
	//	b->Update(dt);
	//}
	
	collsionBox.setPosition(players[0].getPosition().x, players[0].getPosition().y);

	
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

			
			players[0].bulletManager.Spawn();
			
			/*//bullets.push_back(new Bullet(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y)));
			if(sprite.getFlipped())
				bullets.back()->setVelocity(-600, 0);
			else if(!sprite.getFlipped())
				bullets.back()->setVelocity(600, 0);*/

			inputRef->setKeyUp(sf::Keyboard::J);
		}
	}
}


void Level::render(){
	beginDraw();

	//window->draw(backGround);
	gameMap.tileMap.render(window);

	players[0].bulletManager.Render(window);

	if (players[0].isAlive()) {
		window->draw(players[0]);
	}
	if (players[1].isAlive()) {
		window->draw(players[1]);
	}
	window->draw(*crown);
	window->draw(enemy);
	//window->draw(collsionBox);

	gui->Render(window);
	
	endDraw();
}
void Level::CollisionChecks(){
	if (players[0].bulletManager.DeathCheck(&players[1])) {
		players[0].SetScore(1);
	}
	if (Collision::checkBoundingBox(&players[0], &players[1])){
		players[0].collisionResponse(&players[1]);
		ScreenShake(players[0].isHit);

		//setting the playes alive bool to the return f the shaking function, when the shaking has 
		players[1].collisionResponse(&players[0]);
		ScreenShake(players[1].isHit);
	}

	if (Collision::checkBoundingBox(&players[0], crown)){

	    //player_.collisionResponse(crown);
		crown->collisionResponse(&players[0]);
	}
	if (Collision::checkBoundingBox(&players[1], crown)){

		//player_2.collisionResponse(crown);
		crown->collisionResponse(&players[1]);
	}

	// checking the collsion of the player with the map itself
	std::vector<Sprite>* world = gameMap.tileMap.getLevel();
	for (int i = 0; i < (int)world->size(); i++)
	{
		// if collision check should occur
		if ((*world)[i].isCollider()){
			if (Collision::checkBoundingBox(&players[0], &(*world)[i]))
			{
				players[0].collisionResponse(&(*world)[i]);
			}

			if (Collision::checkBoundingBox(&players[1], &(*world)[i]))
			{
				players[1].collisionResponse(&(*world)[i]);
			}

			players[0].bulletManager.DeathCheck(&(*world)[i]);
		}
	}
}
//function to shake the screen, when the shaking has competed return false
void Level::ScreenShake(bool isHit){
	if (isHit) {
		window->setPosition(sf::Vector2i(100 + rand() % 35, window->getPosition().y));
	}
}
void Level::beginDraw(){
	window->clear(sf::Color::Black);
}
void Level::endDraw(){
	window->display();
}
