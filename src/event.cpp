#include "event.hpp"
#include <assert.h>
#include <iostream>

void Dispatcher::subscribe(const Event::DescriptorType &descriptor, SlotType&& slot)
{
	_observers[descriptor].push_back(slot);
}

void Dispatcher::post(const Event& event) const 
{
	auto type{event.type()};

	if (_observers.find(type) == _observers.end())
	{
		std::cout << "No observers found for event type " << type << std::endl;
		return;
	}

	auto&& observers = _observers.at(type);

	for (auto&& observer : observers)
	{
		observer(event);
	}
}
