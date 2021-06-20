#ifndef EVENT_H
#define EVENT_H
/*
 * Followed this tutorial to create this event system.
 * https://bastian.rieck.ru/blog/posts/2015/event_system_cxx11/
 *
 * Usage:
 *
 *		using namespace std::placeholders;
 *		
 *		DemoObserver observer;
 *		Dispatcher::getInstance().subscribe(
 *		  DemoEvent::descriptor,
 *		  std::bind(&DemoObserver::handle, observer, _1)
 *		);
 *		
 *		Dispatcher::getInstance().post(DemoEvent{});
 * 
 * std::function and std::bind are used to implement callbacks.
 * https://stackoverflow.com/questions/6610046/stdfunction-and-stdbind-what-are-they-and-when-should-they-be-used
 */

// TODO: each type of event, and the dispatcher, should be in their own header
// so that if one event type changes, not every cpp file that uses an event
// needs to be recompiled.

#include "comparators.hpp"
#include <cstring>
#include <functional>
#include <vector>
#include <map>

class DemoTimerComponent;

using Id = int;

class Event
{
public:
	virtual ~Event() {};
	using DescriptorType = const char*;
	virtual DescriptorType type() const = 0;
};

class DemoEvent : public Event
{
public:
	DemoEvent() = default;
	static constexpr DescriptorType descriptor = "DemoEvent";
	virtual DescriptorType type() const { return descriptor; }
};

class DemoTimerComponentCreated : public Event
{
public:
	DemoTimerComponent* component;

	DemoTimerComponentCreated(DemoTimerComponent& _component)
		: component(&_component) {};

	static constexpr DescriptorType descriptor = "DemoTimerComponentCreated";
	virtual DescriptorType type() const { return descriptor; }
};

class DemoTimerComponentDestroyed : public Event
{
public:
	DemoTimerComponent* component;

	DemoTimerComponentDestroyed(DemoTimerComponent& _component)
		: component(&_component) {}

	static constexpr DescriptorType descriptor = "DemoTimerComponentDestroyed";

	virtual DescriptorType type() const { return descriptor; }
};

class Dispatcher
{
public:
	// Singleton pattern followed: https://stackoverflow.com/a/1008289/7933478
	static Dispatcher& getInstance()
	{
		static Dispatcher instance;
		return instance;
	}

	using SlotType = std::function<void (const Event&)>;
	void subscribe(const Event::DescriptorType& descriptor, SlotType&& slot);
	void post(const Event& event) const;
private:
	Dispatcher() = default;
	Dispatcher(Dispatcher const&) = delete;
	void operator=(Dispatcher const&) = delete;

	std::map<Event::DescriptorType, std::vector<SlotType>, CompareCStrings> _observers;
};
#endif // EVENT_H
