#ifndef EVENT_H
#define EVENT_H
/*
 * Followed this tutorial to create this event system.
 * https://bastian.rieck.ru/blog/posts/2015/event_system_cxx11/
 *
 * Usage:
 *
 *     using namespace std::placeholders;
 *     DemoObserver observer;
 *     Dispatcher dispatcher;
 *     dispatcher.subscribe(
 *         DemoEvent::descriptor,
 *         std::bind(&DemoObserver::handle, observer, _1)
 *     );
 *     dispatcher.post(DemoEvent{});
 * 
 * std::function and std::bind are used to implement callbacks.
 * https://stackoverflow.com/questions/6610046/stdfunction-and-stdbind-what-are-they-and-when-should-they-be-used
 */

#include <functional>
#include <vector>
#include <map>

class Event
{
public:
	virtual ~Event() {};
	using DescriptorType = const char*;
	// I'm not sure what the point of having both a public DescriptorType
	// variable and DescriptorType getter method.
	virtual DescriptorType type() const = 0;
};

class DemoEvent : public Event
{
	public:
		DemoEvent() = default;
		static constexpr DescriptorType descriptor = "DemoEvent";
		virtual DescriptorType type() const
		{
			return descriptor;
		}
};

class Dispatcher
{
public:
	using SlotType = std::function<void (const Event&)>;
	void subscribe(const Event::DescriptorType& descriptor, SlotType&& slot);
	void post(const Event& event) const;
private:
	std::map<Event::DescriptorType, std::vector<SlotType>> _observers;
};
#endif // EVENT_H
