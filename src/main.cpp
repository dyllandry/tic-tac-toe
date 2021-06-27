#include "main-menu.hpp"
#include "text-component-system.hpp"
#include "input-event-dispatcher.hpp"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Tic-Tac-Toe");
	window.setKeyRepeatEnabled(false);

	// Initialize systems.
	TextComponentSystem textComponentSystem;
	InputEventDispatcher inputEventDispatcher;

	MainMenu mainMenu(window);

	// Game loop.
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			inputEventDispatcher.DispatchEvent(event);
		}

		window.clear(sf::Color::Black);

		textComponentSystem.Render(window);

		window.display();
	}

	return 0;
}
