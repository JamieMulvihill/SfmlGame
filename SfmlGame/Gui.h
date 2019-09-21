#pragma once
#include <SFML/Graphics.hpp>
class Gui
{
public:
	Gui();
	~Gui();

	void Update(float dt);
	void Render(sf::RenderWindow* window);

	
private:
	// variables for value intake
	int scorePlayer1, scorePlayer2, scorePlayer3, scorePlayer4;
	float timer;

	sf::Font font;
	sf::Text timeText, player1Text, player2Text, player3Text, player4Text;

	sf::Texture bgTex;
	sf::RectangleShape guiBackground;
	sf::RectangleShape guiForeground;
};

