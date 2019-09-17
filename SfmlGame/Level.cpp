#include "Level.h"
Level::Level(sf::RenderWindow* hwnd, Input* input)
{
	window = hwnd;
	inputRef = input;

	sprite.setPosition(400, 300);
	sprite.setSize(sf::Vector2f(50, 50));
	sprite.setFillColor(sf::Color::Red);

	// initialise gravity value (gravity 9.8, 200 scale 200 p/s this will need to be uniform)
	gravity = 9.8f * 200.f;
}
Level::~Level()
{
}
void Level::update(float dt)
{
	// Apply gravity force, increasing velocity
	// Move shape by new velocity
	sprite.velocity.y += gravity * dt;
	sprite.move(sprite.velocity * dt);
	// Check for collision with bottom of window
	if (sprite.getPosition().y >= 500)
	{
		sprite.setPosition(sprite.getPosition().x, 500);
		sprite.velocity.y = 0;
	}

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
		if (inputRef->isKeyDown(sf::Keyboard::W)) {
			sprite.setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y - .02));
		}

		if (inputRef->isKeyDown(sf::Keyboard::S)) {
			sprite.setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y + .02));
		}

		if (inputRef->isKeyDown(sf::Keyboard::A)) {
			sprite.setPosition(sf::Vector2f(sprite.getPosition().x - 0.02, sprite.getPosition().y));
		}

		if (inputRef->isKeyDown(sf::Keyboard::D)) {
			sprite.setPosition(sf::Vector2f(sprite.getPosition().x + 0.02, sprite.getPosition().y));
		}

		if (inputRef->isKeyDown(sf::Keyboard::Space))
		{
			sprite.velocity.y = -4.f * 50;
		}
	}
}
void Level::render()
{
	beginDraw();
	window->draw(sprite);
	endDraw();
}
void Level::beginDraw()
{
	window->clear(sf::Color::Black);
}
void Level::endDraw()
{
	window->display();
}