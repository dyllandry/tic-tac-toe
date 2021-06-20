#ifndef COMPONENT_H
#define COMPONENT_H

#include <assert.h>
#include <chrono>
#include <functional>
#include <iostream>
#include <map>
#include <vector>

// Forward declarations
using Id = int;

class Component
{
public:
	using DescriptorType = const char*;
	virtual DescriptorType type() const = 0;
	Id entityId() { return _entityId; }
	Component(Id entityId) : _entityId(entityId) {}
	virtual ~Component() {};
protected:
	Id _entityId;
};

class ComponentSystem
{
public:
	ComponentSystem() = default;
	virtual ~ComponentSystem() {};
};

#endif // COMPONENT_H
