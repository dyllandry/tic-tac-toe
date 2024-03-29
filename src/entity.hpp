#ifndef ENTITY_H
#define ENTITY_H

#include "comparators.hpp"
#include <assert.h>
#include <iostream>
#include <map>

// Forward declarations
class Component;
using DescriptorType = const char*;

class Entity
{
public:

	Entity();
	~Entity();

	using Id = int;
	Id id();

	template<typename T>
	T& addComponent()
	{
		assert(_components.find(T::descriptor) == _components.end());
		T* component = new T(_id);
		_components[component->type()] = component;
		return *component;
	}

	template<typename T>
	void removeComponent()
	{
		auto component {_components.find(T::descriptor)};
		if (component == _components.end()) return; 
		delete component->second;
		_components.erase(T::descriptor);
	}


	template<typename T>
	T* getComponent()
	{
		auto component {_components.find(T::descriptor)};
		if (component == _components.end()) return nullptr;
		else return static_cast<T*>(component->second);
	};

private:
	Id _id;
	Id makeId();
	std::map<DescriptorType, Component*, CompareCStrings> _components{};
};

#endif // ENTITY_H
