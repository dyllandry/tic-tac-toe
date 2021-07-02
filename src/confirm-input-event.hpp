#ifndef CONFIRM_INPUT_EVENT_H
#define CONFIRM_INPUT_EVENT_H

#include "event.hpp"

using DescriptorType = const char*;

class ConfirmInputEvent : public Event
{
public:
	ConfirmInputEvent() = default;
	static constexpr DescriptorType descriptor = "ConfirmInputEvent";
	virtual DescriptorType type() const { return descriptor; }
};

#endif // CONFIRM_INPUT_EVENT_H
