#include <iostream>

#include "Variables.h"
#include "MainGame.h"

int main()
{
	// ------------------ SET UP A WINDOW ---------------------
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Jake the man");
	window.setFramerateLimit(60);

	// ------------------ SET UP A MAIN GAME ---------------------
	MainGame mainGame(0.0f, 0.0f);
	Background bg(&window);
	Player player;

	//--------------------- SET UPO THE CLOCK ---------------------
	sf::Clock clock;

	float deltaTime = 0;
	float time = 0;
	float timeElapsed = clock.getElapsedTime().asSeconds();
	float FPS;

	// ------------------ GAME LOOP ---------------------
	while (window.isOpen())
	{
		deltaTime++;

		Event ev;
		while (window.pollEvent(ev))
		{
			//Typ eventu
			switch (ev.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				switch (ev.key.code)
				{
				case sf::Keyboard::Return:
					break;
				case sf::Event::KeyReleased:
					mainGame.IsPlayerJump(player, false);
					break;
				case sf::Keyboard::Escape:
					window.close();
					break;
				}
				break;
			}

		}

		mainGame.Update(deltaTime);

		window.clear();

		bg.Draw(&window);
		mainGame.Draw(&window);

		window.display();

		timeElapsed = clock.restart().asSeconds();
		deltaTime = timeElapsed - time;
		FPS = 1.0f / deltaTime;
		time = timeElapsed;
	}

	return 0;
}