#include "confirm-input-event.hpp"
#include "main-menu.hpp"
#include "text-component-system.hpp"
#include <iostream>

void MainMenu::_handleConfirmInputEvent(const Event& event)
{
	const ConfirmInputEvent& confirmInputEvent = static_cast<const ConfirmInputEvent&>(event);
	std::cout << "Quick, start the game, now!" << std::endl;
}

// UPGRADE: instead of passing the window object so that MainMenu can
// horizontally center the main menu title text, pass an option to the
// TextComponent to keep it horizontally centered. The TextComponentSystem
// already has a reference to the window in order to render things.
MainMenu::MainMenu(sf::RenderWindow &window)
{
	_title = new Entity();
	auto& titleText {_title->addComponent<TextComponent>()};
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

	Dispatcher::getInstance().subscribe(
			ConfirmInputEvent::descriptor,
			std::bind(&MainMenu::_handleConfirmInputEvent, this, std::placeholders::_1));
}

