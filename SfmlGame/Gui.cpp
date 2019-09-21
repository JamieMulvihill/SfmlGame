#include "Gui.h"
#include <iostream>

Gui::Gui()
{
	guiBackground.setPosition(645, 5);
	guiBackground.setSize(sf::Vector2f(120, 85));
	bgTex.loadFromFile("gfx/BGGui.png");
	guiBackground.setTexture(&bgTex);

	if (!font.loadFromFile("gfx/Blox2.ttf"))
	{
		std::cout << "Error loading font.";
	}

	timer = 60;
	timeText.setFont(font);
	timeText.setPosition(675, 10);
	timeText.setCharacterSize(65);
	timeText.setString(std::to_string(timer));

	scorePlayer1 = 0;
	player1Text.setFont(font);
	player1Text.setPosition(575, 25);
	player1Text.setCharacterSize(30);
	player1Text.setString(std::to_string(scorePlayer1));
	player1Text.setFillColor(sf::Color::Blue);

	scorePlayer2 = 0;
	player2Text.setFont(font);
	player2Text.setPosition(625, 25);
	player2Text.setCharacterSize(30);
	player2Text.setString(std::to_string(scorePlayer2));
	player2Text.setFillColor(sf::Color::Red);

	scorePlayer3 = 0;
	player3Text.setFont(font);
	player3Text.setPosition(775, 25);
	player3Text.setCharacterSize(30);
	player3Text.setString(std::to_string(scorePlayer1));
	player3Text.setFillColor(sf::Color::Green);

	scorePlayer4 = 0;
	player4Text.setFont(font);
	player4Text.setPosition(825, 25);
	player4Text.setCharacterSize(30);
	player4Text.setString(std::to_string(scorePlayer1));
	player4Text.setFillColor(sf::Color::Yellow);

}

Gui::~Gui()
{
}

void Gui::Update(float dt)
{
	if (timer > 0) {
		timer -= dt;
		timeText.setString(std::to_string((int)timer));
	}
}

void Gui::Render(sf::RenderWindow* window)
{
	window->draw(timeText);
	window->draw(player1Text);
	window->draw(player2Text);
	window->draw(player3Text);
	window->draw(player4Text);
}
