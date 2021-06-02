#include "demo-observer.hpp"
#include "event.hpp"
#include <functional>
#include <iostream>

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

int main()
{
	using namespace std::placeholders;
	DemoObserver observer;
	Dispatcher dispatcher;
	dispatcher.subscribe(
		DemoEvent::descriptor,
		// I think using std::bind to pass member function as callback.
		// Could just use the name of a function if it's not a member.
		std::bind(&DemoObserver::handle, observer, _1)
	);
	dispatcher.subscribe(
		DemoEvent::descriptor,
		handle
	);
	dispatcher.post(DemoEvent{});
	return 0;
}
