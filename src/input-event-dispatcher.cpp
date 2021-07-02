#include "confirm-input-event.hpp"
#include "event.hpp"
#include "input-event-dispatcher.hpp"
#include <iostream>

void InputEventDispatcher::dispatchEvent(sf::Event &event)
{
	switch (event.type)
	{
		case sf::Event::KeyPressed:
			if (_isKeyNumber(event.key.code))
			{
				PickedTile pickedTile = _numKeyToPickedTile(event.key.code);
				PickedTileInputEvent pickedTileInputEvent(pickedTile);
				Dispatcher::getInstance().post(pickedTileInputEvent);
			} else if (event.key.code == sf::Keyboard::Enter)
			{
				ConfirmInputEvent confirmInputEvent;
				Dispatcher::getInstance().post(confirmInputEvent);
			}
			break;
		default: break;
	}
}

PickedTile InputEventDispatcher::_numKeyToPickedTile(sf::Keyboard::Key code)
{
	switch (code)
	{
		case sf::Keyboard::Num1:
		case sf::Keyboard::Numpad1:
			return PickedTile::topLeft;
        case sf::Keyboard::Num2:
		case sf::Keyboard::Numpad2:
			return PickedTile::topCenter;
        case sf::Keyboard::Num3:
		case sf::Keyboard::Numpad3:
			return PickedTile::topRight;
        case sf::Keyboard::Num4:
		case sf::Keyboard::Numpad4:
			return PickedTile::centerLeft;
        case sf::Keyboard::Num5:
		case sf::Keyboard::Numpad5:
			return PickedTile::center;
        case sf::Keyboard::Num6:
		case sf::Keyboard::Numpad6:
			return PickedTile::centerRight;
        case sf::Keyboard::Num7:
		case sf::Keyboard::Numpad7:
			return PickedTile::bottomLeft;
        case sf::Keyboard::Num8:
		case sf::Keyboard::Numpad8:
			return PickedTile::bottomCenter;
        case sf::Keyboard::Num9:
		case sf::Keyboard::Numpad9:
			return PickedTile::bottomRight;
		default:
			throw "Cannot convert sf::Keyboard::Key to PickedTile.";
	}
};

bool InputEventDispatcher::_isKeyNumber(sf::Keyboard::Key code)
{
	switch (code)
	{
		case sf::Keyboard::Num1:
        case sf::Keyboard::Num2:
        case sf::Keyboard::Num3:
        case sf::Keyboard::Num4:
        case sf::Keyboard::Num5:
        case sf::Keyboard::Num6:
        case sf::Keyboard::Num7:
        case sf::Keyboard::Num8:
        case sf::Keyboard::Num9:
		case sf::Keyboard::Numpad1:
		case sf::Keyboard::Numpad2:
		case sf::Keyboard::Numpad3:
		case sf::Keyboard::Numpad4:
		case sf::Keyboard::Numpad5:
		case sf::Keyboard::Numpad6:
		case sf::Keyboard::Numpad7:
		case sf::Keyboard::Numpad8:
		case sf::Keyboard::Numpad9:
			return true;
		default: return false;
	}
}
