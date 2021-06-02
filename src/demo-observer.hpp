#ifndef DEMO_OBSERVER_H
#define DEMO_OBSERVER_H

#include <iostream>

class Event
{
public:
	using DescriptorType = const char*;
	virtual DescriptorType type() const = 0;
};

class DemoEvent : public Event
{
public:
	static constexpr DescriptorType descriptor = "DemoEvent";
};

class DemoObserver
{
public:
	void handle(const Event& event)
	{
		// This handler could receive events of different types if you
		// subscribe it to many. So one handler for, lets say keyboard input,
		// could subscribe to events fired for each key. That's where this
		// if statement could be useful.
		if (event.type() == DemoEvent::descriptor)
		{
			const DemoEvent& demoEvent{static_cast<const DemoEvent&>(event)};
			std::cout << __PRETTY_FUNCTION__ << ": " << demoEvent.type() << '\n';
		}
	}
};

#endif // DEMO_OBSERVER_H
