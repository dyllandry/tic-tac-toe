#include "entity.hpp"
#include "text-component-system.hpp"
#include <iostream>

int main()
{
	Entity *entity = new Entity();

	TextComponentSystem textComponentSystem;
	auto& textComponent {entity->addComponent<TextComponent>()};
	textComponent.sfmlText.setString("Tic-Tac-Toe");

	sf::RenderWindow window(sf::VideoMode(800, 600), "Tic-Tac-Toe");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		textComponentSystem.Render(window);

		window.display();
	}

	return 0;
}
