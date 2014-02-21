#include"Game.h"

void Game::OnEvent()
{
	while(window.pollEvent(windowEvent))
	{
		switch(windowEvent.type)
			{
			case sf::Event::Closed:
				running = false;
				break;
			case sf::Event::KeyPressed:
				if(windowEvent.key.code == sf::Keyboard::Escape)
					running = false;
				break;
			}
	}
}