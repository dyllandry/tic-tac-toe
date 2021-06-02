#include "event.hpp"

// I don't know why we need a double pointer for SlotType. It can be useful for
// changing where a passed pointer points to from inside the function.
// https://stackoverflow.com/questions/5580761/why-use-double-indirection-or-why-use-pointers-to-pointers
// I noticed C++11 push_back can take a &value or &&value. I wonder if it
// needs a double pointer so it can handle allocating more size? So it
// can change the pointer at an index while keeping the value it points at?
void Dispatcher::subscribe(const Event::DescriptorType &descriptor, SlotType&& slot)
{
	_observers[descriptor].push_back(slot);
}

void Dispatcher::post(const Event& event) const 
{
	auto type{event.type()};
	if (_observers.find(type) == _observers.end())
		return;
	auto&& observers = _observers.at(type);
	for (auto&& observer : observers)
		observer(event);
}
