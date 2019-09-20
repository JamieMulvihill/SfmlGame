#include "Level.h"
#include "Input.h"
#include <chrono>

void main()
{
	// Create window
	sf::RenderWindow window(sf::VideoMode(1216, 768), "SFML GAME");

	Input input;
	// Initialise level object
	Level level(&window , &input);


	//Delta time
	auto start = std::chrono::system_clock::now();
	auto end = std::chrono::system_clock::now();
	float deltaTime = 0.0f; // .0004;

	// Game loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				window.setView(sf::View(sf::FloatRect(0.f, 0.f,
					(float)event.size.width, (float)event.size.height)));
				break;
			case sf::Event::KeyPressed:
				// update input class
				input.setKeyDown(event.key.code);
				break;
			case sf::Event::KeyReleased:
				//update input class
				input.setKeyUp(event.key.code);
				break;
			case sf::Event::MouseMoved:
				//update input class
				input.setMousePosition(event.mouseMove.x,
					event.mouseMove.y);
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					//update input class
					input.setMouseLeftDown(true);
				}
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					//update input class
					input.setMouseLeftDown(false);
				}
				break;
			default:
				// don't handle other events
				break;
			}
		}


		//calculating deltatime. How much time has passed since it was last calculated and restart
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed_seconds = end - start;
		deltaTime = elapsed_seconds.count();
		start = end;

		level.handleInput(deltaTime);
		level.update(deltaTime);
		level.render();
	}
}