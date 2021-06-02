#include "demo-observer.hpp"
#include "event.hpp"
#include <functional>
#include <iostream>

int main()
{
	using namespace std::placeholders;

	DemoObserver observer;
	Dispatcher dispatcher;

	dispatcher.subscribe(
		DemoEvent::descriptor,
		std::bind(&DemoObserver::handle, observer, _1)
	);

	dispatcher.post(DemoEvent{});

	return 0;
}
