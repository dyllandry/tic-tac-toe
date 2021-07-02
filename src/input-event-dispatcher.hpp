#ifndef INPUT_EVENT_DISPATCHER_H
#define INPUT_EVENT_DISPATCHER_H

#include "picked-tile-input-event.hpp"
#include <functional>
#include <SFML/Window.hpp>

class InputEventDispatcher
{
public:
	InputEventDispatcher() = default;
	void dispatchEvent(sf::Event &event);
private:
	bool _isKeyNumber(sf::Keyboard::Key code);
	PickedTile _numKeyToPickedTile(sf::Keyboard::Key code);
};
#endif // INPUT_EVENT_DISPATCHER_H
