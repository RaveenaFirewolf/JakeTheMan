#include <iostream>

#include "Variables.h"
#include "MainGame.h"

int main()
{
	// ------------------ SET UP A WINDOW ---------------------
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Jake the man");
	window.setFramerateLimit(60);

	sf::View view(sf::FloatRect(0, 0, 1280, 768));
	window.setView(view);

	// ------------------ SET UP A MAIN GAME ---------------------
	MainGame mainGame(0.0f, 0.0f);
	Background bg;
	Player player;
	
	// ------------------ GAME LOOP ---------------------
	while (window.isOpen())
	{
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
					player.GetJumpState(false);
					break;
				case sf::Keyboard::Escape:
					window.close();
					break;
				}
				break;
			}

		}
		player.Movement();

		//mainGame.Update();
		window.clear();

		bg.Draw(&window);
		mainGame.Draw(&window);
		player.Draw(&window);

		window.display();
	}

	return 0;
}