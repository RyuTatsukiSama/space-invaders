#include "Common.h"
#include "Spaceship.h"
#include "GameFSM.h"
#include "ShipController.h"

int main()
{
	srand(UINT32(time(NULL)));

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Space Invaders");

	GameFSM fsm;

	sf::Clock deltaTime;
	while (window.isOpen())
	{
		float dt = deltaTime.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		

		fsm.handleInput(dt);
		fsm.update(dt);
		fsm.render(window);
	}
}