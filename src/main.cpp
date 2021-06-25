#include "entity.hpp"
#include "text-component-system.hpp"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Tic-Tac-Toe");

	// Initialize systems.
	TextComponentSystem textComponentSystem;

	// Create title screen.
	Entity *titleEntity = new Entity();
	auto& titleText {titleEntity->addComponent<TextComponent>()};
	titleText.sfmlText.setString("Tic-Tac-Toe");
	titleText.sfmlText.setOrigin(titleText.sfmlText.getLocalBounds().width / 2.0f, 0.0f);
	titleText.sfmlText.setPosition(static_cast<float>(window.getSize().x) / 2.0f, 20.0f);
	Entity *startTextEntity = new Entity();
	TextComponent& startText = startTextEntity->addComponent<TextComponent>();
	startText.sfmlText.setString("Press enter to start (under construction)");
	startText.sfmlText.setCharacterSize(18);
	startText.sfmlText.setOrigin(startText.sfmlText.getLocalBounds().width / 2.0f, 0);
	startText.sfmlText.setPosition(
		static_cast<float>(window.getSize().x) / 2.0f,
		titleText.sfmlText.getPosition().y + titleText.sfmlText.getLocalBounds().height + 20.0f);

	// Game loop.
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
