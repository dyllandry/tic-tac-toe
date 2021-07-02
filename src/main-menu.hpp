#ifndef MAIN_MENU_H

#include "entity.hpp"
#include "event.hpp"
#include <SFML/Graphics.hpp>

class MainMenu
{
public:
	MainMenu(sf::RenderWindow &window);
private:
	Entity *_title;
	Entity *_startText;
	void _handleConfirmInputEvent(const Event& event);
};

#define MAIN_MENU_H
#endif // MAIN_MENU_H
